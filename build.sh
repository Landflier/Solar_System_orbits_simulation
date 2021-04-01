#!/bin/sh
~/cmake-3.20.0/bin/cmake -S . -B bin/build
make -C bin/build/
mkdir -p run
cd run
../bin/build/Solar_System_rebased
