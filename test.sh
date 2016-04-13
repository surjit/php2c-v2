#!/bin/sh

ROOT=$(pwd)
rm -rf $ROOT/ext
mkdir -p $ROOT/ext

php php2c.php

cd $ROOT/ext

phpize
./configure
make

php -n -d extension_dir=./modules -d extension=sample.so $ROOT/test.php

echo "all done"
