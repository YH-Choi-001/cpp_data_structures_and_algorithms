/**
 * @file LinkedQueue.h The linked queue implementation in C++.
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

#ifndef YH_STRUCTURES_QUEUES_LINKEDQUEUE_H
#define YH_STRUCTURES_QUEUES_LINKEDQUEUE_H

#include "Queue.h"

namespace yh {
    namespace structures {
        namespace queues {
            /**
             * @brief A queue implemented by singly-linked list.
             * @param T The data type to be held by the queue.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class LinkedQueue : public yh::structures::queues::Queue<T> {
                private:
                    /**
                     * @brief The node in a linked queue.
                     */
                    struct Node {
                        T *const data;
                        Node *next;
                        Node(T *const data) : data(data), next(nullptr) {}
                    };

                    /**
                     * @brief The node at the head of the queue.
                     */
                    Node *head;

                    /**
                     * @brief The node at the tail of the queue.
                     */
                    Node *tail;

                    /**
                     * @brief The number of nodes.
                     */
                    size_t nodeCount;

                public:
                    /**
                     * @brief Creates an empty linked queue.
                     */
                    LinkedQueue() :head(nullptr), tail(nullptr), nodeCount(0) {
                        //
                    }

                    /**
                     * @brief Destroys the linked queue.
                     * @warning Only the internal linking nodes are deleted. The data themselves will not be deleted. It is user's responsibility to delete the data.
                     */
                    virtual ~LinkedQueue() override {
                        while (nodeCount > 0) {
                            dequeue();
                        }
                    }

                    virtual void enqueue(T *const data) override {
                        Node *const newNode = new Node(data);
                        if (tail != nullptr) {
                            tail->next = newNode;
                        }
                        tail = newNode;
                        if (head == nullptr) {
                            head = newNode;
                        }
                        ++nodeCount;
                    }

                    virtual T *dequeue() override {
                        if (head == nullptr) {
                            return nullptr;
                        }
                        T *const data = head->data;
                        Node *const removedNode = head;
                        head = head->next;
                        delete removedNode;
                        --nodeCount;
                        if (head == nullptr) {
                            tail = nullptr;
                        }
                        return data;
                    }

                    virtual T *peek() override {
                        if (head == nullptr) {
                            return nullptr;
                        }
                        return head->data;
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

#endif // #ifndef YH_STRUCTURES_QUEUES_LINKEDQUEUE_H