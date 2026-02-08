/**
 * @file _testMap.cpp - Generic tests for map.
 * 
 * @copyright Copyright (c) 2026 YH Choi. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    map of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this map of conditions and the following disclaimer in the documentation
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

// #ifndef MAP_TYPE
// #define MAP_TYPE ArrayMap
// #include "../../../src/structures/maps/ArrayMap.h"
// #endif

#ifdef MAP_TYPE

using yh::structures::maps::Map;
using yh::structures::maps::MAP_TYPE;

TEST_BEGIN(empty_map)
{
    MAP_TYPE<int, int> map;
    int k1 = 35;
    int v1 = 18;
    int k2 = -84;
    int v2 = 96;
    int k3 = 0;
    int v3 = -59;
    int k4 = 19;
    // &v4 == nullptr
    // &k5 == nullptr
    int v5 = 62;
    ASSERT_TRUE(map.isEmpty());
    ASSERT_EQUALS(map.size(), 0);
    ASSERT_IS_NULLPTR(map.get(&k1));
    ASSERT_IS_NULLPTR(map.get(&k2));
    ASSERT_IS_NULLPTR(map.get(&k3));
    ASSERT_IS_NULLPTR(map.get(&k4));
    ASSERT_IS_NULLPTR(map.get(nullptr));
    ASSERT_IS_NULLPTR(map.get(&v1));
    ASSERT_IS_NULLPTR(map.get(&v2));
    ASSERT_IS_NULLPTR(map.get(&v3));
    ASSERT_IS_NULLPTR(map.get(&v5));
}
TEST_END()

TEST_BEGIN(map_with_1_element)
{
    MAP_TYPE<int, int> map;
    int k1 = 35;
    int v1 = 18;
    int k2 = -84;
    int v2 = 96;
    int k3 = 0;
    int v3 = -59;
    int k4 = 19;
    // &v4 == nullptr
    // &k5 == nullptr
    int v5 = 62;
    map.put(&k1, &v1);
    ASSERT_FALSE(map.isEmpty());
    ASSERT_EQUALS(map.size(), 1);
    ASSERT_EQUALS(map.get(&k1), &v1);
    ASSERT_IS_NULLPTR(map.get(&k2));
    ASSERT_IS_NULLPTR(map.get(&k3));
    ASSERT_IS_NULLPTR(map.get(&k4));
    ASSERT_IS_NULLPTR(map.get(nullptr));
    ASSERT_IS_NULLPTR(map.get(&v1));
    ASSERT_IS_NULLPTR(map.get(&v2));
    ASSERT_IS_NULLPTR(map.get(&v3));
    ASSERT_IS_NULLPTR(map.get(&v5));
}
TEST_END()

TEST_BEGIN(map_with_2_elements)
{
    MAP_TYPE<int, int> map;
    int k1 = 35;
    int v1 = 18;
    int k2 = -84;
    int v2 = 96;
    int k3 = 0;
    int v3 = -59;
    int k4 = 19;
    // &v4 == nullptr
    // &k5 == nullptr
    int v5 = 62;
    map.put(&k1, &v1);
    map.put(&k2, &v2);
    ASSERT_FALSE(map.isEmpty());
    ASSERT_EQUALS(map.size(), 2);
    ASSERT_EQUALS(map.get(&k1), &v1);
    ASSERT_EQUALS(map.get(&k2), &v2);
    ASSERT_IS_NULLPTR(map.get(&k3));
    ASSERT_IS_NULLPTR(map.get(&k4));
    ASSERT_IS_NULLPTR(map.get(nullptr));
    ASSERT_IS_NULLPTR(map.get(&v1));
    ASSERT_IS_NULLPTR(map.get(&v2));
    ASSERT_IS_NULLPTR(map.get(&v3));
    ASSERT_IS_NULLPTR(map.get(&v5));
}
TEST_END()

TEST_BEGIN(map_with_3_elements)
{
    MAP_TYPE<int, int> map;
    int k1 = 35;
    int v1 = 18;
    int k2 = -84;
    int v2 = 96;
    int k3 = 0;
    int v3 = -59;
    int k4 = 19;
    // &v4 == nullptr
    // &k5 == nullptr
    int v5 = 62;
    map.put(&k1, &v1);
    map.put(&k2, &v2);
    map.put(&k3, &v3);
    ASSERT_FALSE(map.isEmpty());
    ASSERT_EQUALS(map.size(), 3);
    ASSERT_EQUALS(map.get(&k1), &v1);
    ASSERT_EQUALS(map.get(&k2), &v2);
    ASSERT_EQUALS(map.get(&k3), &v3);
    ASSERT_IS_NULLPTR(map.get(&k4));
    ASSERT_IS_NULLPTR(map.get(nullptr));
    ASSERT_IS_NULLPTR(map.get(&v1));
    ASSERT_IS_NULLPTR(map.get(&v2));
    ASSERT_IS_NULLPTR(map.get(&v3));
    ASSERT_IS_NULLPTR(map.get(&v5));
}
TEST_END()

TEST_BEGIN(map_with_4_elements)
{
    MAP_TYPE<int, int> map;
    int k1 = 35;
    int v1 = 18;
    int k2 = -84;
    int v2 = 96;
    int k3 = 0;
    int v3 = -59;
    int k4 = 19;
    // &v4 == nullptr
    // &k5 == nullptr
    int v5 = 62;
    map.put(&k1, &v1);
    map.put(&k2, &v2);
    map.put(&k3, &v3);
    map.put(&k4, nullptr);
    ASSERT_FALSE(map.isEmpty());
    ASSERT_EQUALS(map.size(), 4);
    ASSERT_EQUALS(map.get(&k1), &v1);
    ASSERT_EQUALS(map.get(&k2), &v2);
    ASSERT_EQUALS(map.get(&k3), &v3);
    ASSERT_IS_NULLPTR(map.get(&k4));
    ASSERT_IS_NULLPTR(map.get(nullptr));
    ASSERT_IS_NULLPTR(map.get(&v1));
    ASSERT_IS_NULLPTR(map.get(&v2));
    ASSERT_IS_NULLPTR(map.get(&v3));
    ASSERT_IS_NULLPTR(map.get(&v5));
}
TEST_END()

TEST_BEGIN(map_with_5_elements)
{
    MAP_TYPE<int, int> map;
    int k1 = 35;
    int v1 = 18;
    int k2 = -84;
    int v2 = 96;
    int k3 = 0;
    int v3 = -59;
    int k4 = 19;
    // &v4 == nullptr
    // &k5 == nullptr
    int v5 = 62;
    map.put(&k1, &v1);
    map.put(&k2, &v2);
    map.put(&k3, &v3);
    map.put(&k4, nullptr);
    map.put(nullptr, &v5);
    ASSERT_FALSE(map.isEmpty());
    ASSERT_EQUALS(map.size(), 5);
    ASSERT_EQUALS(map.get(&k1), &v1);
    ASSERT_EQUALS(map.get(&k2), &v2);
    ASSERT_EQUALS(map.get(&k3), &v3);
    ASSERT_IS_NULLPTR(map.get(&k4));
    ASSERT_EQUALS(map.get(nullptr), &v5);
    ASSERT_IS_NULLPTR(map.get(&v1));
    ASSERT_IS_NULLPTR(map.get(&v2));
    ASSERT_IS_NULLPTR(map.get(&v3));
    ASSERT_IS_NULLPTR(map.get(&v5));
}
TEST_END()

TEST_BEGIN(map_get_remove_operations)
{
    MAP_TYPE<int, int> map;
    int e = 18;
    int f = -6;
    int g = 59;
    int h = 47;
    int i = -6;
    int j = -6;

    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    int b = 87;
    int c = -16;

    int dum1 = 19123;
    ASSERT_EQUALS(map.size(), 0);
    ASSERT_IS_NULLPTR(map.put(&e, &x));
    ASSERT_EQUALS(map.size(), 1);
    ASSERT_IS_NULLPTR(map.put(&f, &y));
    ASSERT_EQUALS(map.size(), 2);
    ASSERT_IS_NULLPTR(map.put(&g, &z));
    ASSERT_EQUALS(map.size(), 3);
    ASSERT_IS_NULLPTR(map.put(&h, &a));
    ASSERT_EQUALS(map.size(), 4);

    ASSERT_EQUALS(map.get(&f), &y);
    ASSERT_EQUALS(map.size(), 4);
    ASSERT_EQUALS(map.remove(&f), &y);
    ASSERT_EQUALS(map.size(), 3);

    ASSERT_EQUALS(map.get(&h), &a);
    ASSERT_EQUALS(map.size(), 3);
    ASSERT_EQUALS(map.remove(&h), &a);
    ASSERT_EQUALS(map.size(), 2);

    ASSERT_IS_NULLPTR(map.get(&dum1));
    ASSERT_EQUALS(map.size(), 2);
    ASSERT_IS_NULLPTR(map.remove(&dum1));
    ASSERT_EQUALS(map.size(), 2);

    ASSERT_EQUALS(map.get(&e), &x);
    ASSERT_EQUALS(map.size(), 2);
    ASSERT_EQUALS(map.remove(&e), &x);
    ASSERT_EQUALS(map.size(), 1);

    ASSERT_EQUALS(map.get(&g), &z);
    ASSERT_EQUALS(map.size(), 1);
    ASSERT_EQUALS(map.remove(&g), &z);
    ASSERT_EQUALS(map.size(), 0);

    ASSERT_TRUE(map.isEmpty());
}
TEST_END()

TEST_BEGIN(map_get_put_remove_operations)
{
    MAP_TYPE<int, int> map;
    int e = 18;
    int f = -6;
    int g = 59;
    int h = 47;

    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    int b = 87;
    int c = -16;

    int dum1 = 19123;
    ASSERT_EQUALS(map.size(), 0);
    ASSERT_IS_NULLPTR(map.put(&e, &x));
    ASSERT_EQUALS(map.size(), 1);
    ASSERT_IS_NULLPTR(map.put(&f, &y));
    ASSERT_EQUALS(map.size(), 2);
    ASSERT_EQUALS(map.get(&e), &x);
    ASSERT_EQUALS(map.put(&e, &b), &x);
    ASSERT_EQUALS(map.size(), 2);
    ASSERT_EQUALS(map.get(&e), &b);
    ASSERT_IS_NULLPTR(map.put(&g, &z));
    ASSERT_EQUALS(map.size(), 3);
    ASSERT_IS_NULLPTR(map.put(&h, &a));
    ASSERT_EQUALS(map.size(), 4);

    ASSERT_EQUALS(map.get(&f), &y);
    ASSERT_EQUALS(map.size(), 4);
    ASSERT_EQUALS(map.remove(&f), &y);
    ASSERT_EQUALS(map.size(), 3);

    ASSERT_EQUALS(map.get(&e), &b);
    ASSERT_EQUALS(map.put(&e, &c), &b);
    ASSERT_EQUALS(map.size(), 3);
    ASSERT_EQUALS(map.get(&e), &c);

    ASSERT_EQUALS(map.get(&h), &a);
    ASSERT_EQUALS(map.size(), 3);
    ASSERT_EQUALS(map.remove(&h), &a);
    ASSERT_EQUALS(map.size(), 2);

    ASSERT_IS_NULLPTR(map.get(&dum1));
    ASSERT_EQUALS(map.size(), 2);
    ASSERT_IS_NULLPTR(map.remove(&dum1));
    ASSERT_EQUALS(map.size(), 2);

    ASSERT_EQUALS(map.get(&e), &c);
    ASSERT_EQUALS(map.size(), 2);
    ASSERT_EQUALS(map.remove(&e), &c);
    ASSERT_EQUALS(map.size(), 1);

    ASSERT_EQUALS(map.get(&g), &z);
    ASSERT_EQUALS(map.size(), 1);
    ASSERT_EQUALS(map.remove(&g), &z);
    ASSERT_EQUALS(map.size(), 0);

    ASSERT_TRUE(map.isEmpty());
}
TEST_END()

TEST_BEGIN(map_foreach)
{
    MAP_TYPE<int, int> map;
    int e = 18;
    int f = -6;
    int g = 59;
    int h = 47;

    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;
    int b = 87;
    int c = -16;

    ASSERT_EQUALS(map.size(), 0);
    ASSERT_IS_NULLPTR(map.put(&e, &x));
    ASSERT_EQUALS(map.size(), 1);
    ASSERT_IS_NULLPTR(map.put(&f, &y));
    ASSERT_EQUALS(map.size(), 2);
    ASSERT_EQUALS(map.get(&e), &x);
    ASSERT_EQUALS(map.put(&e, &b), &x);
    ASSERT_EQUALS(map.size(), 2);
    ASSERT_EQUALS(map.get(&e), &b);
    ASSERT_IS_NULLPTR(map.put(&g, &z));
    ASSERT_EQUALS(map.size(), 3);
    ASSERT_IS_NULLPTR(map.put(&h, &a));
    ASSERT_EQUALS(map.size(), 4);
    ASSERT_EQUALS(map.put(&g, &c), &z);
    ASSERT_EQUALS(map.size(), 4);

    class TestVisitor : public Map<int, int>::Visitor {
        private:
            int *keys [16];
            int *values [16];
            int visitCounter;
        public:
            TestVisitor() :
                keys{nullptr},
                values{nullptr},
                visitCounter(0)
            {
                //
            }
            void visit(Map<int, int>::Entry entry) override {
                keys[visitCounter] = entry.key;
                values[visitCounter] = entry.value;
                visitCounter++;
            }
            int getVisitCounter() {
                return visitCounter;
            }
            int *getKey(const size_t index) {
                if (index >= visitCounter) {
                    return nullptr;
                }
                return keys[index];
            }
            int *getValue(const size_t index) {
                if (index >= visitCounter) {
                    return nullptr;
                }
                return values[index];
            }
    };

    TestVisitor visitor;
    map.foreach(visitor);
    ASSERT_EQUALS(visitor.getVisitCounter(), 4);
    ASSERT_EQUALS(visitor.getKey(0), &e);
    ASSERT_EQUALS(visitor.getValue(0), &b);
    ASSERT_EQUALS(visitor.getKey(1), &f);
    ASSERT_EQUALS(visitor.getValue(1), &y);
    ASSERT_EQUALS(visitor.getKey(2), &g);
    ASSERT_EQUALS(visitor.getValue(2), &c);
    ASSERT_EQUALS(visitor.getKey(3), &h);
    ASSERT_EQUALS(visitor.getValue(3), &a);
}
TEST_END()

TEST_BEGIN(map_removeIf)
{
    MAP_TYPE<int, int> map;
    int e = 18;
    int f = -6;
    int g = 59;
    int h = 47;

    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;

    ASSERT_EQUALS(map.size(), 0);
    ASSERT_IS_NULLPTR(map.put(&e, &x));
    ASSERT_EQUALS(map.size(), 1);
    ASSERT_IS_NULLPTR(map.put(&f, &y));
    ASSERT_EQUALS(map.size(), 2);
    ASSERT_IS_NULLPTR(map.put(&g, &z));
    ASSERT_EQUALS(map.size(), 3);
    ASSERT_IS_NULLPTR(map.put(&h, &a));
    ASSERT_EQUALS(map.size(), 4);
    map.removeIf([](Map<int, int>::Entry entry) -> bool {
        return (*entry.key + *entry.value) % 2 == 0;
    });
    ASSERT_EQUALS(map.size(), 3);
    ASSERT_EQUALS(map.get(&e), &x);
    ASSERT_IS_NULLPTR(map.get(&f));
    ASSERT_EQUALS(map.get(&g), &z);
    ASSERT_EQUALS(map.get(&h), &a);
}
TEST_END()

const testfunc_t functions [] = {
    test_empty_map,
    test_map_with_1_element,
    test_map_with_2_elements,
    test_map_with_3_elements,
    test_map_with_4_elements,
    test_map_with_5_elements,
    test_map_get_remove_operations,
    test_map_get_put_remove_operations,
    test_map_foreach,
    test_map_removeIf
};

MAIN();

#else // # ifdef MAP_TYPE

#error MAP_TYPE needs to be defined.

#endif // #ifdef MAP_TYPE