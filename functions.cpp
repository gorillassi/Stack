#include "stack.h"

void stack_check (struct stack *stk)
    {
        if (stk->buffer == nullptr)
            {
                printf ("ERROR NULLPTR");
                abort ();
            }

    if (stk->num_of_elem > stk->size_of_buff)
        {
            printf ("ERROR OUT OF RANGE");
            abort ();
        }

    if (stk->num_of_elem < 0)
        {
            printf ("ERROR OUT OF RANGE");
            abort ();
        }
}

void push (struct stack *stk, elem_t value)
    {
        stack_check (stk);
        stk->buffer[stk->num_of_elem] = value;
        stk->num_of_elem++;
        stack_check (stk);
    }

elem_t pop (struct stack *stk)
    {
        stack_check (stk);   
        stk->num_of_elem--;
        elem_t temp = stk->buffer[stk->num_of_elem];
        stk->buffer[stk->num_of_elem] = 0;
        stack_check (stk);

        return temp;
    }  

void stack_ctor (struct stack *stk, int num)
    {
        stk->buffer = (elem_t*) calloc (num, sizeof(elem_t));
        stk->size_of_buff = num;
        stack_check (stk);
    }

void stack_dtor (struct stack *stk)
    {
        free (stk->buffer);
        stk->num_of_elem = 0;
        stk->size_of_buff = 0;
    }

void stack_dump (struct stack *stk)
{
    printf ("________________\n");
    printf ("position | value\n");
    for (int i = 0; i < stk->size_of_buff; i++)
    {
        printf ("________________\n");
        printf ("%8d | %5d\n", i, stk->buffer[i]);   
    } 
    printf ("________________\n"); 
}