FROM debian:bullseye

RUN apt-get -y update && apt-get -y upgrade

RUN apt install -y redis

ENTRYPOINT ["redis-server", "--protected-mode no"]