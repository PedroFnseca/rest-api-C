#!/bin/bash
cd ..

set -e

mkdir -p bin

gcc -o bin/main src/main.c -lmicrohttpd -I/usr/include/postgresql -L/usr/lib/x86_64-linux-gnu -lpq
