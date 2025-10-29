#include "../../../src/structures/stacks/LinkedStack.h"

#include <iostream>

using yh::structures::stacks::LinkedStack;

int main() {
    std::cout << "Testing " << __FILE__ << std::endl;
    unsigned int failed_testcase_count = 0;
    size_t testcase_index = 0;

    {
        LinkedStack<int> stack;
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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
        std::cout << "Testcase #" << testcase_index;
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