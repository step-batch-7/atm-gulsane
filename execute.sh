#! /bin/bash

mkdir -p bin
rm -rf ./*.o

excecutable=$1

gcc -c ./*.c
gcc -o $excecutable ./*.o

mv $excecutable ./bin
./bin/$excecutable

rm -rf ./*.o