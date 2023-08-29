#!/bin/bash

echo -e "\n\033[0;33mCompiling...\033[0m\n"

make

if [ $? -ne 0 ]; then
    echo -e "\n\033[0;31mCompilation failed!\033[0m\n"
    exit 1
fi

echo -e "\n\033[0;32mCompilation successful!\033[0m\n"

./bin/main