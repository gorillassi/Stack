#include "stack.h"

void* recalloc(void* ptr, size_t num, size_t Size) {
    assert(ptr && num && Size);

    ptr = realloc(ptr, num * Size);

    return ptr;
}

int stack_check (struct stack *stk)
{
    assert(stk != nullptr);

    stk -> errors = (stk-> buffer == nullptr) * BUFF_NULLPTR                              +
                    (stk -> num_of_elem < 0) * SIZE_BELOW_NULL                            +
                    (stk -> num_of_elem > stk -> size_of_buff) * SIZE_BIGGER_THAN_CAPACITY;   
    
    return stk->errors;
}

void stack_error_decoder(stack* stk, const char* file_path)
{
    assert(stk != nullptr);
    
    FILE *source = fopen(file_path, "a");

    if(stk-> errors == 0)
    {
        fprintf(source, "NO ERROR\n");
    }
    else
    {
        if(stk->errors & BUFF_NULLPTR)
        {
            fprintf(source,"ERROR_BUFFER_NULLPTR");
        }
        if(stk->errors & SIZE_BELOW_NULL)
        {
            fprintf(source,"ERROR_SIZE_BELOW_NULL");
        }
        if(stk->errors & SIZE_BIGGER_THAN_CAPACITY)
        {
            fprintf(source,"ERROR_SIZE_BIGGER_THAN_CAPACITY");
        }
    }

    fclose(source);
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
    for (size_t i = 0; i < stk-> size_of_buff; i++)
    {
        stk->buffer[i] = 228;
    }
    

    stk->num_of_elem = 0;
    stk->size_of_buff = 0;
    stk->buffer = nullptr;
    free (stk->buffer);
}

void stack_dump (struct stack *stk, const char* file_path)
{
    assert(stk != nullptr);

    FILE *source = fopen(file_path, "wb");

    fprintf(source, "size             = %d\n", stk->size_of_buff);
    fprintf(source, "capacity         = %d\n", stk->num_of_elem);
    fprintf(source, "adress of buffer = %p\n", &stk->buffer);
    fprintf(source, " \n");
    fprintf (source ,"-----------DUMP----------\n");
    fprintf (source,     "_________________________\n");
    fprintf (source ,"position | value | adress\n");
    for (int i = 0; i < stk->size_of_buff; i++)
    {
        fprintf (source ,"_________________________\n");
        fprintf (source, "%8d | %5d | %p\n", i, stk->buffer[i], &stk->buffer[i]);   
    } 
    fprintf (source,     "_________________________\n"); 
    fclose(source);
    fprintf (source," \n");
    stack_error_decoder(stk , file_path);

    
}