#!/bin/sh

cd ext
make clean

./configure

make && make install

#/usr/local/apache/bin/apachectl -k restart

make clean

cd ..

