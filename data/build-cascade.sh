#!/bin/bash

UNAME=$(uname -s)
if [ "$UNAME" == "Darwin" ]; then
	export PATH=/usr/local/Cellar/opencv3/3.2.0/bin/:$PATH
fi

# Create the front-right cascade
mkdir -p cascade/front-right
rm -f cascade/front-right/*
opencv_traincascade -data cascade/front-right/ \
		    -acceptanceRatioBreakValue 10e-5 \
		    -bg ./negatives.txt \
		    -vec ./pos-front-right.vec \
		    -numPos 814 \
		    -numNeg 15000 \
		    -mode ALL \
		    -precalcValBufSize 6144 \
		    -precalcIdxBufSize 6144

# Create the front cascade
mkdir -p cascade/front
rm -f cascade/front/*
opencv_traincascade -data cascade/front/ \
		    -acceptanceRatioBreakValue 10e-5 \
		    -bg ./negatives.txt \
		    -vec ./pos-front.vec \
		    -numPos 904 \
		    -numNeg 15000 \
		    -mode ALL \
		    -precalcValBufSize 6144 \
		    -precalcIdxBufSize 6144 \
		    -w 16 -h 16

# Create the front-bith cascade
mkdir -p cascade/front-both
rm -f cascade/front-both/*
opencv_traincascade -data cascade/front-both/ \
		    -acceptanceRatioBreakValue 10e-5 \
		    -bg ./negatives.txt \
		    -vec ./pos-front-both.vec \
		    -numPos 1718 \
		    -numNeg 15000 \
		    -mode ALL \
		    -precalcValBufSize 6144 \
		    -precalcIdxBufSize 6144 \
		    -w 16 -h 16
