#!/usr/bin/env bash

mkdir -p ./build

gcc -g -o ./build/debug/debugApp ./src/*.c ./src/shared/*.c && \
gdb ./build/debug/debugApp