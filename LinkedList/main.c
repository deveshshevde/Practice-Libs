#include "LL.h"



int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    LinkedList_t *list = CreateLinkedList();
    AppendToLinkedList(list, 1); // 0 based indexing
    AppendToLinkedList(list, 2); 
    AppendToLinkedList(list, 3);
    AttachNodeWithIndex(list , 3 , 4);
    DeleteNodeWithIndex(list, 2);
    Print_List(list);
    Free_LinkedList(list);
    
    return 0;
}
