#include "stack.h"

u32 counter ;
void push( LinkedList_t* list ,int value)
{
    
    
    

    AppendToLinkedList(list, value);
    printf("Pushed %d\n", value);
    counter++;
}

void pop(LinkedList_t* list , u32 counter){
    
    if(counter < 0){
        return;
    }
    DeleteNodeWithIndex(list, counter);
    printf("Popped\n");
}
void printStack(LinkedList_t *list){
    Print_List(list);
}