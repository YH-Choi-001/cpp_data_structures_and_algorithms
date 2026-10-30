/**
 * @file _testSort.cpp - Generic tests for sorting algorithms.
 * 
 * @copyright Copyright (c) 2026 YH Choi. All rights reserved.
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

#ifndef SORT_TYPE
#define SORT_TYPE QuickSort
#include "../../../src/algo/sort/QuickSort.h"
#endif

using yh::algo::SORT_TYPE;

#define ASSERT_IS_SORTED(array) { \
    if (sizeof(array) == 0) return; \
    const size_t len = sizeof(array)/sizeof(array[0]); \
    if (len <= 1) return; \
    auto prev = array[0]; \
    for (size_t i = 1; i < len; i++) { \
        auto next = array[i]; \
        ASSERT_FALSE(next < prev); \
        prev = next; \
    } \
}

#define ASSERT_ARRAY_EQUALS(lhs, rhs) { \
    const size_t lhsLen = sizeof(lhs)/sizeof(lhs[0]); \
    const size_t rhsLen = sizeof(rhs)/sizeof(rhs[0]); \
    ASSERT_EQUALS(lhsLen, rhsLen); \
    if (lhsLen != rhsLen) return; \
    for (size_t i = 0; i < lhsLen; i++) { \
        const auto lhsVal = lhs[i]; \
        const auto rhsVal = rhs[i]; \
        ASSERT_EQUALS(lhsVal, rhsVal); \
    } \
}

#define UNPAREN(...) __VA_ARGS__

#define CHECK_SORTING(unsorted, sorted) { \
    int elements[] = UNPAREN unsorted; \
    const int targets[] = UNPAREN sorted; \
    SORT_TYPE<int> sorter; \
    sorter.sort(elements, 0, sizeof(elements) > 0 ? sizeof(elements) / sizeof(elements[0]) : 0); \
    ASSERT_IS_SORTED(elements); \
    ASSERT_ARRAY_EQUALS(elements, targets); \
}

#define TESTCASE(id, unsorted, sorted) \
TEST_BEGIN(id) \
{ \
    CHECK_SORTING(unsorted, sorted); \
} \
TEST_END()

TESTCASE(
    empty_array,
    ({}),
    ({})
)

TESTCASE(
    array_of_0,
    ({0}),
    ({0})
)

TESTCASE(
    array_of_one_positive,
    ({8}),
    ({8})
)

TESTCASE(
    array_of_one_negative,
    ({-5}),
    ({-5})
)

TESTCASE(
    array_of_two_positive_sorted,
    ({3, 8}),
    ({3, 8})
)

TESTCASE(
    array_of_two_positive_unsorted,
    ({8, 3}),
    ({3, 8})
)

TESTCASE(
    array_of_two_equal,
    ({8, 8}),
    ({8, 8})
)

TESTCASE(
    array_of_negative_and_positive_sorted,
    ({-6, 2}),
    ({-6, 2})
)

TESTCASE(
    array_of_negative_and_positive_unsorted,
    ({2, -6}),
    ({-6, 2})
)

TESTCASE(
    array_of_two_negative_sorted,
    ({-8, -3}),
    ({-8, -3})
)

TESTCASE(
    array_of_two_negative_unsorted,
    ({-3, -8}),
    ({-8, -3})
)

TESTCASE(
    array_of_three,
    ({5, 8, -1}),
    ({-1, 5, 8})
)

TESTCASE(
    array_of_seven_positive,
    ({62, 15, 38, 41, 9, 28, 57}),
    ({9, 15, 28, 38, 41, 57, 62})
)

TESTCASE(
    series_a_array_of_10,
    ({-15, 30, -60, 76, -93, -5, 83, 22, -98, -64}),
    ({-98, -93, -64, -60, -15, -5, 22, 30, 76, 83})
)

TESTCASE(
    series_a_array_of_11,
    ({-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51}),
    ({-98, -93, -64, -60, -51, -15, -5, 22, 30, 76, 83})
)

TESTCASE(
    series_a_array_of_12,
    ({-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81}),
    ({-98, -93, -81, -64, -60, -51, -15, -5, 22, 30, 76, 83})
)

TESTCASE(
    series_a_array_of_13,
    ({-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81, -8}),
    ({-98, -93, -81, -64, -60, -51, -15, -8, -5, 22, 30, 76, 83})
)

TESTCASE(
    series_a_array_of_14,
    ({-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97}),
    ({-98, -93, -81, -64, -60, -51, -15, -8, -5, 22, 30, 76, 83, 97})
)

TESTCASE(
    series_a_array_of_15,
    ({-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34}),
    ({-98, -93, -81, -64, -60, -51, -15, -8, -5, 22, 30, 34, 76, 83, 97})
)

TESTCASE(
    series_a_array_of_16,
    ({-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34, 69}),
    ({-98, -93, -81, -64, -60, -51, -15, -8, -5, 22, 30, 34, 69, 76, 83, 97})
)

TESTCASE(
    series_a_array_of_17,
    ({-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34, 69, 38}),
    ({-98, -93, -81, -64, -60, -51, -15, -8, -5, 22, 30, 34, 38, 69, 76, 83, 97})
)

TESTCASE(
    series_a_array_of_18,
    ({-15, 30, -60, 76, 0, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34, 69, 38}),
    ({-98, -93, -81, -64, -60, -51, -15, -8, -5, 0, 22, 30, 34, 38, 69, 76, 83, 97})
)

TESTCASE(
    series_a_array_of_19,
    ({-15, 30, -60, 76, 0, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34, -89, 69, 38}),
    ({-98, -93, -89, -81, -64, -60, -51, -15, -8, -5, 0, 22, 30, 34, 38, 69, 76, 83, 97})
)

TESTCASE(
    series_a_sorted_array_of_19,
    ({-98, -93, -89, -81, -64, -60, -51, -15, -8, -5, 0, 22, 30, 34, 38, 69, 76, 83, 97}),
    ({-98, -93, -89, -81, -64, -60, -51, -15, -8, -5, 0, 22, 30, 34, 38, 69, 76, 83, 97})
)

TESTCASE(
    series_b_array_of_3,
    ({-61, -53, 96}),
    ({-61, -53, 96})
)

TESTCASE(
    series_b_array_of_4,
    ({-61, -53, 96, -3}),
    ({-61, -53, -3, 96})
)

TESTCASE(
    series_b_array_of_5,
    ({-61, -53, 96, -3, -70}),
    ({-70, -61, -53, -3, 96})
)

TESTCASE(
    series_b_array_of_6,
    ({-61, -53, 96, -3, -70, 89}),
    ({-70, -61, -53, -3, 89, 96})
)

TESTCASE(
    series_b_array_of_7,
    ({-61, -53, 96, -3, -70, 89, -68}),
    ({-70, -68, -61, -53, -3, 89, 96})
)

TESTCASE(
    series_b_array_of_8,
    ({-61, -53, 96, -3, -70, 89, -68, 19}),
    ({-70, -68, -61, -53, -3, 19, 89, 96})
)

TESTCASE(
    series_b_array_of_9,
    ({-61, -53, 96, -3, -70, 89, -68, 19, -42}),
    ({-70, -68, -61, -53, -42, -3, 19, 89, 96})
)

TESTCASE(
    series_b_array_of_10,
    ({-61, -53, 96, -3, -70, 89, -68, 19, -42, -22}),
    ({-70, -68, -61, -53, -42, -22, -3, 19, 89, 96})
)

TESTCASE(
    series_b_array_of_11,
    ({-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27}),
    ({-70, -68, -61, -53, -42, -27, -22, -3, 19, 89, 96})
)

TESTCASE(
    series_b_array_of_12,
    ({-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41}),
    ({-70, -68, -61, -53, -42, -41, -27, -22, -3, 19, 89, 96})
)

TESTCASE(
    series_b_array_of_13,
    ({-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72}),
    ({-70, -68, -61, -53, -42, -41, -27, -22, -3, 19, 72, 89, 96})
)

TESTCASE(
    series_b_array_of_14,
    ({-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72, 28}),
    ({-70, -68, -61, -53, -42, -41, -27, -22, -3, 19, 28, 72, 89, 96})
)

TESTCASE(
    series_b_array_of_15,
    ({-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72, 28, 23}),
    ({-70, -68, -61, -53, -42, -41, -27, -22, -3, 19, 23, 28, 72, 89, 96})
)

TESTCASE(
    series_b_array_of_16,
    ({-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72, 28, 23, 19}),
    ({-70, -68, -61, -53, -42, -41, -27, -22, -3, 19, 19, 23, 28, 72, 89, 96})
)

TESTCASE(
    series_b_array_of_17,
    ({-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72, 28, 23, 19, 58}),
    ({-70, -68, -61, -53, -42, -41, -27, -22, -3, 19, 19, 23, 28, 58, 72, 89, 96})
)

TESTCASE(
    series_b_array_of_18,
    ({-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72, 28, 23, 19, 58, -35}),
    ({-70, -68, -61, -53, -42, -41, -35, -27, -22, -3, 19, 19, 23, 28, 58, 72, 89, 96})
)

TESTCASE(
    series_b_sorted_array_of_18,
    ({-70, -68, -61, -53, -42, -41, -35, -27, -22, -3, 19, 19, 23, 28, 58, 72, 89, 96}),
    ({-70, -68, -61, -53, -42, -41, -35, -27, -22, -3, 19, 19, 23, 28, 58, 72, 89, 96})
)

const testfunc_t functions [] = {
    test_empty_array,
    test_array_of_0,
    test_array_of_one_positive,
    test_array_of_one_negative,
    test_array_of_two_positive_sorted,
    test_array_of_two_positive_unsorted,
    test_array_of_two_equal,
    test_array_of_negative_and_positive_sorted,
    test_array_of_negative_and_positive_unsorted,
    test_array_of_two_negative_sorted,
    test_array_of_two_negative_unsorted,
    test_array_of_three,
    test_array_of_seven_positive,
    test_series_a_array_of_10,
    test_series_a_array_of_11,
    test_series_a_array_of_12,
    test_series_a_array_of_13,
    test_series_a_array_of_14,
    test_series_a_array_of_15,
    test_series_a_array_of_16,
    test_series_a_array_of_17,
    test_series_a_array_of_18,
    test_series_a_array_of_19,
    test_series_a_sorted_array_of_19,
    test_series_b_array_of_3,
    test_series_b_array_of_4,
    test_series_b_array_of_5,
    test_series_b_array_of_6,
    test_series_b_array_of_7,
    test_series_b_array_of_8,
    test_series_b_array_of_9,
    test_series_b_array_of_10,
    test_series_b_array_of_11,
    test_series_b_array_of_12,
    test_series_b_array_of_13,
    test_series_b_array_of_14,
    test_series_b_array_of_15,
    test_series_b_array_of_16,
    test_series_b_array_of_17,
    test_series_b_array_of_18,
    test_series_b_sorted_array_of_18,
};

MAIN();
