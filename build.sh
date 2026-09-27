#!/bin/bash
DIR="build/"
[ ! -d "$DIR" ] && mkdir $DIR
cd $DIR
cmake ..
cmake --build .
cd ..