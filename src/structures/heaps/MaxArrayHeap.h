/**
 * @file MaxArrayHeap.h The maximum array heap implementation in C++.
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

#ifndef YH_STRUCTURES_HEAPS_MAXARRAYHEAP_H
#define YH_STRUCTURES_HEAPS_MAXARRAYHEAP_H

#include "ArrayHeap.h"

namespace yh {
    namespace structures {
        namespace heaps {
            /**
             * @brief A maximum heap implemented by an array.
             * @param T The data type to be held by the heap.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class MaxArrayHeap : public yh::structures::heaps::ArrayHeap<T> {
                protected:
                    virtual bool isAcceptable(T *const parent, T *const child) override {
                        return !((*child) > (*parent)); // (*parent) >= (*child);
                    }

                public:
                    /**
                     * @brief Creates an empty maximum array heap with a fixed capacity.
                     * @param capacity The fixed capacity of this heap.
                     */
                    MaxArrayHeap(const size_t capacity) : ArrayHeap<T>(capacity) {
                    }

                    /**
                     * @brief Destroys the heap.
                     */
                    virtual ~MaxArrayHeap() override {
                        //
                    }

                    /**
                     * @brief Inserts an element to this heap.
                     * @param element The element to be inserted to this heap.
                     */
                    virtual void insert(T *element) override {
                        ArrayHeap<T>::insert(element);
                    }

                    /**
                     * @brief Gets the maximum element at the heap without removing it from the heap.
                     * @return The maximum element at the heap, or nullptr if heap is empty.
                     */
                    virtual T *peekMax() {
                        return ArrayHeap<T>::peekRoot();
                    }

                    /**
                     * @brief Removes the maximum element from this heap.
                     * @return The maximum element removed from this heap, or nullptr if heap is empty.
                     */
                    virtual T *removeMax() {
                        return ArrayHeap<T>::removeRoot();
                    }
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_HEAPS_MAXARRAYHEAP_H