#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TRUE  1
#define FALSE 0


int isEqual(char * s, char * t) ;


int main(int argc, char * argv[]) {
    int i = 1;
    char * target = "truffle\n";
    char str[4];
    char buff[256];
    while (i <= 100) {
        char fileName[14] = "area";
        sprintf(str, "%d", i);
        strcat(fileName, str);
        FILE *file = fopen(fileName, "r");
        if (file != NULL) {
            int counter = 0;
            while (fgets(buff, 256, file)) {
                if (isEqual(buff, target)) {
                    counter ++;
                }
            }
            if (counter != t) {
                printf("%s%d\n"," area",i );
            }
        }
        i++;
    }


    return EXIT_SUCCESS;
}
int isEqual(char * s, char * t) {
    int isEqual, i;
    if (strlen(s) == strlen(t)) {
        isEqual = TRUE;
        i = 0;
        while (s[i] != '\0') {
            if (s[i] != t[i]) {
                isEqual = FALSE;
            }
            i++;
        }
    } else {
        isEqual = FALSE;
    }
    return isEqual;
}
