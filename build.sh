#!/bin/sh
cmake -S . -B bin/build
make -C bin/build/
./bin/build/Solar_System_rebased
