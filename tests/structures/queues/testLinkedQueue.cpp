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

#include "../../../src/structures/queues/LinkedQueue.h"

#include <iostream>

using yh::structures::queues::LinkedQueue;

int main() {
    std::cout << "Testing " << __FILE__ << std::endl;
    unsigned int failed_testcase_count = 0;
    size_t testcase_index = 0;

    {
        LinkedQueue<int> queue;
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (queue.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.isEmpty() returns false for an empty queue.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        queue.enqueue(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!queue.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.isEmpty() returns true for a queue with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        queue.enqueue(&x);
        queue.enqueue(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!queue.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.isEmpty() returns true for a queue with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = queue.size();
        if (size == 0) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.size() returns " << size << " for an empty queue.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        queue.enqueue(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = queue.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.size() returns " << size << " for a queue with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        queue.enqueue(&x);
        queue.enqueue(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = queue.size();
        if (size == 2) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.size() returns " << size << " for a queue with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        int z = 0;
        queue.enqueue(&x);
        queue.enqueue(&y);
        queue.enqueue(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = queue.size();
        if (size == 3) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.size() returns " << size << " for a queue with 3 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

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
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = queue.size();
        if (size == 4) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.size() returns " << size << " for a queue with 4 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.peek();
        if (data == nullptr) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.peek() returns " << data << " for an empty queue.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        queue.enqueue(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.peek();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.peek() returns " << data << " but not &x ( = " << &x << ") for a queue with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        queue.enqueue(&x);
        queue.enqueue(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.peek();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.peek() returns " << data << " but not &x ( = " << &x << ") for a queue with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        int z = 0;
        queue.enqueue(&x);
        queue.enqueue(&y);
        queue.enqueue(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.peek();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.peek() returns " << data << " but not &x ( = " << &x << ") for a queue with 3 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        if (data == nullptr) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.dequeue() returns " << data << " for an empty queue.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        queue.enqueue(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.dequeue() returns " << data << " but not &x ( = " << &x << ") for a queue with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        queue.enqueue(&x);
        queue.enqueue(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.dequeue() returns " << data << " but not &x ( = " << &x << ") for a queue with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        int z = 0;
        queue.enqueue(&x);
        queue.enqueue(&y);
        queue.enqueue(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.dequeue() returns " << data << " but not &x ( = " << &x << ") for a queue with 3 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        int z = 0;
        queue.enqueue(&x);
        queue.enqueue(&y);
        queue.enqueue(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        int *data2 = queue.dequeue();
        if (data == &x && data2 == &y) {
            std::cout << " passed.";
        } else {
            if (data != &x) {
                std::cout << " failed: queue.dequeue() returns " << data << " but not &x ( = " << &x << ") for a queue with 3 elements.";
            }
            if (data2 != &y) {
                std::cout << " failed: queue.dequeue() returns " << data << " but not &y ( = " << &y << ") for a queue with 2 elements.";
            }
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        const size_t size = queue.size();
        if (size == 0) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.size() returns " << size << " after popping an empty queue.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        queue.enqueue(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        const size_t size = queue.size();
        if (size == 0) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.size() returns " << size << " after popping a queue with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        queue.enqueue(&x);
        queue.enqueue(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        const size_t size = queue.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.size() returns " << size << " after popping a queue with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        int z = 0;
        queue.enqueue(&x);
        queue.enqueue(&y);
        queue.enqueue(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        const size_t size = queue.size();
        if (size == 2) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.size() returns " << size << " after popping a queue with 3 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        int z = 0;
        queue.enqueue(&x);
        queue.enqueue(&y);
        queue.enqueue(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        int *data2 = queue.dequeue();
        const size_t size = queue.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.size() returns " << size << " after popping a queue with 3 elements twice.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        queue.enqueue(&x);
        queue.enqueue(&y);
        queue.enqueue(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        queue.enqueue(&a);
        const bool isEmpty = queue.isEmpty();
        if (!isEmpty) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.isEmpty() returns " << isEmpty << " after a queue with 3 elements is dequeued then enqueued.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        queue.enqueue(&x);
        queue.enqueue(&y);
        queue.enqueue(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        queue.enqueue(&a);
        const size_t size = queue.size();
        if (size == 3) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.size() returns " << size << " after a queue with 3 elements is dequeued then enqueued.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        queue.enqueue(&x);
        queue.enqueue(&y);
        queue.enqueue(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        queue.enqueue(&a);
        int *data2 = queue.peek();
        if (data2 == &y) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.peek() returns " << data << " but not &y ( = " << &y << ") after a queue with 3 elements is dequeued then enqueued.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        queue.enqueue(&x);
        queue.enqueue(&y);
        queue.enqueue(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        queue.enqueue(&a);
        int *data2 = queue.dequeue();
        if (data2 == &y) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.dequeue() returns " << data << " but not &y ( = " << &y << ") after a queue with 3 elements is dequeued then enqueued.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        queue.enqueue(&x);
        queue.enqueue(&y);
        queue.enqueue(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        queue.enqueue(&a);
        int *data2 = queue.dequeue();
        int *data3 = queue.dequeue();
        int *data4 = queue.dequeue();
        const bool isEmpty = queue.isEmpty();
        if (isEmpty) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: queue.isEmpty() returns " << isEmpty << " but all elements are dequeued after enqueued to a queue.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        LinkedQueue<int> queue;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        queue.enqueue(&x);
        queue.enqueue(&y);
        queue.enqueue(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = queue.dequeue();
        queue.enqueue(&a);
        int *data2 = queue.dequeue();
        int *data3 = queue.dequeue();
        int *data4 = queue.dequeue();
        bool passed = true;
        if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
            std::cout << " failed: queue.pop() returns wrong addresses or in wrong order.";
            passed = false;
        }
        const bool isEmpty = queue.isEmpty();
        if (!isEmpty) {
            std::cout << " failed: queue.isEmpty() returns false for a queue that is dequeued till empty.";
            passed = false;
        }
        const size_t size = queue.size();
        if (size != 0) {
            std::cout << " failed: queue.size() returns " << size << " instead of 0 for a queue that is dequeued till empty.";
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