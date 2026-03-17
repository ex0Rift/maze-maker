#!/bin/bash
echo "Compiling..."
g++ \
    src/main.cpp \
    -I include \
    -o build \
    -lraylib -lm -ldl -lGL -pthread
if [ $? -ne 0 ]; then
    echo "Compile failed! exiting..."
    exit 1
fi
./build
