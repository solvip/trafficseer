# Increase parallelism of builds.  Try to find the number of CPU cores
# or 2.
CPUS ?= $(shell getconf _NPROCESSORS_ONLN || 2)
MAKEFLAGS += --jobs=$(CPUS)

CXXFLAGS = -std=c++11 -g -Wpedantic -Wextra -Wstrict-overflow -fno-strict-aliasing $(shell bin/pkg-config opencv --cflags)
LIBS = $(shell bin/pkg-config opencv --libs)
TARGET = bin/trafficseer
PREPROCESS = bin/preprocess

CXX = g++

.PHONY: all clean

all: $(TARGET) $(PREPROCESS)

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard src/*.cpp))
HEADERS = $(wildcard src/*.h)

%.o: %.c $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(filter-out src/preprocess.o, $(OBJECTS)) -Wall $(LIBS) -o $@

$(PREPROCESS): $(OBJECTS)
	$(CXX) $(filter-out src/trafficseer.o, $(OBJECTS)) -Wall $(LIBS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)
