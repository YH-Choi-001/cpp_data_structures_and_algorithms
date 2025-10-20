/**
 * @file MaxArrayHeap.h The maximum array heap implementation in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
 */

#ifndef YH_STRUCTURES_HEAPS_MAXARRAYHEAP_H
#define YH_STRUCTURES_HEAPS_MAXARRAYHEAP_H

#include "ArrayHeap.h"

namespace yh {
    namespace structures {
        namespace heaps {
            /**
             * @brief A maximum heap implemented by an array.
             * @param T The data type to be held by the heap.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class MaxArrayHeap : public yh::structures::heaps::ArrayHeap<T> {
                protected:
                    virtual bool isAcceptable(T *const parent, T *const child) override {
                        return !((*child) > (*parent)); // (*parent) >= (*child);
                    }

                public:
                    /**
                     * @brief Creates an empty maximum array heap with a fixed capacity.
                     * @param capacity The fixed capacity of this heap.
                     */
                    MaxArrayHeap(const size_t capacity) : ArrayHeap<T>(capacity) {
                    }

                    /**
                     * @brief Destroys the heap.
                     */
                    virtual ~MaxArrayHeap() override {
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
                     * @brief Gets the maximum element at the heap without removing it from the heap.
                     * @return The maximum element at the heap, or nullptr if heap is empty.
                     */
                    virtual T *peekMax() {
                        return ArrayHeap<T>::peekRoot();
                    }

                    /**
                     * @brief Removes the maximum element from this heap.
                     * @return The maximum element removed from this heap, or nullptr if heap is empty.
                     */
                    virtual T *removeMax() {
                        return ArrayHeap<T>::removeRoot();
                    }
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_HEAPS_MAXARRAYHEAP_H