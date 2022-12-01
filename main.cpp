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
        for (int i = 0; i < 20; i++)
            {   
                
                push (&stk,i);
            }
        stack_dump (&stk);
        printf ("%d\n",pop(&stk));
        stack_dtor (&stk);

        return 0;
    }