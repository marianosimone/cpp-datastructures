# Requires libgtest0, libgtest-dev and lcov libraries

CXXFLAGS = -g -pedantic -Wall -fmessage-length=0 -lpthread -lgtest_main -fprofile-arcs -ftest-coverage --coverage

test_files ?= $(wildcard test/*.cpp)
src_files ?= $(wildcard src/*.cpp)
o_files = $(patsubst %.cpp,%.o,$(test_files))
o_files += $(patsubst %.cpp,%.o,$(src_files))
output_dir ?= build
output_bin ?= $(output_dir)/tests

.PHONY: clean test

all:	clean build test

build:	$(o_files)
	mkdir -p -v $(output_dir)
	$(CXX) -lgcov $(CXXFLAGS) $(o_files) -o $(output_bin)

test:
	./build/tests
	lcov --capture --directory src --base-directory . -o $(output_dir)/report_output.out
	genhtml -o $(output_dir)/coverage_report $(output_dir)/report_output.out
	$(MAKE) clean-tmps

clean:
	rm -rf $(output_dir)
	$(MAKE) clean-tmps

clean-tmps:
	rm -rf $(o_files)
	lcov --zerocounters --directory .
	find . -name "*.gcno" -delete
