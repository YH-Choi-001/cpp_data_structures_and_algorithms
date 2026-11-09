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

#include "LeakCheckedTest.h"

#include "../../../src/structures/heaps/MinArrayHeap.h"

using yh::structures::heaps::MinArrayHeap;

class MinArrayHeapTest : public tests::LeakCheckedTest {};

TEST_F(MinArrayHeapTest, IsEmptyForEmptyHeap) {
    MinArrayHeap<int> heap(4);
    EXPECT_TRUE(heap.isEmpty());
}

TEST_F(MinArrayHeapTest, IsNotEmptyFor1ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    EXPECT_FALSE(heap.isEmpty());
}

TEST_F(MinArrayHeapTest, IsNotEmptyFor2ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    EXPECT_FALSE(heap.isEmpty());
}

TEST_F(MinArrayHeapTest, SizeIs0ForEmptyHeap) {
    MinArrayHeap<int> heap(4);
    EXPECT_EQ(heap.size(), 0u);
}

TEST_F(MinArrayHeapTest, SizeIs1For1ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    EXPECT_EQ(heap.size(), 1u);
}

TEST_F(MinArrayHeapTest, SizeIs2For2ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    EXPECT_EQ(heap.size(), 2u);
}

TEST_F(MinArrayHeapTest, SizeIs3For3ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    EXPECT_EQ(heap.size(), 3u);
}

TEST_F(MinArrayHeapTest, SizeIs4For4ElementHeap) {
    MinArrayHeap<int> heap(4);
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

TEST_F(MinArrayHeapTest, PeekingGivesNullptrForEmptyHeap) {
    MinArrayHeap<int> heap(4);
    EXPECT_EQ(heap.peekMin(), nullptr);
}

TEST_F(MinArrayHeapTest, PeekingGivesRootElementFor1ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    EXPECT_EQ(heap.peekMin(), &x);
}

TEST_F(MinArrayHeapTest, PeekingGivesRootElementFor2ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    EXPECT_EQ(heap.peekMin(), &y);
}

TEST_F(MinArrayHeapTest, PeekingGivesRootElementFor3ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    EXPECT_EQ(heap.peekMin(), &y);
}

TEST_F(MinArrayHeapTest, RemovingGivesNullptrForEmptyHeap) {
    MinArrayHeap<int> heap(4);
    EXPECT_EQ(heap.removeMin(), nullptr);
}

TEST_F(MinArrayHeapTest, RemovingGivesRootElementFor1ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    EXPECT_EQ(heap.removeMin(), &x);
}

TEST_F(MinArrayHeapTest, RemovingGivesRootElementFor2ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    EXPECT_EQ(heap.removeMin(), &y);
}

TEST_F(MinArrayHeapTest, RemovingGivesRootElementFor3ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    EXPECT_EQ(heap.removeMin(), &y);
}

TEST_F(MinArrayHeapTest, RemovingTwiceGivesRootElementFor3ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    EXPECT_EQ(heap.removeMin(), &y);
    EXPECT_EQ(heap.removeMin(), &z);
}

TEST_F(MinArrayHeapTest, SizeIs0AfterRemovingFromEmptyHeap) {
    MinArrayHeap<int> heap(4);
    heap.removeMin();
    EXPECT_EQ(heap.size(), 0u);
}

TEST_F(MinArrayHeapTest, SizeIs0AfterRemovingFrom1ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    heap.removeMin();
    EXPECT_EQ(heap.size(), 0u);
}

TEST_F(MinArrayHeapTest, SizeIs1AfterRemovingFrom2ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    heap.removeMin();
    EXPECT_EQ(heap.size(), 1u);
}

TEST_F(MinArrayHeapTest, SizeIs2AfterRemovingFrom3ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMin();
    EXPECT_EQ(heap.size(), 2u);
}

TEST_F(MinArrayHeapTest, SizeIs1AfterRemovingTwiceFrom3ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMin();
    EXPECT_EQ(heap.size(), 2u);
    heap.removeMin();
    EXPECT_EQ(heap.size(), 1u);
}

TEST_F(MinArrayHeapTest, IsNotEmptyFor3ElementHeapRemovedAndInserted) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMin();
    heap.insert(&a);
    EXPECT_FALSE(heap.isEmpty());
}

TEST_F(MinArrayHeapTest, SizeIs3For3ElementHeapRemovedAndInserted) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMin();
    heap.insert(&a);
    EXPECT_EQ(heap.size(), 3u);
}

TEST_F(MinArrayHeapTest, PeekingGivesRootElementFor3ElementHeapRemovedAndInserted) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMin();
    heap.insert(&a);
    EXPECT_EQ(heap.peekMin(), &a);
}

TEST_F(MinArrayHeapTest, RemovingGivesRootElementFor3ElementHeapRemovedAndInserted) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMin();
    heap.insert(&a);
    EXPECT_EQ(heap.removeMin(), &a);
}

TEST_F(MinArrayHeapTest, IsEmptyFor4ElementHeapRemovedAndInserted) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    heap.removeMin();
    heap.insert(&a);
    heap.removeMin();
    heap.removeMin();
    heap.removeMin();
    EXPECT_TRUE(heap.isEmpty());
}

TEST_F(MinArrayHeapTest, OrderFor4ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    int *const data = heap.removeMin();
    heap.insert(&a);
    int *const data2 = heap.removeMin();
    int *const data3 = heap.removeMin();
    int *const data4 = heap.removeMin();
    EXPECT_EQ(data, &y);
    EXPECT_EQ(data2, &a);
    EXPECT_EQ(data3, &z);
    EXPECT_EQ(data4, &x);
    EXPECT_TRUE(heap.isEmpty());
    EXPECT_EQ(heap.size(), 0u);    
}

TEST_F(MinArrayHeapTest, IsNotFullForEmptyHeap) {
    MinArrayHeap<int> heap(4);
    EXPECT_FALSE(heap.isFull());
}

TEST_F(MinArrayHeapTest, IsNotFullFor1ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    heap.insert(&x);
    EXPECT_FALSE(heap.isFull());
}

TEST_F(MinArrayHeapTest, IsNotFullFor2ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    heap.insert(&x);
    heap.insert(&y);
    EXPECT_FALSE(heap.isFull());
}

TEST_F(MinArrayHeapTest, IsNotFullFor3ElementHeap) {
    MinArrayHeap<int> heap(4);
    int x = 35;
    int y = -12;
    int z = 0;
    heap.insert(&x);
    heap.insert(&y);
    heap.insert(&z);
    EXPECT_FALSE(heap.isFull());
}

TEST_F(MinArrayHeapTest, IsFullFor4ElementHeap) {
    MinArrayHeap<int> heap(4);
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
