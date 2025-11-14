/**
 * @file testMinArrayHeap.cpp - Tests for min array heap.
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
#include "../../../src/structures/heaps/MinArrayHeap.h"

#include <iostream>
#include <string>
#include <sstream>

using yh::structures::heaps::MinArrayHeap;

TEST_BEGIN(heap_is_empty_for_empty_heap)
    MinArrayHeap<int> heap(4);
    if (heap.isEmpty()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "heap.isEmpty() returns false for an empty heap.";
    }
TEST_END()

TEST_BEGIN(heap_is_not_empty_for_1_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    if (!heap.isEmpty()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "heap.isEmpty() returns true for a heap with 1 element.";
    }
TEST_END()

TEST_BEGIN(heap_is_not_empty_for_2_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    if (!heap.isEmpty()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "heap.isEmpty() returns true for a heap with 2 elements.";
    }
TEST_END()

TEST_BEGIN(heap_size_is_0_for_empty_heap)
    MinArrayHeap<int> heap(4);
    const size_t size = heap.size();
    if (size == 0) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.size() returns " << size << " for an empty heap.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_size_is_1_for_1_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    const size_t size = heap.size();
    if (size == 1) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.size() returns " << size << " for a heap with 1 element.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_size_is_2_for_2_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    const size_t size = heap.size();
    if (size == 2) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.size() returns " << size << " for a heap with 2 elements.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_size_is_3_for_3_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    const size_t size = heap.size();
    if (size == 3) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.size() returns " << size << " for a heap with 3 elements.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_size_is_4_for_4_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.insert(&a);
    const size_t size = heap.size();
    if (size == 4) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.size() returns " << size << " for a heap with 4 elements.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_peeking_gives_nullptr_for_empty_heap)
    MinArrayHeap<int> heap(4);
    int *data = heap.peekMin();
    if (data == nullptr) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.peekMin() returns " << data << " for an empty heap.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_peeking_gives_root_element_for_1_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    int *data = heap.peekMin();
    if (data == &x) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.peekMin() returns " << data << " but not &x ( = " << &x << ") for a heap with 1 element.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_peeking_gives_root_element_for_2_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    int *data = heap.peekMin();
    if (data == &y) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.peekMin() returns " << data << " but not &y ( = " << &y << ") for a heap with 2 elements.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_peeking_gives_root_element_for_3_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *data = heap.peekMin();
    if (data == &y) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.peekMin() returns " << data << " but not &y ( = " << &y << ") for a heap with 3 elements.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_removing_gives_nullptr_for_empty_heap)
    MinArrayHeap<int> heap(4);
    int *data = heap.removeMin();
    if (data == nullptr) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.removeMin() returns " << data << " for an empty heap.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_removing_gives_root_element_for_1_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    int *data = heap.removeMin();
    if (data == &x) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.removeMin() returns " << data << " but not &x ( = " << &x << ") for a heap with 1 element.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_removing_gives_root_element_for_2_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    int *data = heap.removeMin();
    if (data == &y) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.removeMin() returns " << data << " but not &y ( = " << &y << ") for a heap with 2 elements.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_removing_gives_root_element_for_3_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *data = heap.removeMin();
    if (data == &y) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.removeMin() returns " << data << " but not &y ( = " << &y << ") for a heap with 3 elements.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_removing_twice_gives_root_element_for_3_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *data = heap.removeMin();
    int *data2 = heap.removeMin();
    if (data == &y && data2 == &z) {
        result.passed = true;
    } else {
        if (data != &y) {
            result.passed = false;
            std::stringstream ss;
            ss << "heap.removeMin() returns " << data << " but not &y ( = " << &y << ") for a heap with 3 elements.";
            result.reason = ss.str();
        }
        if (data2 != &z) {
            result.passed = false;
            std::stringstream ss;
            ss << "heap.removeMin() returns " << data << " but not &z ( = " << &z << ") for a heap with 2 elements.";
            result.reason = ss.str();
        }
    }
TEST_END()

TEST_BEGIN(heap_size_is_0_after_removing_from_empty_heap)
    MinArrayHeap<int> heap(4);
    int *data = heap.removeMin();
    const size_t size = heap.size();
    if (size == 0) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.size() returns " << size << " after popping an empty heap.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_size_is_0_after_removing_from_1_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    int *data = heap.removeMin();
    const size_t size = heap.size();
    if (size == 0) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.size() returns " << size << " after popping a heap with 1 element.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_size_is_1_after_removing_from_2_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    int *data = heap.removeMin();
    const size_t size = heap.size();
    if (size == 1) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.size() returns " << size << " after popping a heap with 2 elements.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_size_is_2_after_removing_from_3_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *data = heap.removeMin();
    const size_t size = heap.size();
    if (size == 2) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.size() returns " << size << " after popping a heap with 3 elements.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_size_is_1_after_removing_twice_from_3_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *data = heap.removeMin();
    int *data2 = heap.removeMin();
    const size_t size = heap.size();
    if (size == 1) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.size() returns " << size << " after popping a heap with 3 elements twice.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_is_not_empty_for_3_element_heap_removed_and_inserted)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *data = heap.removeMin();
    heap.insert(&a);
    const bool isEmpty = heap.isEmpty();
    if (!isEmpty) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.isEmpty() returns " << isEmpty << " after a heap with 3 elements is removed then inserted.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_size_is_3_for_3_element_heap_removed_and_inserted)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *data = heap.removeMin();
    heap.insert(&a);
    const size_t size = heap.size();
    if (size == 3) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.size() returns " << size << " after a heap with 3 elements is removed then inserted.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_peeking_gives_root_element_for_3_element_heap_removed_and_inserted)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *data = heap.removeMin();
    heap.insert(&a);
    int *data2 = heap.peekMin();
    if (data2 == &a) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.peekMin() returns " << data << " but not &a ( = " << &a << ") after a heap with 3 elements is removed then inserted.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_removing_gives_root_element_for_3_element_heap_removed_and_inserted)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *data = heap.removeMin();
    heap.insert(&a);
    int *data2 = heap.removeMin();
    if (data2 == &a) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.removeMin() returns " << data << " but not &a ( = " << &a << ") after a heap with 3 elements is removed then inserted.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_is_empty_for_4_element_heap_removed_and_inserted)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *data = heap.removeMin();
    heap.insert(&a);
    int *data2 = heap.removeMin();
    int *data3 = heap.removeMin();
    int *data4 = heap.removeMin();
    const bool isEmpty = heap.isEmpty();
    if (isEmpty) {
        result.passed = true;
    } else {
        result.passed = false;
        std::stringstream ss;
        ss << "heap.isEmpty() returns " << isEmpty << " but all elements are removed after inserted to a heap.";
        result.reason = ss.str();
    }
TEST_END()

TEST_BEGIN(heap_order_for_4_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *data = heap.removeMin();
    heap.insert(&a);
    int *data2 = heap.removeMin();
    int *data3 = heap.removeMin();
    int *data4 = heap.removeMin();
    result.passed = true;
    std::stringstream ss;
    if (data != &y || data2 != &a || data3 != &z || data4 != &x) {
        ss << "heap.removeMin() returns wrong addresses or in wrong order.";
        result.passed = false;
    }
    const bool isEmpty = heap.isEmpty();
    if (!isEmpty) {
        ss << "heap.isEmpty() returns false for a heap that is removed till empty.";
        result.passed = false;
    }
    const size_t size = heap.size();
    if (size != 0) {
        ss << "heap.size() returns " << size << " instead of 0 for a heap that is removed till empty.";
        result.passed = false;
    }
    result.reason = ss.str();
TEST_END()

TEST_BEGIN(heap_is_not_full_for_empty_heap)
    MinArrayHeap<int> heap(4);
    if (!heap.isFull()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "heap.isFull() returns true for an empty heap with capacity = 4.";
    }
TEST_END()

TEST_BEGIN(heap_is_not_full_for_1_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    if (!heap.isFull()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "heap.isFull() returns true when 1 element is inserted to a heap with capacity = 4.";
    }
TEST_END()

TEST_BEGIN(heap_is_not_full_for_2_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    if (!heap.isFull()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "heap.isFull() returns true when 2 elements are inserted to a heap with capacity = 4.";
    }
TEST_END()

TEST_BEGIN(heap_is_not_full_for_3_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    if (!heap.isFull()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "heap.isFull() returns true when 3 elements are inserted to a heap with capacity = 4.";
    }
TEST_END()

TEST_BEGIN(heap_is_full_for_4_element_heap)
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.insert(&a);
    if (heap.isFull()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "heap.isFull() returns false when 4 elements are inserted to a heap with capacity = 4.";
    }
TEST_END()

const testfunc_t functions [] = {
    test_heap_is_empty_for_empty_heap,
    test_heap_is_not_empty_for_1_element_heap,
    test_heap_is_not_empty_for_2_element_heap,
    test_heap_size_is_0_for_empty_heap,
    test_heap_size_is_1_for_1_element_heap,
    test_heap_size_is_2_for_2_element_heap,
    test_heap_size_is_3_for_3_element_heap,
    test_heap_size_is_4_for_4_element_heap,
    test_heap_peeking_gives_nullptr_for_empty_heap,
    test_heap_peeking_gives_root_element_for_1_element_heap,
    test_heap_peeking_gives_root_element_for_2_element_heap,
    test_heap_peeking_gives_root_element_for_3_element_heap,
    test_heap_removing_gives_nullptr_for_empty_heap,
    test_heap_removing_gives_root_element_for_1_element_heap,
    test_heap_removing_gives_root_element_for_2_element_heap,
    test_heap_removing_gives_root_element_for_3_element_heap,
    test_heap_removing_twice_gives_root_element_for_3_element_heap,
    test_heap_size_is_0_after_removing_from_empty_heap,
    test_heap_size_is_0_after_removing_from_1_element_heap,
    test_heap_size_is_1_after_removing_from_2_element_heap,
    test_heap_size_is_2_after_removing_from_3_element_heap,
    test_heap_size_is_1_after_removing_twice_from_3_element_heap,
    test_heap_is_not_empty_for_3_element_heap_removed_and_inserted,
    test_heap_size_is_3_for_3_element_heap_removed_and_inserted,
    test_heap_peeking_gives_root_element_for_3_element_heap_removed_and_inserted,
    test_heap_removing_gives_root_element_for_3_element_heap_removed_and_inserted,
    test_heap_is_empty_for_4_element_heap_removed_and_inserted,
    test_heap_order_for_4_element_heap,
    test_heap_is_not_full_for_empty_heap,
    test_heap_is_not_full_for_1_element_heap,
    test_heap_is_not_full_for_2_element_heap,
    test_heap_is_not_full_for_3_element_heap,
    test_heap_is_full_for_4_element_heap,
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