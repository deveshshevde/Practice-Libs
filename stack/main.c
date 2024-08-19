#include "stack.h"

extern u32 counter;
int main(int argc, char const *argv[])
{

    (void)argc;
    (void)argv;
    puts("started");
    
    LinkedList_t *list = CreateLinkedList();

    push(list, 1);
    printf("%d\n", list->top);
    push(list, 2);
    printf("%d\n", list->top);
    push(list, 3);
    printf("%d\n", list->top);

    printf(" Top on the stack is %d\n", list->top);
    pop(list,(--counter));
    printf(" Top on the stack is %d\n", list->top);
    pop(list,(--counter));
    printf(" Top on the stack is %d\n", list->top);




 


    return 0;
}
