#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

struct node{
    int val;
    Lnode next;  
};


struct list{
    Lnode head;
    int num_nodes;
};

Lnode new_node(int val){
    Lnode new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Out of memory:(\n");
        exit(1);
    }
    new->val = val;
    new->next = NULL;
    return new;
}
List newList(void){
    List new = malloc(sizeof(struct list));
    if(new == NULL){
        printf("Out of memory:(\n");
        exit(1);
    }
    new->head = NULL;
    new->num_nodes = 0;
    return new;
}

void append(List l, int val){
    assert(l != NULL);
    Lnode cur = l->head;
    Lnode new = new_node(val);
    if(cur == NULL){
        l->head = new;
    }else{
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = new;

    }
    l->num_nodes++;
}

void printList(List l){
    assert(l!= NULL);
    Lnode cur = l-> head;
    while(cur != NULL){
        printf("[%d]->",cur->val);
        cur = cur->next;
    }
    printf("X\n");
}


void destroy(List l){
    assert(l!= NULL);
    Lnode cur = l->head;
    Lnode prev = NULL;
    // free every single element of the list
    while(cur!= NULL){
        prev = cur;
        cur = cur->next;
        free(prev);
    }
    // free the list structure itself
    free(l);
}
int num_nodes(List l){
    return l->num_nodes;
}
//Given a linked list and fetch the last element val
static void reverseList ( List l, List rl ) {
    Lnode last = NULL;
    Lnode prev = NULL;
    if ( l != NULL && rl != NULL ) {
        if ( l -> head != NULL ) {
            last = l -> head;
            while ( last -> next != NULL ) {
                prev = last;
                last = last -> next;
            }
            if ( prev == NULL ) {
                l -> head = NULL;
            } else {
                prev -> next = NULL;
            }
            append( rl, last -> val );
            reverseList( l, rl );
        }
    }

} 

//Given a linked list print it out in reverse
//Do not reverse original list
//Example:
//Given linked list [1]->[2]->[3]->X
//print_reverse output: [3]->[2]->[1]->X
void print_reverse(List l){
    List rl = newList();
    if ( l != NULL && rl != NULL ) {
        reverseList( l, rl ); 
        printList( rl );
    }
}
static int containsVal( List l, int val ) {
    Lnode res = NULL;
    Lnode cur = NULL;
    if ( l != NULL ) {
        cur = l -> head;
        while ( cur != NULL && cur -> val != val ) {
            cur = cur -> next;
        }
        if ( cur != NULL && cur -> val == val ) {
            res = cur;
        }

    }
    return (res != NULL) ;
}


//Given a linked list create a new list containing only unique 
//elements of the current list. The order of the elements should remain 
// the same as in original linked list. Do not modify the original list.
//Example
//Input: 1->1->2->3->3->3->0->X
//Output:1->2->3->0->X
List extract_unique(List l){
    List ul = newList();
    if ( l != NULL && ul != NULL ) {
        Lnode cur = l -> head;
        while ( cur != NULL ) {
            if ( ! containsVal( ul, cur -> val )  ) {
                append( ul, cur -> val );
            }
            cur = cur -> next;
        }
    }
    return ul ;
}







