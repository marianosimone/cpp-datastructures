# Requires libgtest0 and libgtest-dev libraries

CXXFLAGS = -O2 -g -pedantic -Wall -fmessage-length=0 -lpthread -lgtest_main

test_files ?= $(wildcard test/*.cpp)
src_files ?= $(wildcard src/*.cpp)
o_files = $(patsubst %.cpp,%.o,$(test_files))
o_files += $(patsubst %.cpp,%.o,$(src_files))

all:	clean tests

tests:	$(o_files)
	$(CXX) $(CXXFLAGS) $(o_files) -o tests

clean:
	rm -f $(o_files) tests
