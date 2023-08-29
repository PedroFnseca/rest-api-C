#!/bin/bash

set -e

mkdir -p bin

gcc -o bin/main src/main.c -lmicrohttpd
