# cpp-random-test
## About
This is a random test tool for competitive programming written in C++.

## Getting started
```
# Clone me
git clone https://github.com/okb-okb/cpp-random-test
cd cpp-random-test

# Run sample test
g++ --std c++17 random_test.cpp
./a.out
# Files ./random_test/input_0_1__1.txt and ./random_test/input_0_1__2.txt differ
# Files ./random_test/input_1_0__1.txt and ./random_test/input_1_0__2.txt differ
```

## How to use
### Change target C++ code
Change line 9 and 10 to your code.

### Change test file name
Change `std::string testfile` as you like(ex. line 101). You can also change suffix of output files by changing `std::string suffix_1` and `std::string suffix_2` in line 66 and 67.

### Change test case
Write `make_testfile()` in line 12 as you like.

### Change build command
Change `std::string compile_command_base` and `std::string run_command_base` in line 31 and 32.