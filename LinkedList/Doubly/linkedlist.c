/*******************************************************************************
 *   Filename:linkedlist.c                                                     *
 *   Author: Nicholas Wright 12880155                                          *
 *   Purpose: Creat a generic linked list that double linked                   *
 *   Date Written: 18/09/21                                                    *
 *   **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


/******************************************************************************
 * Function: createLinkedList                                                 *
 * Author: Nicholas Wright 12880155                                           *
 * Purpose: Initialise the linked list's first node                           *
 * Imports: none                                                              *
 * Exports: The Linked List pointer to first node/head node                   *
 * Assertions- PRE:                                                           *
 *            POST: Linked list head is returned, with head intialised to NULL*
 * Date Written: 18/09/21                                                     *
 * Edited By:       Date Edited:                                              *
 * ***************************************************************************/
LinkedList* createLinkedList()
{
    LinkedList *list = (LinkedList*)malloc( sizeof(LinkedList) );
    list -> head = NULL;
    list -> tail = NULL;
    list -> size = 0;

    return list;
        
}




/******************************************************************************
 * Function: insertFirst                                                      *
 * Author: Nicholas Wright 12880155                                           *
 * Purpose: Insert a node into the first location in the list                 *
 * Imports: an intialised and malloc's LinkedList pointer                     * 
 * Exports: none                                                              *
 * Assertions- PRE: LinkedList is initialised and malloc'd, entry is valid    *
 *            POST: Head points to new node, and the new node points to       *
 *                  either NULL if list was empty, or the previous first node.*
 * Date Written: 18/09/21                                                     *
 * Edited By: NGW   Date Edited: 19/09/21
 * Purpose: Add tail and size and prior functionality
 * ***************************************************************************/

void insertFirst( LinkedList *list, void *entry )
{
    LiLiNode *firstNode = (LiLiNode*)malloc( sizeof(LiLiNode) );

    firstNode -> data = entry;

    if( list -> head == NULL ) 
    {
        /*Empty list, so head is first node*/
        list -> head = firstNode;
        firstNode -> next = NULL;
        firstNode -> prior = NULL;
        /*Creates single node list, so nothing before or after*/
        list -> tail = firstNode; /*If no other node present in list
                                    then the head and tail are the same*/
    }
    else
    {   
        /*Assigns first node to be pointing to what is currently in head, 
         *then sets first node to head*/
        firstNode -> next = list -> head;
        /*Sets the prior what is to be the second node 
         *to what is to be the head*/
        list -> head -> prior = firstNode; 
        list -> head = firstNode;
        list -> head -> prior = NULL;  /*Sets the heads prior back to NULL*/
    }

    ++( list -> size );

}





/******************************************************************************
 * Function: removeFirst                                                      *
 * Author: Nicholas Wright 12880155                                           *
 * Purpose: Remove node the head points to (if any) and reconnects head to    *
 *          next node (if any)                                                *
 * Imports: LinkedList pointer                                                *
 * Exports: void pointer to data of removed node                              *
 * Assertions- PRE: LinkedList is initialised and malloc'd                    *
 *            POST: head has been reconnected to next node in line.           *
 *                  void pointer to data from removed node is returned.       *
 * Date Written: 18/09/21                                                     *
 * Edited By: NGW   Date Edited: 19/09/21
 * Purpose: Add tail and size functionality
 * ***************************************************************************/

void * removeFirst( LinkedList * list )
{
    void* temp = NULL;
    LiLiNode * tempNode = NULL;

    /*First test if list is not empty*/
    if( ( list -> head ) != NULL )
    {
        temp = list -> head -> data;

        /*next checks if list had more than one node*/
        if( ( list -> head -> next ) != NULL )
        {        
            tempNode = list -> head -> next;
            tempNode -> prior = NULL;
        }
        /*As tempNode is initialised to NULL, if the only node was removed
         *this will set the head to NULL, as it would now be an empty list*/

        free( list -> head );

        list -> head = tempNode;
    
        /*assigns the next node in line to head
         *i.e. disconnects first value from the list
          removes previous prior pointer to now removed value*/

        --( list -> size );
            
    }
            /*Data is returned so it can be free'd elsewhere*/
    return temp;
}




/******************************************************************************
 * Function: insertLast                                                       *
 * Author: Nicholas Wright 12880155                                           *
 * Purpose: Insert a node at the end of a linked list                         *
 * Imports: LinkedList and void data pointer                                  *
 * Exports: none                                                              *
 * Assertions- PRE: LinkedList is malloc'd and initialised, void pointer is
 *                  valid
 *            POST: Node has been created and linked lists last node
 *                  now points to it, new node points to NULL
 * Date Written: 18/09/21                                                     *
 * Edited By: NGW   Date Edited: 19/09/21
 * Purpose: Add tail, size and prior functionality
 * ***************************************************************************/
void insertLast( LinkedList * list, void *entry )
{

    LiLiNode *lastNode = (LiLiNode*)malloc(sizeof( LiLiNode ) );
 
    lastNode -> data = entry;
    lastNode -> next = NULL;
    lastNode -> prior = NULL;

    if( list -> head == NULL )
    /*Tests for empty list*/
    {
        /*as only one node, next and prior remain NULL*/
        list -> head = lastNode;
        list -> tail = lastNode;
    }
    else
    {
        /*Makes the node in the tail point to the new lastNode,
 *        and the prior of the new lastNode point to current tail
 *        then sets the lastNode to the tail*/
        lastNode -> prior = list -> tail;
        list -> tail -> next = lastNode;
        list -> tail = lastNode;
    }

    ++( list -> size );

}





/******************************************************************************
 * Function: removeLast                                                       *
 * Author: Nicholas Wright 12880155                                           *
 * Purpose: remove last node in a LinkedList                                  *
 * Imports: An intialised and malloc'd linked list                            *
 * Exports: void pointer                                                      *
 * Assertions- PRE: LinkedList is malloc'd and initialised                    *
 *            POST: last node has been free'd, second last node points to
 *                  null, last node's data pointer is returned.
 * Date Written: 18/09/21                                                     *
 * Edited By: NGW   Date Edited: 19/09/21
 * Purpose: Add tail and size functionality
 * ***************************************************************************/

void *removeLast( LinkedList *list )
{
    void *temp = NULL;

    LiLiNode *tempNode;

    tempNode = list -> head;

    if( tempNode != NULL ) /*Testing for non-empty list*/
    {
        if( tempNode -> next != NULL ) /*Testing for one node only list*/
        {
            /*prior pointer provides the location of new tail after removal*/
            tempNode = list -> tail -> prior;
            temp = list -> tail -> data;
            free( list -> tail );
            list -> tail = tempNode;
            list -> tail -> next = NULL;

        }
        else
        {
            /*Only one item in list*/
            temp = list -> head -> data;
            free( list -> head );
            list -> head = NULL;
            /*With only one node, head = tail, therefore do not need
             *to free tail*/
        }
 
        --( list -> size );
    }
    
    return temp;

}  




/******************************************************************************
 * Function: printLinkedList                                                  *
 * Author: Nicholas Wright 12880155                                           *
 * Purpose: Sends each nodes data to a function to print appropiately         *
 * Imports: LinkedList and Function pointer                                   *
 * Exports: none                                                              *
 * Assertions- PRE: LinkedList is initialised and malloc'd                    *
 *            POST: all data, if any has been sent to funtion pointer.        *
 * Date Written: 18/09/21                                                     *
 * Edited By:       Date Edited:                                              *
 * ***************************************************************************/

void printLinkedList( LinkedList* list, listFunc funcPtr )
{
    LiLiNode* tempNode = list -> head;
    
    while ( tempNode != NULL )/*If list is empty, while loop doesn't start*/
    {
        funcPtr( tempNode -> data );
        tempNode = tempNode -> next;
    }

}






/******************************************************************************
 * Function: freeLinkedList                                                   *
 * Author: Nicholas Wright 12880155                                           *
 * Purpose: Free all nodes and head of LinkedList                             *
 * Imports: LinkedList, function pointer                                      *
 * Exports: none                                                              *
 * Assertions- PRE: function pointer acts to free data, LinkedList is
 *                  malloc'd and intialised
 *            POST: All nodes inlcuding the head and the list have been free'd
 *                  all nodes' data have been sent to the funtion pointer.
 * Date Written: 18/09/21                                                     *
 * Edited By:       Date Edited:                                              *
 * ***************************************************************************/

void freeLinkedList( LinkedList *list, listFunc funcPtr )
{
    LiLiNode* tempNode;

    while( list -> head != NULL )
    {
        tempNode = list -> head -> next; /*Set temp to point to next node*/

        funcPtr( list -> head -> data ); /*Exports data at head to be free'd*/
        free( list -> head );
        list -> head = NULL;
        list -> head = tempNode; /*Sets head to the next node in line*/
    }
    
    free( list );
    list = NULL;
}
    
    
