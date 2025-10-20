/**
 * @file Heap.h The heap interface in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
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