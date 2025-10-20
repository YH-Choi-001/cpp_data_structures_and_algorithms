/**
 * @file heap_sort.h The heap sort implementation in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
 */

#ifndef YH_ALGO_SORT_HEAP_SORT_H
#define YH_ALGO_SORT_HEAP_SORT_H

#ifdef ARDUINO
#include <stddef.h>
#else
#include <cstddef>
#endif

#include "../../structures/heaps/MinArrayHeap.h"

namespace yh {
    namespace algo {
        namespace sort {
            /**
             * @brief Sorts an array with heap sort.
             * @param T The type of elements to be sorted.
             * @param elements The array of elements to be sorted.  This same array will be sorted after this function returns.
             * @param start The index of the first element to be sorted.
             * @param end The index of the first element not to be sorted after <code>start</code>.
             */
            template<typename T>
            inline void heap_sort(T *const elements, const size_t start, const size_t end) {
                if (start + 1 >= end) {
                    return;
                }

                const size_t toSortLength = end - start;

                // create a buffer to hold the elements temporarily
                T *elementsBuffer = new T[toSortLength];
                for (size_t i = 0; i < toSortLength; ++i) {
                    elementsBuffer[i] = elements[start + i];
                }

                // create a min heap and insert elements from the buffer to the heap
                yh::structures::heaps::MinArrayHeap<T> heap(toSortLength);
                for (size_t i = 0; i < toSortLength; ++i) {
                    heap.insert(elementsBuffer + i);
                }

                // copy the minimum elements from the heap back to the original array
                for (size_t i = start; i < end; ++i) {
                    elements[i] = (*heap.removeMin());
                }

                delete[] elementsBuffer;
            }
        }
    }
}

#endif // #ifndef YH_ALGO_SORT_HEAP_SORT_H