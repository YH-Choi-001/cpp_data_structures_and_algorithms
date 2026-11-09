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

#include "LeakCheckedTest.h"

#include "../../../src/structures/stacks/LinkedStack.h"

using yh::structures::stacks::LinkedStack;

class LinkedStackTest : public tests::LeakCheckedTest {};

TEST_F(LinkedStackTest, EmptyTestcase) {
    //
}

TEST_F(LinkedStackTest, ConstructorMemoryLeak) {
    LinkedStack<int> stack;
}

TEST_F(LinkedStackTest, IsEmptyForEmptyStack) {
    LinkedStack<int> stack;
    EXPECT_TRUE(stack.isEmpty());
}

TEST_F(LinkedStackTest, IsNotEmptyFor1ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    EXPECT_FALSE(stack.isEmpty());
}

TEST_F(LinkedStackTest, IsNotEmptyFor2ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    EXPECT_FALSE(stack.isEmpty());
}

TEST_F(LinkedStackTest, SizeIs0ForEmptyStack) {
    LinkedStack<int> stack;
    EXPECT_EQ(stack.size(), 0u);
}

TEST_F(LinkedStackTest, SizeIs1For1ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    EXPECT_EQ(stack.size(), 1u);
}

TEST_F(LinkedStackTest, SizeIs2For2ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    EXPECT_EQ(stack.size(), 2u);
}

TEST_F(LinkedStackTest, SizeIs3For3ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    EXPECT_EQ(stack.size(), 3u);
}

TEST_F(LinkedStackTest, SizeIs4For4ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    stack.push(&a);
    EXPECT_EQ(stack.size(), 4u);
}

TEST_F(LinkedStackTest, PeekingGivesNullptrForEmptyStack) {
    LinkedStack<int> stack;
    EXPECT_EQ(stack.peek(), nullptr);
}

TEST_F(LinkedStackTest, PeekingGivesTopElementFor1ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    EXPECT_EQ(stack.peek(), &x);
}

TEST_F(LinkedStackTest, PeekingGivesTopElementFor2ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    EXPECT_EQ(stack.peek(), &y);
}

TEST_F(LinkedStackTest, PeekingGivesTopElementFor3ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    EXPECT_EQ(stack.peek(), &z);
}

TEST_F(LinkedStackTest, PoppingGivesNullptrForEmptyStack) {
    LinkedStack<int> stack;
    EXPECT_EQ(stack.pop(), nullptr);
}

TEST_F(LinkedStackTest, PoppingGivesTopElementFor1ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    EXPECT_EQ(stack.pop(), &x);
}

TEST_F(LinkedStackTest, PoppingGivesTopElementFor2ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    EXPECT_EQ(stack.pop(), &y);
}

TEST_F(LinkedStackTest, PoppingGivesTopElementFor3ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    EXPECT_EQ(stack.pop(), &z);
}

TEST_F(LinkedStackTest, PoppingTwiceGivesTopElementFor3ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    EXPECT_EQ(stack.pop(), &z);
    EXPECT_EQ(stack.pop(), &y);
}

TEST_F(LinkedStackTest, SizeIs0AfterPoppingFromEmptyStack) {
    LinkedStack<int> stack;
    stack.pop();
    EXPECT_EQ(stack.size(), 0u);
}

TEST_F(LinkedStackTest, SizeIs0AfterPoppingFrom1ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    stack.push(&x);
    stack.pop();
    EXPECT_EQ(stack.size(), 0u);
}

TEST_F(LinkedStackTest, SizeIs1AfterPoppingFrom2ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    stack.push(&x);
    stack.push(&y);
    stack.pop();
    EXPECT_EQ(stack.size(), 1u);
}

TEST_F(LinkedStackTest, SizeIs2AfterPoppingFrom3ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    stack.pop();
    EXPECT_EQ(stack.size(), 2u);
}

TEST_F(LinkedStackTest, SizeIs1AfterPoppingTwiceFrom3ElementStack) {
    LinkedStack<int> stack;
    int x = 35;
    int y = -12;
    int z = 0;
    stack.push(&x);
    stack.push(&y);
    stack.push(&z);
    stack.pop();
    EXPECT_EQ(stack.size(), 2u);
    stack.pop();
    EXPECT_EQ(stack.size(), 1u);
}

TEST_F(LinkedStackTest, IsNotEmptyFor3ElementStackPoppedAndPushed) {
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
    EXPECT_FALSE(stack.isEmpty());
}

TEST_F(LinkedStackTest, SizeIs3For3ElementStackPoppedAndPushed) {
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
    EXPECT_EQ(stack.size(), 3u);
}

TEST_F(LinkedStackTest, PeekingGivesTopElementFor3ElementStackPoppedAndPushed) {
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
    EXPECT_EQ(stack.peek(), &a);
}

TEST_F(LinkedStackTest, PoppingGivesTopElementFor3ElementStackPoppedAndPushed) {
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
    EXPECT_EQ(stack.pop(), &a);
}

TEST_F(LinkedStackTest, IsEmptyFor4ElementStackPushedAndPopped) {
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
    EXPECT_TRUE(stack.isEmpty());
}

TEST_F(LinkedStackTest, OrderFor4ElementStack) {
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

    EXPECT_EQ(data, &z);
    EXPECT_EQ(data2, &a);
    EXPECT_EQ(data3, &y);
    EXPECT_EQ(data4, &x);

    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(stack.size(), 0u);
}
