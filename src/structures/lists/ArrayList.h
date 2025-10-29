/**
 * @file ArrayList.h The array list implementation in C++.
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

#ifndef YH_STRUCTURES_LISTS_ARRAYLIST_H
#define YH_STRUCTURES_LISTS_ARRAYLIST_H

#include "List.h"

namespace yh {
    namespace structures {
        namespace lists {
            /**
             * @brief A list implemented by an array.
             * @param T The data type to be held by the list.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class ArrayList : public yh::structures::lists::List<T> {
                private:
                    /**
                     * @brief The number of elements stored in this list.
                     */
                    size_t elementsCount;

                    /**
                     * @brief The maximum capacity of T* the array can hold.
                     */
                    size_t capacity;

                    /**
                     * @brief The array of T* that points to every element.
                     */
                    T **array;

                    /**
                     * @brief The default initial capacity.
                     */
                    static const size_t DEFAULT_INIT_CAPACITY = 16U;
                public:
                    /**
                     * @brief Creates an empty array list.
                     */
                    ArrayList() : elementsCount(0), capacity(DEFAULT_INIT_CAPACITY), array(new T* [capacity]) {}

                    /**
                     * @brief Destroys the array list.
                     */
                    virtual ~ArrayList() {
                        delete[] array;
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
                        }

                        if (elementsCount >= capacity) {
                            // boost capacity
                            const size_t newCapacity = capacity * 2;
                            // create a new array
                            T **const newArray = new T* [newCapacity];
                            // copy all elements to the left of index to the new array
                            for (size_t i = 0; i < index; i++) {
                                newArray[i] = array[i];
                            }
                            // copy all elements to the right of index to the new array
                            for (size_t i = elementsCount; i > index; i--) {
                                newArray[i] = array[i - 1];
                            }
                            // delete the old array
                            delete[] array;
                            // transfer the array details to the member variables
                            array = newArray;
                            capacity = newCapacity;
                        } else {
                            // move all elements to the right of index to the right by 1 unit
                            for (size_t i = elementsCount; i > index; i--) {
                                array[i] = array[i - 1];
                            }
                        }
                        array[index] = element;
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
                        }
                        return array[index];
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
                        }
                        T *const prevElement = array[index];
                        array[index] = element;
                        return prevElement;
                    }

                    /**
                     * @brief Removes an element from a specific index.
                     * @param index The index of the element to be removed [ 0 : size() ).
                     * @return The element removed, or nullptr if index is invalid.
                     */
                    virtual T *remove(const size_t index) override {
                        if (index >= elementsCount) {
                            return nullptr;
                        }

                        T *const toReturn = array[index];

                        elementsCount--;

                        if (elementsCount * 2 < capacity && elementsCount > DEFAULT_INIT_CAPACITY) {
                            // shrink capacity
                            const size_t newCapacity = capacity / 2;
                            // create a new array
                            T **const newArray = new T* [newCapacity];
                            // copy all elements to the left of index to the new array
                            for (size_t i = 0; i < index; i++) {
                                newArray[i] = array[i];
                            }
                            // copy all elements to the right of index to the new array
                            for (size_t i = index; i < elementsCount; i++) {
                                newArray[i] = array[i + 1];
                            }
                            // delete the old array
                            delete[] array;
                            // transfer the array details to the member variables
                            array = newArray;
                            capacity = newCapacity;
                        } else {
                            // move all elements to the right of index to the left by 1 unit
                            for (size_t i = index; i < elementsCount; i++) {
                                array[i] = array[i + 1];
                            }
                        }

                        return toReturn;
                    }
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_LISTS_ARRAYLIST_H