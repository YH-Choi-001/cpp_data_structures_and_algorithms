/**
 * @file DoublyLinkedList.h The doubly linked list implementation in C++.
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

#ifndef YH_STRUCTURES_LISTS_DOUBLYLINKEDLIST_H
#define YH_STRUCTURES_LISTS_DOUBLYLINKEDLIST_H

#include "List.h"

namespace yh {
    namespace structures {
        namespace lists {
            /**
             * @brief A list implemented by doubly-linked nodes.
             * @param T The data type to be held by the list.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class DoublyLinkedList : public yh::structures::lists::List<T> {
                private:
                    /**
                     * @brief A doubly-linked node.
                     * @param T The data type to be held by the node.
                     */
                    struct Node {
                        /**
                         * @brief The data pointed by this node.
                         */
                        T *data;

                        /**
                         * @brief The previous node.
                         */
                        Node *prev;

                        /**
                         * @brief The next node.
                         */
                        Node *next;

                        /**
                         * @brief Creates a new node with data.
                         * @param initData The data to be pointed by this node.
                         */
                        Node(T *const initData) : data(initData), prev(nullptr), next(nullptr) {}

                        /**
                         * @brief Creates a new node with data and the next node.
                         * @param initData The data to be pointed by this node.
                         * @param initPrev The node before this node.
                         * @param initNext The node after this node.
                         */
                        Node(T *const initData, Node *initPrev, Node *initNext) : data(initData), prev(initPrev), next(initNext) {}
                    };

                    /**
                     * @brief The first node in this list.
                     */
                    Node *head;

                    /**
                     * @brief The last node in this list.
                     */
                    Node *tail;

                    /**
                     * @brief The number of elements stored in this list.
                     */
                    size_t elementsCount;

                    /**
                     * @brief Gets the node at a specific index.
                     * @param index The index of the node requested [0, elementsCount).
                     * @return The node requested.
                     */
                    Node *getNode(const size_t index) {
                        Node *node;

                        if (index <= elementsCount / 2) {
                            // search from the head
                            node = head;
                            for (size_t i = 0; i < index; i++) {
                                node = node->next;
                            }
                        } else {
                            // search from the tail
                            node = tail;
                            for (size_t i = elementsCount - 1; i > index; i--) {
                                node = node->prev;
                            }
                        }

                        return node;
                    }

                    /**
                     * @brief Sets the data of a specific node.
                     * @param node The node whose data to be set.
                     * @param data The new data to be assigned to the node.
                     * @return The old data previously stored in the node.
                     */
                    T *setNodeData(Node *const node, T *const data) {
                        T *const prevData = node->data;
                        node->data = data;
                        return prevData;
                    }
                public:
                    /**
                     * @brief Creates an empty doubly linked list.
                     */
                    DoublyLinkedList() : head(nullptr), tail(nullptr), elementsCount(0) {}

                    /**
                     * @brief Destroys the singly linked list.
                     */
                    virtual ~DoublyLinkedList() {
                        Node *node = head;
                        while (node != nullptr) {
                            Node *const thisNode = node;
                            node = node->next;
                            delete thisNode;
                        }
                    }

                    /**
                     * @brief Gets the number of elements in the list.
                     * @return The number of elements in the list.
                     */
                    virtual size_t size() override {
                        return elementsCount;
                    }

                    /**
                     * After insertion, the inserted element is accessible at the specific index,
                     * while all elements at or after the specific index before insertion
                     * are moved backwards by 1 unit.
                     * @brief Inserts an element at a specific index.
                     * @param index The index where the element is to be inserted [ 0 : size() ].
                     * @param element The element to be inserted.
                     */
                    virtual void insert(const size_t index, T *element) override {
                        if (index > elementsCount) {
                            return;
                        } else if (index == 0) {
                            addHead(element);
                            return;
                        } else if (index == elementsCount) {
                            addTail(element);
                            return;
                        }

                        Node *const newNode = new Node(element);

                        Node *const nextNode = (index == elementsCount) ? nullptr : getNode(index);
                        Node *const prevNode = (nextNode != nullptr) ? nextNode->prev : tail;
                        if (prevNode != nullptr) {
                            prevNode->next = newNode;
                        }
                        if (nextNode != nullptr) {
                            nextNode->prev = newNode;
                        }
                        newNode->prev = prevNode;
                        newNode->next = nextNode;

                        elementsCount++;
                    }

                    /**
                     * @brief Gets an element at a specific index.
                     * @param index The index of the requested element [ 0 : size() ).
                     * @return The requested element, or nullptr if index is invalid.
                     */
                    virtual T *get(const size_t index) override {
                        if (index >= elementsCount) {
                            return nullptr;
                        } else if (index == 0) {
                            return getHead();
                        } else if (index == elementsCount - 1) {
                            return getTail();
                        }

                        return getNode(index)->data;
                    }

                    /**
                     * @brief Sets an element at a specific index.
                     * @param index The index to place the new element [ 0 : size() ).
                     * @param element The new element to be placed at the index.
                     * @return The element that is previously at the index, or nullptr if index is invalid.
                     */
                    virtual T *set(const size_t index, T *element) override {
                        if (index >= elementsCount) {
                            return nullptr;
                        } else if (index == 0) {
                            return setHead(element);
                        } else if (index == elementsCount - 1) {
                            return setTail(element);
                        }

                        Node *const node = getNode(index);
                        return setNodeData(node, element);
                    }

                    /**
                     * @brief Removes an element from a specific index.
                     * @param index The index of the element to be removed [ 0 : size() ).
                     * @return The element removed, or nullptr if index is invalid.
                     */
                    virtual T *remove(const size_t index) override {
                        if (index >= elementsCount) {
                            return nullptr;
                        } else if (index == 0) {
                            return removeHead();
                        } else if (index == elementsCount - 1) {
                            return removeTail();
                        }

                        elementsCount--;

                        Node *const node = getNode(index);
                        Node *const prevNode = node->prev;
                        Node *const nextNode = node->next;

                        if (prevNode != nullptr) {
                            prevNode->next = nextNode;
                        }
                        if (nextNode != nullptr) {
                            nextNode->prev = prevNode;
                        }

                        T *const data = node->data;
                        delete node;
                        return data;
                    }

                    /**
                     * Equivalent to <code>insert(0, element)</code>.
                     * @brief Adds an element to the head of the list.
                     * @param element The element to be added.
                     * @see insert()
                     */
                    virtual void addHead(T *element) override {
                        Node *const newNode = new Node(element, nullptr, head);
                        if (elementsCount == 0) {
                            tail = newNode;
                        } else {
                            head->prev = newNode;
                        }
                        head = newNode;
                        elementsCount++;
                    }

                    /**
                     * Equivalent to <code>insert(size(), element)</code>.
                     * @brief Adds an element to the tail of the list.
                     * @param element The element to be added.
                     * @see insert()
                     */
                    virtual void addTail(T *element) override {
                        Node *const newNode = new Node(element, tail, nullptr);
                        if (elementsCount == 0) {
                            head = newNode;
                        } else {
                            tail->next = newNode;
                        }
                        tail = newNode;
                        elementsCount++;
                    }

                    /**
                     * Equivalent to <code>get(0)</code>.
                     * @brief Gets the element at the head of the list.
                     * @return The element at the head of the list, or nullptr if the list is empty.
                     * @see get()
                     */
                    virtual T *getHead() override {
                        return (elementsCount != 0) ? head->data : nullptr;
                    }

                    /**
                     * Equivalent to <code>get(size() - 1)</code>.
                     * @brief Gets the element at the tail of the list.
                     * @return The element at the tail of the list, or nullptr if the list is empty.
                     * @see get()
                     */
                    virtual T *getTail() override {
                        return (elementsCount != 0) ? tail->data : nullptr;
                    }

                    /**
                     * Equivalent to <code>set(0, element)</code>.
                     * @brief Sets the element at the head of the list.
                     * @param element The new element to be placed at the head of the list.
                     * @return The element that is previously at the head of the list, or nullptr if the list is empty.
                     * @see set()
                     */
                    virtual T *setHead(T *element) override {
                        if (elementsCount == 0) {
                            return nullptr;
                        }
                        return setNodeData(head, element);
                    }

                    /**
                     * Equivalent to <code>set(size() - 1, element)</code>.
                     * @brief Sets the element at the tail of the list.
                     * @param element The new element to be placed at the tail of the list.
                     * @return The element that is previously at the tail of the list, or nullptr if the list is empty.
                     * @see set()
                     */
                    virtual T *setTail(T *element) override {
                        if (elementsCount == 0) {
                            return nullptr;
                        }
                        return setNodeData(tail, element);
                    }

                    /**
                     * Equivalent to <code>remove(0, element)</code>.
                     * @brief Removes the element at the head of the list.
                     * @return The element that is previously at the head of the list, or nullptr if the list is empty.
                     * @see remove()
                     */
                    virtual T *removeHead() override {
                        if (elementsCount == 0) {
                            return nullptr;
                        }
                        elementsCount--;
                        Node *const removedHead = head;
                        Node *const newHead = head->next;
                        if (elementsCount == 0) {
                            tail = nullptr;
                        } else {
                            newHead->prev = nullptr;
                        }
                        head = newHead;
                        T *const data = removedHead->data;
                        delete removedHead;
                        return data;
                    }

                    /**
                     * Equivalent to <code>remove(size() - 1, element)</code>.
                     * @brief Removes the element at the tail of the list.
                     * @return The element that is previously at the tail of the list, or nullptr if the list is empty.
                     * @see remove()
                     */
                    virtual T *removeTail() override {
                        if (elementsCount == 0) {
                            return nullptr;
                        }
                        elementsCount--;
                        Node *const removedTail = tail;
                        Node *const newTail = tail->prev;
                        if (elementsCount == 0) {
                            head = nullptr;
                        } else {
                            newTail->next = nullptr;
                        }
                        tail = newTail;
                        T *const data = removedTail->data;
                        delete removedTail;
                        return data;
                    }

                    /**
                     * @brief Processes each element with a function.
                     * @param func The function to process the elements. param: T* Pointer to the element.
                     * @note Do not add or remove elements in the list within the given function.
                     */
                    virtual void foreach(void (*func)(T *)) override {
                        if (func == nullptr) {
                            return;
                        }
                        Node *node = head;
                        while (node != nullptr) {
                            func(node->data);
                            node = node->next;
                        }
                    }

                    /**
                     * @brief Processes each element with a predicate function.
                     * @param func The function to process the elements. param: T* Pointer to the element. return: True to remove the element.
                     * @note Do not add or remove elements in the list within the given function.
                     */
                    virtual void removeIf(bool (*func)(T *)) override {
                        if (func == nullptr) {
                            return;
                        }
                        Node *node = head;
                        while (node != nullptr) {
                            const bool needToRemove = func(node->data);
                            if (needToRemove) {
                                elementsCount--;

                                Node *const prevNode = node->prev;
                                Node *const nextNode = node->next;
                                if (node == head) {
                                    head = nextNode;
                                }
                                if (node == tail) {
                                    tail = prevNode;
                                }
                                if (prevNode != nullptr) {
                                    prevNode->next = nextNode;
                                }
                                if (nextNode != nullptr) {
                                    nextNode->prev = prevNode;
                                }
                                delete node;
                                node = nextNode;
                            } else {
                                node = node->next;
                            }
                        }
                    }
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_LISTS_DOUBLYLINKEDLIST_H