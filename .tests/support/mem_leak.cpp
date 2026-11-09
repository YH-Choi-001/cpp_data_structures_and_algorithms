/**
 * @file mem_leak.cpp - Replaces the global allocation functions with counting versions.
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

#include <atomic>
#include <cstddef>
#include <cstdlib>
#include <new>

#include "LeakCheckedTest.h"

namespace {
    // Constant-initialised, so it is usable by allocations made during static
    // initialisation (e.g. inside GoogleTest) regardless of initialisation order.
    std::atomic<std::ptrdiff_t> liveAllocations(0);

    void *countedAllocate(const std::size_t size) {
        void *const ptr = std::malloc(size != 0 ? size : 1);
        if (ptr == nullptr) {
            throw std::bad_alloc();
        }
        ++liveAllocations;
        return ptr;
    }

    void countedDeallocate(void *const ptr) noexcept {
        if (ptr == nullptr) {
            return;
        }
        --liveAllocations;
        std::free(ptr);
    }
}

std::ptrdiff_t tests::mem_leak::liveAllocationCount() {
    return liveAllocations.load();
}

void *operator new(const std::size_t size) {
    return countedAllocate(size);
}
void *operator new[](const std::size_t size) {
    return countedAllocate(size);
}
void *operator new(const std::size_t size, const std::nothrow_t &) noexcept {
    try {
        return countedAllocate(size);
    } catch (...) {
        return nullptr;
    }
}
void *operator new[](const std::size_t size, const std::nothrow_t &) noexcept {
    try {
        return countedAllocate(size);
    } catch (...) {
        return nullptr;
    }
}

void operator delete(void *const ptr) noexcept {
    countedDeallocate(ptr);
}
void operator delete[](void *const ptr) noexcept {
    countedDeallocate(ptr);
}
void operator delete(void *const ptr, const std::nothrow_t &) noexcept {
    countedDeallocate(ptr);
}
void operator delete[](void *const ptr, const std::nothrow_t &) noexcept {
    countedDeallocate(ptr);
}
#if defined(__cpp_sized_deallocation)
void operator delete(void *const ptr, std::size_t) noexcept {
    countedDeallocate(ptr);
}
void operator delete[](void *const ptr, std::size_t) noexcept {
    countedDeallocate(ptr);
}
#endif
