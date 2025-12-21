all: test

.compiled_tests:
	find ./ -name "test*.cpp" -exec g++ -std=c++11 {} -o {}.out \;
	mkdir -p .compiled_tests

compile: .compiled_tests

test: .compiled_tests
	find ./ -name "test*.cpp" -exec {}.out \; | grep -E "(All passed|failed)"

clean:
	find ./ -name "test*.cpp" -exec rm {}.out \;
	rm -rf .compiled_tests
