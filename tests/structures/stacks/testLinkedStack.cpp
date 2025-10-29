/**
 * @file testLinkedStack.cpp - Tests for linked stack.
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

#include "../../../src/structures/stacks/LinkedStack.h"

#include <iostream>

using yh::structures::stacks::LinkedStack;

int main() {
    std::cout << "Testing " << __FILE__ << std::endl;
    unsigned int failed_testcase_count = 0;
    size_t testcase_index = 0;

    {
        LinkedStack<int> stack;
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (stack.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.isEmpty() returns false for an empty stack.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        stack.push(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!stack.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.isEmpty() returns true for a stack with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        stack.push(&x);
        stack.push(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!stack.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.isEmpty() returns true for a stack with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = stack.size();
        if (size == 0) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.size() returns " << size << " for an empty stack.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        stack.push(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = stack.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.size() returns " << size << " for a stack with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        stack.push(&x);
        stack.push(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = stack.size();
        if (size == 2) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.size() returns " << size << " for a stack with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = stack.size();
        if (size == 3) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.size() returns " << size << " for a stack with 3 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        stack.push(&a);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = stack.size();
        if (size == 4) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.size() returns " << size << " for a stack with 4 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.peek();
        if (data == nullptr) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.peek() returns " << data << " for an empty stack.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        stack.push(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.peek();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.peek() returns " << data << " but not &x ( = " << &x << ") for a stack with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        stack.push(&x);
        stack.push(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.peek();
        if (data == &y) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.peek() returns " << data << " but not &y ( = " << &y << ") for a stack with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.peek();
        if (data == &z) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.peek() returns " << data << " but not &z ( = " << &z << ") for a stack with 3 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        if (data == nullptr) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.pop() returns " << data << " for an empty stack.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        stack.push(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.pop() returns " << data << " but not &x ( = " << &x << ") for a stack with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        stack.push(&x);
        stack.push(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        if (data == &y) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.pop() returns " << data << " but not &y ( = " << &y << ") for a stack with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        if (data == &z) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.pop() returns " << data << " but not &z ( = " << &z << ") for a stack with 3 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        int *data2 = stack.pop();
        if (data == &z && data2 == &y) {
            std::cout << " passed.";
        } else {
            if (data != &z) {
                std::cout << " failed: stack.pop() returns " << data << " but not &z ( = " << &z << ") for a stack with 3 elements.";
            }
            if (data2 != &y) {
                std::cout << " failed: stack.pop() returns " << data << " but not &y ( = " << &y << ") for a stack with 2 elements.";
            }
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        const size_t size = stack.size();
        if (size == 0) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.size() returns " << size << " after popping an empty stack.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        stack.push(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        const size_t size = stack.size();
        if (size == 0) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.size() returns " << size << " after popping a stack with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        stack.push(&x);
        stack.push(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        const size_t size = stack.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.size() returns " << size << " after popping a stack with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        const size_t size = stack.size();
        if (size == 2) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.size() returns " << size << " after popping a stack with 3 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        int *data2 = stack.pop();
        const size_t size = stack.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.size() returns " << size << " after popping a stack with 3 elements twice.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        stack.push(&a);
        const bool isEmpty = stack.isEmpty();
        if (!isEmpty) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.isEmpty() returns " << isEmpty << " after a stack with 3 elements is popped then pushed.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        stack.push(&a);
        const size_t size = stack.size();
        if (size == 3) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.size() returns " << size << " after a stack with 3 elements is popped then pushed.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        stack.push(&a);
        int *data2 = stack.peek();
        if (data2 == &a) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.peek() returns " << data << " but not &a ( = " << &a << ") after a stack with 3 elements is popped then pushed.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        stack.push(&a);
        int *data2 = stack.pop();
        if (data2 == &a) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.pop() returns " << data << " but not &a ( = " << &a << ") after a stack with 3 elements is popped then pushed.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        stack.push(&a);
        int *data2 = stack.pop();
        int *data3 = stack.pop();
        int *data4 = stack.pop();
        const bool isEmpty = stack.isEmpty();
        if (isEmpty) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: stack.isEmpty() returns " << isEmpty << " but all elements are popped after pushed to a stack.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedStack<int> stack;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        stack.push(&x);
        stack.push(&y);
        stack.push(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = stack.pop();
        stack.push(&a);
        int *data2 = stack.pop();
        int *data3 = stack.pop();
        int *data4 = stack.pop();
        bool passed = true;
        if (data != &z || data2 != &a || data3 != &y || data4 != &x) {
            std::cout << " failed: stack.pop() returns wrong addresses or in wrong order.";
            passed = false;
        }
        const bool isEmpty = stack.isEmpty();
        if (!isEmpty) {
            std::cout << " failed: stack.isEmpty() returns false for a stack that is popped till empty.";
            passed = false;
        }
        const size_t size = stack.size();
        if (size != 0) {
            std::cout << " failed: stack.size() returns " << size << " instead of 0 for a stack that is popped till empty.";
            passed = false;
        }
        if (passed) {
            std::cout << " passed.";
        } else {
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    if (failed_testcase_count == 0) {
        std::cout << "All passed: " << __FILE__ << std::endl;
    } else {
        std::cout << failed_testcase_count << " failed: " << __FILE__ << std::endl;
    }
    return failed_testcase_count;
}