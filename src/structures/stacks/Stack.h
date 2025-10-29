/**
 * @file Stack.h The stack interface in C++.
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

#ifndef YH_STRUCTURES_STACKS_STACK_H
#define YH_STRUCTURES_STACKS_STACK_H

#ifdef ARDUINO
#include <stddef.h>
#else
#include <cstddef>
#endif

namespace yh {
    namespace structures {
        namespace stacks {
            /**
             * @brief The interface of a stack.
             * @param T The data type to be held by the stack.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class Stack {
                protected:
                    /**
                     * @brief Creates an empty stack.
                     */
                    Stack() {}

                public:
                    /**
                     * @brief Destroys the stack.
                     */
                    virtual ~Stack() {}

                    /**
                     * @brief Pushes a data to the top of the stack.
                     * @param data The data to be pushed to the top of the stack.
                     */
                    virtual void push(T *const data) = 0;

                    /**
                     * @brief Pops (removes) a data from the top of the stack.
                     * @return The data to be popped from the top of the stack, or nullptr if the stack is empty.
                     */
                    virtual T *pop() = 0;

                    /**
                     * @brief Get the data at the top of the stack without removing it.
                     * @return The data at the top of the stack, or nullptr if the stack is empty.
                     */
                    virtual T *peek() = 0;

                    /**
                     * @brief Gets the number of elements in the stack.
                     * @return The number of elements in the stack.
                     */
                    virtual size_t size() = 0;

                    /**
                     * @brief Checks whether the stack is empty.
                     * @return true if the stack is empty, false otherwise.
                     */
                    virtual bool isEmpty() {
                        return size() == 0;
                    }

                    /**
                     * @brief Checks whether the stack has used up all of its capacity.
                     * @return true if the stack is full, false otherwise.
                     */
                    virtual bool isFull() = 0;
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_STACKS_STACK_H