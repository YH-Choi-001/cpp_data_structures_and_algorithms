/**
 * @file QuickSort.h The quick sort implementation in C++.
 * 
 * @copyright Copyright (c) 2026 YH Choi. All rights reserved.
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

#ifndef YH_ALGO_SORT_QUICK_SORT_H
#define YH_ALGO_SORT_QUICK_SORT_H

#include "Sort.h"

namespace yh {
    namespace algo {
        template<typename T>
        class QuickSort : public Sort<T> {
            public:
                /**
                 * @brief Sorts an array with quick sort.
                 * @param T The type of elements to be sorted.
                 * @param elements The array of elements to be sorted.  This same array will be sorted after this function returns.
                 * @param start The index of the first element to be sorted.
                 * @param end The index of the first element not to be sorted after <code>start</code>.
                 */
                void sort(T *const elements, const size_t start, const size_t end) override {
                    if (start + 1 >= end) {
                        return;
                    }

                    // set the last element as pivot
                    T *const pivot = elements + end - 1;

                    size_t l = start - 1;
                    for (size_t r = start; r <= (end - 1); ++r) {
                        if (elements[r] < (*pivot) || r == (end - 1)) {
                            ++l;
                            this->swap(elements[l], elements[r]);
                        }
                    }

                    this->sort(elements, start, l);
                    this->sort(elements, l + 1, end);
                }
        };
    }
}

#endif // #ifndef YH_ALGO_SORT_QUICK_SORT_H