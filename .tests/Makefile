# Convenience wrapper around the CMake/CTest build of the GoogleTest suite.
#
#   make             configure (if needed) and build all tests
#   make test        build, then run all tests
#   make clean       remove compiled objects and test executables
#   make distclean   remove the whole build tree, including the fetched GoogleTest

BUILD_DIR  ?= build
BUILD_TYPE ?= Debug
JOBS       ?= $(shell getconf _NPROCESSORS_ONLN 2>/dev/null || echo 2)

.PHONY: all configure build test clean distclean

all: build

configure:
	cmake -S . -B "$(BUILD_DIR)" -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)

build: configure
	cmake --build "$(BUILD_DIR)" --parallel $(JOBS)

test: build
	ctest --test-dir "$(BUILD_DIR)" --output-on-failure --parallel $(JOBS)

clean:
	@if [ -d "$(BUILD_DIR)" ]; then cmake --build "$(BUILD_DIR)" --target clean; fi

distclean:
	rm -rf "$(BUILD_DIR)"
