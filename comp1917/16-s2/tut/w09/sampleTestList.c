/*
 * testList.c
 *
 * White Box Test the List ADT
 *
 * Author:  Curtis Millar
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "List.h"

void testPrepend(void);
void testAppend(void);
void testDeleteNode(void);

int main (int argc, char *argv[]) {
    testDeleteNode();
    testPrepend();
    testAppend();

    printf("All tests passed. You are awesome!!!\n");

    return 0;
}

void testPrepend(void) {
    Lnode list = NULL;

    printf("Should print nothing.\n");
    printList(list);

    list = prepend(list, newNode(19));
    printf("Should print: 19.\n");
    printList(list);

    list = prepend(list, newNode(40));
    printf("Should print: 40, 19.\n");
    printList(list);

    list = prepend(list, newNode(45));
    printf("Should print: 45, 40, 19.\n");
    printList(list);

    list = deleteNode(list, 45);
    list = deleteNode(list, 40);
    list = deleteNode(list, 19);

    printf("Should print nothing.\n");
    printList(list);

    printf("testPrepend passed =^.^=.\n");

    return;
}

void testAppend(void) {
    Lnode list = NULL;

    printf("Should print nothing.\n");
    printList(list);

    list = append(list, newNode(19));
    printf("Should print: 19.\n");
    printList(list);

    list = append(list, newNode(40));
    printf("Should print: 19, 40.\n");
    printList(list);

    list = append(list, newNode(45));
    printf("Should print: 19, 40, 45.\n");
    printList(list);

    list = deleteNode(list, 45);
    list = deleteNode(list, 40);
    list = deleteNode(list, 19);

    printf("Should print nothing.\n");
    printList(list);

    printf("testAppend passed =^.^=.\n");
    return;
}

void testDeleteNode(void) {
    /* Test cases:
     *   Empty list
     *   Not in list
     *   Duplicates (does it only delete the first?)
     *   Single item
     */
    Lnode list = NULL;


    // Empty List
    list = deleteNode(list, 10538);

    printf("Should print nothing.\n");
    printList(list);

    // List with stuff in it
    int i;
    for (i = 0; i < 13; i += 3) {
        list = append(list, newNode(i * 9));
    }

    printList(list);
    list = deleteNode(list, 14);
    printf("Should print the same.\n");
    printList(list);

    // List with stuff in it
    for (i = 0; i < 13; i += 3) {
        list = append(list, newNode(i * 9));
    }

    printList(list);
    list = deleteNode(list, 27);
    printf("Should remove the first 27.\n");
    printList(list);


    return;
}





