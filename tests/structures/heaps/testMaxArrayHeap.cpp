/**
 * @file testMaxArrayHeap.cpp - Tests for max array heap.
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

#include "../../../src/structures/heaps/MaxArrayHeap.h"

#include <iostream>

using yh::structures::heaps::MaxArrayHeap;

int main() {
    std::cout << "Testing " << __FILE__ << std::endl;
    unsigned int failed_testcase_count = 0;
    size_t testcase_index = 0;

    {
        MaxArrayHeap<int> heap(4);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (heap.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.isEmpty() returns false for an empty heap.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        heap.insert(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!heap.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.isEmpty() returns true for a heap with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        heap.insert(&x);
        heap.insert(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!heap.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.isEmpty() returns true for a heap with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = heap.size();
        if (size == 0) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.size() returns " << size << " for an empty heap.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        heap.insert(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = heap.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.size() returns " << size << " for a heap with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        heap.insert(&x);
        heap.insert(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = heap.size();
        if (size == 2) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.size() returns " << size << " for a heap with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = heap.size();
        if (size == 3) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.size() returns " << size << " for a heap with 3 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        heap.insert(&a);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = heap.size();
        if (size == 4) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.size() returns " << size << " for a heap with 4 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.peekMax();
        if (data == nullptr) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.peekMax() returns " << data << " for an empty heap.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        heap.insert(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.peekMax();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.peekMax() returns " << data << " but not &x ( = " << &x << ") for a heap with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        heap.insert(&x);
        heap.insert(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.peekMax();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.peekMax() returns " << data << " but not &x ( = " << &x << ") for a heap with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.peekMax();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.peekMax() returns " << data << " but not &x ( = " << &x << ") for a heap with 3 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        if (data == nullptr) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.removeMax() returns " << data << " for an empty heap.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        heap.insert(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.removeMax() returns " << data << " but not &x ( = " << &x << ") for a heap with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        heap.insert(&x);
        heap.insert(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.removeMax() returns " << data << " but not &x ( = " << &x << ") for a heap with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        if (data == &x) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.removeMax() returns " << data << " but not &x ( = " << &x << ") for a heap with 3 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        int *data2 = heap.removeMax();
        if (data == &x && data2 == &z) {
            std::cout << " passed.";
        } else {
            if (data != &x) {
                std::cout << " failed: heap.removeMax() returns " << data << " but not &x ( = " << &x << ") for a heap with 3 elements.";
            }
            if (data2 != &z) {
                std::cout << " failed: heap.removeMax() returns " << data << " but not &z ( = " << &z << ") for a heap with 2 elements.";
            }
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        const size_t size = heap.size();
        if (size == 0) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.size() returns " << size << " after popping an empty heap.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        heap.insert(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        const size_t size = heap.size();
        if (size == 0) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.size() returns " << size << " after popping a heap with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        heap.insert(&x);
        heap.insert(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        const size_t size = heap.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.size() returns " << size << " after popping a heap with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        const size_t size = heap.size();
        if (size == 2) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.size() returns " << size << " after popping a heap with 3 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        int *data2 = heap.removeMax();
        const size_t size = heap.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.size() returns " << size << " after popping a heap with 3 elements twice.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    // to review
    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        heap.insert(&a);
        const bool isEmpty = heap.isEmpty();
        if (!isEmpty) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.isEmpty() returns " << isEmpty << " after a heap with 3 elements is removed then inserted.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        heap.insert(&a);
        const size_t size = heap.size();
        if (size == 3) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.size() returns " << size << " after a heap with 3 elements is removed then inserted.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        heap.insert(&a);
        int *data2 = heap.peekMax();
        if (data2 == &z) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.peekMax() returns " << data << " but not &z ( = " << &z << ") after a heap with 3 elements is removed then inserted.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        heap.insert(&a);
        int *data2 = heap.removeMax();
        if (data2 == &z) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.removeMax() returns " << data << " but not &z ( = " << &z << ") after a heap with 3 elements is removed then inserted.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        heap.insert(&a);
        int *data2 = heap.removeMax();
        int *data3 = heap.removeMax();
        int *data4 = heap.removeMax();
        const bool isEmpty = heap.isEmpty();
        if (isEmpty) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.isEmpty() returns " << isEmpty << " but all elements are removed after inserted to a heap.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *data = heap.removeMax();
        heap.insert(&a);
        int *data2 = heap.removeMax();
        int *data3 = heap.removeMax();
        int *data4 = heap.removeMax();
        bool passed = true;
        if (data != &x || data2 != &z || data3 != &a || data4 != &y) {
            std::cout << " failed: heap.removeMax() returns wrong addresses or in wrong order.";
            passed = false;
        }
        const bool isEmpty = heap.isEmpty();
        if (!isEmpty) {
            std::cout << " failed: heap.isEmpty() returns false for a heap that is removed till empty.";
            passed = false;
        }
        const size_t size = heap.size();
        if (size != 0) {
            std::cout << " failed: heap.size() returns " << size << " instead of 0 for a heap that is removed till empty.";
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

    {
        MaxArrayHeap<int> heap(4);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!heap.isFull()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.isFull() returns true for an empty heap with capacity = 4.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        heap.insert(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!heap.isFull()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.isFull() returns true when 1 element is inserted to a heap with capacity = 4.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        heap.insert(&x);
        heap.insert(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!heap.isFull()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.isFull() returns true when 2 elements are inserted to a heap with capacity = 4.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!heap.isFull()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.isFull() returns true when 3 elements are inserted to a heap with capacity = 4.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        MaxArrayHeap<int> heap(4);
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        heap.insert(&x);
        heap.insert(&y);
        heap.insert(&z);
        heap.insert(&a);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (heap.isFull()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: heap.isFull() returns false when 4 elements are inserted to a heap with capacity = 4.";
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