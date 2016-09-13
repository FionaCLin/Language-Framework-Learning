#include "Stack.h"
#include "Pancake.h"
#include <stdlib.h>
#include <stdio.h>

struct stack {
    int numPancakes;
    Pancake array[MAX_PANCAKES];
};

Stack createStack(void) {
    // TO DO
    //does zero pancake mean NULL in array?
    Stack newStack = malloc( sizeof(struct stack ) );
    if ( newStack != NULL ) {
        newStack -> numPancakes = 0;
    }
    return newStack;
}
// if stack is already full, do nothing
void addPancake(Stack s, char *topping, int size) {
    // TO DO
    if ( s -> numPancakes != MAX_PANCAKES ) {
        Pancake newPancake = bake( topping, size );
        s -> array[s -> numPancakes] = newPancake;
        s -> numPancakes ++;
    }
}
// if stack is already empty, do nothing

void eatPancake(Stack s){
    // TO DO
    if ( s -> numPancakes != 0) {
        eat( s -> array[s -> numPancakes-1] );
        s -> numPancakes --;
    }
}

int numPancakes(Stack s) {
    // TO DO
    return s -> numPancakes;
}

int totalSize(Stack s) {
    // TO DO
    int totalSize = 0;
    int i;
    for ( i = 0; i < s -> numPancakes; i ++ ){
        //totalSize += s -> array[i] -> size;
        totalSize += getSize( s -> array[i] );
    }
    return totalSize;
}

void printToppings(Stack s) {
    // TO DO
    int i;
    for ( i = s -> numPancakes; i > 0; i-- ) { 
        printf("%d pancake's topping  %s\n", i, getTopping( s -> array[i-1] ) );
    }
}


void consumeStack(Stack s) {
    // TO DO
    int i;
    for ( i = 0; i < s -> numPancakes; i++ ) {
        free( s -> array[i] );// eat( s -> array[i] );
    }
    free( s );
}
