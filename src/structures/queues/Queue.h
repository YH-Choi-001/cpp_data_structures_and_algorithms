/**
 * @file Queue.h The queue interface in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
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
        namespace queues {
            /**
             * @brief The interface of a queue.
             * @param T The data type to be held by the queue.
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