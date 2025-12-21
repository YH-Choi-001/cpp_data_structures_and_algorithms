#ifndef MEM_LEAK_H
#define MEM_LEAK_H

#include <cstddef>
#include <cstdlib>

#ifndef MEM_LEAK_DEBUG_LEVEL
#define MEM_LEAK_DEBUG_LEVEL 2
#endif

void reset_malloc_count();

size_t get_malloc_count();

bool has_memory_leaked();

#if (MEM_LEAK_DEBUG_LEVEL == 0)
// use the default implementation
// void *operator new(const size_t size) {
//     return malloc(size);
// }
// void *operator new[](const size_t size) {
//     return malloc(size);
// }
// void operator delete(void *const ptr) {
//     free(ptr);
// }
// void operator delete[](void *const ptr) {
//     free(ptr);
// }

void reset_malloc_count() {
    //
}

size_t get_malloc_count() {
    return 0;
}

bool has_memory_leaked() {
    return false;
}
#elif (MEM_LEAK_DEBUG_LEVEL == 1)

static size_t malloc_count = 0;

void *operator new(const size_t size) {
    malloc_count++;
    return malloc(size);
}
void *operator new[](const size_t size) {
    malloc_count++;
    return malloc(size);
}
void operator delete(void *const ptr) {
    malloc_count--;
    free(ptr);
}
void operator delete[](void *const ptr) {
    malloc_count--;
    free(ptr);
}

void reset_malloc_count() {
    malloc_count = 0;
}

size_t get_malloc_count() {
    return malloc_count;
}

bool has_memory_leaked() {
    return malloc_count != 0;
}
#elif (MEM_LEAK_DEBUG_LEVEL == 2)
#include <iostream>

static size_t malloc_count = 0;

void *operator new(const size_t size) {
    malloc_count++;
    void *const ptr = malloc(size);
    std::cout << "new @ " << ptr << " (len = " << size << " )" << std::endl;
    return ptr;
}
void *operator new[](const size_t size) {
    malloc_count++;
    void *const ptr = malloc(size);
    std::cout << "new @ " << ptr << " (len = " << size << " )" << std::endl;
    return ptr;
}
void operator delete(void *const ptr) {
    malloc_count--;
    std::cout << "del @ " << ptr << std::endl;
    free(ptr);
}
void operator delete[](void *const ptr) {
    malloc_count--;
    std::cout << "del @ " << ptr << std::endl;
    free(ptr);
}

void reset_malloc_count() {
    malloc_count = 0;
    std::cout << "malloc_count resetted" << std::endl;
}

size_t get_malloc_count() {
    return malloc_count;
}

bool has_memory_leaked() {
    return malloc_count != 0;
}
#endif

#endif // #ifndef MEM_LEAK_H