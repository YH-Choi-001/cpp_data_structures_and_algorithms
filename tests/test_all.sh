# compile every test*.cpp file individually into test*.cpp.out file
find ./ -name "test*.cpp" -exec g++ {} -o {}.out 2> /dev/null \; -exec {}.out \; -exec rm {}.out \; | grep -E "(All passed|failed)"