Trafficseer
===========

# Repository structure

The structure of this repository resembles a fairly vanilla C++ project.
Source files are in src/; tests are in test/, we build everything using Make.
bin/ contains utilities and resulting binaries.

In addition, we have a folder called data/, that contains various auxillary data, such as images
we trained on, reference images, scripts to build classifiers and so on.

To build the software, follow the dependency installations below and then run:

```bash
$ make # Build everything
```


# Building and running

If you've installed the dependencies, you can run:

```bash
$ make
$ bin/trafficseer <path to a captured image>
```

Or, if you want to run trafficseer on multiple images:
```
$ bin/trafficseer data/reference/*
```

## Dependencies

Trafficseer depends on OpenCV3

### Mac OS X

If you're using Mac OS X, then you can install OpenCV 3 using Homebrew:

```bash
$ brew tap homebrew/science
$ brew install homebrew/science/opencv3
```

### Ubuntu

If you're using a recent version of Ubuntu, you'll find OpenCV 3 in apt:

```bash
$ sudo apt-get install opencv3
```
