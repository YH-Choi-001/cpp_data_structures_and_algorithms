/**
 * @file Heap.h The heap interface in C++.
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

#ifndef YH_STRUCTURES_HEAPS_HEAP_H
#define YH_STRUCTURES_HEAPS_HEAP_H

#ifdef ARDUINO
#include <stddef.h>
#else
#include <cstddef>
#endif

namespace yh {
    namespace structures {
        namespace heaps {
            /**
             * @brief The interface of a heap.
             * @param T The data type to be held by the heap.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class Heap {
                protected:
                    /**
                     * @brief Creates an empty heap.
                     */
                    Heap() {}

                    /**
                     * @brief Inserts an element.
                     * @param element The element to be inserted to the heap.
                     */
                    virtual void insert(T *element) = 0;

                    /**
                     * @brief Gets the root element at the heap without removing it from the heap.
                     * @return The root element at the heap, or nullptr if heap is empty.
                     */
                    virtual T *peekRoot() = 0;

                    /**
                     * @brief Removes the root element from the heap.
                     * @return The element removed from the root of the heap, or nullptr if heap is empty.
                     */
                    virtual T *removeRoot() = 0;

                public:
                    /**
                     * @brief Destroys the heap.
                     */
                    virtual ~Heap() {}

                    /**
                     * @brief Gets the number of elements in the heap.
                     * @return The number of elements in the heap.
                     */
                    virtual size_t size() = 0;

                    /**
                     * @brief Checks whether the heap is empty.
                     * @return true if the heap is empty, false otherwise.
                     */
                    virtual bool isEmpty() {
                        return size() == 0;
                    }

                    /**
                     * @brief Checks whether the heap has used up all of its capacity.
                     * @return true if the heap is full, false otherwise.
                     */
                    virtual bool isFull() = 0;
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_HEAPS_HEAP_H