# Use uma imagem de base com suporte para compilação C
FROM gcc:latest

# Instale as dependências necessárias
RUN apt-get update && \
    apt-get install -y libmicrohttpd-dev make nginx libpq-dev

RUN mkdir -p /app

WORKDIR /app

COPY . /app

RUN ./build.sh

COPY nginx.conf /etc/nginx/nginx.conf

EXPOSE 80

CMD nginx -g "daemon off;"

RUN ./bin/main

# Rever execução do ./bin/main