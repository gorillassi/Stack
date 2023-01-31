#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


typedef int elem_t;
typedef long double canary_t;

#define ASSERT_OK(stk)      \
    if(stack_check(stk) != 0)    \
    {                       \
        stack_dump(stk,"/home/gorilla/Documents/GitHub/Stack/data.txt");    \
        stack_dtor(stk);    \
    }                       \



const canary_t CANARYVALUE = 4441512;

struct stack 
{
    canary_t left_canary  = CANARYVALUE;
    int num_of_elem       = 0;
    int *buffer           = nullptr;
    int size_of_buff      = 0;
    int errors            = 0;
    canary_t right_canary = CANARYVALUE;
};

enum stack_errors
{
    BUFF_NULLPTR              = 1 << 0,
    SIZE_BELOW_NULL           = 1 << 1,
    SIZE_BIGGER_THAN_CAPACITY = 1 << 2,
    CANARY_NOT_ALIVE          = 1 << 3,
};

void* recalloc(void* ptr, size_t num, size_t Size);

int stack_check (struct stack *stk);

void stack_error_decoder(stack* stk, const char* file_path);

void push (struct stack *stk, elem_t value);

elem_t pop (struct stack *stk);

void stack_ctor (struct stack *stk, int num);

void stack_dtor (struct stack *stk);

void stack_dump (struct stack *stk, const char* file_path);

void stack_resize(struct stack *stk, size_t new_capacity);
#endif