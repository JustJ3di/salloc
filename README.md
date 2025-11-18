# salloc
Simple pool memory allocator for embedded system.

This project provides a minimal implementation of a static memory pool allocator in C.
It allows allocation and release of fixed-size memory blocks from a pre-allocated pool, without relying on malloc() or the system heap.

The allocator is suitable for embedded systems, real-time applications, or performance-critical code where predictable allocation is required.

''' 
typedef struct {
    block *head;               // Points to the first available block
    unsigned char pool[POOL_SIZE];  // Raw memory pool
} Pool;
'''

