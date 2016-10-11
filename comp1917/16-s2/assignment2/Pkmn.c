#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Pkmn.h"
const char * const TYPES[] = {
    "Bug",
    "Dark",
    "Dragon",
    "Electric",
    "Fairy",
    "Fighting",
    "Fire",
    "Flying",
    "Ghost",
    "Grass",
    "Ground",
    "Ice",
    "Normal",
    "Poison",
    "Psychic",
    "Rock",
    "Steel",
    "Water"};



// ADD YOUR CODE HERE - any extra typedefs and #defines you'd like to use

struct _list {
    // ADD YOUR CODE HERE
    Pkmn head;
    int size;
    Pkmn cur;
    int numFound;
};


struct _pkmn {
    // ADD YOUR CODE HERE
    int isFound;
    int id;
    char *name;
    float height;
    float weight;
    int type1;
    int type2;
    Pkmn next;
};

// ADD YOUR CODE HERE - any extra structs you'd like to use

// ADD YOUR CODE HERE - any extra helper functions you'd like to use from within this file
static void printPkmn(Pkmn m) {
    // m stand for monster
    int i, len;
    if (m != NULL) {
        if ( m -> isFound ) {
            printf( "ID: #%03d \nName: %s\nHeight: %.2fm\nWeight: %.2fkg\n", m
                    -> id, m -> name, m -> height, m -> weight );
            printf( "Type: %s", TYPES[m -> type1] );
            if ( m -> type2 != -1 ) {
                printf( "/%s\n", TYPES[m -> type2] );
            } else {
                printf( "\n" );
            }
        }
        else {
            printf( "ID: %03d \nName: ", m -> id );
            len = strlen( m -> name );
            for ( i = 0; i < len; i++ ) {
                putchar( '*' );
            } 
            printf( "\nHeight: --\nWeight: --\nType: --\n" );
        }
    }
}
const char * getTypeString( int i ) {
    return TYPES[i];
}

Pkmn createPkmn(int id, char * name, double height, double weight, int type1, int type2) {
    // ADD YOUR CODE HERE
    Pkmn newPkmn = malloc(sizeof(struct _pkmn));
    if (newPkmn != NULL) {
        newPkmn -> isFound = FALSE;
        newPkmn -> id = id;
        newPkmn -> name = name;
        newPkmn -> height = height;
        newPkmn -> weight = weight;
        newPkmn -> type1 = type1;
        newPkmn -> type2 = type2;
        newPkmn -> next = NULL;
    }
    return newPkmn;
}

void printCurrentPkmn(PkmnList list) {
    // ADD YOUR CODE HERE
    if (list != NULL)   {
        printPkmn(list -> cur);
    }
}


PkmnList createPkmnList() {
    // ADD YOUR CODE HERE
    PkmnList newList = malloc(sizeof(struct _list));
    if (newList != NULL) {
        newList -> head = NULL;
        newList -> cur = NULL;
        newList -> size = 0;
    }
    return newList;
}

void freePkmnList(PkmnList list) {
    // ADD YOUR CODE HERE
    Pkmn cur = NULL;
    while ( list != NULL && list -> head != NULL ) {
        cur = list -> head;
        list -> head = cur -> next;
        free(cur);       
    }
    free(list);
}

void addPkmnToList(PkmnList list, Pkmn pkmn) {
    // ADD YOUR CODE HERE
    if (list != NULL) {
        if (list -> head == NULL) {
            list -> head = pkmn;    
            list -> cur  = pkmn;    
        } else {
            Pkmn cur = list -> head;
            while (cur -> next != NULL) {
                cur = cur -> next;
            }
            cur -> next = pkmn;
        }
        (list -> size)++;
    }
}

void printPkmnList(PkmnList list) {
    // ADD YOUR CODE HERE
    int i, len;
    Pkmn cur = NULL;
    if (list != NULL) {
        cur = list -> head;
        while (cur != NULL) {
            if (cur == list -> cur) {
                printf("-->#%03d: ", cur -> id);
                if ( cur -> isFound ) {
                    printf("%s\n", cur -> name);
                } else {
                    len = strlen( cur -> name );
                    for ( i = 0; i < len; i++ ) {
                        putchar( '*' );
                    } 
                    putchar( '\n' );
                }
            } else {
                printf("   #%03d: ", cur -> id);
                if ( cur -> isFound ) {
                    printf("%s\n", cur -> name);
                } else {
                    len = strlen( cur -> name );
                    for ( i = 0; i < len; i++ ) {
                        putchar( '*' );
                    } 
                    putchar( '\n' );
                }
            }
            cur = cur -> next;
        }
    } 
}

void nextPkmn(PkmnList list) {
    // ADD YOUR CODE HERE
    Pkmn cur = NULL;
    if ( list != NULL ) {
        cur = list -> head;
        while ( cur != NULL && cur != list -> cur ) {
            cur = cur -> next;
        }
        if ( cur != NULL && cur -> next != NULL ) {
            list -> cur = cur -> next;
        }
    }
}

void prevPkmn(PkmnList list) {
    // ADD YOUR CODE HERE
    Pkmn cur = NULL;
    if ( list != NULL ) {
        cur = list -> head;
        if ( cur != list -> cur ){
            while ( cur != NULL && cur -> next != NULL 
                && cur -> next != list -> cur ) {
                cur = cur -> next;
            }
            if ( list -> size != 1 ){}
                list -> cur = cur;
            }
        }
}

void jumpToPkmn(PkmnList list, int id) {
    // ADD YOUR CODE HERE
    Pkmn cur = NULL;
    if ( list != NULL ) {
        cur = list -> head;
        while ( cur != NULL 
                && cur -> id != id ) {
            cur = cur -> next;
        }
        if ( cur != NULL ){
            list -> cur = cur;
        }
    }
}

void removePkmn(PkmnList list) {
    // ADD YOUR CODE HERE
    if ( list != NULL ) {
        Pkmn remove = list -> cur;
        if ( remove == list -> head ) {
            nextPkmn( list );
            list -> head = remove -> next;
        } else if ( remove -> next == NULL ) {
            prevPkmn( list );
            list -> cur -> next = NULL;
        } else {
            prevPkmn( list );
            list -> cur -> next = remove -> next;
            nextPkmn( list );
        }
        free( remove );
        (list -> size)--;
    }
}

// Stage 3 Functions
void findPkmn(int seed, int factor, int numberOfNewPkmn, PkmnList list) {
    // ADD YOUR CODE HERE
}

int totalFound(PkmnList list) {
    // ADD YOUR CODE HERE
    return 0;
}


// Stage 4 Functions
void addEvolution(PkmnList list, int pkmnId, int evolutionId) {
    // ADD YOUR CODE HERE
}

void showEvolutions(PkmnList list) {
    // ADD YOUR CODE HERE
}


// Stage 5 Functions
PkmnList getPkmnOfType(PkmnList list, int type) {
    // ADD YOUR CODE HERE
    return NULL;
}

PkmnList getFoundPkmn(PkmnList list) {
    // ADD YOUR CODE HERE
    return NULL;
}

PkmnList searchByName(PkmnList list, char text[]) {
    // ADD YOUR CODE HERE
    return NULL;
}

