```bash
docker logs nginx 2>&1 | grep '"http_code":403' | tail -1 | jq '.'
```

### HashiCoper Vault

**Write Sicret**

```bash
vault kv put secret/myapp/production \
  db_host="postgres.example.com" \
  db_password="prod-secret-456" \
  api_key="ak-789xyz" \
  jwt_secret="jwt-super-secret"
```

**Read Specific Field**

```bash
vault kv get -field=api_key secret/myapp/production
```

