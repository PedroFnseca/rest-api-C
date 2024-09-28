#!/bin/bash
cd ..

set -e

mkdir -p bin

gcc -o bin/main src/*.c -lmicrohttpd -I/usr/include/postgresql -L/usr/lib/x86_64-linux-gnu -lpq

if [[ "$1" == "--run" ]]; then
  echo "Executando a aplicação..."
  ./bin/main
fi