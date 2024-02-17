#!/usr/bin/env bash

mkdir -p ./build

gcc ./src/*.c ./src/shared/*.c -o ./build/loadingScreen && \
./build/loadingScreen

read -p "Press enter to clear..."
clear