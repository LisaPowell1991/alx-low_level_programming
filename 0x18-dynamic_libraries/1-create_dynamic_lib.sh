#!/bin/bash
gcc -Wall -c -fPIC *.c
gcc *.o -shared -o liball.so
