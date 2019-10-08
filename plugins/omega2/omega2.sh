#!/bin/sh
g++ -c omega2.cpp -fPIC -I. -I../../src
g++ -shared omega2.o -o omega2.so -loniondebug -lonioni2c -lonionoledexp