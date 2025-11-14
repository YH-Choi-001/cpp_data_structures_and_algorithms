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

#include "../../test.h"
#include "../../../src/structures/stacks/LinkedStack.h"

#include <iostream>
#include <string>
#include <sstream>

using yh::structures::stacks::LinkedStack;

TEST_BEGIN(stack_is_empty_for_empty_stack)
{
    LinkedStack<int> stack;
    if (stack.isEmpty()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "stack.isEmpty() returns false for an empty stack.";
    }
}
TEST_END()

TEST_BEGIN(stack_is_not_empty_for_1_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    if (!stack.isEmpty()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "stack.isEmpty() returns true for a stack with 1 element.";
    }
}
TEST_END()

TEST_BEGIN(stack_is_not_empty_for_2_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    if (!stack.isEmpty()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "stack.isEmpty() returns true for a stack with 2 elements.";
    }
}
TEST_END()

TEST_BEGIN(stack_size_is_0_for_empty_stack)
{
    LinkedStack<int> stack;
    const size_t size = stack.size();
    if (size == 0) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.size() returns " << size << " for an empty stack.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_size_is_1_for_1_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    const size_t size = stack.size();
    if (size == 1) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.size() returns " << size << " for a stack with 1 element.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_size_is_2_for_2_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    const size_t size = stack.size();
    if (size == 2) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.size() returns " << size << " for a stack with 2 elements.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_size_is_3_for_3_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    const size_t size = stack.size();
    if (size == 3) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.size() returns " << size << " for a stack with 3 elements.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_size_is_4_for_4_element_stack)
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
    const size_t size = stack.size();
    if (size == 4) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.size() returns " << size << " for a stack with 4 elements.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_peeking_gives_nullptr_for_empty_stack)
{
    LinkedStack<int> stack;
    int *data = stack.peek();
    if (data == nullptr) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.peek() returns " << data << " for an empty stack.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_peeking_gives_top_element_for_1_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    int *data = stack.peek();
    if (data == &x) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.peek() returns " << data << " but not &x ( = " << &x << ") for a stack with 1 element.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_peeking_gives_top_element_for_2_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    int *data = stack.peek();
    if (data == &y) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.peek() returns " << data << " but not &y ( = " << &y << ") for a stack with 2 elements.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_peeking_gives_top_element_for_3_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    int *data = stack.peek();
    if (data == &z) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.peek() returns " << data << " but not &z ( = " << &z << ") for a stack with 3 elements.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_popping_gives_nullptr_for_empty_stack)
{
    LinkedStack<int> stack;
    int *data = stack.pop();
    if (data == nullptr) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.pop() returns " << data << " for an empty stack.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_popping_gives_top_element_for_1_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    int *data = stack.pop();
    if (data == &x) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.pop() returns " << data << " but not &x ( = " << &x << ") for a stack with 1 element.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_popping_gives_top_element_for_2_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    int *data = stack.pop();
    if (data == &y) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.pop() returns " << data << " but not &y ( = " << &y << ") for a stack with 2 elements.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_popping_gives_top_element_for_3_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    int *data = stack.pop();
    if (data == &z) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.pop() returns " << data << " but not &z ( = " << &z << ") for a stack with 3 elements.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_popping_twice_gives_top_element_for_3_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    int *data = stack.pop();
    int *data2 = stack.pop();
    if (data == &z && data2 == &y) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        if (data != &z) {
            ss << "stack.pop() returns " << data << " but not &z ( = " << &z << ") for a stack with 3 elements.";
        }
        if (data2 != &y) {
            ss << "stack.pop() returns " << data << " but not &y ( = " << &y << ") for a stack with 2 elements.";
        }
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_size_is_0_after_popping_from_empty_stack)
{
    LinkedStack<int> stack;
    int *data = stack.pop();
    const size_t size = stack.size();
    if (size == 0) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.size() returns " << size << " after popping an empty stack.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_size_is_0_after_popping_from_1_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    int *data = stack.pop();
    const size_t size = stack.size();
    if (size == 0) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.size() returns " << size << " after popping a stack with 1 element.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_size_is_1_after_popping_from_2_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    int *data = stack.pop();
    const size_t size = stack.size();
    if (size == 1) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.size() returns " << size << " after popping a stack with 2 elements.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_size_is_2_after_popping_from_3_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    int *data = stack.pop();
    const size_t size = stack.size();
    if (size == 2) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.size() returns " << size << " after popping a stack with 3 elements.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_size_is_1_after_popping_twice_from_3_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    int *data = stack.pop();
    int *data2 = stack.pop();
    const size_t size = stack.size();
    if (size == 1) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.size() returns " << size << " after popping a stack with 3 elements twice.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_is_not_empty_for_3_element_stack_popped_and_pushed)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    int *data = stack.pop();
    stack.push(&a);
    const bool isEmpty = stack.isEmpty();
    if (!isEmpty) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.isEmpty() returns " << isEmpty << " after a stack with 3 elements is popped then pushed.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_size_is_3_for_3_element_stack_popped_and_pushed)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    int *data = stack.pop();
    stack.push(&a);
    const size_t size = stack.size();
    if (size == 3) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.size() returns " << size << " after a stack with 3 elements is popped then pushed.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_peeking_gives_top_element_for_3_element_stack_popped_and_pushed)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    int *data = stack.pop();
    stack.push(&a);
    int *data2 = stack.peek();
    if (data2 == &a) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.peek() returns " << data << " but not &a ( = " << &a << ") after a stack with 3 elements is popped then pushed.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_popping_gives_top_element_for_3_element_stack_popped_and_pushed)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    int *data = stack.pop();
    stack.push(&a);
    int *data2 = stack.pop();
    if (data2 == &a) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "stack.pop() returns " << data << " but not &a ( = " << &a << ") after a stack with 3 elements is popped then pushed.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(stack_is_empty_for_4_element_stack_pushed_and_popped)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    int *data = stack.pop();
    stack.push(&a);
    int *data2 = stack.pop();
    int *data3 = stack.pop();
    int *data4 = stack.pop();
    const bool isEmpty = stack.isEmpty();
    if (isEmpty) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "stack.isEmpty() returns false after a stack with 4 elements is pushed then popped.";
    }
}
TEST_END()

TEST_BEGIN(stack_order_for_4_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    int *data = stack.pop();
    stack.push(&a);
    int *data2 = stack.pop();
    int *data3 = stack.pop();
    int *data4 = stack.pop();
    result.passed = true;
    if (data != &z || data2 != &a || data3 != &y || data4 != &x) {
        result.passed = false;
        result.reason = "stack.pop() returns wrong addresses or in wrong order.";
    }
    const bool isEmpty = stack.isEmpty();
    if (!isEmpty) {
        result.passed = false;
        result.reason = "stack.isEmpty() returns false for a stack that is popped till empty.";
    }
    const size_t size = stack.size();
    if (size != 0) {
        result.passed = false;
        std::stringstream ss;
        ss << " failed: stack.size() returns " << size << " instead of 0 for a stack that is popped till empty.";
        result.reason = ss.str();
    }
}
TEST_END()

const testfunc_t functions [] = {
    test_stack_is_empty_for_empty_stack,
    test_stack_is_not_empty_for_1_element_stack,
    test_stack_is_not_empty_for_2_element_stack,
    test_stack_size_is_0_for_empty_stack,
    test_stack_size_is_1_for_1_element_stack,
    test_stack_size_is_2_for_2_element_stack,
    test_stack_size_is_3_for_3_element_stack,
    test_stack_size_is_4_for_4_element_stack,
    test_stack_peeking_gives_nullptr_for_empty_stack,
    test_stack_peeking_gives_top_element_for_1_element_stack,
    test_stack_peeking_gives_top_element_for_2_element_stack,
    test_stack_peeking_gives_top_element_for_3_element_stack,
    test_stack_popping_gives_nullptr_for_empty_stack,
    test_stack_popping_gives_top_element_for_1_element_stack,
    test_stack_popping_gives_top_element_for_2_element_stack,
    test_stack_popping_gives_top_element_for_3_element_stack,
    test_stack_popping_twice_gives_top_element_for_3_element_stack,
    test_stack_size_is_0_after_popping_from_empty_stack,
    test_stack_size_is_0_after_popping_from_1_element_stack,
    test_stack_size_is_1_after_popping_from_2_element_stack,
    test_stack_size_is_2_after_popping_from_3_element_stack,
    test_stack_size_is_1_after_popping_twice_from_3_element_stack,
    test_stack_is_not_empty_for_3_element_stack_popped_and_pushed,
    test_stack_size_is_3_for_3_element_stack_popped_and_pushed,
    test_stack_peeking_gives_top_element_for_3_element_stack_popped_and_pushed,
    test_stack_popping_gives_top_element_for_3_element_stack_popped_and_pushed,
    test_stack_is_empty_for_4_element_stack_pushed_and_popped,
    test_stack_order_for_4_element_stack,
};

int main() {
    std::cout << "Testing " << __FILE__ << std::endl;
    for (testfunc_t func : functions) {
        test(func);
    }
    const unsigned int failed_testcase_count = get_failed_testcase_count();
    if (failed_testcase_count == 0) {
        std::cout << "All passed: " << __FILE__ << std::endl;
    } else {
        std::cout << failed_testcase_count << " failed: " << __FILE__ << std::endl;
    }
    return failed_testcase_count;
}