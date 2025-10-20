#include "../../../src/algo/sort/selection_sort.h"

#include <iostream>

using yh::algo::sort::selection_sort;

template<typename T>
bool check(T *const elements, const T *const results, const size_t len) {
    selection_sort(elements, 0, len);
    for (size_t i = 0; i < len; i++) {
        if (elements[i] != results[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Testing " << __FILE__ << std::endl;
    unsigned int failed_testcase_count = 0;
    size_t testcase_index = 0;

    #define ELEMENTS(...) \
        int elements [] = __VA_ARGS__;
    
    #define RESULTS(...) \
        const int results [] = __VA_ARGS__;
    
    #define CHECK(l) \
        const size_t len = l; \
        const bool passed = check<int>(elements, results, len); \
        std::cout << "Testcase #" << testcase_index; \
        if (passed) { \
            std::cout << " passed." << std::endl; \
        } else { \
            ++failed_testcase_count; \
            std::cout << " failed: "; \
            std::cout << "Expected: "; \
            for (size_t i = 0; i < len; i++) { \
                std::cout << results[i] << "\t"; \
            } \
            std::cout << "Returned: "; \
            for (size_t i = 0; i < len; i++) { \
                std::cout << elements[i] << "\t"; \
            } \
            std::cout << std::endl; \
        } \
        ++testcase_index; \

    {
        ELEMENTS({})
        RESULTS ({})
        CHECK   (0)
    }
    {
        ELEMENTS({0})
        RESULTS ({0})
        CHECK   (1)
    }
    {
        ELEMENTS({8})
        RESULTS ({8})
        CHECK   (1)
    }
    {
        ELEMENTS({-5})
        RESULTS ({-5})
        CHECK   (1)
    }
    {
        ELEMENTS({3, 8})
        RESULTS ({3, 8})
        CHECK   (2)
    }
    {
        ELEMENTS({8, 3})
        RESULTS ({3, 8})
        CHECK   (2)
    }
    {
        ELEMENTS({8, 8})
        RESULTS ({8, 8})
        CHECK   (2)
    }
    {
        ELEMENTS({-6, 2})
        RESULTS ({-6, 2})
        CHECK   (2)
    }
    {
        ELEMENTS({2, -6})
        RESULTS ({-6, 2})
        CHECK   (2)
    }
    {
        ELEMENTS({-8, -3})
        RESULTS ({-8, -3})
        CHECK   (2)
    }
    {
        ELEMENTS({-3, -8})
        RESULTS ({-8, -3})
        CHECK   (2)
    }
    {
        ELEMENTS({5, 8, -1})
        RESULTS ({-1, 5, 8})
        CHECK   (3)
    }
    {
        ELEMENTS({62, 15, 38, 41, 9, 28, 57})
        RESULTS ({9, 15, 28, 38, 41, 57, 62})
        CHECK   (7)
    }
    {
        ELEMENTS({62, 15, 38, 41, 9, 28, 57, 5})
        RESULTS ({5, 9, 15, 28, 38, 41, 57, 62})
        CHECK   (8)
    }
    if (failed_testcase_count == 0) {
        std::cout << "All passed: " << __FILE__ << std::endl;
    } else {
        std::cout << failed_testcase_count << " failed: " << __FILE__ << std::endl;
    }
    return failed_testcase_count;
}