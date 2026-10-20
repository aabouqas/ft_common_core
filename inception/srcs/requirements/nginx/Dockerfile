FROM debian:bullseye

RUN apt-get -y update && apt-get -y upgrade

RUN apt-get -y install nginx openssl

WORKDIR /etc/nginx/ssl/

RUN openssl req -x509 -nodes -out certificate.pem -keyout key.pem -subj="/C=MO/ST=KH/L=KH/O=1337/OU=1337/CN=aabouqas.42.fr/UID=aissam"

COPY ./conf/nginx.conf /etc/nginx/conf.d

RUN mkdir -p /var/www/wordpress

WORKDIR /var/www/wordpress

RUN chown -R www-data:www-data . && chmod -R 755 .

ENTRYPOINT ["nginx", "-g", "daemon off;"]
