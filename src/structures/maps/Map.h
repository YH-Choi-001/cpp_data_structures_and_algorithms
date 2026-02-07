/**
 * @file Map.h The map interface in C++.
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

#ifndef YH_STRUCTURES_MAPS_MAP_H
#define YH_STRUCTURES_MAPS_MAP_H

#ifdef ARDUINO
#include <stddef.h>
#else
#include <cstddef>
#endif

namespace yh {
    namespace structures {
        /**
         * A map is a commonly used data structure in holding a mapping from keys to values.
         * Values are referred by their keys.
         * @brief Interfaces and implementations of maps.
         */
        namespace maps {
            /**
             * @brief The interface of a map.
             * @param K The data type of the key.
             * @param V The data type of the value.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename K, typename V>
            class Map {
                protected:
                    /**
                     * @brief Creates an empty map.
                     */
                    Map() {}

                public:
                    /**
                     * @brief An entry of a map.
                     */
                    struct Entry {
                        /**
                         * @brief The key of the map entry.
                         */
                        K *key;

                        /**
                         * @brief The value of the map entry.
                         */
                        V *value;

                        /**
                         * @brief Initializes a map entry.
                         */
                        Entry(K *const ikey, V *const ivalue) :
                            key(ikey), value(ivalue) {}
                    };

                protected:
                    /**
                     * @brief Gets the entry from a key.
                     * @param key The key of the entry.
                     * @return The entry requested, or nullptr if the key does not exist.
                     */
                    virtual Entry *getEntry(K *const key) = 0;

                    /**
                     * @brief Inserts an entry.
                     * @param entry The entry to be inserted.
                     */
                    virtual void insertEntry(Entry *const entry) = 0;

                public:
                    /**
                     * @brief Destroys the map.
                     */
                    virtual ~Map() {}

                    /**
                     * @brief Gets the number of entries in the map.
                     * @return The number of entries in the map.
                     */
                    virtual size_t size() = 0;

                    /**
                     * @brief Checks whether the map is empty.
                     * @return true if the map is empty, false otherwise.
                     */
                    virtual bool isEmpty() {
                        return size() == 0;
                    }

                    /**
                     * @brief Gets a value from a specific key.
                     * @param key The key to access a desired value.
                     * @return The requested value, or nullptr if the key does not exist.
                     */
                    virtual V *get(K *const key) {
                        Entry *const entry = getEntry(key);
                        return (entry == nullptr) ? nullptr : entry->value;
                    }

                    /**
                     * @brief Stores a key with a value, or update its value.
                     * @param key The key to place the new value.
                     * @param value The value stored.
                     * @return The value that is previously at the key, or nullptr if the key does not exist.
                     */
                    virtual V *put(K *const key, V *const value) {
                        Entry *const entry = getEntry(key);
                        if (entry == nullptr) {
                            insertEntry(new Entry(key, value));
                            return nullptr;
                        }
                        V *const prevValue = entry->value;
                        entry->value = value;
                        return prevValue;
                    }

                    /**
                     * @brief Removes a key from the map.
                     * @param key The key to be removed.
                     * @return The value removed, or nullptr if the key does not exist.
                     */
                    virtual V *remove(K *const key) = 0;

                    /**
                     * @brief A visitor used to visit entries of a list.
                     */
                    class Visitor {
                        protected:
                            /**
                             * @brief A protected default constructor to avoid accidental instantiation.
                             */
                            Visitor() {}

                        public:
                            /**
                             * @brief Visits each entry once.
                             * @param entry The entry.
                             */
                            virtual void visit(Entry entry) = 0;

                            /**
                             * @brief A virtual destructor.
                             */
                            virtual ~Visitor() {}
                    };

                    /**
                     * @brief Processes each entry with a function.
                     * @param visitor The visitor to visit each entry.
                     * @note Do not add or remove entries in the list within the given function.
                     */
                    virtual void foreach(Visitor &visitor) = 0;
                    // virtual void foreach(Visitor &visitor) {
                    //     const size_t len = size();
                    //     for (size_t i = 0; i < len; i++) {
                    //         visitor.visit(get(i));
                    //     }
                    // }

                    /**
                     * @brief A visitor used to visit entries of a list, with a predicate to accept or reject every entry.
                     */
                    class PredicateVisitor {
                        protected:
                            /**
                             * @brief A protected default constructor to avoid accidental instantiation.
                             */
                            PredicateVisitor() {}

                        public:
                            /**
                             * @brief Visits each entry once.
                             * @param entry The entry.
                             * @return <code>true</code> or <code>false</code> for a decision to be made.
                             */
                            virtual bool visit(Entry entry) = 0;

                            /**
                             * @brief A virtual destructor.
                             */
                            virtual ~PredicateVisitor() {}
                    };

                    /**
                     * @brief Processes each entry with a predicate function.
                     * @param visitor The visitor to visit each entry. Return true to remove the entry, false otherwise.
                     * @note Do not add or remove entries in the list within the given function.
                     */
                    virtual void removeIf(PredicateVisitor &visitor) = 0;
                    // virtual void removeIf(PredicateVisitor &visitor) {
                    //     for (size_t i = 0; i < size();) {
                    //         const bool needToRemove = visitor.visit(get(i));
                    //         if (needToRemove) {
                    //             remove(i);
                    //         } else {
                    //             i++;
                    //         }
                    //     }
                    // }

                    /**
                     * @brief Processes each entry with a function.
                     * @param func The function to process the entries. param: V* Pointer to the entry.
                     * @note Do not add or remove entries in the list within the given function.
                     */
                    virtual void foreach(void (*func)(Entry)) {
                        if (func == nullptr) {
                            return;
                        }
                        class ConcreteVisitor : public Visitor {
                            private:
                                void (*const func)(Entry);
                            public:
                                ConcreteVisitor(void (*func)(Entry)) : func(func) {}
                                virtual void visit(Entry entry) override {
                                    func(entry);
                                }
                        };
                        ConcreteVisitor visitor(func);
                        foreach(visitor);
                    }

                    /**
                     * @brief Processes each entry with a predicate function.
                     * @param func The function to process the values. param: V* Pointer to the value. return: True to remove the entry.
                     * @note Do not add or remove entries in the map within the given function.
                     */
                    virtual void removeIf(bool (*func)(Entry)) {
                        if (func == nullptr) {
                            return;
                        }
                        class ConcretePredicateVisitor : public PredicateVisitor {
                            private:
                                bool (*const func)(Entry);
                            public:
                                ConcretePredicateVisitor(bool (*func)(Entry)) : func(func) {}
                                virtual bool visit(Entry entry) override {
                                    return func(entry);
                                }
                        };
                        ConcretePredicateVisitor visitor(func);
                        removeIf(visitor);
                    }
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_MAPS_MAP_H