#!/bin/bash

cd ..

CONTAINER_NAME="rest-api-c"

docker rm -f "$CONTAINER_NAME" >/dev/null 2>&1

docker build -t rest-api-c .

docker run -d -p 8080:80 --name "$CONTAINER_NAME" rest-api-c
