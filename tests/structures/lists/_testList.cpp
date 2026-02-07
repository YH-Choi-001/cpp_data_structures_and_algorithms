/**
 * @file _testList.cpp - Generic tests for lists.
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

#include <iostream>

#ifdef LIST_TYPE

using yh::structures::lists::LIST_TYPE;

TEST_BEGIN(list_is_empty_for_empty_list)
{
    LIST_TYPE<int> list;
    ASSERT_TRUE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_1_element_list_add_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.addHead(&x);
    ASSERT_FALSE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_1_element_list_add_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.addTail(&x);
    ASSERT_FALSE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_1_element_list_insert)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.insert(0, &x);
    ASSERT_FALSE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_is_empty_for_1_element_list_insert_invalid_index)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.insert(1, &x);
    ASSERT_TRUE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_2_element_list_add_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addHead(&x);
    list.addHead(&y);
    ASSERT_FALSE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_2_element_list_add_head_then_add_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addHead(&x);
    list.addTail(&y);
    ASSERT_FALSE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_2_element_list_add_tail_then_add_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addTail(&x);
    list.addHead(&y);
    ASSERT_FALSE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_2_element_list_add_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addTail(&x);
    list.addTail(&y);
    ASSERT_FALSE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_2_element_list_insert_0_then_insert_0)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(0, &y);
    ASSERT_FALSE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_2_element_list_insert_0_then_insert_1)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(1, &y);
    ASSERT_FALSE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_1_element_list_insert_valid_index_then_insert_invalid_index)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(2, &y);
    ASSERT_FALSE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_1_element_list_insert_invalid_index_then_insert_valid_index)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(1, &x);
    list.insert(0, &y);
    ASSERT_FALSE(list.isEmpty());
}
TEST_END()

TEST_BEGIN(list_size_is_0_for_empty_list)
{
    LIST_TYPE<int> list;
    ASSERT_EQUALS(list.size(), 0);
}
TEST_END()

TEST_BEGIN(list_size_is_1_for_1_element_list_add_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.addHead(&x);
    ASSERT_EQUALS(list.size(), 1);
}
TEST_END()

TEST_BEGIN(list_size_is_1_for_1_element_list_add_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.addTail(&x);
    ASSERT_EQUALS(list.size(), 1);
}
TEST_END()

TEST_BEGIN(list_size_is_1_for_1_element_list_insert)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.insert(0, &x);
    ASSERT_EQUALS(list.size(), 1);
}
TEST_END()

TEST_BEGIN(list_size_is_1_for_1_element_list_insert_invalid_index)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.insert(1, &x);
    ASSERT_EQUALS(list.size(), 0);
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_add_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addHead(&x);
    list.addHead(&y);
    ASSERT_EQUALS(list.size(), 2);
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_add_head_then_add_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addHead(&x);
    list.addTail(&y);
    ASSERT_EQUALS(list.size(), 2);
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_add_tail_then_add_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addTail(&x);
    list.addHead(&y);
    ASSERT_EQUALS(list.size(), 2);
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_add_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addTail(&x);
    list.addTail(&y);
    ASSERT_EQUALS(list.size(), 2);
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_insert_0_then_insert_0)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(0, &y);
    ASSERT_EQUALS(list.size(), 2);
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_insert_0_then_insert_1)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(1, &y);
    ASSERT_EQUALS(list.size(), 2);
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_insert_valid_index_then_insert_invalid_index)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(2, &y);
    ASSERT_EQUALS(list.size(), 1);
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_insert_invalid_index_then_insert_valid_index)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(1, &x);
    list.insert(0, &y);
    ASSERT_EQUALS(list.size(), 1);
}
TEST_END()

TEST_BEGIN(list_add_head_head_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addHead(&x);
    list.addHead(&y);
    list.addHead(&z);
    ASSERT_EQUALS(list.size(), 3);
    ASSERT_EQUALS(list.get(0), &z);
    ASSERT_EQUALS(list.get(1), &y);
    ASSERT_EQUALS(list.get(2), &x);
}
TEST_END()

TEST_BEGIN(list_add_tail_tail_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addTail(&x);
    list.addTail(&y);
    list.addTail(&z);
    ASSERT_EQUALS(list.size(), 3);
    ASSERT_EQUALS(list.get(0), &x);
    ASSERT_EQUALS(list.get(1), &y);
    ASSERT_EQUALS(list.get(2), &z);
}
TEST_END()

TEST_BEGIN(list_add_head_tail_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addHead(&x);
    list.addTail(&y);
    list.addHead(&z);
    ASSERT_EQUALS(list.size(), 3);
    ASSERT_EQUALS(list.get(0), &z);
    ASSERT_EQUALS(list.get(1), &x);
    ASSERT_EQUALS(list.get(2), &y);
}
TEST_END()

TEST_BEGIN(list_add_tail_head_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addTail(&x);
    list.addHead(&y);
    list.addTail(&z);
    ASSERT_EQUALS(list.size(), 3);
    ASSERT_EQUALS(list.get(0), &y);
    ASSERT_EQUALS(list.get(1), &x);
    ASSERT_EQUALS(list.get(2), &z);
}
TEST_END()

TEST_BEGIN(list_add_head_head_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addHead(&x);
    list.addHead(&y);
    list.addTail(&z);
    ASSERT_EQUALS(list.size(), 3);
    ASSERT_EQUALS(list.get(0), &y);
    ASSERT_EQUALS(list.get(1), &x);
    ASSERT_EQUALS(list.get(2), &z);
}
TEST_END()

TEST_BEGIN(list_add_head_tail_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addHead(&x);
    list.addTail(&y);
    list.addTail(&z);
    ASSERT_EQUALS(list.size(), 3);
    ASSERT_EQUALS(list.get(0), &x);
    ASSERT_EQUALS(list.get(1), &y);
    ASSERT_EQUALS(list.get(2), &z);
}
TEST_END()

TEST_BEGIN(list_add_tail_tail_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addTail(&x);
    list.addTail(&y);
    list.addHead(&z);
    ASSERT_EQUALS(list.size(), 3);
    ASSERT_EQUALS(list.get(0), &z);
    ASSERT_EQUALS(list.get(1), &x);
    ASSERT_EQUALS(list.get(2), &y);
}
TEST_END()

TEST_BEGIN(list_add_tail_head_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    list.addTail(&x);
    list.addHead(&y);
    list.addHead(&z);
    ASSERT_EQUALS(list.size(), 3);
    ASSERT_EQUALS(list.get(0), &z);
    ASSERT_EQUALS(list.get(1), &y);
    ASSERT_EQUALS(list.get(2), &x);
}
TEST_END()

TEST_BEGIN(list_add_tail_tail_tail_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.addTail(&x);
    list.addTail(&y);
    list.addTail(&z);
    list.addTail(&a);
    ASSERT_EQUALS(list.size(), 4);
    ASSERT_EQUALS(list.get(0), &x);
    ASSERT_EQUALS(list.get(1), &y);
    ASSERT_EQUALS(list.get(2), &z);
    ASSERT_EQUALS(list.get(3), &a);
}
TEST_END()

TEST_BEGIN(list_insert_tail_tail_tail_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.insert(0, &x);
    list.insert(1, &y);
    list.insert(2, &z);
    list.insert(3, &a);
    ASSERT_EQUALS(list.size(), 4);
    ASSERT_EQUALS(list.get(0), &x);
    ASSERT_EQUALS(list.get(1), &y);
    ASSERT_EQUALS(list.get(2), &z);
    ASSERT_EQUALS(list.get(3), &a);
}
TEST_END()

TEST_BEGIN(list_insert_tail_tail_mid_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.insert(0, &y);
    list.insert(1, &a);
    list.insert(1, &z);
    list.insert(0, &x);
    ASSERT_EQUALS(list.size(), 4);
    ASSERT_EQUALS(list.get(0), &x);
    ASSERT_EQUALS(list.get(1), &y);
    ASSERT_EQUALS(list.get(2), &z);
    ASSERT_EQUALS(list.get(3), &a);
}
TEST_END()

TEST_BEGIN(list_insert_head_head_mid_mid)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.insert(0, &a);
    list.insert(0, &x);
    list.insert(1, &y);
    list.insert(2, &z);
    ASSERT_EQUALS(list.size(), 4);
    ASSERT_EQUALS(list.get(0), &x);
    ASSERT_EQUALS(list.get(1), &y);
    ASSERT_EQUALS(list.get(2), &z);
    ASSERT_EQUALS(list.get(3), &a);
}
TEST_END()

TEST_BEGIN(list_insert_tail_tail_mid_mid)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.insert(0, &x);
    list.insert(1, &a);
    list.insert(1, &y);
    list.insert(2, &z);
    ASSERT_EQUALS(list.size(), 4);
    ASSERT_EQUALS(list.get(0), &x);
    ASSERT_EQUALS(list.get(1), &y);
    ASSERT_EQUALS(list.get(2), &z);
    ASSERT_EQUALS(list.get(3), &a);
}
TEST_END()

TEST_BEGIN(list_head_operations)
{
    LIST_TYPE<int> list;
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

    ASSERT_EQUALS(data, &z);
    ASSERT_EQUALS(data2, &a);
    ASSERT_EQUALS(data3, &y);
    ASSERT_EQUALS(data4, &x);

    ASSERT_EQUALS(data, dataGet);
    ASSERT_EQUALS(data2, dataGet2);
    ASSERT_EQUALS(data3, dataGet3);
    ASSERT_EQUALS(data4, dataGet4);

    ASSERT_TRUE(list.isEmpty());
    ASSERT_EQUALS(list.size(), 0);
}
TEST_END()

TEST_BEGIN(list_tail_operations)
{
    LIST_TYPE<int> list;
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

    ASSERT_EQUALS(data, &z);
    ASSERT_EQUALS(data2, &a);
    ASSERT_EQUALS(data3, &y);
    ASSERT_EQUALS(data4, &x);

    ASSERT_EQUALS(data, dataGet);
    ASSERT_EQUALS(data2, dataGet2);
    ASSERT_EQUALS(data3, dataGet3);
    ASSERT_EQUALS(data4, dataGet4);

    ASSERT_TRUE(list.isEmpty());
    ASSERT_EQUALS(list.size(), 0);
}
TEST_END()

TEST_BEGIN(list_add_head_remove_tail_operations)
{
    LIST_TYPE<int> list;
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

    ASSERT_EQUALS(data, &x);
    ASSERT_EQUALS(data2, &y);
    ASSERT_EQUALS(data3, &z);
    ASSERT_EQUALS(data4, &a);

    ASSERT_EQUALS(data, dataGet);
    ASSERT_EQUALS(data2, dataGet2);
    ASSERT_EQUALS(data3, dataGet3);
    ASSERT_EQUALS(data4, dataGet4);

    ASSERT_TRUE(list.isEmpty());
    ASSERT_EQUALS(list.size(), 0);
}
TEST_END()

TEST_BEGIN(list_add_tail_remove_head_operations)
{
    LIST_TYPE<int> list;
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

    ASSERT_EQUALS(data, &x);
    ASSERT_EQUALS(data2, &y);
    ASSERT_EQUALS(data3, &z);
    ASSERT_EQUALS(data4, &a);

    ASSERT_EQUALS(data, dataGet);
    ASSERT_EQUALS(data2, dataGet2);
    ASSERT_EQUALS(data3, dataGet3);
    ASSERT_EQUALS(data4, dataGet4);

    ASSERT_TRUE(list.isEmpty());
    ASSERT_EQUALS(list.size(), 0);
}
TEST_END()

TEST_BEGIN(list_mixed_ends_add_remove_operations_1)
{
    LIST_TYPE<int> list;
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

    ASSERT_EQUALS(data, &z);
    ASSERT_EQUALS(data2, &a);
    ASSERT_EQUALS(data3, &x);
    ASSERT_EQUALS(data4, &y);

    ASSERT_EQUALS(data, dataGet);
    ASSERT_EQUALS(data2, dataGet2);
    ASSERT_EQUALS(data3, dataGet3);
    ASSERT_EQUALS(data4, dataGet4);

    ASSERT_TRUE(list.isEmpty());
    ASSERT_EQUALS(list.size(), 0);
}
TEST_END()

TEST_BEGIN(list_mixed_ends_add_remove_operations_2)
{
    LIST_TYPE<int> list;
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

    ASSERT_EQUALS(data, &y);
    ASSERT_EQUALS(data2, &z);
    ASSERT_EQUALS(data3, &a);
    ASSERT_EQUALS(data4, &x);

    ASSERT_EQUALS(data, dataGet);
    ASSERT_EQUALS(data2, dataGet2);
    ASSERT_EQUALS(data3, dataGet3);
    ASSERT_EQUALS(data4, dataGet4);

    ASSERT_TRUE(list.isEmpty());
    ASSERT_EQUALS(list.size(), 0);
}
TEST_END()

TEST_BEGIN(list_remove_operations)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.insert(0, &x);
    list.insert(1, &z);
    list.insert(1, &y);
    int *const dataGet = list.get(1);
    int *const data = list.remove(1);
    list.insert(1, &a);
    int *const dataGet2 = list.get(1);
    int *const data2 = list.remove(1);
    int *const dataGet3 = list.get(1);
    int *const data3 = list.remove(1);
    int *const dataGet4 = list.get(0);
    int *const data4 = list.remove(0);

    ASSERT_EQUALS(data, &y);
    ASSERT_EQUALS(data2, &a);
    ASSERT_EQUALS(data3, &z);
    ASSERT_EQUALS(data4, &x);

    ASSERT_EQUALS(data, dataGet);
    ASSERT_EQUALS(data2, dataGet2);
    ASSERT_EQUALS(data3, dataGet3);
    ASSERT_EQUALS(data4, dataGet4);

    ASSERT_TRUE(list.isEmpty());
    ASSERT_EQUALS(list.size(), 0);
}
TEST_END()

TEST_BEGIN(list_set_operations_1)
{
    LIST_TYPE<int> list;
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
    ASSERT_EQUALS(list.size(), 4);
    int *const dataGet2 = list.get(1);
    int *const data2 = list.set(1, &k);
    ASSERT_EQUALS(list.size(), 4);
    int *const dataGet3 = list.get(2);
    int *const data3 = list.set(2, &l);
    ASSERT_EQUALS(list.size(), 4);
    int *const dataGet4 = list.get(3);
    int *const data4 = list.set(3, &m);
    ASSERT_EQUALS(list.size(), 4);

    ASSERT_EQUALS(data, &x);
    ASSERT_EQUALS(data2, &y);
    ASSERT_EQUALS(data3, &z);
    ASSERT_EQUALS(data4, &a);

    ASSERT_EQUALS(data, dataGet);
    ASSERT_EQUALS(data2, dataGet2);
    ASSERT_EQUALS(data3, dataGet3);
    ASSERT_EQUALS(data4, dataGet4);

    ASSERT_EQUALS(list.get(0), &j);
    ASSERT_EQUALS(list.get(1), &k);
    ASSERT_EQUALS(list.get(2), &l);
    ASSERT_EQUALS(list.get(3), &m);
}
TEST_END()

TEST_BEGIN(list_set_operations_2)
{
    LIST_TYPE<int> list;
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
    ASSERT_EQUALS(list.size(), 4);
    int *const dataGet3 = list.get(2);
    int *const data3 = list.set(2, &l);
    ASSERT_EQUALS(list.size(), 4);
    int *const dataGet4 = list.get(3);
    int *const data4 = list.set(3, &m);
    ASSERT_EQUALS(list.size(), 4);
    int *const dataGet2 = list.get(1);
    int *const data2 = list.set(1, &k);
    ASSERT_EQUALS(list.size(), 4);

    ASSERT_EQUALS(data, &x);
    ASSERT_EQUALS(data2, &y);
    ASSERT_EQUALS(data3, &z);
    ASSERT_EQUALS(data4, &a);

    ASSERT_EQUALS(data, dataGet);
    ASSERT_EQUALS(data2, dataGet2);
    ASSERT_EQUALS(data3, dataGet3);
    ASSERT_EQUALS(data4, dataGet4);

    ASSERT_EQUALS(list.get(0), &j);
    ASSERT_EQUALS(list.get(1), &k);
    ASSERT_EQUALS(list.get(2), &l);
    ASSERT_EQUALS(list.get(3), &m);
}
TEST_END()

TEST_BEGIN(list_set_operations_3)
{
    LIST_TYPE<int> list;
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
    ASSERT_EQUALS(list.size(), 4);
    int *const dataGet = list.get(0);
    int *const data = list.set(0, &j);
    ASSERT_EQUALS(list.size(), 4);
    int *const dataGet2 = list.get(1);
    int *const data2 = list.set(1, &k);
    ASSERT_EQUALS(list.size(), 4);
    int *const dataGet3 = list.get(2);
    int *const data3 = list.set(2, &l);
    ASSERT_EQUALS(list.size(), 4);

    ASSERT_EQUALS(data, &x);
    ASSERT_EQUALS(data2, &y);
    ASSERT_EQUALS(data3, &z);
    ASSERT_EQUALS(data4, &a);

    ASSERT_EQUALS(data, dataGet);
    ASSERT_EQUALS(data2, dataGet2);
    ASSERT_EQUALS(data3, dataGet3);
    ASSERT_EQUALS(data4, dataGet4);

    ASSERT_EQUALS(list.get(0), &j);
    ASSERT_EQUALS(list.get(1), &k);
    ASSERT_EQUALS(list.get(2), &l);
    ASSERT_EQUALS(list.get(3), &m);
}
TEST_END()

TEST_BEGIN(list_set_operations_4)
{
    LIST_TYPE<int> list;
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
    ASSERT_EQUALS(list.size(), 4);
    int *const dataGet = list.get(0);
    int *const data = list.set(0, &j);
    ASSERT_EQUALS(list.size(), 4);
    int *const dataGet4 = list.get(3);
    int *const data4 = list.set(3, &m);
    ASSERT_EQUALS(list.size(), 4);
    int *const dataGet2 = list.get(1);
    int *const data2 = list.set(1, &k);
    ASSERT_EQUALS(list.size(), 4);

    ASSERT_EQUALS(data, &x);
    ASSERT_EQUALS(data2, &y);
    ASSERT_EQUALS(data3, &z);
    ASSERT_EQUALS(data4, &a);

    ASSERT_EQUALS(data, dataGet);
    ASSERT_EQUALS(data2, dataGet2);
    ASSERT_EQUALS(data3, dataGet3);
    ASSERT_EQUALS(data4, dataGet4);

    ASSERT_EQUALS(list.get(0), &j);
    ASSERT_EQUALS(list.get(1), &k);
    ASSERT_EQUALS(list.get(2), &l);
    ASSERT_EQUALS(list.get(3), &m);
}
TEST_END()

TEST_BEGIN(list_foreach)
{
    LIST_TYPE<int> list;
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
            int visitCounter;
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
            int getVisitCounter() {
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
    ASSERT_EQUALS(visitor.getVisitCounter(), 4);
    ASSERT_EQUALS(visitor[0], &x);
    ASSERT_EQUALS(visitor[1], &y);
    ASSERT_EQUALS(visitor[2], &z);
    ASSERT_EQUALS(visitor[3], &a);
}
TEST_END()

TEST_BEGIN(list_removeIf)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    list.addTail(&x);
    list.addTail(&y);
    list.addTail(&z);
    list.addTail(&a);
    list.removeIf([](int *const ptr) { return (*ptr) % 4 == 0; });
    ASSERT_EQUALS(list.size(), 1);
    ASSERT_EQUALS(list.get(0), &x);
}
TEST_END()

const testfunc_t functions [] = {
    test_list_is_empty_for_empty_list,
    test_list_is_not_empty_for_1_element_list_add_head,
    test_list_is_not_empty_for_1_element_list_add_tail,
    test_list_is_not_empty_for_1_element_list_insert,
    test_list_is_empty_for_1_element_list_insert_invalid_index,
    test_list_is_not_empty_for_2_element_list_add_head,
    test_list_is_not_empty_for_2_element_list_add_head_then_add_tail,
    test_list_is_not_empty_for_2_element_list_add_tail_then_add_head,
    test_list_is_not_empty_for_2_element_list_add_tail,
    test_list_is_not_empty_for_2_element_list_insert_0_then_insert_0,
    test_list_is_not_empty_for_2_element_list_insert_0_then_insert_1,
    test_list_is_not_empty_for_1_element_list_insert_valid_index_then_insert_invalid_index,
    test_list_is_not_empty_for_1_element_list_insert_invalid_index_then_insert_valid_index,
    test_list_size_is_0_for_empty_list,
    test_list_size_is_1_for_1_element_list_add_head,
    test_list_size_is_1_for_1_element_list_add_tail,
    test_list_size_is_1_for_1_element_list_insert,
    test_list_size_is_1_for_1_element_list_insert_invalid_index,
    test_list_size_is_2_for_2_element_list_add_head,
    test_list_size_is_2_for_2_element_list_add_head_then_add_tail,
    test_list_size_is_2_for_2_element_list_add_tail_then_add_head,
    test_list_size_is_2_for_2_element_list_add_tail,
    test_list_size_is_2_for_2_element_list_insert_0_then_insert_0,
    test_list_size_is_2_for_2_element_list_insert_0_then_insert_1,
    test_list_size_is_2_for_2_element_list_insert_valid_index_then_insert_invalid_index,
    test_list_size_is_2_for_2_element_list_insert_invalid_index_then_insert_valid_index,
    test_list_add_head_head_head,
    test_list_add_tail_tail_tail,
    test_list_add_head_tail_head,
    test_list_add_tail_head_tail,
    test_list_add_head_head_tail,
    test_list_add_head_tail_tail,
    test_list_add_tail_tail_head,
    test_list_add_tail_head_head,
    test_list_add_tail_tail_tail_tail,
    test_list_insert_tail_tail_tail_tail,
    test_list_insert_tail_tail_mid_head,
    test_list_insert_head_head_mid_mid,
    test_list_insert_tail_tail_mid_mid,
    test_list_head_operations,
    test_list_tail_operations,
    test_list_add_head_remove_tail_operations,
    test_list_add_tail_remove_head_operations,
    test_list_mixed_ends_add_remove_operations_1,
    test_list_mixed_ends_add_remove_operations_2,
    test_list_remove_operations,
    test_list_set_operations_1,
    test_list_set_operations_2,
    test_list_set_operations_3,
    test_list_set_operations_4,
    test_list_foreach,
    test_list_removeIf
};

MAIN();

#else // # ifdef LIST_TYPE

#error LIST_TYPE needs to be defined.

#endif // #ifdef LIST_TYPE