#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
#include <sstream>

#include "mem_leak.h"

struct testcase_result_t {
    bool passed;
    int line;
    std::string reason;
};

typedef testcase_result_t (*testfunc_t)();

static size_t testcase_number = 1;
static size_t failed_testcase_count = 0;

void test(testfunc_t func) {
    testcase_result_t result;
    reset_malloc_count();
    result = func();
    const bool is_memory_leaked = has_memory_leaked();
    std::stringstream sstream;
    sstream << "Testcase #" << testcase_number << " at line " << result.line << ": ";
    if (is_memory_leaked) {
        result.passed = false;
        result.reason += "; !!! MEMORY LEAK !!!";
    }
    if (result.passed) {
        sstream << "passed.";
    } else {
        sstream << "failed: " << result.reason;
        failed_testcase_count++;
    }
    std::cout << sstream.str() << std::endl;
    testcase_number++;
}

size_t get_failed_testcase_count() {
    return failed_testcase_count;
}

#define TEST_BEGIN(testcase_name) \
testcase_result_t test_##testcase_name() { \
    testcase_result_t result {false, __LINE__, "no reason provided"};

#define TEST_END() \
    return result; \
}

#endif // #ifndef TEST_H