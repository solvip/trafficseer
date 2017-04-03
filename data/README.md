Trafficseer data corpus
=======================

# Annotating

To annotate positive images, you can use the opencv_annotations tool:

```bash
/usr/local/Cellar/opencv3/3.2.0/bin/opencv_annotation -i=./positives/ -a=./positives.txt
```

# Training

To train the LBP classifier, we use the create-samples.sh and build-cascade.sh tools:

```bash
./create-samples.sh
./build-cascade.sh
```

# Folder structure

The folder structure is as follows:

## /reference

Reference contains reference images, that we use to measure success.
I choose the "Kringlan Suður" camera, mainly because it's a stretch of road that I spend way
too much time on in the morning

The path to the kringlan-suður camera is http://www.vegagerdin.is/vgdata/vefmyndavelar/kringlan_3.jpg

## /positives

Directory containing positive images.  That is; the images we use to base our classifier on.
This is cars, trucks and buses extracted from webcam images.

## /negatives

Directory containing negative images.  This is all kinds of stuff that isn't cars, trucks or buses.
