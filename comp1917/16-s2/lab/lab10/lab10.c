#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#define FALSE 0;
#define TRUE  1;


int non_decreasing(int a[], int N);
char * insert_string(char s[], char t[], int k);
char * del_string(char s[], int lo, int hi);
int is_anagram(char s[], char t[]);
void printArray(int a[], int N);


int main(void) {
    int a [] = {1,2,3,4,5};
    int b [] = {5,4,3,2,1};
    int c [] = {3,5,4,2,1};
    printArray(a, 5);
    if (non_decreasing(a, 5)) {
        printf("not ");
    } 
    printf("decreasing\n");
     
    printArray(b, 5);
    if (non_decreasing(b, 5)) {
        printf("not ");
    } 
    printf("decreasing\n");
    printArray(c, 5);
    if (non_decreasing(c, 5)) {
        printf("not ");
    } 
    printf("decreasing\n");
    char * name1 = "Fiona";
    char * name2 = "Lin";
    char * name = insert_string(name1, name2, 5);
    printf("name(name1+name2)->%s\n", name);
    name = insert_string(name1, name2, -1);
    printf("name(name2+name1)->%s\n", name);
    char * n = insert_string(name1, name2, 2);
    printf("name(name2->name1)->%s\n", name);
    printf("%s and %s ", name, n);
    if (!is_anagram(name, n)) {
        printf("not ");
    }    
    printf("is anagram.\n");
    printf("%s and %s ", name, name1);
    if (!is_anagram(name, name1)) {
        printf("not ");
    }    
    printf("is anagram.\n");


    return 0;
}
void printArray(int a[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d", a[i]);
        if (i < N-1) {
            putchar(',');
        }
    }
    putchar('\n');
}
int non_decreasing(int a[], int N) {
    int nonDec = TRUE;
    int i;
    for (i = 1; i < N && nonDec ; i++) {
        if (a[i-1] > a[i]) {
            nonDec = FALSE;
        }
    }
    return nonDec;
}
char * insert_string(char s[], char t[], int k) {
    int lens = strlen(s);
    int lent = strlen(t);
    int len = lent + lens;
    char *r = malloc(sizeof(char)*len);
    int i, j;
    if (k < 0) {
        for (i = 0; i < lent; i++) {
            r[i] = t[i];
        }
        j = 0;
        for ( ; i < len; i++) {
            r[i] = s[j];
            j++;
        }
        
    } else if (k >= lens) {
        for (i = 0; i < lens; i++) {
            r[i] = s[i];
        }
        j = 0;
        for ( ; i < len; i++) {
            r[i] = t[j];
            j++;
        }
    } else {
        for (i = 0; i < k; i++) {
            r[i] = s[i];
        }
        j = 0; 
        for ( ; i < k + lent ; i++ ) {
            r[i] = t[j];
            j++;
        }
        for ( ; i < len; i++ ) {
            r[i] = s[k];
            k++;
        }  
    }
    return r;
}
char * del_string(char s[], int lo, int hi) {
    int len = strlen(s);
    int i;
    if (lo < len && hi < len && lo >= 0 && hi >= 0) {
        if (lo < hi) {
            for (i = lo; i <= hi; i++) {
                s[i] = s[i+(hi-lo+1)];
            }
            s[len-(hi-lo)] = '\0';    
        }
    }
    return s;

}
int is_anagram(char s[], char t[]) {
    int isAnagram = TRUE;
    int lens = strlen(s);
    int lent = strlen(t);
    int fs[26] = { 0 };
    int ft[26] = { 0 };
    int i;
    int c;
    for (i = 0; i < lens; i++) {
        if (isalpha(s[i])) {
            if (isupper(s[i])) {
                c = toupper(s[i]) - 'A';
                fs[c]++;    
            }
        }
    }
    for (i = 0; i < lent; i++) {
        if (isalpha(t[i])) {
            if (isupper(t[i])) {
                c = toupper(t[i]) - 'A';
                ft[c]++;    
            }
        }
    }
    for (i = 0; i < 26; i++) {
        if (fs[i] != ft[i]) {
            isAnagram = FALSE;
        }
    }
    return isAnagram;
}


