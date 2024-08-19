#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef unsigned int u32;




/*
    * This is building block of our data structure
*/
typedef struct node
{
    u32 Data;
    struct node *Next;
}node_t;



/*
    * This is our data structure
*/
typedef struct LinkedList
{
    /*
        * Head and tail of the linked list data structure
    */
    node_t *head;
    node_t *tail;
    u32 top;

}LinkedList_t;

/*
    * Create a linked list and return the pointer(addr) of the start of the linked list
*/
LinkedList_t *CreateLinkedList();



void Print_List(LinkedList_t* list);
void Free_LinkedList(LinkedList_t* list);

/*
    Create a new node and append it to the linked list!
*/
void AppendToLinkedList(LinkedList_t* list, u32 data);
void AttachNodeWithIndex(LinkedList_t* list, const u32 index, const u32 data);
void DeleteNodeWithIndex(LinkedList_t* list, const u32 index);
