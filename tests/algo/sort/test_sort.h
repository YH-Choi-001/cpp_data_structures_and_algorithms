#ifndef TEST_SORT_H
#define TEST_SORT_H

#include <cstddef>

unsigned int test() {
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
        ELEMENTS({-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34, 69, 38})
        RESULTS ({-98, -93, -81, -64, -60, -51, -15, -8, -5, 22, 30, 34, 38, 69, 76, 83, 97})
        CHECK   (17)
    }
    {
        ELEMENTS({-15, 30, -60, 76, 0, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34, 69, 38})
        RESULTS ({-98, -93, -81, -64, -60, -51, -15, -8, -5, 0, 22, 30, 34, 38, 69, 76, 83, 97})
        CHECK   (18)
    }
    {
        ELEMENTS({-15, 30, -60, 76, 0, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34, -89, 69, 38})
        RESULTS ({-98, -93, -89, -81, -64, -60, -51, -15, -8, -5, 0, 22, 30, 34, 38, 69, 76, 83, 97})
        CHECK   (19)
    }
    {
        ELEMENTS({-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72, 28, 23, 19, 58, -35})
        RESULTS ({-70, -68, -61, -53, -42, -41, -35, -27, -22, -3, 19, 19, 23, 28, 58, 72, 89, 96})
        CHECK   (18)
    }
    return failed_testcase_count;
}

#endif