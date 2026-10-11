/**
 * @file HashMap.h The hash map implementation in C++.
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

#ifndef YH_STRUCTURES_MAPS_HASHMAP_H
#define YH_STRUCTURES_MAPS_HASHMAP_H

#include "Map.h"
#include "../lists/List.h"
#include "../lists/ArrayList.h"
#include "../lists/SinglyLinkedList.h"

namespace yh {
    namespace structures {
        namespace maps {
            /**
             * @brief A hash map.
             * @param K The data type of the key.
             * @param V The data type of the value.
             * @warning This class borrows elements but do not own them: The user should be responsible for deleting them.
             */
            template<typename K, typename V>
            class HashMap : public Map<K, V> {
                public:
                    /**
                     * @brief The type of the hash.
                     * To be generated from the key.
                     */
                    typedef size_t Hash;

                    /**
                     * @brief The type of the hash function.
                     * Obtain a hash of the key.
                     */
                    typedef Hash (*HashFunction)(K *const k);

                private:
                    /**
                     * @brief The bucket type.
                     * An object of this type corresponds to a bucket.
                     */
                    typedef yh::structures::lists::SinglyLinkedList<typename Map<K, V>::Entry> Bucket;

                    /**
                     * @brief The buckets type.
                     * The collection of buckets.
                     */
                    typedef yh::structures::lists::ArrayList<Bucket> Buckets;

                    /**
                     * @brief The buckets.
                     */
                    Buckets buckets;

                    /**
                     * @brief The number of buckets.
                     */
                    const size_t bucketCount;

                    /**
                     * @brief The default number of buckets.
                     */
                    static const size_t DEFAULT_BUCKET_COUNT = 16;

                    /**
                     * @brief The hash function.
                     */
                    HashFunction hashFunction;

                    /**
                     * @brief Gets the bucket number for a key.
                     * @param key The key.
                     * @return the bucket number of the key.
                     */
                    size_t getBucketIndex(K *const key) const {
                        const Hash hash = hashFunction(key);
                        return hash % bucketCount;
                    }

                    /**
                     * @brief Gets the corresponding bucket for a key.
                     * @param key The key.
                     * @return The bucket for the key.
                     */
                    Bucket *getBucket(K *const key) const {
                        const size_t bucketIndex = getBucketIndex(key);
                        Bucket *const bucket = buckets.get(bucketIndex);
                        return bucket;
                    }

                protected:
                    /**
                     * @brief Gets the entry from a key.
                     * @param key The key of the entry.
                     * @return The entry requested, or nullptr if the key does not exist.
                     */
                    virtual typename Map<K, V>::Entry *getEntry(K *const key) override {
                        Bucket *const bucket = getBucket(key);
                        if (bucket == nullptr) {
                            return nullptr;
                        }
                        for (typename Bucket::Iterator it = *bucket; it.hasNext(); it.proceed()) {
                            typename Map<K, V>::Entry *const entry = it.get();
                            if (entry == nullptr) {
                                continue;
                            }
                            if (
                                (key == nullptr && entry->key == nullptr) ||
                                (
                                    (key != nullptr) && (entry->key != nullptr) &&
                                    ((*key) == *(entry->key))
                                )
                            ) {
                                return entry;
                            }
                        }
                        return nullptr;
                    }

                    /**
                     * @brief Inserts an entry.
                     * @param entry The entry to be inserted.
                     */
                    virtual void insertEntry(typename Map<K, V>::Entry *const entry) override {
                        if (entry == nullptr) {
                            return;
                        }
                        Bucket *const bucket = getBucket(entry->key);
                        if (bucket == nullptr) {
                            return;
                        }
                        bucket->addTail(entry);
                    }

                public:
                    /**
                     * @brief Creates an empty hash map.
                     */
                    HashMap(const HashFunction func, const size_t bucketCount = DEFAULT_BUCKET_COUNT) :
                        buckets(),
                        bucketCount(bucketCount),
                        hashFunction(func)
                    {
                        for (size_t i = 0; i < bucketCount; i++) {
                            buckets.addTail(new Bucket());
                        }
                    }

                    /**
                     * @brief Destroys the map.
                     */
                    virtual ~HashMap() {
                        for (typename Buckets::Iterator bucketsIt = buckets; bucketsIt.hasNext(); bucketsIt.proceed()) {
                            Bucket *const bucket = bucketsIt.get();
                            if (bucket == nullptr) {
                                continue;
                            }
                            for (typename Bucket::Iterator it = *bucket; it.hasNext(); it.proceed()) {
                                typename Map<K, V>::Entry *const entry = it.get();
                                if (entry == nullptr) {
                                    continue;
                                }
                                delete entry;
                            }
                            delete bucket;
                        }
                    }

                    /**
                     * @brief Gets the number of entries in the map.
                     * @return The number of entries in the map.
                     */
                    virtual size_t size() override {
                        size_t elementCount = 0;
                        for (typename Buckets::Iterator bucketsIt = buckets; bucketsIt.hasNext(); bucketsIt.proceed()) {
                            Bucket *const bucket = bucketsIt.get();
                            if (bucket == nullptr) {
                                continue;
                            }
                            elementCount += bucket->size();
                        }
                        return elementCount;
                    }

                    /**
                     * @brief Removes a key from the map.
                     * @param key The key to be removed.
                     * @return The value removed, or nullptr if the key does not exist.
                     */
                    virtual V *remove(K *const key) override {
                        Bucket *const bucket = getBucket(key);
                        if (bucket == nullptr) {
                            return nullptr;
                        }
                        for (typename Bucket::Iterator it = *bucket; it.hasNext(); it.proceed()) {
                            typename Map<K, V>::Entry *const entry = it.get();
                            if (entry == nullptr) {
                                continue;
                            }
                            if ((key == nullptr && entry->key == nullptr) || ((*key) == *(entry->key))) {
                                it.remove();
                                V *const value = entry->value;
                                delete entry;
                                return value;
                            }
                        }
                        return nullptr;
                    }

                    /**
                     * @brief Processes each entry with a function.
                     * @param visitor The visitor to visit each entry.
                     * @note Do not add or remove entries in the map within the given function.
                     */
                    virtual void foreach(typename Map<K, V>::Visitor &visitor) override {
                        class BucketsVisitor : public Buckets::Visitor {
                            private:
                                typename Map<K, V>::Visitor &visitor;
                            public:
                                BucketsVisitor(typename Map<K, V>::Visitor &visitor) :
                                    visitor(visitor) {}
                                virtual void visit(Bucket *const bucket) override {
                                    if (bucket == nullptr) {
                                        return;
                                    }
                                    class BucketVisitor : public Bucket::Visitor {
                                        private:
                                            typename Map<K, V>::Visitor &visitor;
                                        public:
                                            BucketVisitor(typename Map<K, V>::Visitor &visitor) :
                                                visitor(visitor) {}
                                            virtual void visit(typename Map<K, V>::Entry *const entry) override {
                                                if (entry == nullptr) {
                                                    return;
                                                }
                                                visitor.visit(*entry);
                                            }
                                    };
                                    BucketVisitor bvv(visitor);
                                    bucket->foreach(bvv);
                                }
                        };
                        BucketsVisitor bv(visitor);
                        buckets.foreach(bv);
                    }

                    /**
                     * @brief Processes each entry with a predicate function.
                     * @param visitor The visitor to visit each entry. Return true to remove the entry, false otherwise.
                     * @note Do not add or remove entries in the map within the given function.
                     */
                    virtual void removeIf(typename Map<K, V>::PredicateVisitor &visitor) override {
                        class BucketsVisitor : public Buckets::Visitor {
                            private:
                                typename Map<K, V>::PredicateVisitor &visitor;
                            public:
                                BucketsVisitor(typename Map<K, V>::PredicateVisitor &visitor) :
                                    visitor(visitor) {}
                                virtual void visit(Bucket *const bucket) override {
                                    if (bucket == nullptr) {
                                        return;
                                    }
                                    class BucketVisitor : public Bucket::PredicateVisitor {
                                        private:
                                            typename Map<K, V>::PredicateVisitor &visitor;
                                        public:
                                            BucketVisitor(typename Map<K, V>::PredicateVisitor &visitor) :
                                                visitor(visitor) {}
                                            virtual bool visit(typename Map<K, V>::Entry *const entry) override {
                                                if (entry == nullptr) {
                                                    return false;
                                                }
                                                const bool toRemove = visitor.visit(*entry);
                                                if (toRemove) {
                                                    delete entry;
                                                }
                                                return toRemove;
                                            }
                                    };
                                    BucketVisitor bvv(visitor);
                                    bucket->removeIf(bvv);
                                }
                        };
                        BucketsVisitor bv(visitor);
                        buckets.foreach(bv);
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
                            HashMap<K, V> &map;

                            /**
                             * @brief The current bucket being visited.
                             */
                            size_t bucketIndex;

                            /**
                             * @brief The iterator of the current bucket being visited.
                             */
                            typename Bucket::Iterator *bucketIterator;

                            size_t getNextNonEmptyBucketIndex() {
                                for (size_t i = bucketIndex + 1; i < map.bucketCount; i++) {
                                    Bucket *const bucket = map.buckets.get(i);
                                    if (bucket != nullptr && !bucket->isEmpty()) {
                                        return i;
                                    }
                                }
                                return map.bucketCount;
                            }

                            void setBucketIterator(typename Bucket::Iterator *const newIterator) {
                                if (bucketIterator != nullptr) {
                                    delete bucketIterator;
                                }
                                bucketIterator = newIterator;
                            }

                            void deleteBucketIterator() {
                                setBucketIterator(nullptr);
                            }

                            void switchToNewBucketIteratorFromBucket(Bucket *const bucket) {
                                if (bucket != nullptr) {
                                    setBucketIterator(new typename Bucket::Iterator(*bucket));
                                } else {
                                    deleteBucketIterator();
                                }
                            }

                            void proceedToNextNonEmptyBucketIterator() {
                                bucketIndex = getNextNonEmptyBucketIndex();
                                Bucket *const bucket = map.buckets.get(bucketIndex);
                                switchToNewBucketIteratorFromBucket(bucket);
                            }

                        public:
                            /**
                             * @brief Creates a new iterator to visit entries of a map.
                             * @param map The map being visited.
                             */
                            Iterator(HashMap<K, V> &map) : map(map), bucketIndex(0), bucketIterator(nullptr)
                            {
                                Bucket *const bucket = map.buckets.get(bucketIndex);
                                if (bucket != nullptr && !bucket->isEmpty()) {
                                    switchToNewBucketIteratorFromBucket(bucket);
                                } else {
                                    proceedToNextNonEmptyBucketIterator();
                                }
                            }

                            /**
                             * @brief Release all the resources held by the iterator.
                             */
                            ~Iterator() {
                                deleteBucketIterator();
                            }

                            /**
                             * @brief Whether there are unvisited entries in the map.
                             * @return `true` if there are unvisited entries, `false` otherwise.
                             */
                            bool hasNext() {
                                if (bucketIterator == nullptr) {
                                    return false;
                                }
                                if (bucketIterator->hasNext()) {
                                    return true;
                                }
                                return getNextNonEmptyBucketIndex() < map.bucketCount;
                            }

                            /**
                             * A nullptr will be returned after removing the current entry.
                             * @brief Get the current entry pointed by the iterator.
                             * @return The current entry pointed by the iterator, or nullptr if it does not exist.
                             * @see remove()
                             */
                            typename Map<K, V>::Entry *get() {
                                if (bucketIterator == nullptr) {
                                    return nullptr;
                                }
                                return bucketIterator->get();
                            }

                            /**
                             * Each entry could only be removed once.
                             * Calling this function repetitively will not remove any other entries from the map.
                             * @brief Remove the current entry from the map.
                             * @return The entry removed, or nullptr if none is removed.
                             * @see get()
                             */
                            V *remove() {
                                if (bucketIterator == nullptr) {
                                    return nullptr;
                                }
                                typename Map<K, V>::Entry *const entry = bucketIterator->remove();
                                V *const value = entry != nullptr ? entry->value : nullptr;
                                if (entry != nullptr) {
                                    delete entry;
                                }
                                return value;
                            }

                            /**
                             * @brief Move on to the next element.
                             */
                            void proceed() {
                                if (bucketIterator == nullptr) {
                                    return;
                                }
                                bucketIterator->proceed();
                                if (!bucketIterator->hasNext()) {
                                    proceedToNextNonEmptyBucketIterator();
                                }
                            }
                    };
            };
        }
    }
}

#endif // #ifndef YH_STRUCTURES_MAPS_HASHMAP_H