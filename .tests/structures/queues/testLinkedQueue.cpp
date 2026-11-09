/**
 * @file testLinkedQueue.cpp - Tests for linked queue.
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

#include "../../../src/structures/queues/LinkedQueue.h"

using yh::structures::queues::LinkedQueue;

class LinkedQueueTest : public tests::LeakCheckedTest {};

TEST_F(LinkedQueueTest, EmptyTestcase) {
    //
}

TEST_F(LinkedQueueTest, ConstructorMemoryLeak) {
    LinkedQueue<int> queue;
}

TEST_F(LinkedQueueTest, IsEmptyForEmptyQueue) {
    LinkedQueue<int> queue;
    EXPECT_TRUE(queue.isEmpty());
}

TEST_F(LinkedQueueTest, IsNotEmptyFor1ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    EXPECT_FALSE(queue.isEmpty());
}

TEST_F(LinkedQueueTest, IsNotEmptyFor2ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    EXPECT_FALSE(queue.isEmpty());
}

TEST_F(LinkedQueueTest, SizeIs0ForEmptyQueue) {
    LinkedQueue<int> queue;
    EXPECT_EQ(queue.size(), 0u);
}

TEST_F(LinkedQueueTest, SizeIs1For1ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    EXPECT_EQ(queue.size(), 1u);
}

TEST_F(LinkedQueueTest, SizeIs2For2ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    EXPECT_EQ(queue.size(), 2u);
}

TEST_F(LinkedQueueTest, SizeIs3For3ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    EXPECT_EQ(queue.size(), 3u);
}

TEST_F(LinkedQueueTest, SizeIs4For4ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    queue.enqueue(&a);
    EXPECT_EQ(queue.size(), 4u);
}

TEST_F(LinkedQueueTest, PeekingGivesNullptrForEmptyQueue) {
    LinkedQueue<int> queue;
    EXPECT_EQ(queue.peek(), nullptr);
}

TEST_F(LinkedQueueTest, PeekingGivesFirstElementFor1ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    EXPECT_EQ(queue.peek(), &x);
}

TEST_F(LinkedQueueTest, PeekingGivesFirstElementFor2ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    EXPECT_EQ(queue.peek(), &x);
}

TEST_F(LinkedQueueTest, PeekingGivesFirstElementFor3ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    EXPECT_EQ(queue.peek(), &x);
}

TEST_F(LinkedQueueTest, DequeueingGivesNullptrForEmptyQueue) {
    LinkedQueue<int> queue;
    EXPECT_EQ(queue.dequeue(), nullptr);
}

TEST_F(LinkedQueueTest, DequeueingGivesFirstElementFor1ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    EXPECT_EQ(queue.dequeue(), &x);
}

TEST_F(LinkedQueueTest, DequeueingGivesFirstElementFor2ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    EXPECT_EQ(queue.dequeue(), &x);
}

TEST_F(LinkedQueueTest, DequeueingGivesFirstElementFor3ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    EXPECT_EQ(queue.dequeue(), &x);
}

TEST_F(LinkedQueueTest, DequeueingTwiceGivesFirstElementFor3ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    EXPECT_EQ(queue.dequeue(), &x);
    EXPECT_EQ(queue.dequeue(), &y);
}

TEST_F(LinkedQueueTest, SizeIs0AfterDequeueingFromEmptyQueue) {
    LinkedQueue<int> queue;
    queue.dequeue();
    EXPECT_EQ(queue.size(), 0u);
}

TEST_F(LinkedQueueTest, SizeIs0AfterDequeueingFrom1ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    queue.dequeue();
    EXPECT_EQ(queue.size(), 0u);
}

TEST_F(LinkedQueueTest, SizeIs1AfterDequeueingFrom2ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.dequeue();
    EXPECT_EQ(queue.size(), 1u);
}

TEST_F(LinkedQueueTest, SizeIs2AfterDequeueingFrom3ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    queue.dequeue();
    EXPECT_EQ(queue.size(), 2u);
}

TEST_F(LinkedQueueTest, SizeIs1AfterDequeueingTwiceFrom3ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    queue.dequeue();
    EXPECT_EQ(queue.size(), 2u);
    queue.dequeue();
    EXPECT_EQ(queue.size(), 1u);
}

TEST_F(LinkedQueueTest, IsNotEmptyFor3ElementQueueDequeuedAndEnqueued) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    queue.dequeue();
    queue.enqueue(&a);
    EXPECT_FALSE(queue.isEmpty());
}

TEST_F(LinkedQueueTest, SizeIs3For3ElementQueueDequeuedAndEnqueued) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    queue.dequeue();
    queue.enqueue(&a);
    EXPECT_EQ(queue.size(), 3u);
}

TEST_F(LinkedQueueTest, PeekingGivesFirstElementFor3ElementQueueDequeuedAndEnqueued) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    queue.dequeue();
    queue.enqueue(&a);
    EXPECT_EQ(queue.peek(), &y);
}

TEST_F(LinkedQueueTest, DequeueingGivesFirstElementFor3ElementQueueDequeuedAndEnqueued) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    queue.dequeue();
    queue.enqueue(&a);
    EXPECT_EQ(queue.dequeue(), &y);
}

TEST_F(LinkedQueueTest, IsEmptyFor4ElementQueueEnqueuedAndDequeued) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    queue.dequeue();
    queue.enqueue(&a);
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    EXPECT_TRUE(queue.isEmpty());
}

TEST_F(LinkedQueueTest, OrderFor4ElementQueue) {
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    int *const data = queue.dequeue();
    queue.enqueue(&a);
    int *const data2 = queue.dequeue();
    int *const data3 = queue.dequeue();
    int *const data4 = queue.dequeue();

    EXPECT_EQ(data, &x);
    EXPECT_EQ(data2, &y);
    EXPECT_EQ(data3, &z);
    EXPECT_EQ(data4, &a);

    EXPECT_TRUE(queue.isEmpty());
    EXPECT_EQ(queue.size(), 0u);
}
