#!/bin/bash

main() {
	dp_user_name=$(grep dp_user_name /run/secrets/credentials | cut -d '=' -f2)
	dp_user_pass=$(cat /run/secrets/dp_pass)
	dp_root_pass=$(cat /run/secrets/dp_root_pass)
	dp_name=$(grep dp_name /run/secrets/credentials | cut -d '=' -f2)

	mariadb -e "CREATE DATABASE IF NOT EXISTS \`${dp_name}\`;"
	mariadb -e "CREATE USER IF NOT EXISTS \`${dp_user_name}\`@'%' IDENTIFIED BY '${dp_user_pass}';"
	mariadb -e "GRANT ALL PRIVILEGES ON \`${dp_name}\`.* TO \`${dp_user_name}\`@'%';"
	mariadb -e "FLUSH PRIVILEGES;"

	mysqladmin -u root -p${dp_root_pass} shutdown
	mysqld_safe --bind-address=0.0.0.0 --datadir='/var/lib/mysql'
}


service mariadb start && sleep 5 && main