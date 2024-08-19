#include "stack.h"

extern u32 counter;
int main(int argc, char const *argv[])
{

    (void)argc;
    (void)argv;
    puts("started");
    
    LinkedList_t *list = CreateLinkedList();

    push(list, 1);
    push(list, 2);
    push(list, 3);

    pop(list,counter-1);
 


    return 0;
}
