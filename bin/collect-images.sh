#!/bin/bash

URL="http://www.vegagerdin.is/vgdata/vefmyndavelar/kringlan_3.jpg"

outputDir=$1
if [ "$outputDir" == "" ]; then
    echo "output directory missing"
    exit 1
fi

while true; do
    curTime=$(date "+%s")
    targetFile="${outputDir}/kringlan_3-${curTime}.jpg"
    wget -q $URL -O "$targetFile" || rm $targetFile

    # We might skip an image eventually.  So what.
    sleep 60;
done
