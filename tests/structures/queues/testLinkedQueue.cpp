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

TEST_BEGIN(queue_is_empty_for_empty_queue)
{
    LinkedQueue<int> queue;
    if (queue.isEmpty()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "queue.isEmpty() returns false for an empty queue.";
    }
}
TEST_END()

TEST_BEGIN(queue_is_not_empty_for_1_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    if (!queue.isEmpty()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "queue.isEmpty() returns true for a queue with 1 element.";
    }
}
TEST_END()

TEST_BEGIN(queue_is_not_empty_for_2_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    if (!queue.isEmpty()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "queue.isEmpty() returns true for a queue with 2 elements.";
    }
}
TEST_END()

TEST_BEGIN(queue_size_is_0_for_empty_queue)
{
    LinkedQueue<int> queue;
    const size_t size = queue.size();
    if (size == 0) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.size() returns " << size << " for an empty queue.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(queue_size_is_1_for_1_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    const size_t size = queue.size();
    if (size == 1) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.size() returns " << size << " for a queue with 1 element.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(queue_size_is_2_for_2_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    const size_t size = queue.size();
    if (size == 2) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.size() returns " << size << " for a queue with 2 elements.";
        result.reason = ss.str();
    }
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
    const size_t size = queue.size();
    if (size == 3) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.size() returns " << size << " for a queue with 3 elements.";
        result.reason = ss.str();
    }
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
    const size_t size = queue.size();
    if (size == 4) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.size() returns " << size << " for a queue with 4 elements.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(queue_peeking_gives_nullptr_for_empty_queue)
{
    LinkedQueue<int> queue;
    int *data = queue.peek();
    if (data == nullptr) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.peek() returns " << data << " for an empty queue.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(queue_peeking_gives_first_element_for_1_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    int *data = queue.peek();
    if (data == &x) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.peek() returns " << data << " but not &x ( = " << &x << ") for a queue with 1 element.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(queue_peeking_gives_first_element_for_2_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    int *data = queue.peek();
    if (data == &x) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.peek() returns " << data << " but not &x ( = " << &x << ") for a queue with 2 elements.";
        result.reason = ss.str();
    }
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
    int *data = queue.peek();
    if (data == &x) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.peek() returns " << data << " but not &x ( = " << &x << ") for a queue with 3 elements.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(queue_dequeueing_gives_nullptr_for_empty_queue)
{
    LinkedQueue<int> queue;
    int *data = queue.dequeue();
    if (data == nullptr) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.dequeue() returns " << data << " for an empty queue.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(queue_dequeueing_gives_first_element_for_1_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    int *data = queue.dequeue();
    if (data == &x) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.dequeue() returns " << data << " but not &x ( = " << &x << ") for a queue with 1 element.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(queue_dequeueing_gives_first_element_for_2_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    int *data = queue.dequeue();
    if (data == &x) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.dequeue() returns " << data << " but not &x ( = " << &x << ") for a queue with 2 elements.";
        result.reason = ss.str();
    }
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
    int *data = queue.dequeue();
    if (data == &x) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.dequeue() returns " << data << " but not &x ( = " << &x << ") for a queue with 3 elements.";
        result.reason = ss.str();
    }
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
    int *data = queue.dequeue();
    int *data2 = queue.dequeue();
    if (data == &x && data2 == &y) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        if (data != &x) {
            ss << "queue.dequeue() returns " << data << " but not &x ( = " << &x << ") for a queue with 3 elements.";
        }
        if (data2 != &y) {
            ss << "queue.dequeue() returns " << data << " but not &y ( = " << &y << ") for a queue with 2 elements.";
        }
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(queue_size_is_0_after_dequeueing_from_empty_queue)
{
    LinkedQueue<int> queue;
    int *data = queue.dequeue();
    const size_t size = queue.size();
    if (size == 0) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.size() returns " << size << " after dequeueing an empty queue.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(queue_size_is_0_after_dequeueing_from_1_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    queue.enqueue(&x);
    int *data = queue.dequeue();
    const size_t size = queue.size();
    if (size == 0) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.size() returns " << size << " after dequeueing a queue with 1 element.";
        result.reason = ss.str();
    }
}
TEST_END()

TEST_BEGIN(queue_size_is_1_after_dequeueing_from_2_element_queue)
{
    LinkedQueue<int> queue;
    int x = 35;
    int y = -12;
    queue.enqueue(&x);
    queue.enqueue(&y);
    int *data = queue.dequeue();
    const size_t size = queue.size();
    if (size == 1) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.size() returns " << size << " after dequeueing a queue with 2 elements.";
        result.reason = ss.str();
    }
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
    int *data = queue.dequeue();
    const size_t size = queue.size();
    if (size == 2) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.size() returns " << size << " after dequeueing a queue with 3 elements.";
        result.reason = ss.str();
    }
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
    int *data = queue.dequeue();
    int *data2 = queue.dequeue();
    const size_t size = queue.size();
    if (size == 1) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.size() returns " << size << " after dequeueing a queue with 3 elements twice.";
        result.reason = ss.str();
    }
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
    int *data = queue.dequeue();
    queue.enqueue(&a);
    const bool isEmpty = queue.isEmpty();
    if (!isEmpty) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.isEmpty() returns " << isEmpty << " after a queue with 3 elements is dequeued then enqueued.";
        result.reason = ss.str();
    }
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
    int *data = queue.dequeue();
    queue.enqueue(&a);
    const size_t size = queue.size();
    if (size == 3) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.size() returns " << size << " after a queue with 3 elements is dequeued then enqueued.";
        result.reason = ss.str();
    }
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
    int *data = queue.dequeue();
    queue.enqueue(&a);
    int *data2 = queue.peek();
    if (data2 == &y) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.peek() returns " << data << " but not &y ( = " << &y << ") after a queue with 3 elements is dequeued then enqueued.";
        result.reason = ss.str();
    }
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
    int *data = queue.dequeue();
    queue.enqueue(&a);
    int *data2 = queue.dequeue();
    if (data2 == &y) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "queue.dequeue() returns " << data << " but not &y ( = " << &y << ") after a queue with 3 elements is dequeued then enqueued.";
        result.reason = ss.str();
    }
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
    int *data = queue.dequeue();
    queue.enqueue(&a);
    int *data2 = queue.dequeue();
    int *data3 = queue.dequeue();
    int *data4 = queue.dequeue();
    const bool isEmpty = queue.isEmpty();
    if (isEmpty) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "queue.isEmpty() returns false after a queue with 4 elements is enqueued then dequeued.";
    }
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
    int *data = queue.dequeue();
    queue.enqueue(&a);
    int *data2 = queue.dequeue();
    int *data3 = queue.dequeue();
    int *data4 = queue.dequeue();
    result.passed = true;
    if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
        result.passed = false;
        result.reason = "queue.dequeue() returns wrong addresses or in wrong order.";
    }
    const bool isEmpty = queue.isEmpty();
    if (!isEmpty) {
        result.passed = false;
        result.reason = "queue.isEmpty() returns false for a queue that is dequeued till empty.";
    }
    const size_t size = queue.size();
    if (size != 0) {
        result.passed = false;
        std::stringstream ss;
        ss << " failed: queue.size() returns " << size << " instead of 0 for a queue that is dequeued till empty.";
        result.reason = ss.str();
    }
}
TEST_END()

const testfunc_t functions [] = {
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

int main() {
    std::cout << "Testing " << __FILE__ << std::endl;
    for (testfunc_t func : functions) {
        sizeof(functions)/sizeof(functions[0]);
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