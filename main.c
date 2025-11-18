#include "salloc.h"

#include <stdio.h>

int main(void) {

    Pool p;
    create_pool(&p);
    
    int *p_int = salloc(&p);
    *p_int = 42;
    printf("%d\n", *p_int);
    return 0;

}

