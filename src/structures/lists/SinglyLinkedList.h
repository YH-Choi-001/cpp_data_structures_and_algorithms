/**
 * @file SinglyLinkedList.h The singly linked list implementation in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
 */

#ifndef YH_STRUCTURES_LISTS_SINGLYLINKEDLIST_H
#define YH_STRUCTURES_LISTS_SINGLYLINKEDLIST_H

#include "List.h"

namespace yh {
    namespace structures {
        namespace lists {
            /**
             * @brief A list implemented by singly-linked nodes.
             * @param T The data type to be held by the list.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class SinglyLinkedList : public yh::structures::lists::List<T> {
                private:
                    /**
                     * @brief A singly-linked node.
                     * @param T The data type to be held by the node.
                     */
                    struct Node {
                        /**
                         * @brief The data pointed by this node.
                         */
                        T *data;

                        /**
                         * @brief The next node.
                         */
                        Node *next;

                        /**
                         * @brief Creates a new node with data.
                         * @param initData The data to be pointed by this node.
                         */
                        Node(T *const initData) : data(initData), next(nullptr) {}

                        /**
                         * @brief Creates a new node with data and the next node.
                         * @param initData The data to be pointed by this node.
                         * @param initNext The node after this node.
                         */
                        Node(T *const initData, Node *initNext) : data(initData), next(initNext) {}
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
                        Node *node = head;
                        for (size_t i = 0; i < index; i++) {
                            node = node->next;
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
                     * @brief Creates an empty singly linked list.
                     */
                    SinglyLinkedList() : head(nullptr), tail(nullptr), elementsCount(0) {}

                    /**
                     * @brief Destroys the singly linked list.
                     */
                    virtual ~SinglyLinkedList() {
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
                        elementsCount++;

                        Node *const prevNode = getNode(index - 1);

                        if (prevNode != nullptr) {
                            newNode->next = prevNode->next;
                            prevNode->next = newNode;
                        }
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

                        Node *const node = getNode(index);
                        return node->data;
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

                        Node *const prevNode = getNode(index - 1);
                        Node *const node = prevNode->next;

                        if (prevNode != nullptr) {
                            prevNode->next = node->next;
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
                        Node *const newNode = new Node(element, head);
                        if (elementsCount == 0) {
                            tail = newNode;
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
                        Node *const newNode = new Node(element);
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
                        T *const data = head->data;
                        Node *const removedHead = head;
                        if (elementsCount == 1) {
                            head = nullptr;
                            tail = nullptr;
                        } else {
                            head = head->next;
                        }
                        delete removedHead;
                        elementsCount--;
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
                        T *const data = tail->data;
                        Node *const removedTail = tail;
                        if (elementsCount == 1) {
                            head = nullptr;
                            tail = nullptr;
                        } else {
                            tail = getNode(elementsCount - 2);
                        }
                        delete removedTail;
                        elementsCount--;
                        return data;
                    }
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_LISTS_SINGLYLINKEDLIST_H