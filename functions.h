#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "stack.h"

void push (struct stack *stk, elem_t value);

elem_t pop (struct stack *stk);

void stack_ctor (struct stack *stk, int num);

void stack_dtor (struct stack *stk);

void stack_dump (struct stack *stk);

void stack_resize(struct stack *stk, size_t new_capacity);
#endif