/**
 * @file LinkedStack.h The linked stack implementation in C++.
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

#ifndef YH_STRUCTURES_STACKS_LINKEDSTACK_H
#define YH_STRUCTURES_STACKS_LINKEDSTACK_H

#include "Stack.h"

namespace yh {
    namespace structures {
        namespace stacks {
            /**
             * @brief A stack implemented by singly-linked list.
             * @param T The data type to be held by the stack.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class LinkedStack : public yh::structures::stacks::Stack<T> {
                private:
                    /**
                     * @brief The node in a linked stack.
                     */
                    struct Node {
                        T *const data;
                        Node *const next;
                        Node(T *const data, Node *const next) : data(data), next(next) {}
                    };

                    /**
                     * @brief The node at the top of the stack.
                     */
                    Node *top;

                    /**
                     * @brief The number of nodes.
                     */
                    size_t nodeCount;

                public:
                    /**
                     * @brief Creates an empty linked stack.
                     */
                    LinkedStack() :top(nullptr), nodeCount(0) {
                        //
                    }

                    /**
                     * @brief Destroys the linked stack.
                     * @warning Only the internal linking nodes are deleted. The data themselves will not be deleted. It is user's responsibility to delete the data.
                     */
                    virtual ~LinkedStack() override {
                        while (nodeCount > 0) {
                            pop();
                        }
                    }

                    virtual void push(T *const data) override {
                        Node *const newNode = new Node(data, top);
                        top = newNode;
                        ++nodeCount;
                    }

                    virtual T *pop() override {
                        if (top == nullptr) {
                            return nullptr;
                        }
                        T *const data = top->data;
                        Node *const removedNode = top;
                        top = top->next;
                        delete removedNode;
                        --nodeCount;
                        return data;
                    }

                    virtual T *peek() override {
                        if (top == nullptr) {
                            return nullptr;
                        }
                        return top->data;
                    }

                    virtual size_t size() override {
                        return nodeCount;
                    }

                    virtual bool isFull() override {
                        return false;
                    }
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_STACKS_LINKEDSTACK_H