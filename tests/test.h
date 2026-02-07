#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
#include <sstream>

#include "mem_leak.h"

namespace testing_framework {

struct testcase_result_t {
    bool passed;
    size_t line;
    std::string reason;

    static const bool DEFAULT_PASSED_STATE = true;
    static const size_t DEFAULT_LINE = 0;
    static const char *const DEFAULT_REASON;

    testcase_result_t() :
        passed(DEFAULT_PASSED_STATE),
        line(DEFAULT_LINE),
        reason(DEFAULT_REASON) {}
};
const char *const testcase_result_t::DEFAULT_REASON = "no reason provided";

typedef void (*testfunc_t)(testcase_result_t &, std::stringstream &);

namespace {
static size_t testcase_number = 1;
static size_t failed_testcase_count = 0;
}

void test(testfunc_t func) {
    testcase_result_t result;
    result.reason.reserve(2048); // avoid malloc resizing when a long reason is provided
    std::stringstream reasonstream;
    tests::mem_leak::reset_malloc_count();
    func(result, reasonstream);
    const size_t malloc_count = tests::mem_leak::get_malloc_count();
    const bool is_memory_leaked = tests::mem_leak::has_memory_leaked();
    {
        // reasonstream handling
        const std::string reasonstr = reasonstream.str();
        if (
            !result.passed &&
            (result.reason == testing_framework::testcase_result_t::DEFAULT_REASON) &&
            !reasonstr.empty()
        ) {
            result.reason = reasonstr;
        }
    }
    std::stringstream sstream;
    sstream << "Testcase #" << testcase_number << " at line " << result.line << ": ";
    if (is_memory_leaked) {
        std::stringstream reasonstream;
        reasonstream << "Memory leak! You forgot " << malloc_count << " delete(s).";
        const std::string reasonstring = reasonstream.str();
        if (result.passed) {
            result.passed = false;
            result.reason = reasonstring;
        } else {
            result.reason += "; " + reasonstring;
        }
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

}

using testing_framework::testfunc_t;

// should be defined in test*.cpp
extern const testing_framework::testfunc_t functions [];

#define TEST_BEGIN(testcase_name) \
void test_##testcase_name(testing_framework::testcase_result_t &result, std::stringstream &reasonstream) { \
    result.line = __LINE__;

#define TEST_END() \
}


#define ASSERT_EQUALS(x,y) \
    if (!((x) == (y))) { \
        result.passed = false; \
        reasonstream << #x << " = " << (x) << " should be, but doesn\'t equal to " << #y << " = " << (y) << "."; \
    }

#define _ASSERT_FLOATING_POINT_EQUALS(x,y,tolerance,type_t) \
    { \
        const type_t eval_x = (x); \
        const type_t eval_y = (y); \
        type_t delta = (eval_x - eval_y); \
        if (delta < 0) { \
            delta = -delta; \
        } \
        const type_t abstolerance = (tolerance > 0) ? tolerance : -tolerance; \
        if (delta > abstolerance) { \
            result.passed = false; \
            reasonstream << #x << " = " << eval_x << " should be, but doesn\'t equal to " << #y << " = " << eval_y << "."; \
        } \
    }

#define ASSERT_FLOAT_EQUALS(x,y,tolerance) \
    _ASSERT_FLOATING_POINT_EQUALS(x,y,tolerance,float)

#define ASSERT_DOUBLE_EQUALS(x,y,tolerance) \
    _ASSERT_FLOATING_POINT_EQUALS(x,y,tolerance,double)

#define ASSERT_CSTR_EQUALS(x,y) \
    if (std::strcmp((x), (y)) != 0) { \
        result.passed = false; \
        reasonstream << #x << " = " << (x) << " should be, but doesn\'t equal to " << #y << " = " << (y) << "."; \
    }

#define ASSERT_NOT_EQUALS(x,y) \
    if (!((x) != (y))) { \
        result.passed = false; \
        reasonstream << #x << " = " << (x) << " should not, but equals to " << #y << " = " << (y) << "."; \
    }

#define ASSERT_TRUE(x) \
    if (!(x)) { \
        result.passed = false; \
        reasonstream << #x << " should be true, but is false."; \
    }

#define ASSERT_FALSE(x) \
    if (x) { \
        result.passed = false; \
        reasonstream << #x << " should be false, but is true."; \
    }

#define ASSERT_IS_NULLPTR(x) { \
        void *const ptr = (x); \
        if ((ptr) != nullptr) { \
            result.passed = false; \
            reasonstream << #x << " should be nullptr, but is " << ptr << "."; \
        } \
    }

#define ASSERT_IS_NOT_NULLPTR(x) \
    if ((x) == nullptr) { \
        result.passed = false; \
        reasonstream << #x << " should not be nullptr, but is nullptr."; \
    }


#define ALL_TESTS_BEGIN() \
    std::cout << "Testing " << __BASE_FILE__ << std::endl;

#define TEST_ALL() \
    for (const testfunc_t func : functions) { \
        test(func); \
    }

#define ALL_TESTS_END() \
    const size_t failed_testcase_count = \
        testing_framework::get_failed_testcase_count(); \
    if (failed_testcase_count == 0) { \
        std::cout << "All passed: " << __BASE_FILE__ << std::endl; \
    } else { \
        std::cout << failed_testcase_count << " failed: " << __BASE_FILE__ << std::endl; \
    } \
    return failed_testcase_count;

#define MAIN() int main() { \
    ALL_TESTS_BEGIN() \
    TEST_ALL() \
    ALL_TESTS_END() \
}

#endif // #ifndef TEST_H