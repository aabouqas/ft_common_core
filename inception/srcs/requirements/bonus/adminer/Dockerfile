FROM debian:bullseye

RUN apt-get -y update && apt-get -y upgrade

RUN apt-get -y install php wget nginx php-fpm php-mysqli php-pdo-mysql php-mysql

COPY ./conf/nginx.conf /etc/nginx/conf.d

WORKDIR /etc/nginx/ssl/

RUN openssl req -x509 -nodes -out certificate.pem -keyout key.pem -subj="/C=MO/ST=KH/L=KH/O=1337/OU=1337/CN=aabouqas.42.fr/UID=aissam"

WORKDIR /var/www/html

RUN wget https://github.com/vrana/adminer/releases/download/v5.2.1/adminer-5.2.1-mysql.php -O adminer.php

ENTRYPOINT service php7.4-fpm start && nginx -g "daemon off;"
