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

#include "../../test.h"
#include "../../../src/structures/heaps/MaxArrayHeap.h"

#include <iostream>
#include <string>
#include <sstream>

using yh::structures::heaps::MaxArrayHeap;

TEST_BEGIN(heap_is_empty_for_empty_heap)
    MaxArrayHeap<int> heap(4);
    ASSERT_TRUE(heap.isEmpty());
TEST_END()

TEST_BEGIN(heap_is_not_empty_for_1_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    ASSERT_FALSE(heap.isEmpty());
TEST_END()

TEST_BEGIN(heap_is_not_empty_for_2_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    ASSERT_FALSE(heap.isEmpty());
TEST_END()

TEST_BEGIN(heap_size_is_0_for_empty_heap)
    MaxArrayHeap<int> heap(4);
    ASSERT_EQUALS(heap.size(), 0);
TEST_END()

TEST_BEGIN(heap_size_is_1_for_1_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    ASSERT_EQUALS(heap.size(), 1);
TEST_END()

TEST_BEGIN(heap_size_is_2_for_2_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    ASSERT_EQUALS(heap.size(), 2);
TEST_END()

TEST_BEGIN(heap_size_is_3_for_3_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    ASSERT_EQUALS(heap.size(), 3);
TEST_END()

TEST_BEGIN(heap_size_is_4_for_4_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.insert(&a);
    ASSERT_EQUALS(heap.size(), 4);
TEST_END()

TEST_BEGIN(heap_peeking_gives_nullptr_for_empty_heap)
    MaxArrayHeap<int> heap(4);
    ASSERT_IS_NULLPTR(heap.peekMax());
TEST_END()

TEST_BEGIN(heap_peeking_gives_root_element_for_1_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    ASSERT_EQUALS(heap.peekMax(), &x);
TEST_END()

TEST_BEGIN(heap_peeking_gives_root_element_for_2_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    ASSERT_EQUALS(heap.peekMax(), &x);
TEST_END()

TEST_BEGIN(heap_peeking_gives_root_element_for_3_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    ASSERT_EQUALS(heap.peekMax(), &x);
TEST_END()

TEST_BEGIN(heap_removing_gives_nullptr_for_empty_heap)
    MaxArrayHeap<int> heap(4);
    ASSERT_IS_NULLPTR(heap.removeMax());
TEST_END()

TEST_BEGIN(heap_removing_gives_root_element_for_1_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    ASSERT_EQUALS(heap.removeMax(), &x);
TEST_END()

TEST_BEGIN(heap_removing_gives_root_element_for_2_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    ASSERT_EQUALS(heap.removeMax(), &x);
TEST_END()

TEST_BEGIN(heap_removing_gives_root_element_for_3_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    ASSERT_EQUALS(heap.removeMax(), &x);
TEST_END()

TEST_BEGIN(heap_removing_twice_gives_root_element_for_3_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    ASSERT_EQUALS(heap.removeMax(), &x);
    ASSERT_EQUALS(heap.removeMax(), &z);
TEST_END()

TEST_BEGIN(heap_size_is_0_after_removing_from_empty_heap)
    MaxArrayHeap<int> heap(4);
    heap.removeMax();
    ASSERT_EQUALS(heap.size(), 0);
TEST_END()

TEST_BEGIN(heap_size_is_0_after_removing_from_1_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    heap.removeMax();
    ASSERT_EQUALS(heap.size(), 0);
TEST_END()

TEST_BEGIN(heap_size_is_1_after_removing_from_2_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    heap.removeMax();
    ASSERT_EQUALS(heap.size(), 1);
TEST_END()

TEST_BEGIN(heap_size_is_2_after_removing_from_3_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMax();
    ASSERT_EQUALS(heap.size(), 2);
TEST_END()

TEST_BEGIN(heap_size_is_1_after_removing_twice_from_3_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMax();
    ASSERT_EQUALS(heap.size(), 2);
    heap.removeMax();
    ASSERT_EQUALS(heap.size(), 1);
TEST_END()

TEST_BEGIN(heap_is_not_empty_for_3_element_heap_removed_and_inserted)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMax();
    heap.insert(&a);
    ASSERT_FALSE(heap.isEmpty());
TEST_END()

TEST_BEGIN(heap_size_is_3_for_3_element_heap_removed_and_inserted)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMax();
    heap.insert(&a);
    ASSERT_EQUALS(heap.size(), 3);
TEST_END()

TEST_BEGIN(heap_peeking_gives_root_element_for_3_element_heap_removed_and_inserted)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMax();
    heap.insert(&a);
    ASSERT_EQUALS(heap.peekMax(), &z);
TEST_END()

TEST_BEGIN(heap_removing_gives_root_element_for_3_element_heap_removed_and_inserted)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMax();
    heap.insert(&a);
    ASSERT_EQUALS(heap.removeMax(), &z);
TEST_END()

TEST_BEGIN(heap_is_empty_for_4_element_heap_removed_and_inserted)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMax();
    heap.insert(&a);
    heap.removeMax();
    heap.removeMax();
    heap.removeMax();
    ASSERT_TRUE(heap.isEmpty());
TEST_END()

TEST_BEGIN(heap_order_for_4_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *data = heap.removeMax();
    heap.insert(&a);
    int *data2 = heap.removeMax();
    int *data3 = heap.removeMax();
    int *data4 = heap.removeMax();
    ASSERT_EQUALS(data, &x);
    ASSERT_EQUALS(data2, &z);
    ASSERT_EQUALS(data3, &a);
    ASSERT_EQUALS(data4, &y);
    ASSERT_TRUE(heap.isEmpty());
    ASSERT_EQUALS(heap.size(), 0);
TEST_END()

TEST_BEGIN(heap_is_not_full_for_empty_heap)
    MaxArrayHeap<int> heap(4);
    ASSERT_FALSE(heap.isFull());
TEST_END()

TEST_BEGIN(heap_is_not_full_for_1_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    ASSERT_FALSE(heap.isFull());
TEST_END()

TEST_BEGIN(heap_is_not_full_for_2_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    ASSERT_FALSE(heap.isFull());
TEST_END()

TEST_BEGIN(heap_is_not_full_for_3_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    ASSERT_FALSE(heap.isFull());
TEST_END()

TEST_BEGIN(heap_is_full_for_4_element_heap)
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.insert(&a);
    ASSERT_TRUE(heap.isFull());
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

MAIN();
