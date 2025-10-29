/**
 * @file List.h The list interface in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
 */

#ifndef YH_STRUCTURES_LISTS_LIST_H
#define YH_STRUCTURES_LISTS_LIST_H

#ifdef ARDUINO
#include <stddef.h>
#else
#include <cstddef>
#endif

namespace yh {
    namespace structures {
        namespace lists {
            /**
             * @brief The interface of a list.
             * @param T The data type to be held by the list.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename T>
            class List {
                protected:
                    /**
                     * @brief Creates an empty list.
                     */
                    List() {}

                public:
                    /**
                     * @brief Destroys the list.
                     */
                    virtual ~List() {}

                    /**
                     * @brief Gets the number of elements in the list.
                     * @return The number of elements in the list.
                     */
                    virtual size_t size() = 0;

                    /**
                     * @brief Checks whether the list is empty.
                     * @return true if the list is empty, false otherwise.
                     */
                    virtual bool isEmpty() {
                        return size() == 0;
                    }

                    /**
                     * After insertion, the inserted element is accessible at the specific index,
                     * while all elements at or after the specific index before insertion
                     * are moved backwards by 1 unit.
                     * @brief Inserts an element at a specific index.
                     * @param index The index where the element is to be inserted [ 0 : size() ].
                     * @param element The element to be inserted.
                     */
                    virtual void insert(const size_t index, T *element) = 0;

                    /**
                     * @brief Gets an element at a specific index.
                     * @param index The index of the requested element [ 0 : size() ).
                     * @return The requested element, or nullptr if index is invalid.
                     */
                    virtual T *get(const size_t index) = 0;

                    /**
                     * @brief Sets an element at a specific index.
                     * @param index The index to place the new element [ 0 : size() ).
                     * @param element The new element to be placed at the index.
                     * @return The element that is previously at the index, or nullptr if index is invalid.
                     */
                    virtual T *set(const size_t index, T *element) = 0;

                    /**
                     * @brief Removes an element from a specific index.
                     * @param index The index of the element to be removed [ 0 : size() ).
                     * @return The element removed, or nullptr if index is invalid.
                     */
                    virtual T *remove(const size_t index) = 0;

                    /**
                     * Equivalent to <code>insert(0, element)</code>.
                     * @brief Adds an element to the head of the list.
                     * @param element The element to be added.
                     * @see insert()
                     */
                    virtual void addHead(T *element) {
                        insert(0, element);
                    }

                    /**
                     * Equivalent to <code>insert(size(), element)</code>.
                     * @brief Adds an element to the tail of the list.
                     * @param element The element to be added.
                     * @see insert()
                     */
                    virtual void addTail(T *element) {
                        insert(size(), element);
                    }

                    /**
                     * Equivalent to <code>get(0)</code>.
                     * @brief Gets the element at the head of the list.
                     * @return The element at the head of the list, or nullptr if the list is empty.
                     * @see get()
                     */
                    virtual T *getHead() {
                        return get(0);
                    }

                    /**
                     * Equivalent to <code>get(size() - 1)</code>.
                     * @brief Gets the element at the tail of the list.
                     * @return The element at the tail of the list, or nullptr if the list is empty.
                     * @see get()
                     */
                    virtual T *getTail() {
                        return get(size() - 1);
                    }

                    /**
                     * Equivalent to <code>set(0, element)</code>.
                     * @brief Sets the element at the head of the list.
                     * @param element The new element to be placed at the head of the list.
                     * @return The element that is previously at the head of the list, or nullptr if the list is empty.
                     * @see set()
                     */
                    virtual T *setHead(T *element) {
                        return set(0, element);
                    }

                    /**
                     * Equivalent to <code>set(size() - 1, element)</code>.
                     * @brief Sets the element at the tail of the list.
                     * @param element The new element to be placed at the tail of the list.
                     * @return The element that is previously at the tail of the list, or nullptr if the list is empty.
                     * @see set()
                     */
                    virtual T *setTail(T *element) {
                        return set(size() - 1, element);
                    }

                    /**
                     * Equivalent to <code>remove(0, element)</code>.
                     * @brief Removes the element at the head of the list.
                     * @return The element that is previously at the head of the list, or nullptr if the list is empty.
                     * @see remove()
                     */
                    virtual T *removeHead() {
                        return remove(0);
                    }

                    /**
                     * Equivalent to <code>remove(size() - 1, element)</code>.
                     * @brief Removes the element at the tail of the list.
                     * @return The element that is previously at the tail of the list, or nullptr if the list is empty.
                     * @see remove()
                     */
                    virtual T *removeTail() {
                        return remove(size() - 1);
                    }
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_LISTS_LIST_H