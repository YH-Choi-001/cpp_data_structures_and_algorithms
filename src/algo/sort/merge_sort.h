/**
 * @file merge_sort.h The merge sort implementation in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
 */

#ifndef YH_ALGO_SORT_MERGE_SORT_H
#define YH_ALGO_SORT_MERGE_SORT_H

#ifdef ARDUINO
#include <stddef.h>
#else
#include <cstddef>
#endif

namespace yh {
    namespace algo {
        namespace sort {
            /**
             * @brief Sorts an array with merge sort.
             * @param T The type of elements to be sorted.
             * @param elements The array of elements to be sorted.  This same array will be sorted after this function returns.
             * @param start The index of the first element to be sorted.
             * @param end The index of the first element not to be sorted after <code>start</code>.
             */
            template<typename T>
            inline void merge_sort(T *const elements, const size_t start, const size_t end) {
                if (start + 1 >= end) {
                    return;
                }

                // sort the 2 halves separately
                const size_t mid = (start + end) / 2;
                merge_sort(elements, start, mid);
                merge_sort(elements, mid, end);

                T sorted[end - start];
                T *sorted_ptr = sorted;
                const T *lhs_ptr = elements + start;
                const T *rhs_ptr = elements + mid;
                const T *const lhs_end = rhs_ptr; // elements + mid
                const T *const rhs_end = elements + end;

                // merge the 2 sorted arrays
                while (lhs_ptr < lhs_end && rhs_ptr < rhs_end) {
                    const T lhs = *lhs_ptr;
                    const T rhs = *rhs_ptr;
                    if (!(rhs < lhs)) { // lhs <= rhs
                        (*sorted_ptr) = lhs;
                        ++lhs_ptr;
                    } else {
                        (*sorted_ptr) = rhs;
                        ++rhs_ptr;
                    }
                    ++sorted_ptr;
                }

                // copy the remaining elements from lhs
                while (lhs_ptr < lhs_end) {
                    (*sorted_ptr) = (*lhs_ptr);
                    ++lhs_ptr;
                    ++sorted_ptr;
                }

                // copy the remaining elements from rhs
                while (rhs_ptr < rhs_end) {
                    (*sorted_ptr) = (*rhs_ptr);
                    ++rhs_ptr;
                    ++sorted_ptr;
                }

                // copy the sorted part from sorted[] back to elements[]
                sorted_ptr = sorted;
                T *elements_ptr = elements + start;
                while (elements_ptr < rhs_end) {
                    (*elements_ptr) = (*sorted_ptr);
                    ++elements_ptr;
                    ++sorted_ptr;
                }
            }
        }
    }
}

#endif // #ifndef YH_ALGO_SORT_MERGE_SORT_H