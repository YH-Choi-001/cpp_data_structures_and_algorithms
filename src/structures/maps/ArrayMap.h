/**
 * @file ArrayMap.h The array map implementation in C++.
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

#ifndef YH_STRUCTURES_MAPS_ARRAYMAP_H
#define YH_STRUCTURES_MAPS_ARRAYMAP_H

#include "Map.h"
#include "../lists/List.h"
#include "../lists/ArrayList.h"

namespace yh {
    namespace structures {
        namespace maps {
            /**
             * @brief A map implemented by an array.
             * @param K The data type of the key.
             * @param V The data type of the value.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename K, typename V>
            class ArrayMap : public Map<K, V> {
                private:
                    /**
                     * @brief The list of entries.
                     */
                    yh::structures::lists::ArrayList<typename Map<K, V>::Entry> entries;

                protected:
                    /**
                     * @brief Gets the entry from a key.
                     * @param key The key of the entry.
                     * @return The index of the entry requested, or entries.size() if such entry does not exist.
                     */
                    virtual size_t getEntryIndex(K *const key) {
                        const bool is_key_null = (key == nullptr);
                        const size_t size = entries.size();
                        for (size_t i = 0; i < size; i++) {
                            typename Map<K, V>::Entry *const entry = entries.get(i);
                            if (entry == nullptr) {
                                continue;
                            }
                            K *const entry_key = entry->key;
                            const bool is_entry_key_null = (entry_key == nullptr);
                            if (
                                (is_entry_key_null && is_key_null)
                                || (!is_entry_key_null && !is_key_null && ((*entry_key) == (*key)))
                            ) {
                                return i;
                            }
                        }
                        return size;
                    }

                    /**
                     * @brief Gets the entry from a key.
                     * @param key The key of the entry.
                     * @return The entry requested, or nullptr if the key does not exist.
                     */
                    virtual typename Map<K, V>::Entry *getEntry(K *const key) override {
                        const size_t size = entries.size();
                        const size_t index = getEntryIndex(key);
                        if (index == size) {
                            return nullptr;
                        }
                        return entries.get(index);
                    }

                    /**
                     * @brief Inserts an entry.
                     * @param entry The entry to be inserted.
                     */
                    virtual void insertEntry(typename Map<K, V>::Entry *const entry) override {
                        if (entry == nullptr) {
                            return;
                        }
                        entries.addTail(entry);
                    }

                    /**
                     * @brief Inserts an entry.
                     * @param entry The entry to be inserted.
                     */
                    void insertEntry(const size_t index, typename Map<K, V>::Entry *const entry) {
                        if (index > entries.size()) {
                            return;
                        }
                        if (entry == nullptr) {
                            return;
                        }
                        entries.insert(index, entry);
                    }

                    /**
                     * @brief Gets the entry from an index.
                     * @param index The index of the entry.
                     * @return The entry requested, or nullptr if the key does not exist.
                     */
                    virtual typename Map<K, V>::Entry *getEntryByIndex(const size_t index) {
                        if (index >= entries.size()) {
                            return nullptr;
                        }
                        return entries.get(index);
                    }

                    /**
                     * @brief Removes an entry by its index.
                     * @param index The index of the entry to be removed.
                     * @return The value pointed by the entry, or nullptr if the entry does not exist.
                     */
                    virtual V *removeEntryByIndex(const size_t index) {
                        if (index >= entries.size()) {
                            return nullptr;
                        }
                        typename Map<K, V>::Entry *const entry = entries.remove(index);
                        V *const value = entry->value;
                        delete entry;
                        return value;
                    }

                public:
                    /**
                     * @brief Creates an empty array map.
                     */
                    ArrayMap() : entries() {}

                    /**
                     * @brief Destroys the map.
                     */
                    virtual ~ArrayMap() {
                        entries.foreach([](typename Map<K, V>::Entry *const entry) {
                            delete entry;
                        });
                    }

                    /**
                     * @brief Gets the number of entries in the map.
                     * @return The number of entries in the map.
                     */
                    virtual size_t size() override {
                        return entries.size();
                    }

                    /**
                     * @brief Removes a key from the map.
                     * @param key The key to be removed.
                     * @return The value removed, or nullptr if the key does not exist.
                     */
                    virtual V *remove(K *const key) override {
                        const size_t size = entries.size();
                        const size_t index = getEntryIndex(key);
                        return removeEntryByIndex(index);
                    }

                    /**
                     * @brief Processes each entry with a function.
                     * @param visitor The visitor to visit each entry.
                     * @note Do not add or remove entries in the map within the given function.
                     */
                    virtual void foreach(typename Map<K, V>::Visitor &visitor) override {
                        class ConcreteVisitor : public yh::structures::lists::List<typename Map<K, V>::Entry>::Visitor {
                            private:
                                typename Map<K, V>::Visitor &visitor;
                            public:
                                ConcreteVisitor(typename Map<K, V>::Visitor &visitor) :
                                    visitor(visitor) {}
                                virtual void visit(typename Map<K, V>::Entry *const entry) override {
                                    visitor.visit(*entry);
                                }
                        };
                        ConcreteVisitor cv(visitor);
                        entries.foreach(cv);
                    }

                    /**
                     * @brief Processes each entry with a predicate function.
                     * @param visitor The visitor to visit each entry. Return true to remove the entry, false otherwise.
                     * @note Do not add or remove entries in the map within the given function.
                     */
                    virtual void removeIf(typename Map<K, V>::PredicateVisitor &visitor) override {
                        class ConcretePredicateVisitor : public yh::structures::lists::List<typename Map<K, V>::Entry>::PredicateVisitor {
                            private:
                                typename Map<K, V>::PredicateVisitor &visitor;
                            public:
                                ConcretePredicateVisitor(typename Map<K, V>::PredicateVisitor &visitor) :
                                    visitor(visitor) {}
                                virtual bool visit(typename Map<K, V>::Entry *const entry) override {
                                    const bool needRemove = visitor.visit(*entry);
                                    if (needRemove) {
                                        delete entry;
                                    }
                                    return needRemove;
                                }
                        };
                        ConcretePredicateVisitor cpv(visitor);
                        entries.removeIf(cpv);
                    }

                    /**
                     * @brief Processes each entry with a function.
                     * @param func The function to process the entries. param: V* Pointer to the entry.
                     * @note Do not add or remove entries in the map within the given function.
                     */
                    virtual void foreach(void (*func)(typename Map<K, V>::Entry)) override {
                        Map<K, V>::foreach(func);
                    }

                    /**
                     * @brief Processes each entry with a predicate function.
                     * @param func The function to process the values. param: V* Pointer to the value. return: True to remove the entry.
                     * @note Do not add or remove entries in the map within the given function.
                     */
                    virtual void removeIf(bool (*func)(typename Map<K, V>::Entry)) override {
                        Map<K, V>::removeIf(func);
                    }

                    /**
                     * @brief An iterator used to visit entries of a map.
                     */
                    class Iterator {
                        private:
                            /**
                             * @brief The map visited by this iterator.
                             */
                            ArrayMap<K, V> &map;

                            /**
                             * @brief The index pointed by this iterator.
                             */
                            size_t index;

                            /**
                             * @brief Whether the current entry is removed.
                             */
                            bool isRemoved;

                        public:
                            /**
                             * @brief Creates a new iterator to visit entries of a map.
                             * @param map The map being visited.
                             */
                            Iterator(ArrayMap<K, V> &map) : map(map), index(0), isRemoved(false)
                            {
                                //
                            }

                            /**
                             * @brief Whether there are unvisited entries in the map.
                             * @return `true` if there are unvisited entries, `false` otherwise.
                             */
                            bool hasNext() {
                                return index < map.size();
                            }

                            /**
                             * A nullptr will be returned after removing the current entry.
                             * @brief Get the current entry pointed by the iterator.
                             * @return The current entry pointed by the iterator, or nullptr if it does not exist.
                             * @see remove()
                             */
                            Map<K, V>::Entry *get() {
                                if (isRemoved || !hasNext()) {
                                    return nullptr;
                                }
                                return map.getEntryByIndex(index);
                            }

                            /**
                             * Each entry could only be removed once.
                             * Calling this function repetitively will not remove any other entries from the map.
                             * @brief Remove the current entry from the map.
                             * @return The entry removed, or nullptr if none is removed.
                             * @see get()
                             */
                            V *remove() {
                                if (isRemoved || !hasNext()) {
                                    return nullptr;
                                }
                                isRemoved = true;
                                return map.removeEntryByIndex(index);
                            }

                            /**
                             * @brief Move on to the next element.
                             */
                            void proceed() {
                                if (isRemoved) {
                                    isRemoved = false;
                                } else if (hasNext()) {
                                    index++;
                                }
                            }
                    };
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_MAPS_ARRAYMAP_H