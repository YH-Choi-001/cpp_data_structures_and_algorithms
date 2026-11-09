/**
 * @file testList.cpp - Typed tests run against every list implementation.
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

#include <string>
#include <type_traits>

#include "LeakCheckedTest.h"

#include "../../../src/structures/lists/ArrayList.h"
#include "../../../src/structures/lists/DoublyLinkedList.h"
#include "../../../src/structures/lists/SinglyLinkedList.h"

using yh::structures::lists::ArrayList;
using yh::structures::lists::DoublyLinkedList;
using yh::structures::lists::List;
using yh::structures::lists::SinglyLinkedList;

template <typename ListT>
class ListTest : public tests::LeakCheckedTest {};

using ListTypes = ::testing::Types<
    ArrayList<int>,
    SinglyLinkedList<int>,
    DoublyLinkedList<int>
>;

struct ListTypeNames {
    template <typename T>
    static std::string GetName(int) {
        if (std::is_same<T, ArrayList<int>>::value) return "ArrayList";
        if (std::is_same<T, SinglyLinkedList<int>>::value) return "SinglyLinkedList";
        if (std::is_same<T, DoublyLinkedList<int>>::value) return "DoublyLinkedList";
        return "Unknown";
    }
};

TYPED_TEST_SUITE(ListTest, ListTypes, ListTypeNames);

TYPED_TEST(ListTest, IsEmptyForEmptyList) {
    TypeParam list;
    EXPECT_TRUE(list.isEmpty());
}

TYPED_TEST(ListTest, IsNotEmptyFor1ElementListAddHead) {
    TypeParam list;
    int x = 35;
    list.addHead(&x);
    EXPECT_FALSE(list.isEmpty());
}

TYPED_TEST(ListTest, IsNotEmptyFor1ElementListAddTail) {
    TypeParam list;
    int x = 35;
    list.addTail(&x);
    EXPECT_FALSE(list.isEmpty());
}

TYPED_TEST(ListTest, IsNotEmptyFor1ElementListInsert) {
    TypeParam list;
    int x = 35;
    list.insert(0, &x);
    EXPECT_FALSE(list.isEmpty());
}

TYPED_TEST(ListTest, IsEmptyFor1ElementListInsertInvalidIndex) {
    TypeParam list;
    int x = 35;
    list.insert(1, &x);
    EXPECT_TRUE(list.isEmpty());
}

TYPED_TEST(ListTest, IsNotEmptyFor2ElementListAddHead) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.addHead(&x);
    list.addHead(&y);
    EXPECT_FALSE(list.isEmpty());
}

TYPED_TEST(ListTest, IsNotEmptyFor2ElementListAddHeadThenAddTail) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.addHead(&x);
    list.addTail(&y);
    EXPECT_FALSE(list.isEmpty());
}

TYPED_TEST(ListTest, IsNotEmptyFor2ElementListAddTailThenAddHead) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.addTail(&x);
    list.addHead(&y);
    EXPECT_FALSE(list.isEmpty());
}

TYPED_TEST(ListTest, IsNotEmptyFor2ElementListAddTail) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.addTail(&x);
    list.addTail(&y);
    EXPECT_FALSE(list.isEmpty());
}

TYPED_TEST(ListTest, IsNotEmptyFor2ElementListInsert0ThenInsert0) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(0, &y);
    EXPECT_FALSE(list.isEmpty());
}

TYPED_TEST(ListTest, IsNotEmptyFor2ElementListInsert0ThenInsert1) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(1, &y);
    EXPECT_FALSE(list.isEmpty());
}

TYPED_TEST(ListTest, IsNotEmptyFor1ElementListInsertValidIndexThenInsertInvalidIndex) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(2, &y);
    EXPECT_FALSE(list.isEmpty());
}

TYPED_TEST(ListTest, IsNotEmptyFor1ElementListInsertInvalidIndexThenInsertValidIndex) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.insert(1, &x);
    list.insert(0, &y);
    EXPECT_FALSE(list.isEmpty());
}

TYPED_TEST(ListTest, SizeIs0ForEmptyList) {
    TypeParam list;
    EXPECT_EQ(list.size(), 0u);
}

TYPED_TEST(ListTest, SizeIs1For1ElementListAddHead) {
    TypeParam list;
    int x = 35;
    list.addHead(&x);
    EXPECT_EQ(list.size(), 1u);
}

TYPED_TEST(ListTest, SizeIs1For1ElementListAddTail) {
    TypeParam list;
    int x = 35;
    list.addTail(&x);
    EXPECT_EQ(list.size(), 1u);
}

TYPED_TEST(ListTest, SizeIs1For1ElementListInsert) {
    TypeParam list;
    int x = 35;
    list.insert(0, &x);
    EXPECT_EQ(list.size(), 1u);
}

TYPED_TEST(ListTest, SizeIs1For1ElementListInsertInvalidIndex) {
    TypeParam list;
    int x = 35;
    list.insert(1, &x);
    EXPECT_EQ(list.size(), 0u);
}

TYPED_TEST(ListTest, SizeIs2For2ElementListAddHead) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.addHead(&x);
    list.addHead(&y);
    EXPECT_EQ(list.size(), 2u);
}

TYPED_TEST(ListTest, SizeIs2For2ElementListAddHeadThenAddTail) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.addHead(&x);
    list.addTail(&y);
    EXPECT_EQ(list.size(), 2u);
}

TYPED_TEST(ListTest, SizeIs2For2ElementListAddTailThenAddHead) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.addTail(&x);
    list.addHead(&y);
    EXPECT_EQ(list.size(), 2u);
}

TYPED_TEST(ListTest, SizeIs2For2ElementListAddTail) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.addTail(&x);
    list.addTail(&y);
    EXPECT_EQ(list.size(), 2u);
}

TYPED_TEST(ListTest, SizeIs2For2ElementListInsert0ThenInsert0) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(0, &y);
    EXPECT_EQ(list.size(), 2u);
}

TYPED_TEST(ListTest, SizeIs2For2ElementListInsert0ThenInsert1) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(1, &y);
    EXPECT_EQ(list.size(), 2u);
}

TYPED_TEST(ListTest, SizeIs2For2ElementListInsertValidIndexThenInsertInvalidIndex) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(2, &y);
    EXPECT_EQ(list.size(), 1u);
}

TYPED_TEST(ListTest, SizeIs2For2ElementListInsertInvalidIndexThenInsertValidIndex) {
    TypeParam list;
    int x = 35;
    int y = -12;
    list.insert(1, &x);
    list.insert(0, &y);
    EXPECT_EQ(list.size(), 1u);
}

TYPED_TEST(ListTest, AddHeadHeadHead) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addHead(&x);
    list.addHead(&y);
    list.addHead(&z);
    EXPECT_EQ(list.size(), 3u);
    EXPECT_EQ(list.get(0), &z);
    EXPECT_EQ(list.get(1), &y);
    EXPECT_EQ(list.get(2), &x);
}

TYPED_TEST(ListTest, AddTailTailTail) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addTail(&x);
    list.addTail(&y);
    list.addTail(&z);
    EXPECT_EQ(list.size(), 3u);
    EXPECT_EQ(list.get(0), &x);
    EXPECT_EQ(list.get(1), &y);
    EXPECT_EQ(list.get(2), &z);
}

TYPED_TEST(ListTest, AddHeadTailHead) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addHead(&x);
    list.addTail(&y);
    list.addHead(&z);
    EXPECT_EQ(list.size(), 3u);
    EXPECT_EQ(list.get(0), &z);
    EXPECT_EQ(list.get(1), &x);
    EXPECT_EQ(list.get(2), &y);
}

TYPED_TEST(ListTest, AddTailHeadTail) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addTail(&x);
    list.addHead(&y);
    list.addTail(&z);
    EXPECT_EQ(list.size(), 3u);
    EXPECT_EQ(list.get(0), &y);
    EXPECT_EQ(list.get(1), &x);
    EXPECT_EQ(list.get(2), &z);
}

TYPED_TEST(ListTest, AddHeadHeadTail) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addHead(&x);
    list.addHead(&y);
    list.addTail(&z);
    EXPECT_EQ(list.size(), 3u);
    EXPECT_EQ(list.get(0), &y);
    EXPECT_EQ(list.get(1), &x);
    EXPECT_EQ(list.get(2), &z);
}

TYPED_TEST(ListTest, AddHeadTailTail) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addHead(&x);
    list.addTail(&y);
    list.addTail(&z);
    EXPECT_EQ(list.size(), 3u);
    EXPECT_EQ(list.get(0), &x);
    EXPECT_EQ(list.get(1), &y);
    EXPECT_EQ(list.get(2), &z);
}

TYPED_TEST(ListTest, AddTailTailHead) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addTail(&x);
    list.addTail(&y);
    list.addHead(&z);
    EXPECT_EQ(list.size(), 3u);
    EXPECT_EQ(list.get(0), &z);
    EXPECT_EQ(list.get(1), &x);
    EXPECT_EQ(list.get(2), &y);
}

TYPED_TEST(ListTest, AddTailHeadHead) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addTail(&x);
    list.addHead(&y);
    list.addHead(&z);
    EXPECT_EQ(list.size(), 3u);
    EXPECT_EQ(list.get(0), &z);
    EXPECT_EQ(list.get(1), &y);
    EXPECT_EQ(list.get(2), &x);
}

TYPED_TEST(ListTest, AddTailTailTailTail) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.addTail(&x);
    list.addTail(&y);
    list.addTail(&z);
    list.addTail(&a);
    EXPECT_EQ(list.size(), 4u);
    EXPECT_EQ(list.get(0), &x);
    EXPECT_EQ(list.get(1), &y);
    EXPECT_EQ(list.get(2), &z);
    EXPECT_EQ(list.get(3), &a);
}

TYPED_TEST(ListTest, InsertTailTailTailTail) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.insert(0, &x);
    list.insert(1, &y);
    list.insert(2, &z);
    list.insert(3, &a);
    EXPECT_EQ(list.size(), 4u);
    EXPECT_EQ(list.get(0), &x);
    EXPECT_EQ(list.get(1), &y);
    EXPECT_EQ(list.get(2), &z);
    EXPECT_EQ(list.get(3), &a);
}

TYPED_TEST(ListTest, InsertTailTailMidHead) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.insert(0, &y);
    list.insert(1, &a);
    list.insert(1, &z);
    list.insert(0, &x);
    EXPECT_EQ(list.size(), 4u);
    EXPECT_EQ(list.get(0), &x);
    EXPECT_EQ(list.get(1), &y);
    EXPECT_EQ(list.get(2), &z);
    EXPECT_EQ(list.get(3), &a);
}

TYPED_TEST(ListTest, InsertHeadHeadMidMid) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.insert(0, &a);
    list.insert(0, &x);
    list.insert(1, &y);
    list.insert(2, &z);
    EXPECT_EQ(list.size(), 4u);
    EXPECT_EQ(list.get(0), &x);
    EXPECT_EQ(list.get(1), &y);
    EXPECT_EQ(list.get(2), &z);
    EXPECT_EQ(list.get(3), &a);
}

TYPED_TEST(ListTest, InsertTailTailMidMid) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.insert(0, &x);
    list.insert(1, &a);
    list.insert(1, &y);
    list.insert(2, &z);
    EXPECT_EQ(list.size(), 4u);
    EXPECT_EQ(list.get(0), &x);
    EXPECT_EQ(list.get(1), &y);
    EXPECT_EQ(list.get(2), &z);
    EXPECT_EQ(list.get(3), &a);
}

TYPED_TEST(ListTest, HeadOperations) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.addHead(&x);
    list.addHead(&y);
    list.addHead(&z);
    int *const dataGet = list.getHead();
    int *const data = list.removeHead();
    list.addHead(&a);
    int *const dataGet2 = list.getHead();
    int *const data2 = list.removeHead();
    int *const dataGet3 = list.getHead();
    int *const data3 = list.removeHead();
    int *const dataGet4 = list.getHead();
    int *const data4 = list.removeHead();

    EXPECT_EQ(data, &z);
    EXPECT_EQ(data2, &a);
    EXPECT_EQ(data3, &y);
    EXPECT_EQ(data4, &x);

    EXPECT_EQ(data, dataGet);
    EXPECT_EQ(data2, dataGet2);
    EXPECT_EQ(data3, dataGet3);
    EXPECT_EQ(data4, dataGet4);

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0u);
}

TYPED_TEST(ListTest, TailOperations) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.addTail(&x);
    list.addTail(&y);
    list.addTail(&z);
    int *const dataGet = list.getTail();
    int *const data = list.removeTail();
    list.addTail(&a);
    int *const dataGet2 = list.getTail();
    int *const data2 = list.removeTail();
    int *const dataGet3 = list.getTail();
    int *const data3 = list.removeTail();
    int *const dataGet4 = list.getTail();
    int *const data4 = list.removeTail();

    EXPECT_EQ(data, &z);
    EXPECT_EQ(data2, &a);
    EXPECT_EQ(data3, &y);
    EXPECT_EQ(data4, &x);

    EXPECT_EQ(data, dataGet);
    EXPECT_EQ(data2, dataGet2);
    EXPECT_EQ(data3, dataGet3);
    EXPECT_EQ(data4, dataGet4);

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0u);
}

TYPED_TEST(ListTest, AddHeadRemoveTailOperations) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.addHead(&x);
    list.addHead(&y);
    list.addHead(&z);
    int *const dataGet = list.getTail();
    int *const data = list.removeTail();
    list.addHead(&a);
    int *const dataGet2 = list.getTail();
    int *const data2 = list.removeTail();
    int *const dataGet3 = list.getTail();
    int *const data3 = list.removeTail();
    int *const dataGet4 = list.getTail();
    int *const data4 = list.removeTail();

    EXPECT_EQ(data, &x);
    EXPECT_EQ(data2, &y);
    EXPECT_EQ(data3, &z);
    EXPECT_EQ(data4, &a);

    EXPECT_EQ(data, dataGet);
    EXPECT_EQ(data2, dataGet2);
    EXPECT_EQ(data3, dataGet3);
    EXPECT_EQ(data4, dataGet4);

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0u);
}

TYPED_TEST(ListTest, AddTailRemoveHeadOperations) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.addTail(&x);
    list.addTail(&y);
    list.addTail(&z);
    int *const dataGet = list.getHead();
    int *const data = list.removeHead();
    list.addTail(&a);
    int *const dataGet2 = list.getHead();
    int *const data2 = list.removeHead();
    int *const dataGet3 = list.getHead();
    int *const data3 = list.removeHead();
    int *const dataGet4 = list.getHead();
    int *const data4 = list.removeHead();

    EXPECT_EQ(data, &x);
    EXPECT_EQ(data2, &y);
    EXPECT_EQ(data3, &z);
    EXPECT_EQ(data4, &a);

    EXPECT_EQ(data, dataGet);
    EXPECT_EQ(data2, dataGet2);
    EXPECT_EQ(data3, dataGet3);
    EXPECT_EQ(data4, dataGet4);

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0u);
}

TYPED_TEST(ListTest, MixedEndsAddRemoveOperations1) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.addHead(&x);
    list.addTail(&y);
    list.addHead(&z);
    int *const dataGet = list.getHead();
    int *const data = list.removeHead();
    list.addTail(&a);
    int *const dataGet2 = list.getTail();
    int *const data2 = list.removeTail();
    int *const dataGet3 = list.getHead();
    int *const data3 = list.removeHead();
    int *const dataGet4 = list.getTail();
    int *const data4 = list.removeTail();

    EXPECT_EQ(data, &z);
    EXPECT_EQ(data2, &a);
    EXPECT_EQ(data3, &x);
    EXPECT_EQ(data4, &y);

    EXPECT_EQ(data, dataGet);
    EXPECT_EQ(data2, dataGet2);
    EXPECT_EQ(data3, dataGet3);
    EXPECT_EQ(data4, dataGet4);

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0u);
}

TYPED_TEST(ListTest, MixedEndsAddRemoveOperations2) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.addHead(&x);
    list.addTail(&y);
    list.addHead(&z);
    int *const dataGet = list.getTail();
    int *const data = list.removeTail();
    list.addTail(&a);
    int *const dataGet2 = list.getHead();
    int *const data2 = list.removeHead();
    int *const dataGet3 = list.getTail();
    int *const data3 = list.removeTail();
    int *const dataGet4 = list.getHead();
    int *const data4 = list.removeHead();

    EXPECT_EQ(data, &y);
    EXPECT_EQ(data2, &z);
    EXPECT_EQ(data3, &a);
    EXPECT_EQ(data4, &x);

    EXPECT_EQ(data, dataGet);
    EXPECT_EQ(data2, dataGet2);
    EXPECT_EQ(data3, dataGet3);
    EXPECT_EQ(data4, dataGet4);

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0u);
}

TYPED_TEST(ListTest, RemoveOperations) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.insert(0, &x);
    EXPECT_EQ(list.size(), 1u);
    list.insert(1, &z);
    EXPECT_EQ(list.size(), 2u);
    list.insert(1, &y);
    EXPECT_EQ(list.size(), 3u);
    int *const dataGet = list.get(1);
    EXPECT_EQ(list.size(), 3u);
    int *const data = list.remove(1);
    EXPECT_EQ(list.size(), 2u);
    list.insert(1, &a);
    EXPECT_EQ(list.size(), 3u);
    int *const dataGet2 = list.get(1);
    EXPECT_EQ(list.size(), 3u);
    int *const data2 = list.remove(1);
    EXPECT_EQ(list.size(), 2u);
    int *const dataGet3 = list.get(1);
    EXPECT_EQ(list.size(), 2u);
    int *const data3 = list.remove(1);
    EXPECT_EQ(list.size(), 1u);
    int *const dataGet4 = list.get(0);
    EXPECT_EQ(list.size(), 1u);
    int *const data4 = list.remove(0);
    EXPECT_EQ(list.size(), 0u);

    EXPECT_EQ(data, &y);
    EXPECT_EQ(data2, &a);
    EXPECT_EQ(data3, &z);
    EXPECT_EQ(data4, &x);

    EXPECT_EQ(data, dataGet);
    EXPECT_EQ(data2, dataGet2);
    EXPECT_EQ(data3, dataGet3);
    EXPECT_EQ(data4, dataGet4);

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0u);
}

TYPED_TEST(ListTest, SetOperations1) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    int j = 15;
    int k = 8;
    int l = 6;
    int m = 39;
    list.insert(0, &x);
    list.insert(1, &y);
    list.insert(2, &z);
    list.insert(3, &a);
    int *const dataGet = list.get(0);
    int *const data = list.set(0, &j);
    EXPECT_EQ(list.size(), 4u);
    int *const dataGet2 = list.get(1);
    int *const data2 = list.set(1, &k);
    EXPECT_EQ(list.size(), 4u);
    int *const dataGet3 = list.get(2);
    int *const data3 = list.set(2, &l);
    EXPECT_EQ(list.size(), 4u);
    int *const dataGet4 = list.get(3);
    int *const data4 = list.set(3, &m);
    EXPECT_EQ(list.size(), 4u);

    EXPECT_EQ(data, &x);
    EXPECT_EQ(data2, &y);
    EXPECT_EQ(data3, &z);
    EXPECT_EQ(data4, &a);

    EXPECT_EQ(data, dataGet);
    EXPECT_EQ(data2, dataGet2);
    EXPECT_EQ(data3, dataGet3);
    EXPECT_EQ(data4, dataGet4);

    EXPECT_EQ(list.get(0), &j);
    EXPECT_EQ(list.get(1), &k);
    EXPECT_EQ(list.get(2), &l);
    EXPECT_EQ(list.get(3), &m);
}

TYPED_TEST(ListTest, SetOperations2) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    int j = 15;
    int k = 8;
    int l = 6;
    int m = 39;
    list.insert(0, &x);
    list.insert(1, &y);
    list.insert(2, &z);
    list.insert(3, &a);
    int *const dataGet = list.get(0);
    int *const data = list.set(0, &j);
    EXPECT_EQ(list.size(), 4u);
    int *const dataGet3 = list.get(2);
    int *const data3 = list.set(2, &l);
    EXPECT_EQ(list.size(), 4u);
    int *const dataGet4 = list.get(3);
    int *const data4 = list.set(3, &m);
    EXPECT_EQ(list.size(), 4u);
    int *const dataGet2 = list.get(1);
    int *const data2 = list.set(1, &k);
    EXPECT_EQ(list.size(), 4u);

    EXPECT_EQ(data, &x);
    EXPECT_EQ(data2, &y);
    EXPECT_EQ(data3, &z);
    EXPECT_EQ(data4, &a);

    EXPECT_EQ(data, dataGet);
    EXPECT_EQ(data2, dataGet2);
    EXPECT_EQ(data3, dataGet3);
    EXPECT_EQ(data4, dataGet4);

    EXPECT_EQ(list.get(0), &j);
    EXPECT_EQ(list.get(1), &k);
    EXPECT_EQ(list.get(2), &l);
    EXPECT_EQ(list.get(3), &m);
}

TYPED_TEST(ListTest, SetOperations3) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    int j = 15;
    int k = 8;
    int l = 6;
    int m = 39;
    list.insert(0, &x);
    list.insert(1, &y);
    list.insert(2, &z);
    list.insert(3, &a);
    int *const dataGet4 = list.get(3);
    int *const data4 = list.set(3, &m);
    EXPECT_EQ(list.size(), 4u);
    int *const dataGet = list.get(0);
    int *const data = list.set(0, &j);
    EXPECT_EQ(list.size(), 4u);
    int *const dataGet2 = list.get(1);
    int *const data2 = list.set(1, &k);
    EXPECT_EQ(list.size(), 4u);
    int *const dataGet3 = list.get(2);
    int *const data3 = list.set(2, &l);
    EXPECT_EQ(list.size(), 4u);

    EXPECT_EQ(data, &x);
    EXPECT_EQ(data2, &y);
    EXPECT_EQ(data3, &z);
    EXPECT_EQ(data4, &a);

    EXPECT_EQ(data, dataGet);
    EXPECT_EQ(data2, dataGet2);
    EXPECT_EQ(data3, dataGet3);
    EXPECT_EQ(data4, dataGet4);

    EXPECT_EQ(list.get(0), &j);
    EXPECT_EQ(list.get(1), &k);
    EXPECT_EQ(list.get(2), &l);
    EXPECT_EQ(list.get(3), &m);
}

TYPED_TEST(ListTest, SetOperations4) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    int j = 15;
    int k = 8;
    int l = 6;
    int m = 39;
    list.insert(0, &x);
    list.insert(1, &y);
    list.insert(2, &z);
    list.insert(3, &a);
    int *const dataGet3 = list.get(2);
    int *const data3 = list.set(2, &l);
    EXPECT_EQ(list.size(), 4u);
    int *const dataGet = list.get(0);
    int *const data = list.set(0, &j);
    EXPECT_EQ(list.size(), 4u);
    int *const dataGet4 = list.get(3);
    int *const data4 = list.set(3, &m);
    EXPECT_EQ(list.size(), 4u);
    int *const dataGet2 = list.get(1);
    int *const data2 = list.set(1, &k);
    EXPECT_EQ(list.size(), 4u);

    EXPECT_EQ(data, &x);
    EXPECT_EQ(data2, &y);
    EXPECT_EQ(data3, &z);
    EXPECT_EQ(data4, &a);

    EXPECT_EQ(data, dataGet);
    EXPECT_EQ(data2, dataGet2);
    EXPECT_EQ(data3, dataGet3);
    EXPECT_EQ(data4, dataGet4);

    EXPECT_EQ(list.get(0), &j);
    EXPECT_EQ(list.get(1), &k);
    EXPECT_EQ(list.get(2), &l);
    EXPECT_EQ(list.get(3), &m);
}

TYPED_TEST(ListTest, Foreach) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.addTail(&x);
    list.addTail(&y);
    list.addTail(&z);
    list.addTail(&a);

    class TestVisitor : public yh::structures::lists::List<int>::Visitor {
        private:
            int *pointers[16];
            size_t visitCounter;
        public:
            TestVisitor() :
                pointers{nullptr},
                visitCounter(0)
            {
                //
            }
            void visit(int *const elementPointer) override {
                pointers[visitCounter] = elementPointer;
                visitCounter++;
            }
            size_t getVisitCounter() {
                return visitCounter;
            }
            int *operator[](const size_t index) {
                if (index >= visitCounter) {
                    return nullptr;
                }
                return pointers[index];
            }
    };

    TestVisitor visitor;
    list.foreach(visitor);
    EXPECT_EQ(visitor.getVisitCounter(), 4u);
    EXPECT_EQ(visitor[0], &x);
    EXPECT_EQ(visitor[1], &y);
    EXPECT_EQ(visitor[2], &z);
    EXPECT_EQ(visitor[3], &a);
}

TYPED_TEST(ListTest, RemoveIf) {
    TypeParam list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.addTail(&x);
    list.addTail(&y);
    list.addTail(&z);
    list.addTail(&a);
    list.removeIf([](int *const ptr) { return (*ptr) % 4 == 0; });
    EXPECT_EQ(list.size(), 1u);
    EXPECT_EQ(list.get(0), &x);
}

#define SETUP_ITERATOR_LIST() \
    TypeParam list; \
    int x = 35; \
    int y = -12; \
    int z = 0; \
    int a = -4; \
    list.addTail(&x); \
    list.addTail(&y); \
    list.addTail(&z); \
    list.addTail(&a); \
 \
    typename TypeParam::Iterator it = list; \


#define EXPECT_NEXT_ELEMENT_IS(e,rm,checkRemovedIsHidden) { \
    for (int i = 0; i < 10; i++) { \
        EXPECT_TRUE(it.hasNext()); \
    } \
    for (int i = 0; i < 10; i++) { \
        EXPECT_EQ(it.get(), &e); \
    } \
    if (rm) { \
        EXPECT_EQ(it.remove(), &e); \
        if (checkRemovedIsHidden) { \
            for (int i = 0; i < 10; i++) { \
                EXPECT_EQ(it.get(), nullptr); \
            } \
        } \
        for (int i = 0; i < 10; i++) { \
            EXPECT_EQ(it.remove(), nullptr); \
        } \
    } \
    it.proceed(); \
}

#define EXPECT_NO_NEXT_ELEMENT() { \
    EXPECT_FALSE(it.hasNext()); \
    for (int i = 0; i < 10; i++) { \
        EXPECT_EQ(it.get(), nullptr); \
        EXPECT_EQ(it.remove(), nullptr); \
    } \
    it.proceed(); \
}

#define EXPECT_NO_MORE_ELEMENTS() { \
    for (int i = 0; i < 10; i++) { \
        EXPECT_NO_NEXT_ELEMENT(); \
    } \
}

TYPED_TEST(ListTest, IteratorReadonly) {
    SETUP_ITERATOR_LIST();

    EXPECT_NEXT_ELEMENT_IS(x, false, false);
    EXPECT_NEXT_ELEMENT_IS(y, false, false);
    EXPECT_NEXT_ELEMENT_IS(z, false, false);
    EXPECT_NEXT_ELEMENT_IS(a, false, false);

    EXPECT_NO_MORE_ELEMENTS();

    EXPECT_EQ(list.size(), 4u);
    EXPECT_EQ(list.get(0), &x);
    EXPECT_EQ(list.get(1), &y);
    EXPECT_EQ(list.get(2), &z);
    EXPECT_EQ(list.get(3), &a);
}

TYPED_TEST(ListTest, IteratorRemoveOnlyOnceForAllEvens) {
    SETUP_ITERATOR_LIST();

    EXPECT_NEXT_ELEMENT_IS(x, false, false);
    EXPECT_NEXT_ELEMENT_IS(y, true, false);
    EXPECT_NEXT_ELEMENT_IS(z, false, false);
    EXPECT_NEXT_ELEMENT_IS(a, true, false);

    EXPECT_NO_MORE_ELEMENTS();

    EXPECT_EQ(list.size(), 2u);
    EXPECT_EQ(list.get(0), &x);
    EXPECT_EQ(list.get(1), &z);
}

TYPED_TEST(ListTest, IteratorRemoveOnlyOnceForAllOdds) {
    SETUP_ITERATOR_LIST();

    EXPECT_NEXT_ELEMENT_IS(x, true, false);
    EXPECT_NEXT_ELEMENT_IS(y, false, false);
    EXPECT_NEXT_ELEMENT_IS(z, true, false);
    EXPECT_NEXT_ELEMENT_IS(a, false, false);

    EXPECT_NO_MORE_ELEMENTS();

    EXPECT_EQ(list.size(), 2u);
    EXPECT_EQ(list.get(0), &y);
    EXPECT_EQ(list.get(1), &a);
}

TYPED_TEST(ListTest, IteratorRemoveOnlyOnceForAllElements) {
    SETUP_ITERATOR_LIST();

    EXPECT_NEXT_ELEMENT_IS(x, true, false);
    EXPECT_NEXT_ELEMENT_IS(y, true, false);
    EXPECT_NEXT_ELEMENT_IS(z, true, false);
    EXPECT_NEXT_ELEMENT_IS(a, true, false);

    EXPECT_NO_MORE_ELEMENTS();

    EXPECT_EQ(list.size(), 0u);
}

TYPED_TEST(ListTest, IteratorRemovedEvenElementsAreNotVisible) {
    SETUP_ITERATOR_LIST();

    EXPECT_NEXT_ELEMENT_IS(x, false, true);
    EXPECT_NEXT_ELEMENT_IS(y, true, true);
    EXPECT_NEXT_ELEMENT_IS(z, false, true);
    EXPECT_NEXT_ELEMENT_IS(a, true, true);

    EXPECT_NO_MORE_ELEMENTS();

    EXPECT_EQ(list.size(), 2u);
    EXPECT_EQ(list.get(0), &x);
    EXPECT_EQ(list.get(1), &z);
}

TYPED_TEST(ListTest, IteratorRemovedOddElementsAreNotVisible) {
    SETUP_ITERATOR_LIST();

    EXPECT_NEXT_ELEMENT_IS(x, true, true);
    EXPECT_NEXT_ELEMENT_IS(y, false, true);
    EXPECT_NEXT_ELEMENT_IS(z, true, true);
    EXPECT_NEXT_ELEMENT_IS(a, false, true);

    EXPECT_NO_MORE_ELEMENTS();

    EXPECT_EQ(list.size(), 2u);
    EXPECT_EQ(list.get(0), &y);
    EXPECT_EQ(list.get(1), &a);
}

TYPED_TEST(ListTest, IteratorRemovedAllElementsAreNotVisible) {
    SETUP_ITERATOR_LIST();

    EXPECT_NEXT_ELEMENT_IS(x, true, true);
    EXPECT_NEXT_ELEMENT_IS(y, true, true);
    EXPECT_NEXT_ELEMENT_IS(z, true, true);
    EXPECT_NEXT_ELEMENT_IS(a, true, true);

    EXPECT_NO_MORE_ELEMENTS();

    EXPECT_EQ(list.size(), 0u);
}

TYPED_TEST(ListTest, Expand) {
    TypeParam list;
    int numbers [40];
    for (int i = 0; i < 40; i++) {
        numbers[i] = 15 - i;
        EXPECT_EQ(list.size(), static_cast<size_t>(i));
        list.insert(i, numbers + i);
        EXPECT_EQ(list.size(), static_cast<size_t>(i + 1));
    }
}

TYPED_TEST(ListTest, Shrink) {
    TypeParam list;
    int numbers [40];
    for (int i = 0; i < 40; i++) {
        numbers[i] = 15 - i;
        EXPECT_EQ(list.size(), static_cast<size_t>(i));
        list.insert(i, numbers + i);
        EXPECT_EQ(list.size(), static_cast<size_t>(i + 1));
    }
    for (int i = 0; i < 40; i++) {
        EXPECT_EQ(list.size(), static_cast<size_t>(40 - i));
        const int *const ptr = list.remove(0);
        EXPECT_EQ(list.size(), static_cast<size_t>(40 - 1 - i));
        EXPECT_EQ(ptr, numbers + i);
        EXPECT_EQ(*ptr, 15 - i);
    }
}
