FROM debian:bullseye

RUN apt-get -y update && apt-get -y upgrade

RUN apt-get install -y curl php php7.4-fpm php-mysql mariadb-client php-redis

WORKDIR /var/www/wordpress

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

RUN sed -i 's|listen = /run/php/php7.4-fpm.sock|listen = 9000|' /etc/php/7.4/fpm/pool.d/www.conf

RUN mkdir -p /run/php

COPY ./tools/run.sh /home/

RUN chmod +x /home/run.sh

ENTRYPOINT ["/home/run.sh"]
