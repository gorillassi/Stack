#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define ASSERT_OK(stk)      \
    if(stack_check != 0)    \
    {                       \
        stack_dump(stk);    \
        stack_dtor(stk);    \
    }                       \


typedef int elem_t;

struct stack 
{
    int num_of_elem  = 0;
    int *buffer      = nullptr;
    int size_of_buff = 0;
    int errors       = 0;
};

enum stack_errors
{
    BUFF_NULLPTR              = 1 << 0,
    SIZE_BELOW_NULL           = 1 << 1,
    SIZE_BIGGER_THAN_CAPACITY = 1 << 2,
};
#endif