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

#include "../../test.h"
#include "../../../src/structures/queues/LinkedQueue.h"

#include <iostream>
#include <string>
#include <sstream>

using yh::structures::queues::LinkedQueue;

TEST_BEGIN(empty_testcase)
{
    //
}
TEST_END()

TEST_BEGIN(constructor_memory_leak)
{
    LinkedQueue<int> queue;
}
TEST_END()

TEST_BEGIN(queue_is_empty_for_empty_queue)
{
    LinkedQueue<int> queue;
    ASSERT_TRUE(queue.isEmpty());
}
TEST_END()

TEST_BEGIN(queue_is_not_empty_for_1_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    ASSERT_FALSE(queue.isEmpty());
}
TEST_END()

TEST_BEGIN(queue_is_not_empty_for_2_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    ASSERT_FALSE(queue.isEmpty());
}
TEST_END()

TEST_BEGIN(queue_size_is_0_for_empty_queue)
{
    LinkedQueue<int> queue;
    ASSERT_EQUALS(queue.size(), 0);
}
TEST_END()

TEST_BEGIN(queue_size_is_1_for_1_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    ASSERT_EQUALS(queue.size(), 1);
}
TEST_END()

TEST_BEGIN(queue_size_is_2_for_2_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    ASSERT_EQUALS(queue.size(), 2);
}
TEST_END()

TEST_BEGIN(queue_size_is_3_for_3_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    ASSERT_EQUALS(queue.size(), 3);
}
TEST_END()

TEST_BEGIN(queue_size_is_4_for_4_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    queue.enqueue(&a);
    ASSERT_EQUALS(queue.size(), 4);
}
TEST_END()

TEST_BEGIN(queue_peeking_gives_nullptr_for_empty_queue)
{
    LinkedQueue<int> queue;
    ASSERT_IS_NULLPTR(queue.peek());
}
TEST_END()

TEST_BEGIN(queue_peeking_gives_first_element_for_1_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    ASSERT_EQUALS(queue.peek(), &x);
}
TEST_END()

TEST_BEGIN(queue_peeking_gives_first_element_for_2_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    ASSERT_EQUALS(queue.peek(), &x);
}
TEST_END()

TEST_BEGIN(queue_peeking_gives_first_element_for_3_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    ASSERT_EQUALS(queue.peek(), &x);
}
TEST_END()

TEST_BEGIN(queue_dequeueing_gives_nullptr_for_empty_queue)
{
    LinkedQueue<int> queue;
    ASSERT_IS_NULLPTR(queue.dequeue());
}
TEST_END()

TEST_BEGIN(queue_dequeueing_gives_first_element_for_1_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    ASSERT_EQUALS(queue.dequeue(), &x);
}
TEST_END()

TEST_BEGIN(queue_dequeueing_gives_first_element_for_2_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    ASSERT_EQUALS(queue.dequeue(), &x);
}
TEST_END()

TEST_BEGIN(queue_dequeueing_gives_first_element_for_3_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    ASSERT_EQUALS(queue.dequeue(), &x);
}
TEST_END()

TEST_BEGIN(queue_dequeueing_twice_gives_first_element_for_3_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    ASSERT_EQUALS(queue.dequeue(), &x);
    ASSERT_EQUALS(queue.dequeue(), &y);
}
TEST_END()

TEST_BEGIN(queue_size_is_0_after_dequeueing_from_empty_queue)
{
    LinkedQueue<int> queue;
    queue.dequeue();
    ASSERT_EQUALS(queue.size(), 0);
}
TEST_END()

TEST_BEGIN(queue_size_is_0_after_dequeueing_from_1_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    queue.dequeue();
    ASSERT_EQUALS(queue.size(), 0);
}
TEST_END()

TEST_BEGIN(queue_size_is_1_after_dequeueing_from_2_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.dequeue();
    ASSERT_EQUALS(queue.size(), 1);
}
TEST_END()

TEST_BEGIN(queue_size_is_2_after_dequeueing_from_3_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    queue.dequeue();
    ASSERT_EQUALS(queue.size(), 2);
}
TEST_END()

TEST_BEGIN(queue_size_is_1_after_dequeueing_twice_from_3_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    int z = 0;
    queue.enqueue(&x);
    queue.enqueue(&y);
    queue.enqueue(&z);
    queue.dequeue();
    ASSERT_EQUALS(queue.size(), 2);
    queue.dequeue();
    ASSERT_EQUALS(queue.size(), 1);
}
TEST_END()

TEST_BEGIN(queue_is_not_empty_for_3_element_queue_dequeued_and_enqueued)
{
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
    ASSERT_FALSE(queue.isEmpty());
}
TEST_END()

TEST_BEGIN(queue_size_is_3_for_3_element_queue_dequeued_and_enqueued)
{
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
    ASSERT_EQUALS(queue.size(), 3);
}
TEST_END()

TEST_BEGIN(queue_peeking_gives_first_element_for_3_element_queue_dequeued_and_enqueued)
{
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
    ASSERT_EQUALS(queue.peek(), &y);
}
TEST_END()

TEST_BEGIN(queue_dequeueing_gives_first_element_for_3_element_queue_dequeued_and_enqueued)
{
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
    ASSERT_EQUALS(queue.dequeue(), &y);
}
TEST_END()

TEST_BEGIN(queue_is_empty_for_4_element_queue_enqueued_and_dequeued)
{
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
    ASSERT_TRUE(queue.isEmpty());
}
TEST_END()

TEST_BEGIN(queue_order_for_4_element_queue)
{
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

    ASSERT_EQUALS(data, &x);
    ASSERT_EQUALS(data2, &y);
    ASSERT_EQUALS(data3, &z);
    ASSERT_EQUALS(data4, &a);

    ASSERT_TRUE(queue.isEmpty());
    ASSERT_EQUALS(queue.size(), 0);
}
TEST_END()

const testfunc_t functions [] = {
    test_empty_testcase,
    test_constructor_memory_leak,
    test_queue_is_empty_for_empty_queue,
    test_queue_is_not_empty_for_1_element_queue,
    test_queue_is_not_empty_for_2_element_queue,
    test_queue_size_is_0_for_empty_queue,
    test_queue_size_is_1_for_1_element_queue,
    test_queue_size_is_2_for_2_element_queue,
    test_queue_size_is_3_for_3_element_queue,
    test_queue_size_is_4_for_4_element_queue,
    test_queue_peeking_gives_nullptr_for_empty_queue,
    test_queue_peeking_gives_first_element_for_1_element_queue,
    test_queue_peeking_gives_first_element_for_2_element_queue,
    test_queue_peeking_gives_first_element_for_3_element_queue,
    test_queue_dequeueing_gives_nullptr_for_empty_queue,
    test_queue_dequeueing_gives_first_element_for_1_element_queue,
    test_queue_dequeueing_gives_first_element_for_2_element_queue,
    test_queue_dequeueing_gives_first_element_for_3_element_queue,
    test_queue_dequeueing_twice_gives_first_element_for_3_element_queue,
    test_queue_size_is_0_after_dequeueing_from_empty_queue,
    test_queue_size_is_0_after_dequeueing_from_1_element_queue,
    test_queue_size_is_1_after_dequeueing_from_2_element_queue,
    test_queue_size_is_2_after_dequeueing_from_3_element_queue,
    test_queue_size_is_1_after_dequeueing_twice_from_3_element_queue,
    test_queue_is_not_empty_for_3_element_queue_dequeued_and_enqueued,
    test_queue_size_is_3_for_3_element_queue_dequeued_and_enqueued,
    test_queue_peeking_gives_first_element_for_3_element_queue_dequeued_and_enqueued,
    test_queue_dequeueing_gives_first_element_for_3_element_queue_dequeued_and_enqueued,
    test_queue_is_empty_for_4_element_queue_enqueued_and_dequeued,
    test_queue_order_for_4_element_queue,
};

MAIN();
