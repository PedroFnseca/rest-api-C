FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    libmicrohttpd-dev \
    gcc \
    make