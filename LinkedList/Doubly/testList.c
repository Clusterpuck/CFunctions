/******************************************************************************
 * Filename:  testList.c                                                      *
 * Author: Nicholas Wright 12880155                                           *
 * Purpose:                                                                   *
 * Assertions- PRE:                                                           *
 *            POST:                                                           *
 * Date Written:                                                              *
 * Edited By:       Date Edited:                                              *
 * ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void printInt( void *data )
{
    int* num = (int*)(data);
    printf("%d\n", *num);
}

void freeInt( void *data )
{
    free( data );
}


int main(int argc, char * argv[])
{
    int *onePtr =  (int*)malloc(sizeof(int));
    int *twoPtr =  (int*)malloc(sizeof(int));
    int *threePtr =  (int*)malloc(sizeof(int));
    int *fourPtr =  (int*)malloc(sizeof(int));
    int *fivePtr =  (int*)malloc(sizeof(int));
    int *testPtr = (int*)malloc(sizeof(int));

    void* temp;
    LinkedList *testList = createLinkedList();

    *onePtr = 1;
    *twoPtr = 2;
    *threePtr = 3;
    *fourPtr = 4;
    *fivePtr = 5;
    *testPtr = 200;

    /*This doesn't need to be cast to void- interesting*/
    insertLast( testList, onePtr );
    insertLast( testList, twoPtr );
    insertLast( testList, threePtr );
    insertLast( testList, fourPtr );
    insertLast( testList, fivePtr );

    
    printf("List size is %d\n", testList -> size );
    printLinkedList( testList, &printInt );

    printf("prior test\n");
    printf("from head next prior is %d\n",
            *((int*)(testList->head->next->prior->data) ) );


    /*@insert first test*/
    printf("inserting first\n");
    insertFirst( testList, testPtr );
    printLinkedList( testList, &printInt );
    printf("List size is %d\n", testList -> size );

    /*@remove first test*/
    printf("removing first\n");
    temp = removeFirst( testList );
    printLinkedList( testList, &printInt );
    printf("List size is %d\n", testList -> size );

    /*@insert last test*/
    printf("inserting last\n");
    insertLast( testList, testPtr );
    printLinkedList( testList, &printInt );
    printf("List size is %d\n", testList -> size );

    /*@remove last test*/
    printf("removing last\n");
    temp = removeLast( testList );
    freeInt( temp );
    printLinkedList( testList, &printInt );
    printf("List size is %d\n", testList -> size );

    while( testList->head != NULL )
    {
        removeFirst( testList );
    }

    freeLinkedList( testList, &freeInt );


    return 0;
}   
