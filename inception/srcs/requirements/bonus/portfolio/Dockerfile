FROM debian:bullseye

RUN apt-get -y update && apt-get -y upgrade

RUN apt install -y nginx openssl

COPY ./conf/nginx.conf /etc/nginx/conf.d/

WORKDIR /etc/nginx/ssh/

RUN openssl req -x509 -nodes -out certificate.pem -keyout key.pem -subj="/C=MO/ST=KH/L=KH/O=1337/OU=1337/CN=aabouqas.42.fr/UID=aissam"

WORKDIR /var/www/website

COPY ./website .

RUN chown -R www-data:www-data . && chmod -R 755 .

ENTRYPOINT ["nginx", "-g", "daemon off;"]