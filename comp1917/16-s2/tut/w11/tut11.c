#include <stdio.h>
#include <stdlib.h>
typedef struct node* Lnode;

struct node{
    int val;
    Lnode next;

};

typedef struct _queue* Queue;

struct _queue{
    Lnode head;
    int num_nodes;

};

void printQ( Queue q ) {
    if ( q != NULL ) {
        Lnode c = q -> head;
        while ( c != NULL ) {
            printf( "%d ", c -> val );
            c = c -> next;
        }
        putchar('\n');
    }

}
//
//implement the function below.
//1. Write a function Queue createQueue(void) that creates a new Queue.
Queue createQueue( void ) {
    Queue res = malloc( sizeof( struct _queue ) );
    if ( res != NULL ) {
        res -> head = NULL;
        res -> num_nodes = 0;
    }
    return res;
}
//2. Write a function void enqueue(Queue q, int val) that adds an item
//to the queue.
void enqueue(Queue q, int val) {
    if ( q != NULL ) {
        Lnode new = malloc( sizeof( struct node ) );
        if ( new != NULL ) {
            new -> val = val;
            new -> next = NULL;
            if ( q -> head == NULL ) {
                q -> head = new;
            } else {
                Lnode curr = q -> head;
                while( curr -> next != NULL ) {
                    curr = curr -> next;
                }
                curr -> next = new;
                ( q -> num_nodes )++;
            }
        }
    }
}

//3. Write a function void dequeue(Queue q) that removes an item from
//the queue.
void dequeue(Queue q) {
    if ( q != NULL ) {
        if ( q -> head != NULL ) {
            Lnode cur = q-> head;
            q -> head = cur -> next;
        }
    }
}
//4. Create a separate file called testQueue.c and test the above
//functions.

//Now we will build an array based queue. Use the following struct
//definition

//typedef struct _queue* Queue;
//
//struct _queue{
//    int *array; // make it 10 elements initially
//    int num_nodes;
//
//};
//
//
//5. Are there any disadvantages of this implementation in comparison to
//linked list one.
//memory need to reserve 10 elements initially; not dynamic allocation.
//6. How would you change your tests if you use this representation?
//?
//7. Write whitebox tests for both implementations.
//?
//8. If time allows use your valgrind and gdb skills to debug the
//following [1]code
//__________________________________________________________________
//
