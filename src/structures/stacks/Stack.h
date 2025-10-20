/**
 * @file Stack.h The stack interface in C++.
 * 
 * @copyright Copyright (c) 2025 YH Choi.
 */

#ifndef YH_STRUCTURES_STACKS_STACK_H
#define YH_STRUCTURES_STACKS_STACK_H

#ifdef ARDUINO
#include <stddef.h>
#else
#include <cstddef>
#endif

namespace yh {
    namespace structures {
        namespace stacks {
            /**
             * @brief The interface of a stack.
             * @param T The data type to be held by the stack.
             */
            template<typename T>
            class Stack {
                protected:
                    /**
                     * @brief Creates an empty stack.
                     */
                    Stack() {}

                public:
                    /**
                     * @brief Destroys the stack.
                     */
                    virtual ~Stack() {}

                    /**
                     * @brief Pushes a data to the top of the stack.
                     * @param data The data to be pushed to the top of the stack.
                     */
                    virtual void push(T *const data) = 0;

                    /**
                     * @brief Pops (removes) a data from the top of the stack.
                     * @return The data to be popped from the top of the stack, or nullptr if the stack is empty.
                     */
                    virtual T *pop() = 0;

                    /**
                     * @brief Get the data at the top of the stack without removing it.
                     * @return The data at the top of the stack, or nullptr if the stack is empty.
                     */
                    virtual T *peek() = 0;

                    /**
                     * @brief Gets the size of the stack.
                     * @return The size of the stack.
                     */
                    virtual size_t size() = 0;

                    /**
                     * @brief Checks whether the stack is empty.
                     * @return true if the stack is empty, false otherwise.
                     */
                    virtual bool isEmpty() {
                        return size() == 0;
                    }

                    /**
                     * @brief Checks whether the stack has used up all of its capacity.
                     * @return true if the stack is full, false otherwise.
                     */
                    virtual bool isFull() = 0;
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_STACKS_STACK_H