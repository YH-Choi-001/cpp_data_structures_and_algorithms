/**
 * @file testMap.cpp - Typed tests run against every map implementation.
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

#include <cstddef>
#include <string>
#include <type_traits>

#include "LeakCheckedTest.h"

#include "../../../src/structures/maps/ArrayMap.h"
#include "../../../src/structures/maps/HashMap.h"
#include "../../../src/structures/maps/SortedArrayMap.h"

using yh::structures::maps::ArrayMap;
using yh::structures::maps::HashMap;
using yh::structures::maps::Map;
using yh::structures::maps::SortedArrayMap;

/**
 * @brief HashMap with the hash function used by these tests, so that every
 * type under test is default-constructible.
 */
class IntHashMap : public HashMap<int, int> {
    public:
        IntHashMap() : HashMap<int, int>(hashKey) {}
    private:
        static size_t hashKey(int *const k) {
            return k != nullptr ? *k : 0;
        }
};

/**
 * @brief Whether iterating over the map visits the entries in key order, which
 * lets the tests assert the exact visiting order instead of only the contents.
 */
template <typename MapT>
struct IteratesInKeyOrder : std::false_type {};
template <>
struct IteratesInKeyOrder<SortedArrayMap<int, int>> : std::true_type {};

template <typename MapT>
class MapTest : public tests::LeakCheckedTest {};

using MapTypes = ::testing::Types<
    ArrayMap<int, int>,
    SortedArrayMap<int, int>,
    IntHashMap
>;

struct MapTypeNames {
    template <typename T>
    static std::string GetName(int) {
        if (std::is_same<T, ArrayMap<int, int>>::value) return "ArrayMap";
        if (std::is_same<T, SortedArrayMap<int, int>>::value) return "SortedArrayMap";
        if (std::is_same<T, IntHashMap>::value) return "HashMap";
        return "Unknown";
    }
};

TYPED_TEST_SUITE(MapTest, MapTypes, MapTypeNames);

TYPED_TEST(MapTest, EmptyMap) {
    TypeParam map;
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
    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(), 0u);
    EXPECT_EQ(map.get(&k1), nullptr);
    EXPECT_EQ(map.get(&k2), nullptr);
    EXPECT_EQ(map.get(&k3), nullptr);
    EXPECT_EQ(map.get(&k4), nullptr);
    EXPECT_EQ(map.get(nullptr), nullptr);
    EXPECT_EQ(map.get(&v1), nullptr);
    EXPECT_EQ(map.get(&v2), nullptr);
    EXPECT_EQ(map.get(&v3), nullptr);
    EXPECT_EQ(map.get(&v5), nullptr);
}

TYPED_TEST(MapTest, With1Element) {
    TypeParam map;
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
    EXPECT_FALSE(map.isEmpty());
    EXPECT_EQ(map.size(), 1u);
    EXPECT_EQ(map.get(&k1), &v1);
    EXPECT_EQ(map.get(&k2), nullptr);
    EXPECT_EQ(map.get(&k3), nullptr);
    EXPECT_EQ(map.get(&k4), nullptr);
    EXPECT_EQ(map.get(nullptr), nullptr);
    EXPECT_EQ(map.get(&v1), nullptr);
    EXPECT_EQ(map.get(&v2), nullptr);
    EXPECT_EQ(map.get(&v3), nullptr);
    EXPECT_EQ(map.get(&v5), nullptr);
}

TYPED_TEST(MapTest, With2Elements) {
    TypeParam map;
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
    EXPECT_FALSE(map.isEmpty());
    EXPECT_EQ(map.size(), 2u);
    EXPECT_EQ(map.get(&k1), &v1);
    EXPECT_EQ(map.get(&k2), &v2);
    EXPECT_EQ(map.get(&k3), nullptr);
    EXPECT_EQ(map.get(&k4), nullptr);
    EXPECT_EQ(map.get(nullptr), nullptr);
    EXPECT_EQ(map.get(&v1), nullptr);
    EXPECT_EQ(map.get(&v2), nullptr);
    EXPECT_EQ(map.get(&v3), nullptr);
    EXPECT_EQ(map.get(&v5), nullptr);
}

TYPED_TEST(MapTest, With3Elements) {
    TypeParam map;
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
    EXPECT_FALSE(map.isEmpty());
    EXPECT_EQ(map.size(), 3u);
    EXPECT_EQ(map.get(&k1), &v1);
    EXPECT_EQ(map.get(&k2), &v2);
    EXPECT_EQ(map.get(&k3), &v3);
    EXPECT_EQ(map.get(&k4), nullptr);
    EXPECT_EQ(map.get(nullptr), nullptr);
    EXPECT_EQ(map.get(&v1), nullptr);
    EXPECT_EQ(map.get(&v2), nullptr);
    EXPECT_EQ(map.get(&v3), nullptr);
    EXPECT_EQ(map.get(&v5), nullptr);
}

TYPED_TEST(MapTest, With4Elements) {
    TypeParam map;
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
    EXPECT_FALSE(map.isEmpty());
    EXPECT_EQ(map.size(), 4u);
    EXPECT_EQ(map.get(&k1), &v1);
    EXPECT_EQ(map.get(&k2), &v2);
    EXPECT_EQ(map.get(&k3), &v3);
    EXPECT_EQ(map.get(&k4), nullptr);
    EXPECT_EQ(map.get(nullptr), nullptr);
    EXPECT_EQ(map.get(&v1), nullptr);
    EXPECT_EQ(map.get(&v2), nullptr);
    EXPECT_EQ(map.get(&v3), nullptr);
    EXPECT_EQ(map.get(&v5), nullptr);
}

TYPED_TEST(MapTest, With5Elements) {
    TypeParam map;
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
    EXPECT_FALSE(map.isEmpty());
    EXPECT_EQ(map.size(), 5u);
    EXPECT_EQ(map.get(&k1), &v1);
    EXPECT_EQ(map.get(&k2), &v2);
    EXPECT_EQ(map.get(&k3), &v3);
    EXPECT_EQ(map.get(&k4), nullptr);
    EXPECT_EQ(map.get(nullptr), &v5);
    EXPECT_EQ(map.get(&v1), nullptr);
    EXPECT_EQ(map.get(&v2), nullptr);
    EXPECT_EQ(map.get(&v3), nullptr);
    EXPECT_EQ(map.get(&v5), nullptr);
}

TYPED_TEST(MapTest, GetRemoveOperations) {
    TypeParam map;
    int e = 18;
    int f = -6;
    int g = 59;
    int h = 47;

    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;

    int dum1 = 19123;
    EXPECT_EQ(map.size(), 0u);
    EXPECT_EQ(map.put(&e, &x), nullptr);
    EXPECT_EQ(map.size(), 1u);
    EXPECT_EQ(map.put(&f, &y), nullptr);
    EXPECT_EQ(map.size(), 2u);
    EXPECT_EQ(map.put(&g, &z), nullptr);
    EXPECT_EQ(map.size(), 3u);
    EXPECT_EQ(map.put(&h, &a), nullptr);
    EXPECT_EQ(map.size(), 4u);

    EXPECT_EQ(map.get(&f), &y);
    EXPECT_EQ(map.size(), 4u);
    EXPECT_EQ(map.remove(&f), &y);
    EXPECT_EQ(map.size(), 3u);

    EXPECT_EQ(map.get(&h), &a);
    EXPECT_EQ(map.size(), 3u);
    EXPECT_EQ(map.remove(&h), &a);
    EXPECT_EQ(map.size(), 2u);

    EXPECT_EQ(map.get(&dum1), nullptr);
    EXPECT_EQ(map.size(), 2u);
    EXPECT_EQ(map.remove(&dum1), nullptr);
    EXPECT_EQ(map.size(), 2u);

    EXPECT_EQ(map.get(&e), &x);
    EXPECT_EQ(map.size(), 2u);
    EXPECT_EQ(map.remove(&e), &x);
    EXPECT_EQ(map.size(), 1u);

    EXPECT_EQ(map.get(&g), &z);
    EXPECT_EQ(map.size(), 1u);
    EXPECT_EQ(map.remove(&g), &z);
    EXPECT_EQ(map.size(), 0u);

    EXPECT_TRUE(map.isEmpty());
}

TYPED_TEST(MapTest, GetPutRemoveOperations) {
    TypeParam map;
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
    EXPECT_EQ(map.size(), 0u);
    EXPECT_EQ(map.put(&e, &x), nullptr);
    EXPECT_EQ(map.size(), 1u);
    EXPECT_EQ(map.put(&f, &y), nullptr);
    EXPECT_EQ(map.size(), 2u);
    EXPECT_EQ(map.get(&e), &x);
    EXPECT_EQ(map.put(&e, &b), &x);
    EXPECT_EQ(map.size(), 2u);
    EXPECT_EQ(map.get(&e), &b);
    EXPECT_EQ(map.put(&g, &z), nullptr);
    EXPECT_EQ(map.size(), 3u);
    EXPECT_EQ(map.put(&h, &a), nullptr);
    EXPECT_EQ(map.size(), 4u);

    EXPECT_EQ(map.get(&f), &y);
    EXPECT_EQ(map.size(), 4u);
    EXPECT_EQ(map.remove(&f), &y);
    EXPECT_EQ(map.size(), 3u);

    EXPECT_EQ(map.get(&e), &b);
    EXPECT_EQ(map.put(&e, &c), &b);
    EXPECT_EQ(map.size(), 3u);
    EXPECT_EQ(map.get(&e), &c);

    EXPECT_EQ(map.get(&h), &a);
    EXPECT_EQ(map.size(), 3u);
    EXPECT_EQ(map.remove(&h), &a);
    EXPECT_EQ(map.size(), 2u);

    EXPECT_EQ(map.get(&dum1), nullptr);
    EXPECT_EQ(map.size(), 2u);
    EXPECT_EQ(map.remove(&dum1), nullptr);
    EXPECT_EQ(map.size(), 2u);

    EXPECT_EQ(map.get(&e), &c);
    EXPECT_EQ(map.size(), 2u);
    EXPECT_EQ(map.remove(&e), &c);
    EXPECT_EQ(map.size(), 1u);

    EXPECT_EQ(map.get(&g), &z);
    EXPECT_EQ(map.size(), 1u);
    EXPECT_EQ(map.remove(&g), &z);
    EXPECT_EQ(map.size(), 0u);

    EXPECT_TRUE(map.isEmpty());
}

class TestVisitor : public Map<int, int>::Visitor {
    private:
        int *keys [16];
        int *values [16];
        size_t visitCounter;
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
        size_t getVisitCounter() {
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
#define EXPECT_VISITOR_CONTAINS(visitor,k,v) EXPECT_NE(visitor.indexOfKeyValuePair(&k, &v), visitor.getVisitCounter())

TYPED_TEST(MapTest, Foreach) {
    TypeParam map;
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

    EXPECT_EQ(map.size(), 0u);
    EXPECT_EQ(map.put(&e, &x), nullptr);
    EXPECT_EQ(map.size(), 1u);
    EXPECT_EQ(map.put(&f, &y), nullptr);
    EXPECT_EQ(map.size(), 2u);
    EXPECT_EQ(map.get(&e), &x);
    EXPECT_EQ(map.put(&e, &b), &x);
    EXPECT_EQ(map.size(), 2u);
    EXPECT_EQ(map.get(&e), &b);
    EXPECT_EQ(map.put(&g, &z), nullptr);
    EXPECT_EQ(map.size(), 3u);
    EXPECT_EQ(map.put(&h, &a), nullptr);
    EXPECT_EQ(map.size(), 4u);
    EXPECT_EQ(map.put(&g, &c), &z);
    EXPECT_EQ(map.size(), 4u);

    TestVisitor visitor;
    map.foreach(visitor);
    EXPECT_EQ(visitor.getVisitCounter(), 4u);

    EXPECT_VISITOR_CONTAINS(visitor, e, b);
    EXPECT_VISITOR_CONTAINS(visitor, f, y);
    EXPECT_VISITOR_CONTAINS(visitor, g, c);
    EXPECT_VISITOR_CONTAINS(visitor, h, a);

    if (IteratesInKeyOrder<TypeParam>::value) {
        EXPECT_EQ(visitor.getKey(0), &f);
        EXPECT_EQ(visitor.getValue(0), &y);
        EXPECT_EQ(visitor.getKey(1), &e);
        EXPECT_EQ(visitor.getValue(1), &b);
        EXPECT_EQ(visitor.getKey(2), &h);
        EXPECT_EQ(visitor.getValue(2), &a);
        EXPECT_EQ(visitor.getKey(3), &g);
        EXPECT_EQ(visitor.getValue(3), &c);
    }
}

TYPED_TEST(MapTest, RemoveIf) {
    TypeParam map;
    int e = 18;
    int f = -6;
    int g = 59;
    int h = 47;

    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;

    EXPECT_EQ(map.size(), 0u);
    EXPECT_EQ(map.put(&e, &x), nullptr);
    EXPECT_EQ(map.size(), 1u);
    EXPECT_EQ(map.put(&f, &y), nullptr);
    EXPECT_EQ(map.size(), 2u);
    EXPECT_EQ(map.put(&g, &z), nullptr);
    EXPECT_EQ(map.size(), 3u);
    EXPECT_EQ(map.put(&h, &a), nullptr);
    EXPECT_EQ(map.size(), 4u);
    map.removeIf([](Map<int, int>::Entry entry) -> bool {
        return (*entry.key + *entry.value) % 2 == 0;
    });
    EXPECT_EQ(map.size(), 3u);
    EXPECT_EQ(map.get(&e), &x);
    EXPECT_EQ(map.get(&f), nullptr);
    EXPECT_EQ(map.get(&g), &z);
    EXPECT_EQ(map.get(&h), &a);
}

#define SETUP_ITERATOR_MAP() \
    TypeParam map; \
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
    EXPECT_EQ(map.size(), 0u); \
    EXPECT_EQ(map.put(&e, &x), nullptr); \
    EXPECT_EQ(map.size(), 1u); \
    EXPECT_EQ(map.put(&f, &y), nullptr); \
    EXPECT_EQ(map.size(), 2u); \
    EXPECT_EQ(map.get(&e), &x); \
    EXPECT_EQ(map.put(&e, &b), &x); \
    EXPECT_EQ(map.size(), 2u); \
    EXPECT_EQ(map.get(&e), &b); \
    EXPECT_EQ(map.put(&g, &z), nullptr); \
    EXPECT_EQ(map.size(), 3u); \
    EXPECT_EQ(map.put(&h, &a), nullptr); \
    EXPECT_EQ(map.size(), 4u); \
    EXPECT_EQ(map.put(&g, &c), &z); \
    EXPECT_EQ(map.size(), 4u); \
 \
    typename TypeParam::Iterator it(map); \


#define EXPECT_HAS_NEXT_ENTRY() { \
    for (int i = 0; i < 10; i++) { \
        EXPECT_TRUE(it.hasNext()); \
    } \
}

#define EXPECT_ENTRY_EQUALS(k,v) { \
    for (int i = 0; i < 10; i++) { \
        Map<int, int>::Entry *const entry = it.get(); \
        EXPECT_NE(entry, nullptr); \
        EXPECT_EQ(entry->key, &k); \
        EXPECT_EQ(entry->value, &v); \
    } \
}

#define ENTRY_REMOVAL_OPS(v,rm,checkRemovedIsHidden) { \
    if (rm) { \
        EXPECT_EQ(it.remove(), &v); \
        if (checkRemovedIsHidden) { \
            for (int i = 0; i < 10; i++) { \
                EXPECT_EQ(it.get(), nullptr); \
            } \
        } \
        for (int i = 0; i < 10; i++) { \
            EXPECT_EQ(it.remove(), nullptr); \
        } \
    } \
}

#define EXPECT_ENTRY_OPS(k,v,rm,checkRemovedIsHidden) { \
    EXPECT_ENTRY_EQUALS(k,v); \
    ENTRY_REMOVAL_OPS(v,rm,checkRemovedIsHidden); \
}

#define EXPECT_NEXT_ENTRY_IS(k,v,rm,checkRemovedIsHidden) { \
    EXPECT_HAS_NEXT_ENTRY(); \
    EXPECT_ENTRY_OPS(k,v,rm,checkRemovedIsHidden); \
    it.proceed(); \
}

#define EXPECT_NO_NEXT_ENTRY() { \
    EXPECT_FALSE(it.hasNext()); \
    for (int i = 0; i < 10; i++) { \
        EXPECT_EQ(it.get(), nullptr); \
        EXPECT_EQ(it.remove(), nullptr); \
    } \
    it.proceed(); \
}

#define EXPECT_NO_MORE_ENTRIES() { \
    for (int i = 0; i < 10; i++) { \
        EXPECT_NO_NEXT_ENTRY(); \
    } \
}

#define ARRAY_LEN(x) (sizeof(x)/sizeof((x)[0]))

#define EXPECT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden) \
    TestVisitor visitor; \
    int *const keys [] = {&e, &f, &g, &h}; \
    int *const values [] = {&b, &y, &c, &a}; \
    EXPECT_EQ(ARRAY_LEN(keys), ARRAY_LEN(values)); \
    EXPECT_EQ(ARRAY_LEN(keys), ARRAY_LEN(removeElements)); \
    EXPECT_EQ(ARRAY_LEN(keys), ARRAY_LEN(checkRemovedIsHidden)); \
    for (size_t i = 0; i < ARRAY_LEN(keys); i++) { \
        EXPECT_HAS_NEXT_ENTRY(); \
        yh::structures::maps::Map<int, int>::Entry *const entry = it.get(); \
        EXPECT_NE(entry, nullptr); \
        visitor.visit(*entry); \
        for (size_t j = 0; j < ARRAY_LEN(keys); j++) { \
            if (entry->key == keys[j]) { \
                EXPECT_ENTRY_OPS(*keys[j], *values[j], removeElements[j], checkRemovedIsHidden[j]); \
                break; \
            } \
        } \
        it.proceed(); \
    }


TYPED_TEST(MapTest, IteratorReadonly) {
    SETUP_ITERATOR_MAP();

    if (!IteratesInKeyOrder<TypeParam>::value) {
        const bool removeElements [] = {false, false, false, false};
        const bool checkRemovedIsHidden [] = {false, false, false, false};
        EXPECT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
        EXPECT_VISITOR_CONTAINS(visitor, e, b);
        EXPECT_VISITOR_CONTAINS(visitor, f, y);
        EXPECT_VISITOR_CONTAINS(visitor, g, c);
        EXPECT_VISITOR_CONTAINS(visitor, h, a);
    } else {
        EXPECT_NEXT_ENTRY_IS(f, y, false, false);
        EXPECT_NEXT_ENTRY_IS(e, b, false, false);
        EXPECT_NEXT_ENTRY_IS(h, a, false, false);
        EXPECT_NEXT_ENTRY_IS(g, c, false, false);
    }
    EXPECT_NO_MORE_ENTRIES();

    EXPECT_EQ(map.size(), 4u);
    EXPECT_EQ(map.get(&e), &b);
    EXPECT_EQ(map.get(&f), &y);
    EXPECT_EQ(map.get(&g), &c);
    EXPECT_EQ(map.get(&h), &a);
}

TYPED_TEST(MapTest, IteratorRemoveOnlyOnceForAllEvens) {
    SETUP_ITERATOR_MAP();

    if (!IteratesInKeyOrder<TypeParam>::value) {
        const bool removeElements [] = {false, true, false, true};
        const bool checkRemovedIsHidden [] = {false, false, false, false};
        EXPECT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
        EXPECT_VISITOR_CONTAINS(visitor, e, b);
        EXPECT_VISITOR_CONTAINS(visitor, f, y);
        EXPECT_VISITOR_CONTAINS(visitor, g, c);
        EXPECT_VISITOR_CONTAINS(visitor, h, a);
        EXPECT_NO_MORE_ENTRIES();

        EXPECT_EQ(map.size(), 2u);
        EXPECT_EQ(map.get(&e), &b);
        EXPECT_EQ(map.get(&f), nullptr);
        EXPECT_EQ(map.get(&g), &c);
        EXPECT_EQ(map.get(&h), nullptr);
    } else {
        EXPECT_NEXT_ENTRY_IS(f, y, false, false);
        EXPECT_NEXT_ENTRY_IS(e, b, true, false);
        EXPECT_NEXT_ENTRY_IS(h, a, false, false);
        EXPECT_NEXT_ENTRY_IS(g, c, true, false);
        EXPECT_NO_MORE_ENTRIES();

        EXPECT_EQ(map.size(), 2u);
        EXPECT_EQ(map.get(&f), &y);
        EXPECT_EQ(map.get(&e), nullptr);
        EXPECT_EQ(map.get(&h), &a);
        EXPECT_EQ(map.get(&g), nullptr);
    }
}

TYPED_TEST(MapTest, IteratorRemoveOnlyOnceForAllOdds) {
    SETUP_ITERATOR_MAP();

    if (!IteratesInKeyOrder<TypeParam>::value) {
        const bool removeElements [] = {true, false, true, false};
        const bool checkRemovedIsHidden [] = {false, false, false, false};
        EXPECT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
        EXPECT_VISITOR_CONTAINS(visitor, e, b);
        EXPECT_VISITOR_CONTAINS(visitor, f, y);
        EXPECT_VISITOR_CONTAINS(visitor, g, c);
        EXPECT_VISITOR_CONTAINS(visitor, h, a);
        EXPECT_NO_MORE_ENTRIES();

        EXPECT_EQ(map.size(), 2u);
        EXPECT_EQ(map.get(&e), nullptr);
        EXPECT_EQ(map.get(&f), &y);
        EXPECT_EQ(map.get(&g), nullptr);
        EXPECT_EQ(map.get(&h), &a);
    } else {
        EXPECT_NEXT_ENTRY_IS(f, y, true, false);
        EXPECT_NEXT_ENTRY_IS(e, b, false, false);
        EXPECT_NEXT_ENTRY_IS(h, a, true, false);
        EXPECT_NEXT_ENTRY_IS(g, c, false, false);
        EXPECT_NO_MORE_ENTRIES();

        EXPECT_EQ(map.size(), 2u);
        EXPECT_EQ(map.get(&f), nullptr);
        EXPECT_EQ(map.get(&e), &b);
        EXPECT_EQ(map.get(&h), nullptr);
        EXPECT_EQ(map.get(&g), &c);
    }
}

TYPED_TEST(MapTest, IteratorRemoveOnlyOnceForAllEntries) {
    SETUP_ITERATOR_MAP();

    if (!IteratesInKeyOrder<TypeParam>::value) {
        const bool removeElements [] = {true, true, true, true};
        const bool checkRemovedIsHidden [] = {false, false, false, false};
        EXPECT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
        EXPECT_VISITOR_CONTAINS(visitor, e, b);
        EXPECT_VISITOR_CONTAINS(visitor, f, y);
        EXPECT_VISITOR_CONTAINS(visitor, g, c);
        EXPECT_VISITOR_CONTAINS(visitor, h, a);
    } else {
        EXPECT_NEXT_ENTRY_IS(f, y, true, false);
        EXPECT_NEXT_ENTRY_IS(e, b, true, false);
        EXPECT_NEXT_ENTRY_IS(h, a, true, false);
        EXPECT_NEXT_ENTRY_IS(g, c, true, false);
    }

    EXPECT_NO_MORE_ENTRIES();

    EXPECT_EQ(map.size(), 0u);
    EXPECT_EQ(map.get(&e), nullptr);
    EXPECT_EQ(map.get(&f), nullptr);
    EXPECT_EQ(map.get(&g), nullptr);
    EXPECT_EQ(map.get(&h), nullptr);
}

TYPED_TEST(MapTest, IteratorRemovedEvenElementsAreNotVisible) {
    SETUP_ITERATOR_MAP();

    if (!IteratesInKeyOrder<TypeParam>::value) {
        const bool removeElements [] = {false, true, false, true};
        const bool checkRemovedIsHidden [] = {true, true, true, true};
        EXPECT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
        EXPECT_VISITOR_CONTAINS(visitor, e, b);
        EXPECT_VISITOR_CONTAINS(visitor, f, y);
        EXPECT_VISITOR_CONTAINS(visitor, g, c);
        EXPECT_VISITOR_CONTAINS(visitor, h, a);
        EXPECT_NO_MORE_ENTRIES();

        EXPECT_EQ(map.size(), 2u);
        EXPECT_EQ(map.get(&e), &b);
        EXPECT_EQ(map.get(&f), nullptr);
        EXPECT_EQ(map.get(&g), &c);
        EXPECT_EQ(map.get(&h), nullptr);
    } else {
        EXPECT_NEXT_ENTRY_IS(f, y, false, true);
        EXPECT_NEXT_ENTRY_IS(e, b, true, true);
        EXPECT_NEXT_ENTRY_IS(h, a, false, true);
        EXPECT_NEXT_ENTRY_IS(g, c, true, true);
        EXPECT_NO_MORE_ENTRIES();

        EXPECT_EQ(map.size(), 2u);
        EXPECT_EQ(map.get(&f), &y);
        EXPECT_EQ(map.get(&e), nullptr);
        EXPECT_EQ(map.get(&h), &a);
        EXPECT_EQ(map.get(&g), nullptr);
    }
}

TYPED_TEST(MapTest, IteratorRemovedOddElementsAreNotVisible) {
    SETUP_ITERATOR_MAP();

    if (!IteratesInKeyOrder<TypeParam>::value) {
        const bool removeElements [] = {true, false, true, false};
        const bool checkRemovedIsHidden [] = {true, true, true, true};
        EXPECT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
        EXPECT_VISITOR_CONTAINS(visitor, e, b);
        EXPECT_VISITOR_CONTAINS(visitor, f, y);
        EXPECT_VISITOR_CONTAINS(visitor, g, c);
        EXPECT_VISITOR_CONTAINS(visitor, h, a);
        EXPECT_NO_MORE_ENTRIES();

        EXPECT_EQ(map.size(), 2u);
        EXPECT_EQ(map.get(&e), nullptr);
        EXPECT_EQ(map.get(&f), &y);
        EXPECT_EQ(map.get(&g), nullptr);
        EXPECT_EQ(map.get(&h), &a);
    } else {
        EXPECT_NEXT_ENTRY_IS(f, y, true, true);
        EXPECT_NEXT_ENTRY_IS(e, b, false, true);
        EXPECT_NEXT_ENTRY_IS(h, a, true, true);
        EXPECT_NEXT_ENTRY_IS(g, c, false, true);
        EXPECT_NO_MORE_ENTRIES();

        EXPECT_EQ(map.size(), 2u);
        EXPECT_EQ(map.get(&f), nullptr);
        EXPECT_EQ(map.get(&e), &b);
        EXPECT_EQ(map.get(&h), nullptr);
        EXPECT_EQ(map.get(&g), &c);
    }
}

TYPED_TEST(MapTest, IteratorRemovedAllElementsAreNotVisible) {
    SETUP_ITERATOR_MAP();

    if (!IteratesInKeyOrder<TypeParam>::value) {
        const bool removeElements [] = {true, true, true, true};
        const bool checkRemovedIsHidden [] = {true, true, true, true};
        EXPECT_ENTRIES_OPS(visitor, removeElements, checkRemovedIsHidden);
        EXPECT_VISITOR_CONTAINS(visitor, e, b);
        EXPECT_VISITOR_CONTAINS(visitor, f, y);
        EXPECT_VISITOR_CONTAINS(visitor, g, c);
        EXPECT_VISITOR_CONTAINS(visitor, h, a);
    } else {
        EXPECT_NEXT_ENTRY_IS(f, y, true, true);
        EXPECT_NEXT_ENTRY_IS(e, b, true, true);
        EXPECT_NEXT_ENTRY_IS(h, a, true, true);
        EXPECT_NEXT_ENTRY_IS(g, c, true, true);
    }

    EXPECT_NO_MORE_ENTRIES();

    EXPECT_EQ(map.size(), 0u);
    EXPECT_EQ(map.get(&e), nullptr);
    EXPECT_EQ(map.get(&f), nullptr);
    EXPECT_EQ(map.get(&g), nullptr);
    EXPECT_EQ(map.get(&h), nullptr);
}

TYPED_TEST(MapTest, IteratorRemoveSome) {
    TypeParam map;
    int e = 18;
    int f = -6;
    int g = 59;
    int h = 47;

    int x = 35;
    int y = -12;
    int z = 0;
    int a = -4;

    EXPECT_EQ(map.size(), 0u);
    EXPECT_EQ(map.put(&e, &x), nullptr);
    EXPECT_EQ(map.size(), 1u);
    EXPECT_EQ(map.put(&f, &y), nullptr);
    EXPECT_EQ(map.size(), 2u);
    EXPECT_EQ(map.put(&g, &z), nullptr);
    EXPECT_EQ(map.size(), 3u);
    EXPECT_EQ(map.put(&h, &a), nullptr);
    EXPECT_EQ(map.size(), 4u);

    typename TypeParam::Iterator it(map);

    while (it.hasNext()) {
        Map<int, int>::Entry *const entry = it.get();
        if ((*entry->key + *entry->value) % 2 == 0) {
            it.remove();
        }
        it.proceed();
    }
    EXPECT_NO_MORE_ENTRIES();

    EXPECT_EQ(map.size(), 3u);
    EXPECT_EQ(map.get(&e), &x);
    EXPECT_EQ(map.get(&f), nullptr);
    EXPECT_EQ(map.get(&g), &z);
    EXPECT_EQ(map.get(&h), &a);
}
