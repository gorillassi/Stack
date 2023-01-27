#include "stack.h"

void* recalloc(void* ptr, size_t num, size_t Size) {
    assert(ptr && num && Size);

    ptr = realloc(ptr, num * Size);

    return ptr;
}

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

void stack_resize(struct stack *stk, size_t new_capacity)
{
    stack_check(stk);
    stk->buffer = (elem_t*)recalloc(stk->buffer,new_capacity,sizeof(elem_t));

    if(stk->size_of_buff < new_capacity)
    {
        for (size_t i = stk->size_of_buff; i < new_capacity ; i++)
        {
            stk->buffer[i] = 0;
        }
    }

    stk->size_of_buff = new_capacity;
}

void push (struct stack *stk, elem_t value)
{
    stack_check (stk);

    if(stk->num_of_elem >= stk->size_of_buff)
    {
        stack_resize(stk, 2 * stk->size_of_buff);
    }

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

    if(stk->num_of_elem + 1 <= stk->size_of_buff / 2 && stk->num_of_elem)
    {
        stack_resize(stk, stk->size_of_buff / 2);
    }

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
    stk->buffer = nullptr;
}

void stack_dump (struct stack *stk)
{
    printf ("________________\n");
    printf ("position | value\n");
    for (int i = 0; i < stk->size_of_buff; i++)
    {
        printf ("________________\n");
        printf ("%8d | %5d\n", i+1, stk->buffer[i]);   
    } 
    printf ("________________\n"); 
}

