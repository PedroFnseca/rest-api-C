#!/bin/bash

mkdir -p bin

gcc -o bin/main src/main.c -lmicrohttpd

if [ $? -eq 0 ]; then
    echo "Compilação bem-sucedida."
else
    echo "Erro durante a compilação."
fi
