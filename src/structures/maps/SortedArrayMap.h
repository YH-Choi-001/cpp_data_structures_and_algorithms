/**
 * @file SortedArrayMap.h The array map implementation in C++.
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

#ifndef YH_STRUCTURES_MAPS_SORTEDARRAYMAP_H
#define YH_STRUCTURES_MAPS_SORTEDARRAYMAP_H

#include "ArrayMap.h"

#include <iostream>

namespace yh {
    namespace structures {
        namespace maps {
            /**
             * @brief A map implemented by a sorted array.
             * @param K The data type of the key.
             * @param V The data type of the value.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename K, typename V>
            class SortedArrayMap : public ArrayMap<K, V> {
                protected:
                    /**
                     * @brief Gets the entry from a key.
                     * @param key The key of the entry.
                     * @return The index of the entry requested, or entries.size() if such entry does not exist.
                     */
                    virtual size_t getEntryIndex(K *const key) override {
                        const size_t size = ArrayMap<K, V>::size();
                        if (size == 0) {
                            // ensure we don't waste time searching in an empty array
                            return size;
                        }
                        if (key == nullptr) {
                            // here we ensure that (key != nullptr)
                            // we always put the nullptr key at the beginning of the sorted array
                            typename Map<K, V>::Entry *const entry = ArrayMap<K, V>::getEntryByIndex(0);
                            return (entry->key == nullptr) ? 0 : size;
                        }
                        size_t lowerBound = 0;  // inclusive
                        size_t upperBound = size; // exclusive
                        while (lowerBound < upperBound) {
                            const size_t midIndex = (lowerBound + upperBound) / 2;
                            typename Map<K, V>::Entry *const entry = ArrayMap<K, V>::getEntryByIndex(midIndex);
                            if (entry == nullptr) {
                                // entry is missing...
                                return size;
                            }
                            K *const entryKey = entry->key;
                            if (entryKey == nullptr) {
                                // ensure (entryKey != nullptr)
                                return size;
                            }
                            if ((*entryKey) == (*key)) {
                                return midIndex;
                            }
                            // change either lower or upper bound to refine search area
                            if ((*entryKey) < (*key)) {
                                lowerBound = midIndex + 1;
                            } else {
                                upperBound = midIndex;
                            }
                        }
                        return size;
                    }

                    /**
                     * @brief Inserts an entry.
                     * @param entry The entry to be inserted.
                     */
                    virtual void insertEntry(typename Map<K, V>::Entry *const entry) override {
                        if (entry == nullptr) {
                            return;
                        }
                        K *const entryKey = entry->key;
                        if (entryKey == nullptr) {
                            ArrayMap<K, V>::insertEntry(0, entry);
                            return;
                        }
                        const size_t size = ArrayMap<K, V>::size();
                        size_t lowerBound = 0;  // inclusive
                        size_t upperBound = size; // exclusive
                        while (lowerBound < upperBound) {
                            const size_t midIndex = (lowerBound + upperBound) / 2;
                            typename Map<K, V>::Entry *const midEntry = ArrayMap<K, V>::getEntryByIndex(midIndex);
                            if (midEntry == nullptr) {
                                // entry is missing...
                                break;
                            }
                            K *const midEntryKey = midEntry->key;
                            if (midEntryKey == nullptr) {
                                // ensure (midEntryKey != nullptr)
                                lowerBound = midIndex + 1;
                                continue;
                            }
                            if ((*midEntryKey) == (*entryKey)) {
                                lowerBound = midIndex;
                                upperBound = midIndex;
                                break;
                            }
                            // change either lower or upper bound to refine search area
                            if ((*midEntryKey) < (*entryKey)) {
                                lowerBound = midIndex + 1;
                            } else {
                                upperBound = midIndex;
                            }
                        }
                        if (lowerBound == upperBound) {
                            ArrayMap<K, V>::insertEntry(lowerBound, entry);
                        } else {
                        }
                    }

                public:
                    /**
                     * @brief Creates an empty sortedarray map.
                     */
                    SortedArrayMap() : ArrayMap<K, V>() {}

                    /**
                     * @brief Destroys the list of entries.
                     */
                    virtual ~SortedArrayMap() {
                        //
                    }
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_MAPS_SORTEDARRAYMAP_H