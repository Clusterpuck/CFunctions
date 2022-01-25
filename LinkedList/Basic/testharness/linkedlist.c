/*******************************************************************************
 *   Filename:linkedlist.c                                                     *
 *   Author: Nicholas Wright 12880155                                          *
 *   Purpose:                                                                  *
 *   Date Written:                                                             *
 *   Edited By:       Date Editted:                                            *
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
    list -> size =0;

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
 * Edited By:       Date Edited:                                              *
 * ***************************************************************************/

void insertFirst( LinkedList *list, void *entry )
{
    LiLiNode *firstNode = (LiLiNode*)malloc( sizeof(LiLiNode) );

    firstNode -> data = entry;

    if( list -> head == NULL ) 
    {
        #ifdef DEBUG
            printf("Empty list, inserting in head\n");
        #endif
        /*Empty list, so head is first node*/
        list -> head = firstNode;
        firstNode -> next = NULL;
    }
    else
    {   
        #ifdef DEBUG
            printf("Non-empty list, inserting then reassigning\n");
        #endif
        /*Assigns first node to be pointing to what is currently in head, 
 *        then sets first node to head*/
        ( firstNode -> next ) = ( list -> head );
        ( list -> head ) = firstNode;
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
 * Edited By:       Date Edited:                                              *
 * ***************************************************************************/
void * removeFirst( LinkedList * list )
{
    void* temp = NULL;
    LiLiNode * tempNode = NULL;

    /*First test if list is empty*/
    if( ( list -> head ) != NULL )
    {
        temp = list -> head -> data;

        /*next checks if list had more than one node*/
        if( ( list -> head -> next ) != NULL )
        {        
            tempNode = list -> head -> next;
        }
        /*As tempNode is initialised to NULL, if the only node was removed
         *this will set the head to NULL, as it would now be an empty list*/

        free( list -> head );

        list -> head = tempNode;

        /*assigns the next node in line to head
         *i.e. disconnects first value from the list*/
    
        --( list -> size );
            
    }
    else
    {
        printf( "List is empty, cannot remove node" );
    } 
            /*Data is returned so it can be free'd elsewhere*/
    return temp;
}




/******************************************************************************
 * Function: inserLast                                                        *
 * Author: Nicholas Wright 12880155                                           *
 * Purpose: Insert a node at the end of a linked list                         *
 * Imports: LinkedList and void data pointer                                  *
 * Exports: none                                                              *
 * Assertions- PRE: LinkedList is malloc'd and initialised, void pointer is
 *                  valid
 *            POST: Node has been created and linked lists last node
 *                  now points to it, new node points to NULL
 * Date Written: 18/09/21                                                     *
 * Edited By:       Date Edited:                                              *
 * ***************************************************************************/
void insertLast( LinkedList * list, void *entry )
{

    LiLiNode *lastNode = (LiLiNode*)malloc(sizeof( LiLiNode ) );
    /*tempNode does not need to be malloc as it's a second pointer
     *to a memory space that was already malloc'd*/
    LiLiNode *tempNode = list -> head;  
 
    lastNode -> data = entry;
    lastNode -> next = NULL;

    if( list -> head == NULL )
    /*Tests for empty list*/
    {
        list -> head = lastNode;
    }
    else
    {
        while( ( tempNode -> next ) != NULL )
        {
            #ifdef DEBUG
                printf("In the insertLast while loop\n");
            #endif
            tempNode = tempNode -> next;
        }
        /*When while loop is done, temp node will be the first null pointer*/

        tempNode -> next = lastNode;
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
 * Edited By:       Date Edited:                                              *
 * ***************************************************************************/
void *removeLast( LinkedList *list )
{
    void *temp = NULL;

    LiLiNode *tempOneNode;
    LiLiNode *tempTwoNode = NULL;

    tempOneNode = list -> head;

    if( tempOneNode != NULL ) /*Testing for empty list*/
    {
        if( tempOneNode -> next != NULL ) /*Testing for one node only list*/
        {
            tempTwoNode = tempOneNode -> next;

            while( ( tempTwoNode -> next ) != NULL )
            {
                tempOneNode = tempTwoNode;
                tempTwoNode = tempOneNode -> next;
            }

            /*When while loop is done, tempTwoNode will be last node
             *tempOneNode will be second last*/

            temp = tempOneNode -> next -> data; 

            free( tempOneNode -> next );
            tempOneNode -> next = NULL;

        }
        else
        {
            /*Only one item in list*/
            temp = list -> head -> data;
            free( list -> head );
            list -> head = NULL;
        }

        --( list->size );
    }
    else
    {
        #ifdef DEBUG
            printf( "List is empty, cannot remove last\n" );
        #endif
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
    
    
