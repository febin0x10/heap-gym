#!/bin/bash

sudo apt install patchelf
gcc capsule*.c -o capsuledb --stack-protector-all -no-pie
patchelf --set-interpreter ./ld-2.27.so --set-rpath . ./capsuledb
chmod u+s ./capsuledb