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
    if (list.isEmpty()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "list.isEmpty() returns false for an empty list.";
    }
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_1_element_list_add_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.addHead(&x);
    if (!list.isEmpty()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "list.isEmpty() returns true for a list with 1 element.";
    }
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_1_element_list_add_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.addTail(&x);
    if (!list.isEmpty()) {
        result.passed = true;
    } else {
        result.passed = false;
        result.reason = "list.isEmpty() returns true for a list with 1 element.";
    }
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_1_element_list_insert)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.insert(0, &x);
    if (!list.isEmpty()) {
        result.passed = true;
    } else {
        result.reason = "list.isEmpty() returns true for a list with 1 element.";
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_is_empty_for_1_element_list_insert_invalid_index)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.insert(1, &x);
    if (list.isEmpty()) {
        result.passed = true;
    } else {
        result.reason = "list.isEmpty() returns false for an empty list but with an element inserted at an invalid index.";
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_2_element_list_add_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addHead(&x);
    list.addHead(&y);
    if (!list.isEmpty()) {
        result.passed = true;
    } else {
        result.reason = "list.isEmpty() returns true for a list with 2 elements.";
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_2_element_list_add_head_then_add_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addHead(&x);
    list.addTail(&y);
    if (!list.isEmpty()) {
        result.passed = true;
    } else {
        result.reason = "list.isEmpty() returns true for a list with 2 elements.";
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_2_element_list_add_tail_then_add_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addTail(&x);
    list.addHead(&y);
    if (!list.isEmpty()) {
        result.passed = true;
    } else {
        result.reason = "list.isEmpty() returns true for a list with 2 elements.";
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_2_element_list_add_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addTail(&x);
    list.addTail(&y);
    if (!list.isEmpty()) {
        result.passed = true;
    } else {
        result.reason = "list.isEmpty() returns true for a list with 2 elements.";
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_2_element_list_insert_0_then_insert_0)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(0, &y);
    if (!list.isEmpty()) {
        result.passed = true;
    } else {
        result.reason = "list.isEmpty() returns true for a list with 2 elements.";
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_2_element_list_insert_0_then_insert_1)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(1, &y);
    if (!list.isEmpty()) {
        result.passed = true;
    } else {
        result.reason = "list.isEmpty() returns true for a list with 2 elements.";
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_1_element_list_insert_valid_index_then_insert_invalid_index)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(2, &y);
    if (!list.isEmpty()) {
        result.passed = true;
    } else {
        result.reason = "list.isEmpty() returns true for a list with 1 element.";
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_is_not_empty_for_1_element_list_insert_invalid_index_then_insert_valid_index)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(1, &x);
    list.insert(0, &y);
    if (!list.isEmpty()) {
        result.passed = true;
    } else {
        result.reason = "list.isEmpty() returns true for a list with 1 element.";
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_0_for_empty_list)
{
    LIST_TYPE<int> list;
    const size_t size = list.size();
    if (size == 0) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for an empty list.";
        result.reason = sstream.str();
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_1_for_1_element_list_add_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.addHead(&x);
    const size_t size = list.size();
    if (size == 1) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 1 element.";
        result.reason = sstream.str();
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_1_for_1_element_list_add_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.addTail(&x);
    const size_t size = list.size();
    if (size == 1) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 1 element.";
        result.reason = sstream.str();
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_1_for_1_element_list_insert)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.insert(0, &x);
    const size_t size = list.size();
    if (size == 1) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 1 element.";
        result.reason = sstream.str();
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_1_for_1_element_list_insert_invalid_index)
{
    LIST_TYPE<int> list;
    int x = 35;
    list.insert(1, &x);
    const size_t size = list.size();
    if (size == 0) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for an empty list but with an element inserted at an invalid index.";
        result.reason = sstream.str();
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_add_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addHead(&x);
    list.addHead(&y);
    const size_t size = list.size();
    if (size == 2) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 2 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_add_head_then_add_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addHead(&x);
    list.addTail(&y);
    const size_t size = list.size();
    if (size == 2) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 2 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_add_tail_then_add_head)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addTail(&x);
    list.addHead(&y);
    const size_t size = list.size();
    if (size == 2) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 2 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_add_tail)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.addTail(&x);
    list.addTail(&y);
    const size_t size = list.size();
    if (size == 2) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 2 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_insert_0_then_insert_0)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(0, &y);
    const size_t size = list.size();
    if (size == 2) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 2 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_insert_0_then_insert_1)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(1, &y);
    const size_t size = list.size();
    if (size == 2) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 2 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_insert_valid_index_then_insert_invalid_index)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(0, &x);
    list.insert(2, &y);
    const size_t size = list.size();
    if (size == 1) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 1 element and another element inserted at an invalid index.";
        result.reason = sstream.str();
        result.passed = false;
    }
}
TEST_END()

TEST_BEGIN(list_size_is_2_for_2_element_list_insert_invalid_index_then_insert_valid_index)
{
    LIST_TYPE<int> list;
    int x = 35;
    int y = -12;
    list.insert(1, &x);
    list.insert(0, &y);
    const size_t size = list.size();
    if (size == 1) {
        result.passed = true;
    } else {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 1 element and another element inserted at an invalid index.";
        result.reason = sstream.str();
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 3) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 3 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &z || list.get(1) != &y || list.get(2) != &x) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 3 elements.";
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 3) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 3 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 3 elements.";
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 3) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 3 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &z || list.get(1) != &x || list.get(2) != &y) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 3 elements.";
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 3) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 3 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &y || list.get(1) != &x || list.get(2) != &z) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 3 elements.";
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 3) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 3 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &y || list.get(1) != &x || list.get(2) != &z) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 3 elements.";
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 3) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 3 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 3 elements.";
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 3) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 3 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &z || list.get(1) != &x || list.get(2) != &y) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 3 elements.";
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 3) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 3 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &z || list.get(1) != &y || list.get(2) != &x) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 3 elements.";
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 4) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 4 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z || list.get(3) != &a) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 4 elements.";
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 4) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 4 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z || list.get(3) != &a) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 4 elements.";
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 4) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 4 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z || list.get(3) != &a) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 4 elements.";
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 4) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 4 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z || list.get(3) != &a) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 4 elements.";
        result.passed = false;
    }
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
    const size_t size = list.size();
    result.passed = true;
    if (size != 4) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 4 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z || list.get(3) != &a) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 4 elements.";
        result.passed = false;
    }
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
    int *dataGet = list.getHead();
    int *data = list.removeHead();
    list.addHead(&a);
    int *dataGet2 = list.getHead();
    int *data2 = list.removeHead();
    int *dataGet3 = list.getHead();
    int *data3 = list.removeHead();
    int *dataGet4 = list.getHead();
    int *data4 = list.removeHead();
    result.passed = true;
    if (data != &z || data2 != &a || data3 != &y || data4 != &x) {
        result.reason = "list.remove...() returns wrong addresses or in wrong order.";
        result.passed = false;
    }
    if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
        result.reason = "list.get...() and list.remove...() do not return the same objects.";
        result.passed = false;
    }
    const bool isEmpty = list.isEmpty();
    if (!isEmpty) {
        result.reason = "list.isEmpty() returns false for a list that is removed till empty.";
        result.passed = false;
    }
    const size_t size = list.size();
    if (size != 0) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
        result.reason = sstream.str();
        result.passed = false;
    }
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
    int *dataGet = list.getTail();
    int *data = list.removeTail();
    list.addTail(&a);
    int *dataGet2 = list.getTail();
    int *data2 = list.removeTail();
    int *dataGet3 = list.getTail();
    int *data3 = list.removeTail();
    int *dataGet4 = list.getTail();
    int *data4 = list.removeTail();
    result.passed = true;
    if (data != &z || data2 != &a || data3 != &y || data4 != &x) {
        result.reason = "list.remove...() returns wrong addresses or in wrong order.";
        result.passed = false;
    }
    if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
        result.reason = "list.get...() and list.remove...() do not return the same objects.";
        result.passed = false;
    }
    const bool isEmpty = list.isEmpty();
    if (!isEmpty) {
        result.reason = "list.isEmpty() returns false for a list that is removed till empty.";
        result.passed = false;
    }
    const size_t size = list.size();
    if (size != 0) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
        result.reason = sstream.str();
        result.passed = false;
    }
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
    int *dataGet = list.getTail();
    int *data = list.removeTail();
    list.addHead(&a);
    int *dataGet2 = list.getTail();
    int *data2 = list.removeTail();
    int *dataGet3 = list.getTail();
    int *data3 = list.removeTail();
    int *dataGet4 = list.getTail();
    int *data4 = list.removeTail();
    result.passed = true;
    if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
        result.reason = "list.remove...() returns wrong addresses or in wrong order.";
        result.passed = false;
    }
    if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
        result.reason = "list.get...() and list.remove...() do not return the same objects.";
        result.passed = false;
    }
    const bool isEmpty = list.isEmpty();
    if (!isEmpty) {
        result.reason = "list.isEmpty() returns false for a list that is removed till empty.";
        result.passed = false;
    }
    const size_t size = list.size();
    if (size != 0) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
        result.reason = sstream.str();
        result.passed = false;
    }
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
    int *dataGet = list.getHead();
    int *data = list.removeHead();
    list.addTail(&a);
    int *dataGet2 = list.getHead();
    int *data2 = list.removeHead();
    int *dataGet3 = list.getHead();
    int *data3 = list.removeHead();
    int *dataGet4 = list.getHead();
    int *data4 = list.removeHead();
    result.passed = true;
    if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
        result.reason = "list.remove...() returns wrong addresses or in wrong order.";
        result.passed = false;
    }
    if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
        result.reason = "list.get...() and list.remove...() do not return the same objects.";
        result.passed = false;
    }
    const bool isEmpty = list.isEmpty();
    if (!isEmpty) {
        result.reason = "list.isEmpty() returns false for a list that is removed till empty.";
        result.passed = false;
    }
    const size_t size = list.size();
    if (size != 0) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
        result.reason = sstream.str();
        result.passed = false;
    }
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
    int *dataGet = list.getHead();
    int *data = list.removeHead();
    list.addTail(&a);
    int *dataGet2 = list.getTail();
    int *data2 = list.removeTail();
    int *dataGet3 = list.getHead();
    int *data3 = list.removeHead();
    int *dataGet4 = list.getTail();
    int *data4 = list.removeTail();
    result.passed = true;
    if (data != &z || data2 != &a || data3 != &x || data4 != &y) {
        result.reason = "list.remove...() returns wrong addresses or in wrong order.";
        result.passed = false;
    }
    if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
        result.reason = "list.get...() and list.remove...() do not return the same objects.";
        result.passed = false;
    }
    const bool isEmpty = list.isEmpty();
    if (!isEmpty) {
        result.reason = "list.isEmpty() returns false for a list that is removed till empty.";
        result.passed = false;
    }
    const size_t size = list.size();
    if (size != 0) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
        result.reason = sstream.str();
        result.passed = false;
    }
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
    int *dataGet = list.getTail();
    int *data = list.removeTail();
    list.addTail(&a);
    int *dataGet2 = list.getHead();
    int *data2 = list.removeHead();
    int *dataGet3 = list.getTail();
    int *data3 = list.removeTail();
    int *dataGet4 = list.getHead();
    int *data4 = list.removeHead();
    result.passed = true;
    if (data != &y || data2 != &z || data3 != &a || data4 != &x) {
        result.reason = "list.remove...() returns wrong addresses or in wrong order.";
        result.passed = false;
    }
    if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
        result.reason = "list.get...() and list.remove...() do not return the same objects.";
        result.passed = false;
    }
    const bool isEmpty = list.isEmpty();
    if (!isEmpty) {
        result.reason = "list.isEmpty() returns false for a list that is removed till empty.";
        result.passed = false;
    }
    const size_t size = list.size();
    if (size != 0) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
        result.reason = sstream.str();
        result.passed = false;
    }
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
    int *dataGet = list.get(1);
    int *data = list.remove(1);
    list.insert(1, &a);
    int *dataGet2 = list.get(1);
    int *data2 = list.remove(1);
    int *dataGet3 = list.get(1);
    int *data3 = list.remove(1);
    int *dataGet4 = list.get(0);
    int *data4 = list.remove(0);
    result.passed = true;
    if (data != &y || data2 != &a || data3 != &z || data4 != &x) {
        result.reason = "list.remove...() returns wrong addresses or in wrong order.";
        result.passed = false;
    }
    if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
        result.reason = "list.get...() and list.remove...() do not return the same objects.";
        result.passed = false;
    }
    const bool isEmpty = list.isEmpty();
    if (!isEmpty) {
        result.reason = "list.isEmpty() returns false for a list that is removed till empty.";
        result.passed = false;
    }
    const size_t size = list.size();
    if (size != 0) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
        result.reason = sstream.str();
        result.passed = false;
    }
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
    int *dataGet = list.get(0);
    int *data = list.set(0, &j);
    const size_t size = list.size();
    int *dataGet2 = list.get(1);
    int *data2 = list.set(1, &k);
    const size_t size2 = list.size();
    int *dataGet3 = list.get(2);
    int *data3 = list.set(2, &l);
    const size_t size3 = list.size();
    int *dataGet4 = list.get(3);
    int *data4 = list.set(3, &m);
    const size_t size4 = list.size();
    result.passed = true;
    if (size != 4 || size2 != 4 || size3 != 4 || size4 != 4) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 4 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
        result.reason = "list.set() returns wrong order or invalid addresses for a list with 4 elements.";
        result.passed = false;
    }
    if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
        result.reason = "list.set() and list.get() returns different objects.";
        result.passed = false;
    }
    if (list.get(0) != &j || list.get(1) != &k || list.get(2) != &l || list.get(3) != &m) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 4 elements after list.set().";
        result.passed = false;
    }
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
    int *dataGet = list.get(0);
    int *data = list.set(0, &j);
    const size_t size = list.size();
    int *dataGet3 = list.get(2);
    int *data3 = list.set(2, &l);
    const size_t size3 = list.size();
    int *dataGet4 = list.get(3);
    int *data4 = list.set(3, &m);
    const size_t size4 = list.size();
    int *dataGet2 = list.get(1);
    int *data2 = list.set(1, &k);
    const size_t size2 = list.size();
    result.passed = true;
    if (size != 4 || size2 != 4 || size3 != 4 || size4 != 4) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 4 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
        result.reason = "list.set() returns wrong order or invalid addresses for a list with 4 elements.";
        result.passed = false;
    }
    if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
        result.reason = "list.set() and list.get() returns different objects.";
        result.passed = false;
    }
    if (list.get(0) != &j || list.get(1) != &k || list.get(2) != &l || list.get(3) != &m) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 4 elements after list.set().";
        result.passed = false;
    }
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
    int *dataGet4 = list.get(3);
    int *data4 = list.set(3, &m);
    const size_t size4 = list.size();
    int *dataGet = list.get(0);
    int *data = list.set(0, &j);
    const size_t size = list.size();
    int *dataGet2 = list.get(1);
    int *data2 = list.set(1, &k);
    const size_t size2 = list.size();
    int *dataGet3 = list.get(2);
    int *data3 = list.set(2, &l);
    const size_t size3 = list.size();
    result.passed = true;
    if (size != 4 || size2 != 4 || size3 != 4 || size4 != 4) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 4 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
        result.reason = "list.set() returns wrong order or invalid addresses for a list with 4 elements.";
        result.passed = false;
    }
    if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
        result.reason = "list.set() and list.get() returns different objects.";
        result.passed = false;
    }
    if (list.get(0) != &j || list.get(1) != &k || list.get(2) != &l || list.get(3) != &m) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 4 elements after list.set().";
        result.passed = false;
    }
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
    int *dataGet3 = list.get(2);
    int *data3 = list.set(2, &l);
    const size_t size3 = list.size();
    int *dataGet = list.get(0);
    int *data = list.set(0, &j);
    const size_t size = list.size();
    int *dataGet4 = list.get(3);
    int *data4 = list.set(3, &m);
    const size_t size4 = list.size();
    int *dataGet2 = list.get(1);
    int *data2 = list.set(1, &k);
    const size_t size2 = list.size();
    result.passed = true;
    if (size != 4 || size2 != 4 || size3 != 4 || size4 != 4) {
        std::stringstream sstream;
        sstream << "list.size() returns " << size << " for a list with 4 elements.";
        result.reason = sstream.str();
        result.passed = false;
    }
    if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
        result.reason = "list.set() returns wrong order or invalid addresses for a list with 4 elements.";
        result.passed = false;
    }
    if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
        result.reason = "list.set() and list.get() returns different objects.";
        result.passed = false;
    }
    if (list.get(0) != &j || list.get(1) != &k || list.get(2) != &l || list.get(3) != &m) {
        result.reason = "list.get() returns wrong order or invalid addresses for a list with 4 elements after list.set().";
        result.passed = false;
    }
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
    test_list_set_operations_4
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

#else // # ifdef LIST_TYPE

#error LIST_TYPE needs to be defined.

#endif // #ifdef LIST_TYPE