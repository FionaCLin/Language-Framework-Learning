#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize(char *s);

char * twentify(char s[]);

int main( int argc, char * argv [] ) {
    char s[] = "crazy for truffle";
    printf("original :%s\n", s);
    twentify(s);
    printf("twentify :%s\n", s);

    return EXIT_SUCCESS;
}


char * twentify(char s[]) {
    int i = 0;
    int j = 0;
    //make a copy of original string
    char * copy = strdup(s);
    // go through the copy string 
    while(copy[i] != '\0') {
        //find space
        if (isspace(copy[i])) {
            //make a new index for result string
            int k = i;
            //replace space with %
            s[k + j] = '%';
            //increment the shift index counter 
            j++;
            //insert 2 after %
            s[k + j] = '2';
            //increment the shift index counter 
            j++;
            //insert 0 after 2
            s[k + j] = '0';
            //increment result string index counter to get the charactor after space
            k++;
            while ( copy[k] != '\0') {
                //copy the rest of string to result string
                s[k + j] = copy[k];
                k++;
            }
            // put null character at the end.
            s[k+j]= '\0';
        }
        //continue move along the copy
        i++;
    }

    return s;
}
