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

#include "LeakCheckedTest.h"

#include "../../../src/structures/heaps/MaxArrayHeap.h"

using yh::structures::heaps::MaxArrayHeap;

class MaxArrayHeapTest : public tests::LeakCheckedTest {};

TEST_F(MaxArrayHeapTest, IsEmptyForEmptyHeap) {
    MaxArrayHeap<int> heap(4);
    EXPECT_TRUE(heap.isEmpty());
}

TEST_F(MaxArrayHeapTest, IsNotEmptyFor1ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    EXPECT_FALSE(heap.isEmpty());
}

TEST_F(MaxArrayHeapTest, IsNotEmptyFor2ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    EXPECT_FALSE(heap.isEmpty());
}

TEST_F(MaxArrayHeapTest, SizeIs0ForEmptyHeap) {
    MaxArrayHeap<int> heap(4);
    EXPECT_EQ(heap.size(), 0u);
}

TEST_F(MaxArrayHeapTest, SizeIs1For1ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    EXPECT_EQ(heap.size(), 1u);
}

TEST_F(MaxArrayHeapTest, SizeIs2For2ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    EXPECT_EQ(heap.size(), 2u);
}

TEST_F(MaxArrayHeapTest, SizeIs3For3ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    EXPECT_EQ(heap.size(), 3u);
}

TEST_F(MaxArrayHeapTest, SizeIs4For4ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.insert(&a);
    EXPECT_EQ(heap.size(), 4u);
}

TEST_F(MaxArrayHeapTest, PeekingGivesNullptrForEmptyHeap) {
    MaxArrayHeap<int> heap(4);
    EXPECT_EQ(heap.peekMax(), nullptr);
}

TEST_F(MaxArrayHeapTest, PeekingGivesRootElementFor1ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    EXPECT_EQ(heap.peekMax(), &x);
}

TEST_F(MaxArrayHeapTest, PeekingGivesRootElementFor2ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    EXPECT_EQ(heap.peekMax(), &x);
}

TEST_F(MaxArrayHeapTest, PeekingGivesRootElementFor3ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    EXPECT_EQ(heap.peekMax(), &x);
}

TEST_F(MaxArrayHeapTest, RemovingGivesNullptrForEmptyHeap) {
    MaxArrayHeap<int> heap(4);
    EXPECT_EQ(heap.removeMax(), nullptr);
}

TEST_F(MaxArrayHeapTest, RemovingGivesRootElementFor1ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    EXPECT_EQ(heap.removeMax(), &x);
}

TEST_F(MaxArrayHeapTest, RemovingGivesRootElementFor2ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    EXPECT_EQ(heap.removeMax(), &x);
}

TEST_F(MaxArrayHeapTest, RemovingGivesRootElementFor3ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    EXPECT_EQ(heap.removeMax(), &x);
}

TEST_F(MaxArrayHeapTest, RemovingTwiceGivesRootElementFor3ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    EXPECT_EQ(heap.removeMax(), &x);
    EXPECT_EQ(heap.removeMax(), &z);
}

TEST_F(MaxArrayHeapTest, SizeIs0AfterRemovingFromEmptyHeap) {
    MaxArrayHeap<int> heap(4);
    heap.removeMax();
    EXPECT_EQ(heap.size(), 0u);
}

TEST_F(MaxArrayHeapTest, SizeIs0AfterRemovingFrom1ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    heap.removeMax();
    EXPECT_EQ(heap.size(), 0u);
}

TEST_F(MaxArrayHeapTest, SizeIs1AfterRemovingFrom2ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    heap.removeMax();
    EXPECT_EQ(heap.size(), 1u);
}

TEST_F(MaxArrayHeapTest, SizeIs2AfterRemovingFrom3ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMax();
    EXPECT_EQ(heap.size(), 2u);
}

TEST_F(MaxArrayHeapTest, SizeIs1AfterRemovingTwiceFrom3ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMax();
    EXPECT_EQ(heap.size(), 2u);
    heap.removeMax();
    EXPECT_EQ(heap.size(), 1u);
}

TEST_F(MaxArrayHeapTest, IsNotEmptyFor3ElementHeapRemovedAndInserted) {
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
    EXPECT_FALSE(heap.isEmpty());
}

TEST_F(MaxArrayHeapTest, SizeIs3For3ElementHeapRemovedAndInserted) {
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
    EXPECT_EQ(heap.size(), 3u);
}

TEST_F(MaxArrayHeapTest, PeekingGivesRootElementFor3ElementHeapRemovedAndInserted) {
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
    EXPECT_EQ(heap.peekMax(), &z);
}

TEST_F(MaxArrayHeapTest, RemovingGivesRootElementFor3ElementHeapRemovedAndInserted) {
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
    EXPECT_EQ(heap.removeMax(), &z);
}

TEST_F(MaxArrayHeapTest, IsEmptyFor4ElementHeapRemovedAndInserted) {
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
    EXPECT_TRUE(heap.isEmpty());
}

TEST_F(MaxArrayHeapTest, OrderFor4ElementHeap) {
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
    EXPECT_EQ(data, &x);
    EXPECT_EQ(data2, &z);
    EXPECT_EQ(data3, &a);
    EXPECT_EQ(data4, &y);
    EXPECT_TRUE(heap.isEmpty());
    EXPECT_EQ(heap.size(), 0u);
}

TEST_F(MaxArrayHeapTest, IsNotFullForEmptyHeap) {
    MaxArrayHeap<int> heap(4);
    EXPECT_FALSE(heap.isFull());
}

TEST_F(MaxArrayHeapTest, IsNotFullFor1ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    EXPECT_FALSE(heap.isFull());
}

TEST_F(MaxArrayHeapTest, IsNotFullFor2ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    EXPECT_FALSE(heap.isFull());
}

TEST_F(MaxArrayHeapTest, IsNotFullFor3ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    EXPECT_FALSE(heap.isFull());
}

TEST_F(MaxArrayHeapTest, IsFullFor4ElementHeap) {
    MaxArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.insert(&a);
    EXPECT_TRUE(heap.isFull());
}
