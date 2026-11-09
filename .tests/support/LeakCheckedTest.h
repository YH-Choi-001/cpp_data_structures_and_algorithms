/**
 * @file LeakCheckedTest.h - GoogleTest fixture that fails a test which leaks heap memory.
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

#ifndef TESTS_SUPPORT_LEAK_CHECKED_TEST_H
#define TESTS_SUPPORT_LEAK_CHECKED_TEST_H

#include <cstddef>

#include <gtest/gtest.h>

namespace tests {
    namespace mem_leak {
        /**
         * @brief Number of blocks obtained from the global operator new (any form)
         * that have not been released yet. Implemented in mem_leak.cpp, which
         * replaces the global allocation functions for every test executable.
         */
        std::ptrdiff_t liveAllocationCount();
    }

    /**
     * @brief Base fixture for every test in this suite.
     *
     * Records the number of live heap allocations before the test body runs and
     * fails the test if that number has changed once the body has finished, i.e.
     * the code under test forgot a delete (or deleted something it did not own).
     *
     * The check is skipped for tests that have already failed: GoogleTest keeps
     * the failure messages it allocated alive until the end of the run, so they
     * would otherwise be misreported as leaks.
     */
    class LeakCheckedTest : public ::testing::Test {
        protected:
            void SetUp() override {
                allocationsBeforeTest = mem_leak::liveAllocationCount();
            }

            void TearDown() override {
                if (HasFailure()) {
                    return;
                }
                const std::ptrdiff_t leaked =
                    mem_leak::liveAllocationCount() - allocationsBeforeTest;
                EXPECT_EQ(leaked, 0)
                    << "Memory leak! You forgot " << leaked << " delete(s).";
            }

        private:
            std::ptrdiff_t allocationsBeforeTest = 0;
    };
}

#endif // #ifndef TESTS_SUPPORT_LEAK_CHECKED_TEST_H
