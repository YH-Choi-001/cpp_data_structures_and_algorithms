/**
 * @file heap_sort.h The heap sort implementation in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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