#include "LL.h"


LinkedList_t *CreateLinkedList()
{
    LinkedList_t *list = (LinkedList_t*)malloc(sizeof(LinkedList_t));

    list->head = NULL;
    list->tail = NULL;

    return list;
}
void Print_List(LinkedList_t* list)
{
    /*
        This is a iterator node which traverse through the linked list
    */
    node_t *iterator = (node_t*)(malloc(sizeof(node_t)));
    iterator = list->head;
    while(iterator != NULL)
    {
        printf("%d ", iterator->Data);
        iterator = iterator->Next;
    }
    puts("\n");
}
void Free_LinkedList(LinkedList_t* list)
{
    node_t *iterator = (node_t*)(malloc(sizeof(node_t)));
    iterator = list->head;
    while(iterator != NULL)
    {
        node_t *temp = iterator;
        iterator = iterator->Next;
        free(temp);
    }
    free(list);
}
void AppendToLinkedList(LinkedList_t* list, u32 data)
{
    /*
        * check whether the list is empty or not 
    */

   if(list->head == NULL)
   {
    /*
      * Hence head is pointing to NULL , so we have to create a head node only
    */
    node_t *newnode  = (node_t*)malloc(sizeof(node_t));
    newnode->Data = data;
    newnode->Next = NULL;
    list->head = newnode;
    list->tail = newnode;
    list->top = data;
   }
   else
   {
    /*
        * In this case no need to tinker the head just update the tail of LL
    */
    node_t *newnode  = (node_t*)malloc(sizeof(node_t));
    newnode->Data = data;
    newnode->Next = NULL;
    list->tail->Next = newnode;
    list->tail = newnode;
    list->top = data;

   }
}


void AttachNodeWithIndex(LinkedList_t* list, const u32 index, const u32 data){

    node_t *iterator  = (node_t*)malloc(sizeof(node_t));
    iterator = list->head;
    u32 nodeCount = 0;

    while(iterator != NULL){

        if(nodeCount == index - 1){
            node_t *newnode = (node_t*)malloc(sizeof(node_t));
            newnode->Data = data;
            newnode->Next = iterator->Next;
            iterator->Next = newnode;
            
            break;
        }
        iterator = iterator->Next;
        nodeCount++;
    }
}


void DeleteNodeWithIndex(LinkedList_t* list, const u32 index){

    node_t *iterator  = (node_t*)malloc(sizeof(node_t));
    iterator = list->head;
    u32 nodeCount = 0;
    while(iterator != NULL){
        if(nodeCount == index -1){

            node_t *temp = iterator->Next;
            iterator->Next = temp->Next;
            list->top = iterator->Data;
            free(temp);
            break;
        }
        iterator = iterator->Next;
        nodeCount++;
    }

}



