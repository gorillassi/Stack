#ifndef STACKH1
#define STACKH1

#include <stdio.h>
#include <stdlib.h>

typedef int elem_t;

struct stack 
    {
        int num_of_elem = 0;
        int *buffer;
        int size_of_buff;
    };

#endif