/*
 *  tut6.c
 *  Description: 
 *  Write a program that uses struct _student with attributes int zid
 *  and double height. Create an array of these structs and populate
 *  each struct with infromation from standard input.
 *  Extend previous program to use function tallest_student that takes
 *  in an array of student structs and returns zid of the tallest
 *  student.
 *  Tutorial class: T14A
 *  Tutor name: Curtis Millar
 *  Author: Fiona Lin
 *  Date:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char * allocate_string(char * current);

int main(int argc, char *argv[]){

    char buffer[100];
    char *strings[100];
    int count = 0;

    while(fgets(buffer,100,stdin)!= NULL && count < 100){

        strings[count] = allocate_string(buffer);
        count++;
    }
    int i;
    for(i = 0; i < count; i++){
        printf("%s\n",strings[i]);
        free(strings[i]); 
    }   

    return EXIT_SUCCESS;
}


char * allocate_string(char *current){
    char * res = malloc(sizeof(char*));
    
    //I get some memory in the heap
    int i = 0;

    //put the current string in the heap
    while ( *current != '\0' && i < 100 ) {
        *res = *current;
        i++;
        res++;
        current++;
    }
    *res = '\0';
    res = res - i;
    //return the start pointer back
    return res;
}

