#!/bin/bash

wp_admin_username=$(grep wp_admin_username /run/secrets/credentials | cut -d '=' -f2)
wp_admin_pass=$(grep wp_admin_pass /run/secrets/credentials | cut -d '=' -f2)
wp_admin_email=$(grep wp_admin_email /run/secrets/credentials | cut -d '=' -f2)

wp_username=$(grep wp_username /run/secrets/credentials | cut -d '=' -f2)
wp_user_pass=$(grep wp_user_pass /run/secrets/credentials | cut -d '=' -f2)
wp_user_email=$(grep wp_user_email /run/secrets/credentials | cut -d '=' -f2)

dp_user_name=$(grep dp_user_name /run/secrets/credentials | cut -d '=' -f2)
dp_pass=$(cat /run/secrets/dp_pass)
dp_name=$(grep dp_name /run/secrets/credentials | cut -d '=' -f2)
wp_user_rule=$(grep wp_user_rule /run/secrets/credentials | cut -d '=' -f2)

wp core download --allow-root || true
wp core config --dbhost="$DB_HOST" --dbname="${dp_name}" --dbuser="${dp_user_name}" --dbpass="${dp_pass}" --allow-root || true
wp core install --url="$DOMAIN_NAME" --title="$WP_TITLE" --admin_user="${wp_admin_username}" --admin_password="${wp_admin_pass}" --admin_email="${wp_admin_email}" --allow-root || true
wp user create "${wp_username}" "${wp_user_email}" --user_pass="${wp_user_pass}" --role="${wp_user_rule}" --allow-root || true

wp plugin install redis-cache --activate --allow-root || true
wp config set WP_REDIS_HOST 'redis' --type=constant --allow-root || true
wp config set WP_REDIS_PORT 6379 --type=constant --allow-root || true
wp redis enable --allow-root || true

chmod -R 775 /var/www/wordpress && chown -R www-data:www-data /var/www/wordpress

php-fpm7.4 -F