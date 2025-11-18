#pragma once

#include <stddef.h>
#include <stdint.h>

#define POOL_SIZE 2048

typedef struct block block;
struct block{
    block *next;  
};



typedef struct {
    block *head; //point to the avaiabile block
    uint8_t pool[POOL_SIZE];//pool size is also the alignament for the block
}Pool;



void create_pool(Pool *p){

    p->head = (block *)p->pool; //set head inside pool
    block *c = p->head;  //set the current block    
    for (size_t i = 0; i < (POOL_SIZE /sizeof(*c)) - 1 ; i++){
        c->next = (block *)((uint8_t *)c + sizeof(block));
        c = c->next;
    }
    c->next = NULL;
}

/// @brief Alloc new memory object
/// @param p pointer to Pool, the Pool must be initializated to call to this funcion
/// @return memory to use.
void *salloc(Pool *p){
    if(p->head == NULL){
        return NULL; //check the error in the caller funcion
    }
    block *free  = p->head;
    p->head = free->next; 

    return (void *)free;

}

/// @brief Release memory. 
/// @param p pointer to Pool, the Pool must be initializated to call to this funcion
/// @param ptr pointer allocated, the pointer must be an allocated pointer.
void srelease(Pool *p, void *ptr){
    block *b = (block *)ptr;
    b->next = p->head; //block now can point to the head.
    p->head = b; //reset head to the block
}





