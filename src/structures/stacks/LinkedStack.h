/**
 * @file Stack.h The stack interface in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
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
                        Node(T *const data) : data(data), next(nullptr) {}
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