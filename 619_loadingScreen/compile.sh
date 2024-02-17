#!/usr/bin/env bash

mkdir -p ./build

gcc ./src/*.c -o ./build/loadingScreen && \
./build/loadingScreen