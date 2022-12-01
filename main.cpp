#include "functions.h"

int main () 
    {
        int n = 0;
        printf ("Num:");
        scanf ("%d", &n);

        struct stack stk{
            0,{}, 0
        };
        
        stack_ctor (&stk, n);
        for (int i = 0; i < stk.size_of_buff; i++)
            {   
                scanf ("%d", &n);
                push (&stk,n);
            }
        stack_dump (&stk);
        printf ("%d\n",pop(&stk));
        stack_dtor (&stk);

        return 0;
    }