FROM debian:bullseye

RUN apt-get -y update && apt-get -y upgrade

RUN apt-get install -y vsftpd

WORKDIR /root

COPY ./tools/setup.sh .

RUN chmod +x setup.sh

ENTRYPOINT [ "./setup.sh" ]