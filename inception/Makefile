export MARIADB=/home/aabouqas/data/mariadb
export WORDPRESS=/home/aabouqas/data/wordpress
include srcs/.env

all: up
	@clear
	@command -v python3 2> /dev/null 1> /dev/null && echo "print('-' * 60)" | python3 || true
	@echo "wordpress : https://${DOMAIN_NAME}"
	@echo "portfolio : https://${DOMAIN_NAME}:5000"
	@echo "cadvisor : http://${DOMAIN_NAME}:5001"
	@echo "adminer : https://${DOMAIN_NAME}:5002/adminer.php"
	@echo "ftp => 5010 | redis => 6379 | adminer => 6379"
	@command -v python3 2> /dev/null 1> /dev/null && echo "print('-' * 60)" | python3 || true

up: down
	docker-compose -f srcs/docker-compose.yml up --build -d

down:
	@echo "Shutting down containers..."
	@docker-compose -f srcs/docker-compose.yml down 2> /dev/null 1> /dev/null || true
	@echo "Shutting down containers [done]"

re: fclean all

clean: down
	@docker run --rm -v /home/aabouqas/data/wordpress:/var/www/wordpress alpine:3.14 sh -c "rm -rf /var/www/wordpress/*" || true
	@docker run --rm -v /home/aabouqas/data/mariadb:/var/lib/mysql/ alpine:3.14 sh -c "rm -rf /var/lib/mysql/*" || true
	@docker rm -f $(shell docker container ls -aq) 2> /dev/null 1> /dev/null || true
	@docker volume rm -f $(shell docker volume ls -q) 2> /dev/null 1> /dev/null || true
	@docker network rm inception 2> /dev/null 1> /dev/null || true

fclean: clean
	@read -p "Are you sure you want to delete all images ? [y/n] : " ans; \
	if [ "$$ans" = "y" ]; then \
		echo "Deleting..."; \
		docker image rm -f $(shell docker image ls -aq) 2> /dev/null 1> /dev/null || true; \
	else \
		echo "Aborted."; \
	fi

stop:
	@echo "Stopping containers..."
	@docker stop $(shell docker container ls -aq) 2> /dev/null 1> /dev/null || true

start:
	@echo "Starting containers..."
	@docker start $(shell docker container ls -aq) 2> /dev/null 1> /dev/null || true

rebuild: down up

restart: stop start


.PHONY: start stop fclean clean down up