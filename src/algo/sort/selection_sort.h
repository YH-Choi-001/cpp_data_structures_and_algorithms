/**
 * @file selection_sort.h The selection sort implementation in C++.
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

#ifndef YH_ALGO_SORT_SELECTION_SORT_H
#define YH_ALGO_SORT_SELECTION_SORT_H

#ifdef ARDUINO
#include <stddef.h>
#else
#include <cstddef>
#endif

namespace yh {
    namespace algo {
        namespace sort {
            namespace _selection_sort {
                template<typename T>
                inline void swap(T &lhs, T &rhs) {
                    T temp = lhs; // copy lhs to temp
                    lhs = rhs; // move rhs to lhs
                    rhs = temp; // move temp to rhs
                }
            }
            /**
             * @brief Sorts an array with selection sort.
             * @param T The type of elements to be sorted.
             * @param elements The array of elements to be sorted.  This same array will be sorted after this function returns.
             * @param start The index of the first element to be sorted.
             * @param end The index of the first element not to be sorted after <code>start</code>.
             */
            template<typename T>
            inline void selection_sort(T *const elements, const size_t start, const size_t end) {
                if (start + 1 >= end) {
                    return;
                }

                T *const end_ptr = elements + end;
                for (T *insert_ptr = elements + start; insert_ptr < end_ptr; ++insert_ptr) {
                    T *min_ptr = insert_ptr;
                    for (T *running_ptr = insert_ptr + 1; running_ptr < end_ptr; ++running_ptr) {
                        if ((*running_ptr) < (*min_ptr)) {
                            min_ptr = running_ptr;
                        }
                    }
                    _selection_sort::swap((*insert_ptr), (*min_ptr));
                }
            }
        }
    }
}

#endif // #ifndef YH_ALGO_SORT_SELECTION_SORT_H