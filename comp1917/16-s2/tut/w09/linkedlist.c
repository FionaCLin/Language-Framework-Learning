#include <stdio.h>
#include <stdlib.h>

typedef struct node* Lnode;

struct node{
    int val;
    Lnode next;  
};

typedef struct list* List;

struct list{
    Lnode head;
    int numNodes;
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

Lnode prepend( List list, Lnode new ) {
    //append rest of head to new
    new -> next = list->head;
    list -> head = new;
    list -> numNodes ++;
    return list -> head;
}

Lnode append( List list, Lnode new ) {
    Lnode curr = list -> head;
    while ( curr->next != NULL ) { 
        curr = curr -> next;
    }
    curr -> next = new;
    return list -> head;
}

void printList( List list ) {
    Lnode curr = list -> head;
    
    while( curr != NULL ) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}
Lnode deleteNode( List list, int val ) {
    Lnode nTF = list -> head;
    Lnode prev = NULL;
    while ( nTF != NULL && nTF->val != val ) {
        prev = nTF;
        nTF = nTF->next;
    }
    if ( nTF != NULL ) {
        if ( nTF == list -> head ) {
            list -> head = nTF->next;
        } else {
            prev->next = nTF->next;
        }
        free(nTF);
    }
    return list->head;
}

Lnode concat( Lnode L, Lnode M ) {
    Lnode cur = L;
    while ( cur != NULL ) {
        cur = cur -> next;
    }
    cur -> next = M;
    return L;
}























