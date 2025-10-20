/**
 * @file quick_sort.h The quick sort implementation in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
 */

#ifndef YH_ALGO_SORT_QUICK_SORT_H
#define YH_ALGO_SORT_QUICK_SORT_H

#ifdef ARDUINO
#include <stddef.h>
#else
#include <cstddef>
#endif

namespace yh {
    namespace algo {
        namespace sort {
            namespace _quick_sort {
                template<typename T>
                inline void swap(T &lhs, T &rhs) {
                    T temp = lhs; // copy lhs to temp
                    lhs = rhs; // move rhs to lhs
                    rhs = temp; // move temp to rhs
                }
            }
            /**
             * @brief Sorts an array with quick sort.
             * @param T The type of elements to be sorted.
             * @param elements The array of elements to be sorted.  This same array will be sorted after this function returns.
             * @param start The index of the first element to be sorted.
             * @param end The index of the first element not to be sorted after <code>start</code>.
             */
            template<typename T>
            inline void quick_sort(T *const elements, const size_t start, const size_t end) {
                if (start + 1 >= end) {
                    return;
                }

                // set the last element as pivot
                T *const pivot = elements + end - 1;


                T *i = elements;
                T *j = elements - 1;

                while (i < pivot) {
                    if ((*i) < (*pivot)) {
                        ++j;
                        _quick_sort::swap<T>(*i, *j);
                    }
                    ++i;
                }
                
                // put the pivot to the middle of the partition
                ++j;
                _quick_sort::swap<T>(*pivot, *j);

                // j now points to the pivot
                // sort the remaining partitions
                const size_t j_position = (size_t)(j - elements);
                quick_sort(elements, start, j_position);
                quick_sort(elements, j_position + 1, end);
            }

        }
    }
}

#endif // #ifndef YH_ALGO_SORT_QUICK_SORT_H