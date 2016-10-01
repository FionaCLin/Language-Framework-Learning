//list.c file that implements all functions declared in list.h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct _node {
    int value;
    Node next;
} node;


Node new_node(int value){
    Node newNode = malloc(sizeof(node));
    assert(newNode != NULL);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}


//frees everything malloced for the list
void destroy(Node head) {
    Node curNode = head;
    Node prevNode = NULL;

    while (curNode != NULL) {
        prevNode = curNode;
        curNode = prevNode->next;
        free(prevNode);
    }

}

//appends a node of value to the end of the list
Node append(Node head, int value) {

    Node newNode = new_node(value);
    Node curNode = head;

    if ( curNode == NULL ) {
        head = newNode;
    } else {
        while ( curNode->next!=NULL ) {
            curNode = curNode->next;
        }
        curNode->next = newNode;
    }
    return head;
}

void printList(Node head){
    Node cur = head;
    while(cur != NULL){
        printf("[%d]->",cur->value);
        cur = cur->next;
    }
    printf("X\n");
}

// returns the length of a linked list
int length(Node head){
    // TODO
    Node cur = head;
    int len = 0;
    while(cur !=NULL) {
        cur = cur->next;
        len ++;
    }
    return len;
}

// Given a sorted list, insert a node into the list
// preserving sorted order
//given a list 0->1->2->5->7->X
//then sorted_insert(l, 4)
//now the list will be 0->1->2->4->5->7->X

Node sorted_insert(Node head, int val){
    //TODO
    Node cur = head;
    Node new = new_node(val);
    Node pre = NULL;
    if (  head == NULL ) { 
        head = new;
    } else {
        //traverse the list for the sorted order
        while( cur -> next != NULL && cur -> value < val ) {
            pre = cur;
            cur = cur -> next;
        }
        //check if it is inserting in the head 
        if ( cur -> next != NULL && pre != NULL ) {
            // it is not the end, put cur after new
            new -> next = cur;
            // it is not the head, put it after pre's next
            pre -> next = new;
        } else if ( pre == NULL ) {
            // it's the head, put it in the head
            new -> next = head;
            head = new;
        } else if ( cur -> next == NULL ) {
            //check if it is inserting in the end
            //it is the end, put new after cur->next
            cur -> next = new;
        }

    }
    return head;
}

//inserts a node of value AT specified index
//0  1  2  3
//given a list 0->1->2->X
//then insertAt(l, 2, 9);
//0  1  2  3  4
//now the list will be 0->1->9->2->X
//if specified index is greater than the length of the list 
//append it to the end
Node insertAt(Node head, int index, int value){
    //TODO
    Node new = new_node( value );
    if( head != NULL ) {
        if ( index == 0 ) {
            new -> next = head; 
            head = new;
        } else if ( index < length( head ) ) {
            int i;
            Node cur = head;
            for ( i = 0; i < index-1; i++ ) {
                cur = cur -> next;
            }
            new -> next = cur->next;
            cur->next = new;

        } else {
            head =  append( head, value );
        }
    } else {
        head =  append( head, value );
    }
    return head;
}
