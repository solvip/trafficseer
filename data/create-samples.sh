#!/bin/bash

UNAME=$(uname -s)
if [ "$UNAME" == "Darwin" ]; then
	export PATH=/usr/local/Cellar/opencv3/3.2.0/bin/:$PATH
fi

cat positives/*-front-right.dat | sed "s#\./#\./positives/#g" > pos-front-right.dat
opencv_createsamples -info pos-front-right.dat -vec pos-front-right.vec -num 10000

cat positives/*-front.dat | sed "s#\./#\./positives/#g" > pos-front.dat
opencv_createsamples -info pos-front.dat -vec pos-front.vec -num 10000 -w 16 -h 16

cat pos-front.dat pos-front-right.dat > pos-front-both.dat
opencv_createsamples -info pos-front-both.dat -vec pos-front-both.vec -num 10000 -w 16 -h 16
