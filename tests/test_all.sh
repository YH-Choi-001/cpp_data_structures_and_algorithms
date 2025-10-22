# compile every test*.cpp file individually into test*.cpp.out file
find ./ -name "test*.cpp" -exec g++ {} -o {}.out \; -exec {}.out \; -exec rm {}.out \;