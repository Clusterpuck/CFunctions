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

void printChar( void *data )
{
    char** text = (char**)(data);
    printf("%d\n", *text);
}

void freeChar( void *data )
{
    free( data );
}


int main(int argc, char * argv[])
{
    char *onePtr =  (char*)malloc(sizeof(int));
    char *twoPtr =  (char*)malloc(sizeof(int));
    char *threePtr =  (char*)malloc(sizeof(int));
    int *fourPtr =  (int*)malloc(sizeof(int));
    int *fivePtr =  (int*)malloc(sizeof(int));
    int *testPtr = (int*)malloc(sizeof(int));

    void* temp;
    int i;
    int *varyPtr;
    LinkedList *testList = createLinkedList();

    *onePtr = 1;
    *twoPtr = 2;
    *threePtr = 3;
    *fourPtr = 4;
    *fivePtr = 5;
    *testPtr = 99;

    /*This doesn't need to be cast to void- interesting*/
    insertLast( testList, onePtr );
    insertLast( testList, twoPtr );
    insertLast( testList, threePtr );
    insertLast( testList, fourPtr );
    insertLast( testList, fivePtr );

    for( i = 6; i < 11; i++)
    {
        varyPtr = (int*)malloc(sizeof(int));
        (*varyPtr) = i;
        insertLast( testList, (void*)varyPtr );
    } 
    
    printf("List size is %d\n", testList -> size );
    printLinkedList( testList, &printInt );

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

    freeLinkedList( testList, &freeInt );


    return 0;
}   
