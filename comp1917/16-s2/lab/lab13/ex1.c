#include <stdio.h>
#include <stdlib.h>


void shift_right(int* array, int n);
void printArray(int * array, int n) ;


int main( int argc, char * argv [] ) {
    int arr[] = { 1, 2, 3, 4, 5 };    
    printArray( arr, 5);
    shift_right( arr, 5);
    printArray( arr, 5);
    shift_right( arr, 5);
    printArray( arr, 5);
    shift_right( arr, 5);
    printArray( arr, 5);
    shift_right( arr, 5);
    printArray( arr, 5);
    shift_right( arr, 5);
    printArray( arr, 5);

    return EXIT_SUCCESS;
}

void shift_right(int* array, int n) {
    int i;
    int temp = array[n-1];
    for ( i = n - 1; i > 0; i--) {
        array[i] = array[i - 1]; 
    }

    array[0] = temp;
}
void printArray(int * array, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    putchar('\n'); 
}
