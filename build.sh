#!/bin/bash

# Cria a pasta bin se não existir
mkdir -p bin

# Compila o código da pasta src usando gcc e libmicrohttpd, e coloca o executável na pasta bin
gcc -o bin/main src/main.c -lmicrohttpd

# Verifica se a compilação foi bem-sucedida
if [ $? -eq 0 ]; then
    echo "Compilação bem-sucedida."
else
    echo "Erro durante a compilação."
fi
