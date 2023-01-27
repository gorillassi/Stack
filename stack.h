#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef int elem_t;

struct stack 
    {
        int num_of_elem = 0;
        int *buffer = nullptr;
        int size_of_buff = 0;
    };

#endif