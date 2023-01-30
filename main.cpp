#include "functions.h"

int main () 
    {
        int capacity = 0;
        printf ("capacity: ");
        scanf ("%d", &capacity);

        struct stack stk{
            0,{}, 0
        };
        
        stack_ctor (&stk, capacity);
        
        for (int i = 0; i < capacity + 2; i++)
        {   
            int tt = 0;
            scanf("%d", &tt);
            push(&stk, tt);
            
        }
        
        //pop(&stk); 

        stack_dump (&stk, "/home/gorilla/Documents/GitHub/Stack/data.txt");

        stack_dtor (&stk);
        return 0;
    }