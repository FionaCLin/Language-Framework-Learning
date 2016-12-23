#include <stdio.h>
#include <stdlib.h>

typedef struct node * Lnode;

struct node {
    int val;
    Lnode next; // Lnode next;
};

Lnode newNode( int value ) {
    Lnode newNode = malloc(sizeof(struct node));
    if ( newNode == NULL ) {
        printf( "out of memory" );
    }
    newNode -> next = NULL;
    newNode -> val = value;
    return newNode;
}

Lnode prepend( Lnode head, Lnode new ) {
    //append rest of head to new
    new -> next = head;
    return new;
}
Lnode append( Lnode head, Lnode new ) {
    Lnode curr = head;
    while ( curr->next != NULL ) { 
        curr = curr -> next;
    }
    curr -> next = new;
    return head;
}
void printList( Lnode head ) {
    Lnode curr = head;
    
    while( curr != NULL ) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}
Lnode deleteNode( Lnode head, int val ) {
    Lnode nTF = head;
    Lnode prev = NULL;
    while ( nTF != NULL && nTF->val != val ) {
        prev = nTF;
        nTF = nTF->next;
    }
    if ( nTF != NULL ) {
        if ( nTF == head ) {
            head = nTF->next;
        } else {
            prev->next = nTF->next;
        }
        free(nTF);
    }
    return head;
}























/*
void printList(List list){
    int i;
    Node curr = list->head;
    for ( i = 0; i < list->ize; i++ ){
        printf("%d",curr->item);
        curr = curr->next;
    }
    
}*/
