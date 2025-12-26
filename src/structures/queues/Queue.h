/**
 * @file Queue.h The queue interface in C++.
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

#ifndef YH_STRUCTURES_QUEUES_QUEUE_H
#define YH_STRUCTURES_QUEUES_QUEUE_H

#ifdef ARDUINO
#include <stddef.h>
#else
#include <cstddef>
#endif

namespace yh {
    namespace structures {
        /**
         * A queue is a special list,
         * where elements could only be appended to the tail,
         * and elements could only be visited and removed in the order they joined the list.
         * @brief Interfaces and implementations of queues.
         */
        namespace queues {
            /**
             * @brief The interface of a queue.
             * @param T The data type to be held by the queue.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class Queue {
                protected:
                    /**
                     * @brief Creates an empty queue.
                     */
                    Queue() {}

                public:
                    /**
                     * @brief Destroys the queue.
                     */
                    virtual ~Queue() {}

                    /**
                     * @brief Appends a data to the tail of the queue.
                     * @param data The data to be appended to the tail of the queue.
                     */
                    virtual void enqueue(T *const data) = 0;

                    /**
                     * @brief Removes a data from the head of the queue.
                     * @return The data to be removed from the head of the queue, or nullptr if the queue is empty.
                     */
                    virtual T *dequeue() = 0;

                    /**
                     * @brief Get the data at the head of the queue without removing it.
                     * @return The data at the head of the queue, or nullptr if the queue is empty.
                     */
                    virtual T *peek() = 0;

                    /**
                     * @brief Gets the number of elements in the queue.
                     * @return The number of elements in the queue.
                     */
                    virtual size_t size() = 0;

                    /**
                     * @brief Checks whether the queue is empty.
                     * @return true if the queue is empty, false otherwise.
                     */
                    virtual bool isEmpty() {
                        return size() == 0;
                    }

                    /**
                     * @brief Checks whether the queue has used up all of its capacity.
                     * @return true if the queue is full, false otherwise.
                     */
                    virtual bool isFull() = 0;
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_QUEUES_QUEUE_H