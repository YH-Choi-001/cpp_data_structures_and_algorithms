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

#ifndef MAP_TYPE
#define MAP_TYPE ArrayMap
#include "../../../src/structures/maps/ArrayMap.h"
#endif

using yh::structures::maps::Map;
using yh::structures::maps::MAP_TYPE;

#ifdef CONSTRUCTOR_ARGS
#define CONSTRUCT_EMPTY_MAP(map) \
  MAP_TYPE<int, int> map(CONSTRUCTOR_ARGS);
#else
#define CONSTRUCT_EMPTY_MAP(map) \
  MAP_TYPE<int, int> map;
#endif

TEST_BEGIN(empty_map)
{
    CONSTRUCT_EMPTY_MAP(map);
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
    CONSTRUCT_EMPTY_MAP(map);
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
    CONSTRUCT_EMPTY_MAP(map);
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
    CONSTRUCT_EMPTY_MAP(map);
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
    CONSTRUCT_EMPTY_MAP(map);
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
    CONSTRUCT_EMPTY_MAP(map);
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
    CONSTRUCT_EMPTY_MAP(map);
    int e = 18;
    int f = -6;
    int g = 59;
    int h = 47;

    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;

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
    CONSTRUCT_EMPTY_MAP(map);
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
        size_t indexOfKeyValuePair(int *const key, int *const value) {
            for (size_t i = 0; i < visitCounter; i++) {
                if (keys[i] == key && values[i] == value) {
                    return i;
                }
            }
            return visitCounter;
        }
};
#define ASSERT_VISITOR_CONTAINS(visitor,k,v) ASSERT_NOT_EQUALS(visitor.indexOfKeyValuePair(&k, &v), visitor.getVisitCounter())

TEST_BEGIN(map_foreach)
{
    CONSTRUCT_EMPTY_MAP(map);
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

    TestVisitor visitor;
    map.foreach(visitor);
    ASSERT_EQUALS(visitor.getVisitCounter(), 4);

    ASSERT_VISITOR_CONTAINS(visitor, e, b);
    ASSERT_VISITOR_CONTAINS(visitor, f, y);
    ASSERT_VISITOR_CONTAINS(visitor, g, c);
    ASSERT_VISITOR_CONTAINS(visitor, h, a);

    #ifdef YH_STRUCTURES_MAPS_SORTEDARRAYMAP_H
    ASSERT_EQUALS(visitor.getKey(0), &f);
    ASSERT_EQUALS(visitor.getValue(0), &y);
    ASSERT_EQUALS(visitor.getKey(1), &e);
    ASSERT_EQUALS(visitor.getValue(1), &b);
    ASSERT_EQUALS(visitor.getKey(2), &h);
    ASSERT_EQUALS(visitor.getValue(2), &a);
    ASSERT_EQUALS(visitor.getKey(3), &g);
    ASSERT_EQUALS(visitor.getValue(3), &c);
    #endif
}
TEST_END()

TEST_BEGIN(map_removeIf)
{
    CONSTRUCT_EMPTY_MAP(map);
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

#define SETUP_ITERATOR_MAP() \
    CONSTRUCT_EMPTY_MAP(map); \
    int e = 18; \
    int f = -6; \
    int g = 59; \
    int h = 47; \
 \
    int x = 35; \
    int y = -12; \
    int z = 0; \
    int a = -4; \
    int b = 87; \
    int c = -16; \
 \
    ASSERT_EQUALS(map.size(), 0); \
    ASSERT_IS_NULLPTR(map.put(&e, &x)); \
    ASSERT_EQUALS(map.size(), 1); \
    ASSERT_IS_NULLPTR(map.put(&f, &y)); \
    ASSERT_EQUALS(map.size(), 2); \
    ASSERT_EQUALS(map.get(&e), &x); \
    ASSERT_EQUALS(map.put(&e, &b), &x); \
    ASSERT_EQUALS(map.size(), 2); \
    ASSERT_EQUALS(map.get(&e), &b); \
    ASSERT_IS_NULLPTR(map.put(&g, &z)); \
    ASSERT_EQUALS(map.size(), 3); \
    ASSERT_IS_NULLPTR(map.put(&h, &a)); \
    ASSERT_EQUALS(map.size(), 4); \
    ASSERT_EQUALS(map.put(&g, &c), &z); \
    ASSERT_EQUALS(map.size(), 4); \
 \
    MAP_TYPE<int, int>::Iterator it(map); \


#define ASSERT_HAS_NEXT_ENTRY() { \
    for (int i = 0; i < 10; i++) { \
        ASSERT_TRUE(it.hasNext()); \
    } \
}

#define ASSERT_ENTRY_EQUALS(k,v) { \
    for (int i = 0; i < 10; i++) { \
        Map<int, int>::Entry *const entry = it.get(); \
        ASSERT_IS_NOT_NULLPTR(entry); \
        ASSERT_EQUALS(entry->key, &k); \
        ASSERT_EQUALS(entry->value, &v); \
    } \
}

#define ENTRY_REMOVAL_OPS(v,rm,checkRemovedIsHidden) { \
    if (rm) { \
        ASSERT_EQUALS(it.remove(), &v); \
        if (checkRemovedIsHidden) { \
            for (int i = 0; i < 10; i++) { \
                ASSERT_IS_NULLPTR(it.get()); \
            } \
        } \
        for (int i = 0; i < 10; i++) { \
            ASSERT_IS_NULLPTR(it.remove()); \
        } \
    } \
}

#define ASSERT_ENTRY_OPS(k,v,rm,checkRemovedIsHidden) { \
    ASSERT_ENTRY_EQUALS(k,v); \
    ENTRY_REMOVAL_OPS(v,rm,checkRemovedIsHidden); \
}

#define ASSERT_NEXT_ENTRY_IS(k,v,rm,checkRemovedIsHidden) { \
    ASSERT_HAS_NEXT_ENTRY(); \
    ASSERT_ENTRY_OPS(k,v,rm,checkRemovedIsHidden); \
    it.proceed(); \
}

#define ASSERT_NO_NEXT_ENTRY() { \
    ASSERT_FALSE(it.hasNext()); \
    for (int i = 0; i < 10; i++) { \
        ASSERT_IS_NULLPTR(it.get()); \
        ASSERT_IS_NULLPTR(it.remove()); \
    } \
    it.proceed(); \
}

#define ASSERT_NO_MORE_ENTRIES() { \
    for (int i = 0; i < 10; i++) { \
        ASSERT_NO_NEXT_ENTRY(); \
    } \
}

#define ARRAY_LEN(x) (sizeof(x)/sizeof((x)[0]))

#define ASSERT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden) \
    TestVisitor visitor; \
    int *const keys [] = {&e, &f, &g, &h}; \
    int *const values [] = {&b, &y, &c, &a}; \
    ASSERT_EQUALS(ARRAY_LEN(keys), ARRAY_LEN(values)); \
    ASSERT_EQUALS(ARRAY_LEN(keys), ARRAY_LEN(removeElements)); \
    ASSERT_EQUALS(ARRAY_LEN(keys), ARRAY_LEN(checkRemovedIsHidden)); \
    for (size_t i = 0; i < ARRAY_LEN(keys); i++) { \
        ASSERT_HAS_NEXT_ENTRY(); \
        yh::structures::maps::Map<int, int>::Entry *const entry = it.get(); \
        ASSERT_IS_NOT_NULLPTR(entry); \
        visitor.visit(*entry); \
        for (size_t j = 0; j < ARRAY_LEN(keys); j++) { \
            if (entry->key == keys[j]) { \
                ASSERT_ENTRY_OPS(*keys[j], *values[j], removeElements[j], checkRemovedIsHidden[j]); \
                break; \
            } \
        } \
        it.proceed(); \
    }


TEST_BEGIN(map_iterator_readonly)
{
    SETUP_ITERATOR_MAP();

    #ifndef YH_STRUCTURES_MAPS_SORTEDARRAYMAP_H
    const bool removeElements [] = {false, false, false, false};
    const bool checkRemovedIsHidden [] = {false, false, false, false};
    ASSERT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
    ASSERT_VISITOR_CONTAINS(visitor, e, b);
    ASSERT_VISITOR_CONTAINS(visitor, f, y);
    ASSERT_VISITOR_CONTAINS(visitor, g, c);
    ASSERT_VISITOR_CONTAINS(visitor, h, a);
    #else
    ASSERT_NEXT_ENTRY_IS(f, y, false, false);
    ASSERT_NEXT_ENTRY_IS(e, b, false, false);
    ASSERT_NEXT_ENTRY_IS(h, a, false, false);
    ASSERT_NEXT_ENTRY_IS(g, c, false, false);
    #endif
    ASSERT_NO_MORE_ENTRIES();

    ASSERT_EQUALS(map.size(), 4);
    ASSERT_EQUALS(map.get(&e), &b);
    ASSERT_EQUALS(map.get(&f), &y);
    ASSERT_EQUALS(map.get(&g), &c);
    ASSERT_EQUALS(map.get(&h), &a);
}
TEST_END()

TEST_BEGIN(map_iterator_remove_only_once_for_all_evens)
{
    SETUP_ITERATOR_MAP();

    #ifndef YH_STRUCTURES_MAPS_SORTEDARRAYMAP_H
    const bool removeElements [] = {false, true, false, true};
    const bool checkRemovedIsHidden [] = {false, false, false, false};
    ASSERT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
    ASSERT_VISITOR_CONTAINS(visitor, e, b);
    ASSERT_VISITOR_CONTAINS(visitor, f, y);
    ASSERT_VISITOR_CONTAINS(visitor, g, c);
    ASSERT_VISITOR_CONTAINS(visitor, h, a);
    ASSERT_NO_MORE_ENTRIES();

    ASSERT_EQUALS(map.size(), 2);
    ASSERT_EQUALS(map.get(&e), &b);
    ASSERT_IS_NULLPTR(map.get(&f));
    ASSERT_EQUALS(map.get(&g), &c);
    ASSERT_IS_NULLPTR(map.get(&h));
    #else
    ASSERT_NEXT_ENTRY_IS(f, y, false, false);
    ASSERT_NEXT_ENTRY_IS(e, b, true, false);
    ASSERT_NEXT_ENTRY_IS(h, a, false, false);
    ASSERT_NEXT_ENTRY_IS(g, c, true, false);
    ASSERT_NO_MORE_ENTRIES();

    ASSERT_EQUALS(map.size(), 2);
    ASSERT_EQUALS(map.get(&f), &y);
    ASSERT_IS_NULLPTR(map.get(&e));
    ASSERT_EQUALS(map.get(&h), &a);
    ASSERT_IS_NULLPTR(map.get(&g));
    #endif
}
TEST_END()

TEST_BEGIN(map_iterator_remove_only_once_for_all_odds)
{
    SETUP_ITERATOR_MAP();

    #ifndef YH_STRUCTURES_MAPS_SORTEDARRAYMAP_H
    const bool removeElements [] = {true, false, true, false};
    const bool checkRemovedIsHidden [] = {false, false, false, false};
    ASSERT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
    ASSERT_VISITOR_CONTAINS(visitor, e, b);
    ASSERT_VISITOR_CONTAINS(visitor, f, y);
    ASSERT_VISITOR_CONTAINS(visitor, g, c);
    ASSERT_VISITOR_CONTAINS(visitor, h, a);
    ASSERT_NO_MORE_ENTRIES();

    ASSERT_EQUALS(map.size(), 2);
    ASSERT_IS_NULLPTR(map.get(&e));
    ASSERT_EQUALS(map.get(&f), &y);
    ASSERT_IS_NULLPTR(map.get(&g));
    ASSERT_EQUALS(map.get(&h), &a);
    #else
    ASSERT_NEXT_ENTRY_IS(f, y, true, false);
    ASSERT_NEXT_ENTRY_IS(e, b, false, false);
    ASSERT_NEXT_ENTRY_IS(h, a, true, false);
    ASSERT_NEXT_ENTRY_IS(g, c, false, false);
    ASSERT_NO_MORE_ENTRIES();

    ASSERT_EQUALS(map.size(), 2);
    ASSERT_IS_NULLPTR(map.get(&f));
    ASSERT_EQUALS(map.get(&e), &b);
    ASSERT_IS_NULLPTR(map.get(&h));
    ASSERT_EQUALS(map.get(&g), &c);
    #endif
}
TEST_END()

TEST_BEGIN(map_iterator_remove_only_once_for_all_entries)
{
    SETUP_ITERATOR_MAP();

    #ifndef YH_STRUCTURES_MAPS_SORTEDARRAYMAP_H
    const bool removeElements [] = {true, true, true, true};
    const bool checkRemovedIsHidden [] = {false, false, false, false};
    ASSERT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
    ASSERT_VISITOR_CONTAINS(visitor, e, b);
    ASSERT_VISITOR_CONTAINS(visitor, f, y);
    ASSERT_VISITOR_CONTAINS(visitor, g, c);
    ASSERT_VISITOR_CONTAINS(visitor, h, a);
    #else
    ASSERT_NEXT_ENTRY_IS(f, y, true, false);
    ASSERT_NEXT_ENTRY_IS(e, b, true, false);
    ASSERT_NEXT_ENTRY_IS(h, a, true, false);
    ASSERT_NEXT_ENTRY_IS(g, c, true, false);
    #endif

    ASSERT_NO_MORE_ENTRIES();

    ASSERT_EQUALS(map.size(), 0);
    ASSERT_IS_NULLPTR(map.get(&e));
    ASSERT_IS_NULLPTR(map.get(&f));
    ASSERT_IS_NULLPTR(map.get(&g));
    ASSERT_IS_NULLPTR(map.get(&h));
}
TEST_END()

TEST_BEGIN(map_iterator_removed_even_elements_are_not_visible)
{
    SETUP_ITERATOR_MAP();

    #ifndef YH_STRUCTURES_MAPS_SORTEDARRAYMAP_H
    const bool removeElements [] = {false, true, false, true};
    const bool checkRemovedIsHidden [] = {true, true, true, true};
    ASSERT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
    ASSERT_VISITOR_CONTAINS(visitor, e, b);
    ASSERT_VISITOR_CONTAINS(visitor, f, y);
    ASSERT_VISITOR_CONTAINS(visitor, g, c);
    ASSERT_VISITOR_CONTAINS(visitor, h, a);
    ASSERT_NO_MORE_ENTRIES();

    ASSERT_EQUALS(map.size(), 2);
    ASSERT_EQUALS(map.get(&e), &b);
    ASSERT_IS_NULLPTR(map.get(&f));
    ASSERT_EQUALS(map.get(&g), &c);
    ASSERT_IS_NULLPTR(map.get(&h));
    #else
    ASSERT_NEXT_ENTRY_IS(f, y, false, true);
    ASSERT_NEXT_ENTRY_IS(e, b, true, true);
    ASSERT_NEXT_ENTRY_IS(h, a, false, true);
    ASSERT_NEXT_ENTRY_IS(g, c, true, true);
    ASSERT_NO_MORE_ENTRIES();

    ASSERT_EQUALS(map.size(), 2);
    ASSERT_EQUALS(map.get(&f), &y);
    ASSERT_IS_NULLPTR(map.get(&e));
    ASSERT_EQUALS(map.get(&h), &a);
    ASSERT_IS_NULLPTR(map.get(&g));
    #endif
}
TEST_END()

TEST_BEGIN(map_iterator_removed_odd_elements_are_not_visible)
{
    SETUP_ITERATOR_MAP();

    #ifndef YH_STRUCTURES_MAPS_SORTEDARRAYMAP_H
    const bool removeElements [] = {true, false, true, false};
    const bool checkRemovedIsHidden [] = {true, true, true, true};
    ASSERT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
    ASSERT_VISITOR_CONTAINS(visitor, e, b);
    ASSERT_VISITOR_CONTAINS(visitor, f, y);
    ASSERT_VISITOR_CONTAINS(visitor, g, c);
    ASSERT_VISITOR_CONTAINS(visitor, h, a);
    ASSERT_NO_MORE_ENTRIES();

    ASSERT_EQUALS(map.size(), 2);
    ASSERT_IS_NULLPTR(map.get(&e));
    ASSERT_EQUALS(map.get(&f), &y);
    ASSERT_IS_NULLPTR(map.get(&g));
    ASSERT_EQUALS(map.get(&h), &a);
    #else
    ASSERT_NEXT_ENTRY_IS(f, y, true, true);
    ASSERT_NEXT_ENTRY_IS(e, b, false, true);
    ASSERT_NEXT_ENTRY_IS(h, a, true, true);
    ASSERT_NEXT_ENTRY_IS(g, c, false, true);
    ASSERT_NO_MORE_ENTRIES();

    ASSERT_EQUALS(map.size(), 2);
    ASSERT_IS_NULLPTR(map.get(&f));
    ASSERT_EQUALS(map.get(&e), &b);
    ASSERT_IS_NULLPTR(map.get(&h));
    ASSERT_EQUALS(map.get(&g), &c);
    #endif
}
TEST_END()

TEST_BEGIN(map_iterator_removed_all_elements_are_not_visible)
{
    SETUP_ITERATOR_MAP();

    #ifndef YH_STRUCTURES_MAPS_SORTEDARRAYMAP_H
    const bool removeElements [] = {true, true, true, true};
    const bool checkRemovedIsHidden [] = {true, true, true, true};
    ASSERT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
    ASSERT_VISITOR_CONTAINS(visitor, e, b);
    ASSERT_VISITOR_CONTAINS(visitor, f, y);
    ASSERT_VISITOR_CONTAINS(visitor, g, c);
    ASSERT_VISITOR_CONTAINS(visitor, h, a);
    #else
    ASSERT_NEXT_ENTRY_IS(f, y, true, true);
    ASSERT_NEXT_ENTRY_IS(e, b, true, true);
    ASSERT_NEXT_ENTRY_IS(h, a, true, true);
    ASSERT_NEXT_ENTRY_IS(g, c, true, true);
    #endif

    ASSERT_NO_MORE_ENTRIES();

    ASSERT_EQUALS(map.size(), 0);
    ASSERT_IS_NULLPTR(map.get(&e));
    ASSERT_IS_NULLPTR(map.get(&f));
    ASSERT_IS_NULLPTR(map.get(&g));
    ASSERT_IS_NULLPTR(map.get(&h));
}
TEST_END()

TEST_BEGIN(map_iterator_remove_some)
{
    CONSTRUCT_EMPTY_MAP(map);
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

    MAP_TYPE<int, int>::Iterator it(map);

    while (it.hasNext()) {
        Map<int, int>::Entry *const entry = it.get();
        if ((*entry->key + *entry->value) % 2 == 0) {
            it.remove();
        }
        it.proceed();
    }
    ASSERT_NO_MORE_ENTRIES();

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
    test_map_removeIf,
    test_map_iterator_readonly,
    test_map_iterator_remove_only_once_for_all_evens,
    test_map_iterator_remove_only_once_for_all_odds,
    test_map_iterator_remove_only_once_for_all_entries,
    test_map_iterator_removed_even_elements_are_not_visible,
    test_map_iterator_removed_odd_elements_are_not_visible,
    test_map_iterator_removed_all_elements_are_not_visible,
    test_map_iterator_remove_some,
};

MAIN();
