FROM debian:bullseye

RUN apt-get -y update && apt-get -y upgrade

RUN apt-get -y install mariadb-server netcat

WORKDIR /root

COPY ./tools/run.sh .

ENTRYPOINT [ "./run.sh" ]