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


List newList(void);
void append(List l, Lnode new);
void printList(List l);
void deleteNode(List l, int val);
void shuffle_Merge(List l, List m);
void reverse(List l);
void swap(List l);


List newList(void) {
    List new = malloc(sizeof(struct list));
    if (new != NULL) {
        new -> head = NULL;
        new -> numNodes = 0;
    }
    return new;
}

void append(List l, Lnode new) {i
    if ( l -> numNodes == 0 ){
        l -> head = new;
    } else {
        Lnode cur = l -> head;
        while ( cur -> next != NULL ) {
            cur = cur -> next;
        }
        cur -> next = new;
    }
}
void printList(List l) {
    if (l -> numNodes != 0) {
        Lnode cur = l -> head;
        while (cur != NULL) {
            printf("%d", cur -> val);
            if ( cur -> next != NULL ) {
                printf(", ");
            }
            cur = cur -> next;
        }
        printf("\n");
    }
}

void deleteNode(List l, int val) {
    if (l -> numNodes != 0) {
        Lnode cur = l -> head;
        Lnode pre = NULL;
        while ( cur != NULL ) {
            if (cur -> val == val) {
                if (pre == NULL) {
                    l -> next = cur -> next;
                } else {
                    pre -> next = cur -> next;
                }
                free(cur);
            } else {
                pre = cur;
                cur = cur -> next;
            }
        }
    }
}
