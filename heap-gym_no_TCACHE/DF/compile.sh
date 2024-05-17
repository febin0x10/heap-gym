#!/bin/bash

sudo apt install patchelf
gcc capsule*.c -o capsuledb --stack-protector-all -z now
patchelf --set-interpreter ./ld-2.23.so --set-rpath . ./capsuledb
chmod u+s ./capsuledb
