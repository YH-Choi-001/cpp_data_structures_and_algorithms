/**
 * @file LinkedQueue.h The linked queue implementation in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
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