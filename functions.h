#ifndef STACKH2
#define STACKH2

#include "stack.h"

void push (struct stack *stk, elem_t value);

elem_t pop (struct stack *stk);

void stack_ctor (struct stack *stk, int num);

void stack_dtor (struct stack *stk);

void stack_dump (struct stack *stk);

#endif