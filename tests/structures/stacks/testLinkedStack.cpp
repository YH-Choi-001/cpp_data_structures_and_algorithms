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

TEST_BEGIN(empty_testcase)
{
    //
}
TEST_END()

TEST_BEGIN(constructor_memory_leak)
{
    LinkedStack<int> stack;
}
TEST_END()

TEST_BEGIN(stack_is_empty_for_empty_stack)
{
    LinkedStack<int> stack;
    ASSERT_TRUE(stack.isEmpty());
}
TEST_END()

TEST_BEGIN(stack_is_not_empty_for_1_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    ASSERT_FALSE(stack.isEmpty());
}
TEST_END()

TEST_BEGIN(stack_is_not_empty_for_2_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    ASSERT_FALSE(stack.isEmpty());
}
TEST_END()

TEST_BEGIN(stack_size_is_0_for_empty_stack)
{
    LinkedStack<int> stack;
    ASSERT_EQUALS(stack.size(), 0);
}
TEST_END()

TEST_BEGIN(stack_size_is_1_for_1_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    ASSERT_EQUALS(stack.size(), 1);
}
TEST_END()

TEST_BEGIN(stack_size_is_2_for_2_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    ASSERT_EQUALS(stack.size(), 2);
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
    ASSERT_EQUALS(stack.size(), 3);
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
    ASSERT_EQUALS(stack.size(), 4);
}
TEST_END()

TEST_BEGIN(stack_peeking_gives_nullptr_for_empty_stack)
{
    LinkedStack<int> stack;
    ASSERT_IS_NULLPTR(stack.peek());
}
TEST_END()

TEST_BEGIN(stack_peeking_gives_top_element_for_1_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    ASSERT_EQUALS(stack.peek(), &x);
}
TEST_END()

TEST_BEGIN(stack_peeking_gives_top_element_for_2_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    ASSERT_EQUALS(stack.peek(), &y);
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
    ASSERT_EQUALS(stack.peek(), &z);
}
TEST_END()

TEST_BEGIN(stack_popping_gives_nullptr_for_empty_stack)
{
    LinkedStack<int> stack;
    ASSERT_IS_NULLPTR(stack.pop());
}
TEST_END()

TEST_BEGIN(stack_popping_gives_top_element_for_1_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    ASSERT_EQUALS(stack.pop(), &x);
}
TEST_END()

TEST_BEGIN(stack_popping_gives_top_element_for_2_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    ASSERT_EQUALS(stack.pop(), &y);
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
    ASSERT_EQUALS(stack.pop(), &z);
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
    ASSERT_EQUALS(stack.pop(), &z);
    ASSERT_EQUALS(stack.pop(), &y);
}
TEST_END()

TEST_BEGIN(stack_size_is_0_after_popping_from_empty_stack)
{
    LinkedStack<int> stack;
    stack.pop();
    ASSERT_EQUALS(stack.size(), 0);
}
TEST_END()

TEST_BEGIN(stack_size_is_0_after_popping_from_1_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    stack.pop();
    ASSERT_EQUALS(stack.size(), 0);
}
TEST_END()

TEST_BEGIN(stack_size_is_1_after_popping_from_2_element_stack)
{
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    stack.pop();
    ASSERT_EQUALS(stack.size(), 1);
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
    stack.pop();
    ASSERT_EQUALS(stack.size(), 2);
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
    stack.pop();
    ASSERT_EQUALS(stack.size(), 2);
    stack.pop();
    ASSERT_EQUALS(stack.size(), 1);
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
    stack.pop();
    stack.push(&a);
    ASSERT_FALSE(stack.isEmpty());
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
    stack.pop();
    stack.push(&a);
    ASSERT_EQUALS(stack.size(), 3);
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
    stack.pop();
    stack.push(&a);
    ASSERT_EQUALS(stack.peek(), &a);
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
    stack.pop();
    stack.push(&a);
    ASSERT_EQUALS(stack.pop(), &a);
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
    stack.pop();
    stack.push(&a);
    stack.pop();
    stack.pop();
    stack.pop();
    ASSERT_TRUE(stack.isEmpty());
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
    int *const data = stack.pop();
    stack.push(&a);
    int *const data2 = stack.pop();
    int *const data3 = stack.pop();
    int *const data4 = stack.pop();

    ASSERT_EQUALS(data, &z);
    ASSERT_EQUALS(data2, &a);
    ASSERT_EQUALS(data3, &y);
    ASSERT_EQUALS(data4, &x);

    ASSERT_TRUE(stack.isEmpty());
    ASSERT_EQUALS(stack.size(), 0);
}
TEST_END()

const testfunc_t functions [] = {
    test_empty_testcase,
    test_constructor_memory_leak,
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

MAIN();
