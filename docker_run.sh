#!/bin/bash

# Nome do contêiner
CONTAINER_NAME="rest-api-c"

# Remove o contêiner existente com o mesmo nome
docker rm -f "$CONTAINER_NAME" >/dev/null 2>&1

# Constrói a imagem do Docker a partir do Dockerfile
docker build -t rest-api-c .

# Executa o contêiner, expondo a porta 8080 e atribuindo o nome "rest-api-c"
docker run -d -p 8080:80 --name "$CONTAINER_NAME" rest-api-c
