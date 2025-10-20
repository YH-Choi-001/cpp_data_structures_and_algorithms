/**
 * @file MinArrayHeap.h The minimum array heap implementation in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
 */

#ifndef YH_STRUCTURES_HEAPS_MINARRAYHEAP_H
#define YH_STRUCTURES_HEAPS_MINARRAYHEAP_H

#include "ArrayHeap.h"

namespace yh {
    namespace structures {
        namespace heaps {
            /**
             * @brief A minimum heap implemented by an array.
             * @param T The data type to be held by the heap.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class MinArrayHeap : public yh::structures::heaps::ArrayHeap<T> {
                protected:
                    virtual bool isAcceptable(T *const parent, T *const child) override {
                        return !((*child) < (*parent)); // (*parent) <= (*child);
                    }

                public:
                    /**
                     * @brief Creates an empty minimum array heap with a fixed capacity.
                     * @param capacity The fixed capacity of this heap.
                     */
                    MinArrayHeap(const size_t capacity) : ArrayHeap<T>(capacity) {
                    }

                    /**
                     * @brief Destroys the heap.
                     */
                    virtual ~MinArrayHeap() override {
                        //
                    }

                    /**
                     * @brief Inserts an element to this heap.
                     * @param element The element to be inserted to this heap.
                     */
                    virtual void insert(T *element) override {
                        ArrayHeap<T>::insert(element);
                    }

                    /**
                     * @brief Gets the minimum element at the heap without removing it from the heap.
                     * @return The minimum element at the heap, or nullptr if heap is empty.
                     */
                    virtual T *peekMin() {
                        return ArrayHeap<T>::peekRoot();
                    }

                    /**
                     * @brief Removes the minimum element from this heap.
                     * @return The minimum element removed from this heap, or nullptr if heap is empty.
                     */
                    virtual T *removeMin() {
                        return ArrayHeap<T>::removeRoot();
                    }
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_HEAPS_MINARRAYHEAP_H