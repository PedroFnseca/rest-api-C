FROM gcc:latest

RUN apt-get update && \
    apt-get install -y libmicrohttpd-dev make nginx libpq-dev

RUN mkdir -p /app

WORKDIR /app

COPY . /app

COPY nginx.conf /etc/nginx/nginx.conf

EXPOSE 80

CMD service nginx start && ./main_run.sh