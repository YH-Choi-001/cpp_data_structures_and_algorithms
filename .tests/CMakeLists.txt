# Test suite for cpp_data_structures_and_algorithms, built on GoogleTest.
#
#   cmake -S .tests -B .tests/build
#   cmake --build .tests/build --parallel
#   ctest --test-dir .tests/build --output-on-failure --parallel

cmake_minimum_required(VERSION 3.16)
project(cpp_data_structures_and_algorithms_tests LANGUAGES CXX)

# GoogleTest 1.16 needs C++14. The library itself targets C++11, which is
# checked separately by the cxx11_header_check target below.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

set(DSA_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../src")

# ---------------------------------------------------------------- GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.tar.gz
    URL_HASH SHA256=78c676fc63881529bf97bf9d45948d905a66833fbfa5318ea2cd7478cb98f399
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # MSVC: match the CRT of the tests
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

# ---------------------------------------------------------------- warnings
if(MSVC)
    set(DSA_WARNING_FLAGS /W4)
else()
    set(DSA_WARNING_FLAGS -Wall -Wextra)
endif()

# ---------------------------------------------------------------- test support
# An OBJECT library, so the replacement operator new/delete in mem_leak.cpp are
# always linked in (a static library member could be dropped by the linker).
add_library(test_support OBJECT support/mem_leak.cpp)
target_include_directories(test_support PUBLIC support)
target_link_libraries(test_support PUBLIC GTest::gtest)
target_compile_options(test_support PRIVATE ${DSA_WARNING_FLAGS})

# add_dsa_test(<name> <source>): one GoogleTest executable, registered with CTest.
function(add_dsa_test name source)
    add_executable(${name} ${source})
    target_link_libraries(${name} PRIVATE test_support GTest::gtest_main)
    target_compile_options(${name} PRIVATE ${DSA_WARNING_FLAGS})
    gtest_discover_tests(${name} DISCOVERY_TIMEOUT 30)
endfunction()

add_dsa_test(testSort         algo/sort/testSort.cpp)
add_dsa_test(testMinArrayHeap structures/heaps/testMinArrayHeap.cpp)
add_dsa_test(testMaxArrayHeap structures/heaps/testMaxArrayHeap.cpp)
add_dsa_test(testList         structures/lists/testList.cpp)
add_dsa_test(testMap          structures/maps/testMap.cpp)
add_dsa_test(testLinkedQueue  structures/queues/testLinkedQueue.cpp)
add_dsa_test(testLinkedStack  structures/stacks/testLinkedStack.cpp)

# ---------------------------------------------------------------- C++11 check
# The tests are compiled as C++14 (required by GoogleTest), so make sure every
# library header still compiles on its own as C++11.
file(GLOB_RECURSE DSA_HEADERS CONFIGURE_DEPENDS "${DSA_SRC_DIR}/*.h")
set(DSA_HEADER_CHECK_SOURCE "")
foreach(header IN LISTS DSA_HEADERS)
    string(APPEND DSA_HEADER_CHECK_SOURCE "#include \"${header}\"\n")
endforeach()
file(GENERATE
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/cxx11_header_check.cpp"
    CONTENT "${DSA_HEADER_CHECK_SOURCE}"
)
add_library(cxx11_header_check OBJECT "${CMAKE_CURRENT_BINARY_DIR}/cxx11_header_check.cpp")
set_target_properties(cxx11_header_check PROPERTIES CXX_STANDARD 11)
target_compile_options(cxx11_header_check PRIVATE ${DSA_WARNING_FLAGS})
