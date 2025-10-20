/**
 * @file insertion_sort.h The insertion sort implementation in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
 */

#ifndef YH_ALGO_SORT_INSERTION_SORT_H
#define YH_ALGO_SORT_INSERTION_SORT_H

#ifdef ARDUINO
#include <stddef.h>
#else
#include <cstddef>
#endif

namespace yh {
    namespace algo {
        namespace sort {
            namespace _insertion_sort {
                template<typename T>
                inline void swap(T &lhs, T &rhs) {
                    T temp = lhs; // copy lhs to temp
                    lhs = rhs; // move rhs to lhs
                    rhs = temp; // move temp to rhs
                }
            }
            /**
             * @brief Sorts an array with insertion sort.
             * @param T The type of elements to be sorted.
             * @param elements The array of elements to be sorted.  This same array will be sorted after this function returns.
             * @param start The index of the first element to be sorted.
             * @param end The index of the first element not to be sorted after <code>start</code>.
             */
            template<typename T>
            inline void insertion_sort(T *const elements, const size_t start, const size_t end) {
                if (start + 1 >= end) {
                    return;
                }

                for (size_t i = start + 1; i < end; ++i) {
                    for (size_t j = i; (j > start) && (elements[j] < elements[j - 1]); --j) {
                        _insertion_sort::swap(elements[j], elements[j - 1]);
                    }
                }
            }
        }
    }
}

#endif // #ifndef YH_ALGO_SORT_INSERTION_SORT_H