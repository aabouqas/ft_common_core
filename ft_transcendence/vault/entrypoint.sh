#!/bin/sh

# All secrets come from the environment (see ../.env.example)
for var in VAULT_ROOT_TOKEN SECRET_KEY REFRESH_SECRET_KEY SMTP_ACCESS_TOKEN \
           SMTP_CLIENT SMTP_PASSWORD GOOGLE_CLIENT_ID GOOGLE_CLIENT_SECRET; do
  eval "value=\${$var}"
  if [ -z "$value" ]; then
    echo "❌ Missing required environment variable: $var" >&2
    exit 1
  fi
done

# Start Vault in dev mode in the background
vault server -dev \
  -dev-root-token-id="$VAULT_ROOT_TOKEN" \
  -dev-listen-address=0.0.0.0:8200 &

VAULT_PID=$!

# Wait for Vault to be ready
echo "⏳ Waiting for Vault to start..."
export VAULT_ADDR='http://0.0.0.0:8200'
export VAULT_TOKEN="$VAULT_ROOT_TOKEN"

# Wait until Vault is actually ready
until vault status > /dev/null 2>&1; do
  echo "Waiting for Vault..."
  sleep 1
done

echo "✅ Vault is ready!"

# Enable KV secrets engine (ignore error if already enabled)
echo "🔧 Enabling KV secrets engine..."
vault secrets enable -path=secret kv-v2 2>/dev/null || echo "KV engine already enabled"

# Put the secrets
echo "🔐 Storing secrets in Vault..."
vault kv put secret/myapp/env \
    PORT="${PORT:-3001}" \
    HOST="${HOST:-0.0.0.0}" \
    HOST_NAME="${HOST_NAME:-ft-transcendence.42.fr}" \
    FRONTEND_URL="${FRONTEND_URL:-https://ft-transcendence.42.fr}" \
    secretKey="$SECRET_KEY" \
    refreshSecretKey="$REFRESH_SECRET_KEY" \
    expireTime="${EXPIRE_TIME:-5m}" \
    refreshExpireTime="${REFRESH_EXPIRE_TIME:-7d}" \
    SMTP_ACCESS_TOKEN="$SMTP_ACCESS_TOKEN" \
    GOOGLE_CLIENT_ID="$GOOGLE_CLIENT_ID" \
    GOOGLE_CLIENT_SECRET="$GOOGLE_CLIENT_SECRET" \
    SMTP_PASSWORD="$SMTP_PASSWORD" \
    SMTP_CLIENT="$SMTP_CLIENT"

echo "✅ Vault initialized with secrets!"

# Keep the container running (wait for Vault process)
wait $VAULT_PID
