#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize(char *s);


int main( int argc, char * argv [] ) {
    char s[] = "crazyfortruffle";
    printf("original :%s\n", s);
    sanitize(s);
    printf("sanitize :%s\n", s);

    return EXIT_SUCCESS;
}

void sanitize(char *s) { 
    int index = 0;
    int dindex = 1;
    while ( s[index] != '\0' ) {
        char c = s[index];
        dindex = index+1;
        while ( s[dindex] != '\0' ) {
            if (c == s[dindex]) {
            //if (c == s[dindex] && index != dindex) {
                s[dindex] = '\0';
                dindex++;
                strcat(s, s+dindex);
            }else {
                dindex++;
            }
        }
        index ++;
    }


}
