FROM debian:bullseye

RUN apt-get -y update && apt-get -y upgrade

RUN apt-get -y install wget

WORKDIR /usr/local/bin/

RUN wget https://github.com/google/cadvisor/releases/download/v0.52.1/cadvisor-v0.52.1-linux-amd64 -O cadvisor

RUN chmod +x cadvisor

ENTRYPOINT cadvisor