#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>

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
    reset_malloc_count();
    std::cout << "Testcase #" << testcase_number;
    testcase_result_t result = func();
    std::cout << " at line " << result.line << ": ";
    if (has_memory_leaked()) {
        result.passed = false;
        result.reason += "; !!! MEMORY LEAK !!!";
    }
    if (result.passed) {
        std::cout << "passed.";
    } else {
        std::cout << "failed: " << result.reason;
        failed_testcase_count++;
    }
    std::cout << std::endl;
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