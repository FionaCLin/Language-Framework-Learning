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
//this 3 charactor string become an nasty bugger which it is not enough
//space for number 100 to convert to a 3 charactors string
    //char str[3];
    char str[4];
    char buff[256];
    while (i <= 100) {
        char fileName[14] = "forest/area";
        sprintf(str, "%d", i);
        strcat(fileName, str);
//        printf("%s\t", fileName);
        FILE *file = fopen(fileName, "r");
        if (file != NULL) {
            int counter = 0;
            while (fgets(buff, 256, file)) {
                if (isEqual(buff, target)) {
                    counter ++;
                }
            }
            if (counter != 0) {
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
