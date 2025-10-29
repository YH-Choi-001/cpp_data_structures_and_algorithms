/**
 * @file testArrayList.cpp - Tests for array lists.
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

#include "../../../src/structures/lists/ArrayList.h"

#include <iostream>

using yh::structures::lists::ArrayList;

int main() {
    std::cout << "Testing " << __FILE__ << std::endl;
    unsigned int failed_testcase_count = 0;
    size_t testcase_index = 0;

    {
        ArrayList<int> list;
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns false for an empty list.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        list.addHead(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns true for a list with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        list.addTail(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns true for a list with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        list.insert(0, &x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns true for a list with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        list.insert(1, &x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns false for an empty list but with an element inserted at an invalid index.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.addHead(&x);
        list.addHead(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns true for a list with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.addHead(&x);
        list.addTail(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns true for a list with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.addTail(&x);
        list.addHead(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns true for a list with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.addTail(&x);
        list.addTail(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns true for a list with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.insert(0, &x);
        list.insert(0, &y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns true for a list with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.insert(0, &x);
        list.insert(1, &y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns true for a list with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.insert(0, &x);
        list.insert(2, &y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns true for a list with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.insert(1, &x);
        list.insert(0, &y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        if (!list.isEmpty()) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.isEmpty() returns true for a list with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 0) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for an empty list.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        list.addHead(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for a list with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        list.addTail(&x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for a list with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        list.insert(0, &x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for a list with 1 element.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        list.insert(1, &x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 0) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for an empty list but with an element inserted at an invalid index.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.addHead(&x);
        list.addHead(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 2) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for a list with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.addHead(&x);
        list.addTail(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 2) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for a list with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.addTail(&x);
        list.addHead(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 2) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for a list with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.addTail(&x);
        list.addTail(&y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 2) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for a list with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.insert(0, &x);
        list.insert(0, &y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 2) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for a list with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.insert(0, &x);
        list.insert(1, &y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 2) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for a list with 2 elements.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.insert(0, &x);
        list.insert(2, &y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for a list with 1 element and another element inserted at an invalid index.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        list.insert(1, &x);
        list.insert(0, &y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        if (size == 1) {
            std::cout << " passed.";
        } else {
            std::cout << " failed: list.size() returns " << size << " for a list with 1 element and another element inserted at an invalid index.";
            ++failed_testcase_count;
        }
        std::cout << std::endl;
        ++testcase_index;
    }

    {
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        list.addHead(&x);
        list.addHead(&y);
        list.addHead(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 3) {
            std::cout << " failed: list.size() returns " << size << " for a list with 3 elements.";
            passed = false;
        }
        if (list.get(0) != &z || list.get(1) != &y || list.get(2) != &x) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 3 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        list.addTail(&x);
        list.addTail(&y);
        list.addTail(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 3) {
            std::cout << " failed: list.size() returns " << size << " for a list with 3 elements.";
            passed = false;
        }
        if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 3 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        list.addHead(&x);
        list.addTail(&y);
        list.addHead(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 3) {
            std::cout << " failed: list.size() returns " << size << " for a list with 3 elements.";
            passed = false;
        }
        if (list.get(0) != &z || list.get(1) != &x || list.get(2) != &y) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 3 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        list.addTail(&x);
        list.addHead(&y);
        list.addTail(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 3) {
            std::cout << " failed: list.size() returns " << size << " for a list with 3 elements.";
            passed = false;
        }
        if (list.get(0) != &y || list.get(1) != &x || list.get(2) != &z) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 3 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        list.addHead(&x);
        list.addHead(&y);
        list.addTail(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 3) {
            std::cout << " failed: list.size() returns " << size << " for a list with 3 elements.";
            passed = false;
        }
        if (list.get(0) != &y || list.get(1) != &x || list.get(2) != &z) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 3 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        list.addHead(&x);
        list.addTail(&y);
        list.addTail(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 3) {
            std::cout << " failed: list.size() returns " << size << " for a list with 3 elements.";
            passed = false;
        }
        if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 3 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        list.addTail(&x);
        list.addTail(&y);
        list.addHead(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 3) {
            std::cout << " failed: list.size() returns " << size << " for a list with 3 elements.";
            passed = false;
        }
        if (list.get(0) != &z || list.get(1) != &x || list.get(2) != &y) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 3 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        list.addTail(&x);
        list.addHead(&y);
        list.addHead(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 3) {
            std::cout << " failed: list.size() returns " << size << " for a list with 3 elements.";
            passed = false;
        }
        if (list.get(0) != &z || list.get(1) != &y || list.get(2) != &x) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 3 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        list.addTail(&x);
        list.addTail(&y);
        list.addTail(&z);
        list.addTail(&a);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 4) {
            std::cout << " failed: list.size() returns " << size << " for a list with 4 elements.";
            passed = false;
        }
        if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z || list.get(3) != &a) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 4 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        list.insert(0, &x);
        list.insert(1, &y);
        list.insert(2, &z);
        list.insert(3, &a);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 4) {
            std::cout << " failed: list.size() returns " << size << " for a list with 4 elements.";
            passed = false;
        }
        if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z || list.get(3) != &a) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 4 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        list.insert(0, &y);
        list.insert(1, &a);
        list.insert(1, &z);
        list.insert(0, &x);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 4) {
            std::cout << " failed: list.size() returns " << size << " for a list with 4 elements.";
            passed = false;
        }
        if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z || list.get(3) != &a) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 4 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        list.insert(0, &a);
        list.insert(0, &x);
        list.insert(1, &y);
        list.insert(2, &z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 4) {
            std::cout << " failed: list.size() returns " << size << " for a list with 4 elements.";
            passed = false;
        }
        if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z || list.get(3) != &a) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 4 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        list.insert(0, &x);
        list.insert(1, &a);
        list.insert(1, &y);
        list.insert(2, &z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        const size_t size = list.size();
        bool passed = true;
        if (size != 4) {
            std::cout << " failed: list.size() returns " << size << " for a list with 4 elements.";
            passed = false;
        }
        if (list.get(0) != &x || list.get(1) != &y || list.get(2) != &z || list.get(3) != &a) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 4 elements.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        list.addHead(&x);
        list.addHead(&y);
        list.addHead(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *dataGet = list.getHead();
        int *data = list.removeHead();
        list.addHead(&a);
        int *dataGet2 = list.getHead();
        int *data2 = list.removeHead();
        int *dataGet3 = list.getHead();
        int *data3 = list.removeHead();
        int *dataGet4 = list.getHead();
        int *data4 = list.removeHead();
        bool passed = true;
        if (data != &z || data2 != &a || data3 != &y || data4 != &x) {
            std::cout << " failed: list.remove...() returns wrong addresses or in wrong order.";
            passed = false;
        }
        if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
            std::cout << " failed: list.get...() and list.remove...() do not return the same objects.";
            passed = false;
        }
        const bool isEmpty = list.isEmpty();
        if (!isEmpty) {
            std::cout << " failed: list.isEmpty() returns false for a list that is removed till empty.";
            passed = false;
        }
        const size_t size = list.size();
        if (size != 0) {
            std::cout << " failed: list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        list.addTail(&x);
        list.addTail(&y);
        list.addTail(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *dataGet = list.getTail();
        int *data = list.removeTail();
        list.addTail(&a);
        int *dataGet2 = list.getTail();
        int *data2 = list.removeTail();
        int *dataGet3 = list.getTail();
        int *data3 = list.removeTail();
        int *dataGet4 = list.getTail();
        int *data4 = list.removeTail();
        bool passed = true;
        if (data != &z || data2 != &a || data3 != &y || data4 != &x) {
            std::cout << " failed: list.remove...() returns wrong addresses or in wrong order.";
            passed = false;
        }
        if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
            std::cout << " failed: list.get...() and list.remove...() do not return the same objects.";
            passed = false;
        }
        const bool isEmpty = list.isEmpty();
        if (!isEmpty) {
            std::cout << " failed: list.isEmpty() returns false for a list that is removed till empty.";
            passed = false;
        }
        const size_t size = list.size();
        if (size != 0) {
            std::cout << " failed: list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        list.addHead(&x);
        list.addHead(&y);
        list.addHead(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *dataGet = list.getTail();
        int *data = list.removeTail();
        list.addHead(&a);
        int *dataGet2 = list.getTail();
        int *data2 = list.removeTail();
        int *dataGet3 = list.getTail();
        int *data3 = list.removeTail();
        int *dataGet4 = list.getTail();
        int *data4 = list.removeTail();
        bool passed = true;
        if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
            std::cout << " failed: list.remove...() returns wrong addresses or in wrong order.";
            passed = false;
        }
        if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
            std::cout << " failed: list.get...() and list.remove...() do not return the same objects.";
            passed = false;
        }
        const bool isEmpty = list.isEmpty();
        if (!isEmpty) {
            std::cout << " failed: list.isEmpty() returns false for a list that is removed till empty.";
            passed = false;
        }
        const size_t size = list.size();
        if (size != 0) {
            std::cout << " failed: list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        list.addTail(&x);
        list.addTail(&y);
        list.addTail(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *dataGet = list.getHead();
        int *data = list.removeHead();
        list.addTail(&a);
        int *dataGet2 = list.getHead();
        int *data2 = list.removeHead();
        int *dataGet3 = list.getHead();
        int *data3 = list.removeHead();
        int *dataGet4 = list.getHead();
        int *data4 = list.removeHead();
        bool passed = true;
        if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
            std::cout << " failed: list.remove...() returns wrong addresses or in wrong order.";
            passed = false;
        }
        if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
            std::cout << " failed: list.get...() and list.remove...() do not return the same objects.";
            passed = false;
        }
        const bool isEmpty = list.isEmpty();
        if (!isEmpty) {
            std::cout << " failed: list.isEmpty() returns false for a list that is removed till empty.";
            passed = false;
        }
        const size_t size = list.size();
        if (size != 0) {
            std::cout << " failed: list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        list.addHead(&x);
        list.addTail(&y);
        list.addHead(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *dataGet = list.getHead();
        int *data = list.removeHead();
        list.addTail(&a);
        int *dataGet2 = list.getTail();
        int *data2 = list.removeTail();
        int *dataGet3 = list.getHead();
        int *data3 = list.removeHead();
        int *dataGet4 = list.getTail();
        int *data4 = list.removeTail();
        bool passed = true;
        if (data != &z || data2 != &a || data3 != &x || data4 != &y) {
            std::cout << " failed: list.remove...() returns wrong addresses or in wrong order.";
            passed = false;
        }
        if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
            std::cout << " failed: list.get...() and list.remove...() do not return the same objects.";
            passed = false;
        }
        const bool isEmpty = list.isEmpty();
        if (!isEmpty) {
            std::cout << " failed: list.isEmpty() returns false for a list that is removed till empty.";
            passed = false;
        }
        const size_t size = list.size();
        if (size != 0) {
            std::cout << " failed: list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        list.addHead(&x);
        list.addTail(&y);
        list.addHead(&z);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *dataGet = list.getTail();
        int *data = list.removeTail();
        list.addTail(&a);
        int *dataGet2 = list.getHead();
        int *data2 = list.removeHead();
        int *dataGet3 = list.getTail();
        int *data3 = list.removeTail();
        int *dataGet4 = list.getHead();
        int *data4 = list.removeHead();
        bool passed = true;
        if (data != &y || data2 != &z || data3 != &a || data4 != &x) {
            std::cout << " failed: list.remove...() returns wrong addresses or in wrong order.";
            passed = false;
        }
        if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
            std::cout << " failed: list.get...() and list.remove...() do not return the same objects.";
            passed = false;
        }
        const bool isEmpty = list.isEmpty();
        if (!isEmpty) {
            std::cout << " failed: list.isEmpty() returns false for a list that is removed till empty.";
            passed = false;
        }
        const size_t size = list.size();
        if (size != 0) {
            std::cout << " failed: list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
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
        ArrayList<int> list;
        int x = 35;
        int y = -12;
        int z = 0;
        int a = -4;
        list.insert(0, &x);
        list.insert(1, &z);
        list.insert(1, &y);
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        int *dataGet = list.get(1);
        int *data = list.remove(1);
        list.insert(1, &a);
        int *dataGet2 = list.get(1);
        int *data2 = list.remove(1);
        int *dataGet3 = list.get(1);
        int *data3 = list.remove(1);
        int *dataGet4 = list.get(0);
        int *data4 = list.remove(0);
        bool passed = true;
        if (data != &y || data2 != &a || data3 != &z || data4 != &x) {
            std::cout << " failed: list.remove...() returns wrong addresses or in wrong order.";
            passed = false;
        }
        if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
            std::cout << " failed: list.get...() and list.remove...() do not return the same objects.";
            passed = false;
        }
        const bool isEmpty = list.isEmpty();
        if (!isEmpty) {
            std::cout << " failed: list.isEmpty() returns false for a list that is removed till empty.";
            passed = false;
        }
        const size_t size = list.size();
        if (size != 0) {
            std::cout << " failed: list.size() returns " << size << " instead of 0 for a list that is removed till empty.";
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
        ArrayList<int> list;
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
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        bool passed = true;
        if (size != 4 || size2 != 4 || size3 != 4 || size4 != 4) {
            std::cout << " failed: list.size() returns " << size << " for a list with 4 elements.";
            passed = false;
        }
        if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
            std::cout << " failed: list.set() returns wrong order or invalid addresses for a list with 4 elements.";
            passed = false;
        }
        if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
            std::cout << " failed: list.set() and list.get() returns different objects.";
            passed = false;
        }
        if (list.get(0) != &j || list.get(1) != &k || list.get(2) != &l || list.get(3) != &m) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 4 elements after list.set().";
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
        ArrayList<int> list;
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
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        bool passed = true;
        if (size != 4 || size2 != 4 || size3 != 4 || size4 != 4) {
            std::cout << " failed: list.size() returns " << size << " for a list with 4 elements.";
            passed = false;
        }
        if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
            std::cout << " failed: list.set() returns wrong order or invalid addresses for a list with 4 elements.";
            passed = false;
        }
        if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
            std::cout << " failed: list.set() and list.get() returns different objects.";
            passed = false;
        }
        if (list.get(0) != &j || list.get(1) != &k || list.get(2) != &l || list.get(3) != &m) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 4 elements after list.set().";
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
        ArrayList<int> list;
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
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        bool passed = true;
        if (size != 4 || size2 != 4 || size3 != 4 || size4 != 4) {
            std::cout << " failed: list.size() returns " << size << " for a list with 4 elements.";
            passed = false;
        }
        if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
            std::cout << " failed: list.set() returns wrong order or invalid addresses for a list with 4 elements.";
            passed = false;
        }
        if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
            std::cout << " failed: list.set() and list.get() returns different objects.";
            passed = false;
        }
        if (list.get(0) != &j || list.get(1) != &k || list.get(2) != &l || list.get(3) != &m) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 4 elements after list.set().";
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
        ArrayList<int> list;
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
        std::cout << "Testcase #" << testcase_index << " at line " << __LINE__;
        bool passed = true;
        if (size != 4 || size2 != 4 || size3 != 4 || size4 != 4) {
            std::cout << " failed: list.size() returns " << size << " for a list with 4 elements.";
            passed = false;
        }
        if (data != &x || data2 != &y || data3 != &z || data4 != &a) {
            std::cout << " failed: list.set() returns wrong order or invalid addresses for a list with 4 elements.";
            passed = false;
        }
        if (data != dataGet || data2 != dataGet2 || data3 != dataGet3 || data4 != dataGet4) {
            std::cout << " failed: list.set() and list.get() returns different objects.";
            passed = false;
        }
        if (list.get(0) != &j || list.get(1) != &k || list.get(2) != &l || list.get(3) != &m) {
            std::cout << " failed: list.get() returns wrong order or invalid addresses for a list with 4 elements after list.set().";
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

    if (failed_testcase_count == 0) {
        std::cout << "All passed: " << __FILE__ << std::endl;
    } else {
        std::cout << failed_testcase_count << " failed: " << __FILE__ << std::endl;
    }
    return failed_testcase_count;
}