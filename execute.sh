#! /bin/bash

excecutable=$1

rm -rf $directory/*.o

gcc -c ./*.c
gcc -o $excecutable ./*.o

mv $excecutable ./bin
./bin/$excecutable
rm -rf *.o