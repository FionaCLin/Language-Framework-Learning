#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Pkmn.h"

#define FALSE 0
#define TRUE  !(FALSE)

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
    int nextGenId;
};

// ADD YOUR CODE HERE - any extra structs you'd like to use

// ADD YOUR CODE HERE - any extra helper functions you'd like to use from within this file
static void displayUnfoundName(char * name) {
    int i;
    int len = strlen(name);
    for (i = 0; i < len; i++) {
        putchar('*');
    }
}

static void printPkmnListName(Pkmn pkmn, Pkmn cur) {
    if (pkmn ==  cur) {
        printf("--> #%03d: ", pkmn -> id);
        if (pkmn -> isFound) {
            printf("%s\n", pkmn -> name);
        } else {
            displayUnfoundName(pkmn -> name);
            putchar('\n');
        }
    } else {
        printf("    #%03d: ", pkmn -> id);
        if (pkmn -> isFound) {
            printf("%s\n", pkmn -> name);
        } else {
            displayUnfoundName(pkmn -> name);
            putchar('\n');
        }
    }
}

static Pkmn cpPkmn(Pkmn pkmn) {
    Pkmn newPkmn = malloc(sizeof(struct _pkmn));
    if (newPkmn != NULL) {
        newPkmn -> isFound = pkmn -> isFound;
        newPkmn -> id = pkmn -> id;
        newPkmn -> name = strdup(pkmn -> name);
        newPkmn -> height = pkmn -> height;
        newPkmn -> weight = pkmn -> weight;
        newPkmn -> type1 = pkmn -> type1;
        newPkmn -> type2 = pkmn -> type2;
        newPkmn -> next = NULL;
        newPkmn -> nextGenId = pkmn -> nextGenId;
    }
    return newPkmn;
}

static void printPkmn(Pkmn m) {
    // m stand for monster
    if (m != NULL) {
        if (m -> isFound) {
            printf("Id:%03d\nName: %s\nHeight: %.2fm\nWeight: %.2fkg\n", m
                    -> id, m -> name, m -> height, m -> weight);
            printf("Type: %s", TYPES[m -> type1]);
            if (m -> type2 != -1) {
                printf("/%s\n", TYPES[m -> type2]);
            } else {
                printf("\n");
            }
        }
        else {
            printf("Id: %03d\nName: ", m -> id);
            displayUnfoundName(m -> name); 
            printf("\nHeight: --\nWeight: --\nType: --\n");
        }
    }
}

static Pkmn fetchById(PkmnList list, int id) {
    Pkmn fetch = NULL;
    Pkmn curr = NULL;
    if (list != NULL && list -> head != NULL) {
        curr = list -> head;    
        while (curr -> next != NULL && curr -> id != id) {
            curr = curr -> next;
        }
        if (curr -> id == id) {
            fetch = curr;
        }
    }
    return fetch;
}

static int * sortListIds(PkmnList list) {
    int i = 0;
    Pkmn cur = NULL;
    int temp;
    int swap = -1;
    int * ids = NULL;
    if (list != NULL) {
        ids = malloc(sizeof(int) * list -> size);
        cur = list -> head;
        while (cur != NULL) {
            ids[i] = cur -> id;
            cur = cur -> next;
            i++;
        }
        while (swap != 0) {
            swap =0;
            for (i = 1; i < list -> size; i ++) {
                if (ids[i - 1] > ids[i]) {
                    temp = ids[i];
                    ids[i] = ids[i - 1];
                    ids[i - 1] = temp;
                    swap++;
                }
            }
        }
    }
    return ids;
}

static int nContainsT(char * n, char * t) {
    int contains = FALSE;
    int i = 0;
    int j = 0;
    int nlen = 0;
    int tlen = 0;

    while (n[i] != '\0') {
        i++;
    }
    nlen = i;
    i = 0;
    while (t[i] != '\0') {
        i++;
    }
    tlen = i;
    i = 0;
    if (nlen >= tlen) {
        while (n[i] != '\0') {
            j = 0;
            if (tolower(n[i + j]) == tolower(t[j])) {
                while (t[j] != '\0' && tolower(n[i + j])  == tolower(t[j])) {
                    j++;
                }
                if (t[j] == '\0') {
                    contains = TRUE;
                }
            }
            i++;
        }
    }
    return contains;
}

const char * getTypeString(int i) {
    return TYPES[i];
}

Pkmn createPkmn(int id, char * name, double height, double weight, int type1, int type2) {
    // ADD YOUR CODE HERE
    Pkmn newPkmn = malloc(sizeof(struct _pkmn));
    if (newPkmn != NULL) {
        newPkmn -> isFound = FALSE;
        newPkmn -> id = id;
        newPkmn -> name = strdup(name);
        newPkmn -> height = height;
        newPkmn -> weight = weight;
        newPkmn -> type1 = type1;
        newPkmn -> type2 = type2;
        newPkmn -> next = NULL;
        newPkmn -> nextGenId = id;
    }
    return newPkmn;
}

void printCurrentPkmn(PkmnList list) {
    // ADD YOUR CODE HERE
    if (list != NULL) {
        if (list -> size != 0) {
            printPkmn(list -> cur);
        } else {
            printf("No Pokemon in list.\n");
        }
    }
}


PkmnList createPkmnList() {
    // ADD YOUR CODE HERE
    PkmnList newList = malloc(sizeof(struct _list));
    if (newList != NULL) {
        newList -> head = NULL;
        newList -> cur = NULL;
        newList -> size = 0;
        newList -> numFound = 0;
    }
    return newList;
}

void freePkmnList(PkmnList list) {
    // ADD YOUR CODE HERE
    Pkmn cur = NULL;
    while (list != NULL && list -> head != NULL) {
        cur = list -> head;
        list -> head = cur -> next;
        free(cur->name);       
        free(cur);       
    }
    free(list);
}

void addPkmnToList(PkmnList list, Pkmn pkmn) {
    // ADD YOUR CODE HERE
    if (list != NULL && pkmn != NULL) {
        if (list -> head == NULL) {
            list -> head = pkmn;    
            list -> cur  = pkmn;
        } else {
            Pkmn cur = list -> head;
            while (cur -> next != NULL && cur -> id != pkmn -> id) {
                cur = cur -> next;
            }
            if (cur -> next == NULL) {
                cur -> next = pkmn;
            } 
        }
        (list -> size)++;
    }
}
void printPkmnList(PkmnList list) {
    // ADD YOUR CODE HERE
    Pkmn cur = NULL;
    if (list != NULL) {
        if (list -> head != NULL) {
            int * res = sortListIds(list);
            int i;
            for (i = 0; i < list -> size; i++) {
                cur = fetchById(list, res[i]);
                printPkmnListName(cur, list-> cur);            
            }

            free(res);
        } else {
            printf("No Pokemon in list.\n");
        }
    }
} 

void nextPkmn(PkmnList list) {
    // ADD YOUR CODE HERE
    Pkmn cur = NULL;
    if (list != NULL) {
        cur = list -> head;
        while (cur != NULL && cur != list -> cur) {
            cur = cur -> next;
        }
        if (cur != NULL && cur -> next != NULL) {
            list -> cur = cur -> next;
        }
    }
}

void prevPkmn(PkmnList list) {
    // ADD YOUR CODE HERE
    Pkmn cur = NULL;
    if (list != NULL) {
        cur = list -> head;
        if (cur != list -> cur) {
            while (cur != NULL && cur -> next != NULL 
                    && cur -> next != list -> cur) {
                cur = cur -> next;
            }
            //            if (list -> size != 1) {}
            list -> cur = cur;
        }
    }
}

void jumpToPkmn(PkmnList list, int id) {
    // ADD YOUR CODE HERE
    Pkmn cur = NULL;
    if (list != NULL) {
        cur = fetchById(list, id);
        if (cur != NULL) {
            list -> cur = cur;
        }
    }
}

void removePkmn(PkmnList list) {
    // ADD YOUR CODE HERE
    if (list != NULL) {
        Pkmn remove = list -> cur;
        if (remove == list -> head) {
            nextPkmn(list);
            list -> head = remove -> next;
        } else if (remove -> next == NULL) {
            prevPkmn(list);
            list -> cur -> next = NULL;
        } else {
            prevPkmn(list);
            list -> cur -> next = remove -> next;
            nextPkmn(list);
        }
        free(remove);
        (list -> size)--;
    }
}

//Stage 3 Functions
//void findPkmn(int seed, int factor, int numberOfNewPkmn, PkmnList list) {
//   // ADD YOUR CODE HERE
//   srandom(seed);
//   if (numberOfNewPkmn > 0) {
//       Pkmn cur = NULL;
//       int numFound = 0;
//       while (numFound < numberOfNewPkmn) {
//           int num =(rand() % factor);
//           if (list != NULL && list -> head != NULL) {
//               cur = list -> head;
//               while (cur -> next != NULL && cur -> id != num) {
//                   cur = cur -> next;
//               }
//               if (cur -> id == num) {
//                   if (!(cur -> isFound)) {
//                       cur -> isFound = TRUE;
//                       (list -> numFound)++;
//                       numFound++;
//                   }
//               }
//           }
//       }
//   }
//}


//recursion findPkmn function 
void findPkmn (int seed, int factor, int numberOfNewPkmn, PkmnList list) {

    // ADD YOUR CODE HERE
    if (numberOfNewPkmn > 0) {
        Pkmn cur = NULL;
        int num = (rand () % factor);
        //printf ("%d\n", num);
        if (list != NULL && list -> head != NULL) {
            cur = list -> head;
            while (cur -> next != NULL && cur -> id != num) {
                cur = cur -> next;
            }
            if (cur -> id == num && !(cur -> isFound)) {
                    cur -> isFound = TRUE;
                    (list -> numFound)++;
                    findPkmn (seed, factor, numberOfNewPkmn - 1, list);
            } else {
                findPkmn (seed, factor, numberOfNewPkmn, list);
            }
        }
    } else if (numberOfNewPkmn == 0) {
        srandom (seed);
    }
}





int totalFound(PkmnList list) {
    // ADD YOUR CODE HERE
    int re = 0;
    if (list != NULL) {
        re = list -> numFound;
    }
    return re;
}

// Stage 4 Functions
void addEvolution(PkmnList list, int pkmnId, int evolutionId) {
    // ADD YOUR CODE HERE
    if (list != NULL) {
        Pkmn fetch = fetchById(list, pkmnId);
        if (fetch != NULL) {
            fetch -> nextGenId = evolutionId;
        }
    }
}

void showPkmnEvolutions(PkmnList list, int id) {
    Pkmn cur = NULL;
    if (list != NULL) {
        cur = fetchById(list, id);
    }
    if (cur != NULL) {
        printf("#%03d ", cur -> id);
        if (cur -> isFound) {
            printf("%s", cur -> name);
        } else {
            displayUnfoundName(cur -> name);
        }
        if (cur -> nextGenId != cur -> id) {
            printf(" --> ");
            showPkmnEvolutions(list, cur -> nextGenId);
        } else {
            putchar('\n');
        }
    } else {
        printf("#%03d ?????\n", id);
    }
}

void showEvolutions(PkmnList list) {
    // ADD YOUR CODE HERE
    Pkmn cur = NULL; 
    if (list != NULL && list -> cur != NULL) {
        cur = list -> cur;
        if (cur -> id != cur -> nextGenId) {
            showPkmnEvolutions(list, cur -> id);
        }
    }
}


// Stage 5 Functions
PkmnList getPkmnOfType(PkmnList list, int type) {
    // ADD YOUR CODE HERE
    PkmnList newlist = NULL;
    if (type < -1 || type > 18) {
        printf("Invalid type.");
    } else {
        if (list != NULL) {
            newlist = createPkmnList();
            if (list -> head != NULL) {
                Pkmn cur = list -> head;
                while (cur != NULL) {
                    if ((cur -> type1 == type) ||(cur -> type2 == type)) {
                        if (newlist != NULL) {
                            addPkmnToList(newlist, cpPkmn(cur));
                        }
                    }
                    cur = cur -> next;
                } 
            }
        }
    }
    return newlist;
}

PkmnList getFoundPkmn(PkmnList list) {
    // ADD YOUR CODE HERE
    PkmnList newlist = NULL;
    newlist = createPkmnList();
    if (list != NULL && newlist != NULL) {
        if (list -> head != NULL) {
            Pkmn cur = list -> head;
            while (cur != NULL) {
                if (cur -> isFound == TRUE) {
                    addPkmnToList(newlist, cpPkmn(cur));
                }
                cur = cur -> next;
            } 
        }
    }
    return newlist;
}

PkmnList searchByName(PkmnList list, char text[]) {
    // ADD YOUR CODE HERE
    PkmnList newlist = NULL;
    newlist = createPkmnList();
    if (list != NULL && newlist != NULL) {
        if (list -> head != NULL) {
            Pkmn cur = list -> head;
            while (cur != NULL) {
                if (nContainsT(cur -> name, text)) {
                    addPkmnToList(newlist, cpPkmn(cur));
                }
                cur = cur -> next;
            } 
        }
    }
    return newlist;
}

