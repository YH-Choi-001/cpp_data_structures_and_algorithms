/**
 * @file testSort.cpp - Typed tests run against every sorting algorithm.
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

#include <algorithm>
#include <string>
#include <type_traits>
#include <vector>

#include "LeakCheckedTest.h"

#include "../../../src/algo/sort/HeapSort.h"
#include "../../../src/algo/sort/InsertionSort.h"
#include "../../../src/algo/sort/MergeSort.h"
#include "../../../src/algo/sort/QuickSort.h"
#include "../../../src/algo/sort/SelectionSort.h"

using yh::algo::HeapSort;
using yh::algo::InsertionSort;
using yh::algo::MergeSort;
using yh::algo::QuickSort;
using yh::algo::SelectionSort;

template <typename SorterT>
class SortTest : public tests::LeakCheckedTest {
    protected:
        void expectSortsTo(std::vector<int> elements, const std::vector<int> &expected) {
            SorterT sorter;
            sorter.sort(elements.data(), 0, elements.size());
            EXPECT_TRUE(std::is_sorted(elements.begin(), elements.end()));
            EXPECT_EQ(elements, expected);
        }
};

using SortTypes = ::testing::Types<
    HeapSort<int>,
    InsertionSort<int>,
    MergeSort<int>,
    QuickSort<int>,
    SelectionSort<int>
>;

struct SortTypeNames {
    template <typename T>
    static std::string GetName(int) {
        if (std::is_same<T, HeapSort<int>>::value) return "HeapSort";
        if (std::is_same<T, InsertionSort<int>>::value) return "InsertionSort";
        if (std::is_same<T, MergeSort<int>>::value) return "MergeSort";
        if (std::is_same<T, QuickSort<int>>::value) return "QuickSort";
        if (std::is_same<T, SelectionSort<int>>::value) return "SelectionSort";
        return "Unknown";
    }
};

TYPED_TEST_SUITE(SortTest, SortTypes, SortTypeNames);

TYPED_TEST(SortTest, EmptyArray) {
    this->expectSortsTo(
        {},
        {}
    );
}

TYPED_TEST(SortTest, ArrayOf0) {
    this->expectSortsTo(
        {0},
        {0}
    );
}

TYPED_TEST(SortTest, ArrayOfOnePositive) {
    this->expectSortsTo(
        {8},
        {8}
    );
}

TYPED_TEST(SortTest, ArrayOfOneNegative) {
    this->expectSortsTo(
        {-5},
        {-5}
    );
}

TYPED_TEST(SortTest, ArrayOfTwoPositiveSorted) {
    this->expectSortsTo(
        {3, 8},
        {3, 8}
    );
}

TYPED_TEST(SortTest, ArrayOfTwoPositiveUnsorted) {
    this->expectSortsTo(
        {8, 3},
        {3, 8}
    );
}

TYPED_TEST(SortTest, ArrayOfTwoEqual) {
    this->expectSortsTo(
        {8, 8},
        {8, 8}
    );
}

TYPED_TEST(SortTest, ArrayOfNegativeAndPositiveSorted) {
    this->expectSortsTo(
        {-6, 2},
        {-6, 2}
    );
}

TYPED_TEST(SortTest, ArrayOfNegativeAndPositiveUnsorted) {
    this->expectSortsTo(
        {2, -6},
        {-6, 2}
    );
}

TYPED_TEST(SortTest, ArrayOfTwoNegativeSorted) {
    this->expectSortsTo(
        {-8, -3},
        {-8, -3}
    );
}

TYPED_TEST(SortTest, ArrayOfTwoNegativeUnsorted) {
    this->expectSortsTo(
        {-3, -8},
        {-8, -3}
    );
}

TYPED_TEST(SortTest, ArrayOfThree) {
    this->expectSortsTo(
        {5, 8, -1},
        {-1, 5, 8}
    );
}

TYPED_TEST(SortTest, ArrayOfSevenPositive) {
    this->expectSortsTo(
        {62, 15, 38, 41, 9, 28, 57},
        {9, 15, 28, 38, 41, 57, 62}
    );
}

TYPED_TEST(SortTest, SeriesAArrayOf10) {
    this->expectSortsTo(
        {-15, 30, -60, 76, -93, -5, 83, 22, -98, -64},
        {-98, -93, -64, -60, -15, -5, 22, 30, 76, 83}
    );
}

TYPED_TEST(SortTest, SeriesAArrayOf11) {
    this->expectSortsTo(
        {-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51},
        {-98, -93, -64, -60, -51, -15, -5, 22, 30, 76, 83}
    );
}

TYPED_TEST(SortTest, SeriesAArrayOf12) {
    this->expectSortsTo(
        {-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81},
        {-98, -93, -81, -64, -60, -51, -15, -5, 22, 30, 76, 83}
    );
}

TYPED_TEST(SortTest, SeriesAArrayOf13) {
    this->expectSortsTo(
        {-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81, -8},
        {-98, -93, -81, -64, -60, -51, -15, -8, -5, 22, 30, 76, 83}
    );
}

TYPED_TEST(SortTest, SeriesAArrayOf14) {
    this->expectSortsTo(
        {-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97},
        {-98, -93, -81, -64, -60, -51, -15, -8, -5, 22, 30, 76, 83, 97}
    );
}

TYPED_TEST(SortTest, SeriesAArrayOf15) {
    this->expectSortsTo(
        {-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34},
        {-98, -93, -81, -64, -60, -51, -15, -8, -5, 22, 30, 34, 76, 83, 97}
    );
}

TYPED_TEST(SortTest, SeriesAArrayOf16) {
    this->expectSortsTo(
        {-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34, 69},
        {-98, -93, -81, -64, -60, -51, -15, -8, -5, 22, 30, 34, 69, 76, 83, 97}
    );
}

TYPED_TEST(SortTest, SeriesAArrayOf17) {
    this->expectSortsTo(
        {-15, 30, -60, 76, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34, 69, 38},
        {-98, -93, -81, -64, -60, -51, -15, -8, -5, 22, 30, 34, 38, 69, 76, 83, 97}
    );
}

TYPED_TEST(SortTest, SeriesAArrayOf18) {
    this->expectSortsTo(
        {-15, 30, -60, 76, 0, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34, 69, 38},
        {-98, -93, -81, -64, -60, -51, -15, -8, -5, 0, 22, 30, 34, 38, 69, 76, 83, 97}
    );
}

TYPED_TEST(SortTest, SeriesAArrayOf19) {
    this->expectSortsTo(
        {-15, 30, -60, 76, 0, -93, -5, 83, 22, -98, -64, -51, -81, -8, 97, 34, -89, 69, 38},
        {-98, -93, -89, -81, -64, -60, -51, -15, -8, -5, 0, 22, 30, 34, 38, 69, 76, 83, 97}
    );
}

TYPED_TEST(SortTest, SeriesASortedArrayOf19) {
    this->expectSortsTo(
        {-98, -93, -89, -81, -64, -60, -51, -15, -8, -5, 0, 22, 30, 34, 38, 69, 76, 83, 97},
        {-98, -93, -89, -81, -64, -60, -51, -15, -8, -5, 0, 22, 30, 34, 38, 69, 76, 83, 97}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf3) {
    this->expectSortsTo(
        {-61, -53, 96},
        {-61, -53, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf4) {
    this->expectSortsTo(
        {-61, -53, 96, -3},
        {-61, -53, -3, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf5) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70},
        {-70, -61, -53, -3, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf6) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89},
        {-70, -61, -53, -3, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf7) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89, -68},
        {-70, -68, -61, -53, -3, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf8) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89, -68, 19},
        {-70, -68, -61, -53, -3, 19, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf9) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89, -68, 19, -42},
        {-70, -68, -61, -53, -42, -3, 19, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf10) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89, -68, 19, -42, -22},
        {-70, -68, -61, -53, -42, -22, -3, 19, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf11) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27},
        {-70, -68, -61, -53, -42, -27, -22, -3, 19, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf12) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41},
        {-70, -68, -61, -53, -42, -41, -27, -22, -3, 19, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf13) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72},
        {-70, -68, -61, -53, -42, -41, -27, -22, -3, 19, 72, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf14) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72, 28},
        {-70, -68, -61, -53, -42, -41, -27, -22, -3, 19, 28, 72, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf15) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72, 28, 23},
        {-70, -68, -61, -53, -42, -41, -27, -22, -3, 19, 23, 28, 72, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf16) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72, 28, 23, 19},
        {-70, -68, -61, -53, -42, -41, -27, -22, -3, 19, 19, 23, 28, 72, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf17) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72, 28, 23, 19, 58},
        {-70, -68, -61, -53, -42, -41, -27, -22, -3, 19, 19, 23, 28, 58, 72, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBArrayOf18) {
    this->expectSortsTo(
        {-61, -53, 96, -3, -70, 89, -68, 19, -42, -22, -27, -41, 72, 28, 23, 19, 58, -35},
        {-70, -68, -61, -53, -42, -41, -35, -27, -22, -3, 19, 19, 23, 28, 58, 72, 89, 96}
    );
}

TYPED_TEST(SortTest, SeriesBSortedArrayOf18) {
    this->expectSortsTo(
        {-70, -68, -61, -53, -42, -41, -35, -27, -22, -3, 19, 19, 23, 28, 58, 72, 89, 96},
        {-70, -68, -61, -53, -42, -41, -35, -27, -22, -3, 19, 19, 23, 28, 58, 72, 89, 96}
    );
}
