#include "../../../src/algo/sort/quick_sort.h"

#include <iostream>

template<typename T>
bool check(T *const elements, const T *const results, const size_t len) {
    yh::algo::sort::quick_sort(elements, 0, len);
    for (size_t i = 0; i < len; i++) {
        if (elements[i] != results[i]) {
            return false;
        }
    }
    return true;
}

#include "test_sort.h"

int main() {
    std::cout << "Testing " << __FILE__ << std::endl;
    const unsigned int failed_testcase_count = test();
    if (failed_testcase_count == 0) {
        std::cout << "All passed: ";
    } else {
        std::cout << failed_testcase_count << " failed: ";
    }
    std::cout << __FILE__ << std::endl;
    return failed_testcase_count;
}