/**
 * @file ArrayHeap.h The array heap implementation in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
 */

#ifndef YH_STRUCTURES_HEAPS_ARRAYHEAP_H
#define YH_STRUCTURES_HEAPS_ARRAYHEAP_H

#include "Heap.h"

#include <iostream>

namespace yh {
    namespace structures {
        namespace heaps {
            /**
             * @brief A heap implemented by an array.
             * @param T The data type to be held by the heap.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class ArrayHeap : public yh::structures::heaps::Heap<T> {
                private:
                    T **const array;
                    const size_t capacity;
                    size_t elementCount;

                    void swap(size_t lhsIdx, size_t rhsIdx) {
                        T *const temp = array[lhsIdx];
                        array[lhsIdx] = array[rhsIdx];
                        array[rhsIdx] = temp;
                    }

                protected:
                    /**
                     * @brief Creates an empty array heap with a fixed capacity.
                     * @param capacity The fixed capacity of this heap.
                     */
                    ArrayHeap(const size_t capacity) : array(new T* [capacity + 1]), capacity(capacity), elementCount(0) {
                        array[0] = nullptr;
                    }

                    /**
                     * @brief Checks whether the parent-child relationship is acceptable in this heap.
                     * @return true if the parent-child relationship is acceptable false otherwise.
                     */
                    virtual bool isAcceptable(T *const parent, T *const child) = 0;

                    /**
                     * @brief Inserts an element to this heap.
                     * @param element The element to be inserted to this heap.
                     */
                    virtual void insert(T *element) override {
                        if (isFull()) {
                            return;
                        }

                        ++elementCount;

                        // append element to end of array
                        array[elementCount] = element;

                        // bubble up
                        size_t index = elementCount;
                        while ((index > 1) && !isAcceptable(array[index / 2], array[index])) {
                            swap(index / 2, index);
                            index /= 2;
                        }
                    }

                    /**
                     * @brief Gets the root element at the heap without removing it from the heap.
                     * @return The root element at the heap, or nullptr if heap is empty.
                     */
                    virtual T *peekRoot() override {
                        if (Heap<T>::isEmpty()) {
                            return nullptr;
                        }

                        return array[1];
                    }

                    /**
                     * @brief Removes the root element from this heap.
                     * @return The root element removed from this heap, or nullptr if heap is empty.
                     */
                    virtual T *removeRoot() override {
                        if (Heap<T>::isEmpty()) {
                            return nullptr;
                        }

                        T *const element = array[1];

                        // place last element to root position
                        array[1] = array[elementCount];
                        array[elementCount] = nullptr;

                        // bubble down
                        size_t index = 1;
                        while (index * 2 < elementCount) {
                            const size_t leftChildIndex = index * 2;
                            const size_t rightChildIndex = leftChildIndex + 1;
                            const size_t potentialParentIndex =
                                (rightChildIndex < elementCount) && 
                                !isAcceptable(array[leftChildIndex], array[rightChildIndex]) ? rightChildIndex : leftChildIndex;
                            if (!isAcceptable(array[index], array[potentialParentIndex])) {
                                swap(index, potentialParentIndex);
                                index = potentialParentIndex;
                            } else {
                                break;
                            }
                        }

                        --elementCount;

                        return element;
                    }

                public:
                    /**
                     * @brief Destroys the heap.
                     */
                    virtual ~ArrayHeap() override {
                        if (array != nullptr) {
                            delete[] array;
                        }
                    }

                    virtual size_t size() override {
                        return elementCount;
                    }

                    virtual bool isFull() override {
                        return elementCount >= capacity;
                    }
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_HEAPS_ARRAYHEAP_H