/*
 *  assign1.c
 *  Description: 
 *  a simplified scoring system for Yahtzee
 *  Tutorial class: T14A
 *  Tutor name: Curtis Millar
 *  Author: Fiona Lin
 *  Date:20 Aug 2016
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FALSE 0
#define TRUE  1  
#define BUFFERLEN   350 
#define THREEKIND   0 
#define FOURKIND    1
#define FULLHOUSE   2
#define XSTRAIGHT   3
#define STRAIGHT    4
#define YAHTZEE     5
#define CHANCE      6


int readLine( char * input );

int inValidRange( char ch , int min, int max ) ;
int isDigit( char ch );
int isSpace( char ch );

int correctFormat( char input[BUFFERLEN] ) ;
int isValid( char input[BUFFERLEN] ) ;
int totalDigit(  char input[BUFFERLEN]  );
int is5Num( char input[BUFFERLEN]  ) ;

int legalInput( char *input ) ;

int rollAll( char * in, int num [] ) ;

int rollSome( char *in, int num [] ) ;

int isValidDice( char in [] ) ;
int inputRerollDice( char * input ) ;
int readRerollDice( char in[], int position[] ) ;

int inputRerollValues( char *input, int numOfDice ) ;

int selectOpts() ;

int convertNumbers( char * input, int * num ) ; 
void printDiceValues( int num[] ) ;

void update( int num[], int position[], int value[], int numOfDice ) ;
void keepDice( int num [] );
void analyseInputScore(int num [], char * display [], int scores[]) ;


int main( int argc, char * argv[] ) {

    char input[BUFFERLEN]; 
    int num[BUFFERLEN];
    int choice = 2;
    int allowTimes = 0;
    int gameOn = TRUE;

    while (choice < 3 && choice && gameOn && allowTimes < 3) {

        allowTimes ++;

        if ( choice == 1 ) {

            gameOn = rollSome( input, num );
        }
        else if ( choice == 2 ) {

            gameOn = rollAll( input,  num );
        }
        if ( gameOn && allowTimes < 3 ) {

            choice = selectOpts();
        } else if ( gameOn && allowTimes == 3 ) {

            choice = 3;            
        }
    }
    if ( choice == 3 ) {

        keepDice( num );
    }
    return EXIT_SUCCESS;
}

int readLine( char * input ) {

    int isEmptyLine = FALSE ;
    if ( fgets( input, BUFFERLEN, stdin ) != NULL ) {

        isEmptyLine = TRUE;
    }
    return isEmptyLine;
}

int isDigit( char ch ) {
    return ( (ch - '0') >= 0  && (ch - '0') < 10 );
}

int isSpace( char ch ) {
    return ( ch == ' ' );
}

int inValidRange( char ch , int min, int max ) {

    int num = ch - '0';
    return ( num >= min && num <= max ) ;
}


int correctFormat( char * input ) {

    int correct = TRUE;
    int i = 0;
    char current;
    char previous;

    while ( input[i] != '\n' && correct ) {

        current = input[i] ;

        if ( !(isSpace( current ) || isDigit( current)) ){

            correct = FALSE;

        } else if ( i != 0 && isDigit( current )) {

            previous = input [i-1];

            if ( ! isSpace( previous ) ){

                correct = FALSE;
            }

        }
        i ++ ;
    }
    printf("\n");
    return correct;
}


int isValid( char in [] ) {

    int isValid = TRUE;
    int i = 0;
    char c = in[i] ;

    while ( c != '\n' && isValid ) {

        if ( !isSpace( c ) ) {

            if ( ! inValidRange( c, 1, 6 ) ) {

                isValid = FALSE;
            }
        }
        i ++;
        c = in [i];
    }
    return isValid;
}

int isValidDice( char in [] ) {

    int isValid = TRUE;
    int i = 0;
    char c = in[i] ;

    while ( c != '\n' && isValid ) {

        if ( !isSpace( c ) ) {

            if ( ! inValidRange( c, 1, 5 ) ) {

                isValid = FALSE;
            }
        }
        i ++;
        c = in [i];
    }
    return isValid;
}

int is5Num( char input[BUFFERLEN]  ) {

    int total = totalDigit( input );

    return  ( total == 5 );
}

int totalDigit(  char input[BUFFERLEN]  ) {

    int totalDigit = 0 ; 
    int i = 0 ;
    char c = input[i];

    while ( i < BUFFERLEN && c != '\n' ) {

        if ( isDigit( c ) ) {

            totalDigit ++;
        }
        i ++;
        c = input[i];
    }
    return totalDigit;
}

int convertNumbers( char in[], int num[] ) {

    int i = 0;
    int j = 0;
    char c = in[i] ;

    while ( c != '\n' ) {

        if ( ! isSpace( c )) { 

            num[j] = in[i] - '0';
            j ++;
        }
        i ++;
        c = in [i];
    }
    return j;
}

void printDiceValues( int num[] ) {

    int i;
    printf("Your dice values are:");

    for ( i = 0; i < 5 ; i ++ ) { 

        printf(" %d", num[i]);
    }
    printf("\n\n");
    return ;
}

int selectOpts() {

    float isNotInteger; 
    int i;
    int isNumber;
    float input;
    char in[BUFFERLEN]; 
    char * opts [] = {
        "Reroll some dice",
        "Reroll all dice",
        "Keep dice"
    };

    printf( "Please choose:\n" );
    for ( i = 0; i < 3; i++ ) {

        printf(" %d -> %s\n", i+1, opts[i]);
    }

    printf( ">" );

    if ( readLine( in ) ) { 

        isNumber = sscanf( in, "%f", &input );
    }

    isNotInteger = fmodf( input, 1); 

    if ( !isNumber || isNotInteger || !( input > 0 && input < 4 ) ) {

        printf("\nInvalid Choice.\n");
        input = 0 ;
    }

    return (int)input;
}

void keepDice( int num [] ) {

    float isNotInteger;
    char buffer[BUFFERLEN]; 
    int index ;
    int isNumber = 0;
    float input;
    int score = 0;
    int counter = -1;
    //refactor to inter pointer
    int points [7] = { 0 };
    int choices [7] = { 0 };
    char * opts [] = { "Three of a Kind", "Four of a Kind", "FullHouse",
        "Small Straight", "Straight" , "Yahtzee"  , "Chance" } ;

    printf( " \nYour score options are:\n" );

    analyseInputScore( num, opts, points ); 

    for ( index = 0; index < 7; index ++ ) {

        if ( points[index] != 0 ) {

            counter ++;
            printf(" %d -> %s (%d points)\n", counter+1, opts[index],
                    points[index]);
            choices[counter] = points[index];
        }
    }
    printf( "> " );

    if ( readLine( buffer ) ) { 

        isNumber = sscanf( buffer, "%f\n", &input );
    }

    isNotInteger = fmodf( input, 1);
/*
    if ( input == 22 ) {
        input = 2 ;
    }
*/
    if ( !isNumber || isNotInteger || input < 1 || input > ( counter + 1 ) ) {

        printf("\nInvalid Choice.\n");
        input = 0 ;
    } else {

        score = choices[(int)input-1];
        printf( "\nYour score is: %d points\n", score );
    }
    return ;
}

int legalInput( char *input ) {

    int pass = TRUE;

    if( readLine( input ) ) {

        if ( !correctFormat( input ) ) {

            printf("Incorrect Input Format.\n");
            pass = FALSE;

        } else if ( !isValid( input ) ) {

            printf("Value Out of Range.\n");
            pass = FALSE;
        }
    } 
    return pass;
}


int rollAll( char * input, int num [] ) {

    int pass = TRUE;

    printf ("\nPlease enter dice values:\n> ");
    pass = legalInput( input ); 

    if ( pass ) {

        if ( !is5Num( input ) ) {

            printf("Incorrect Number of Values.\n");
            pass = FALSE;

        } else {

            convertNumbers( input, num );
            printDiceValues( num );
        }
    }     
    return pass;
}

int inputRerollDice( char * input ){

    int pass = TRUE;

    printf (" \nPlease enter dice to reroll (1 - 5):\n> ");

    if( readLine( input ) ) {

        if ( !correctFormat( input ) ) {

            printf("\nIncorrect Input Format.\n");
            pass = FALSE;

        } else if ( !isValidDice( input ) ) {

            printf("Dice Number Out of Range.\n");
            pass = FALSE;
        }
    } 
    return pass;
}

int readRerollDice( char in[], int position[] ) {

    int p[6] = { 0 };
    int i = 0;
    int totalDice = 0;
    int numOfDigit = convertNumbers( in, position );

    while( i < numOfDigit ){

        if (position[i] != 0 ) {

            p[position[i]] ++;
        }
        i ++;
    }

    for ( i = 0; i < 6 ; i ++ ) {

        if ( p[i] != 0 ){

            *position = i;
            position ++;
            totalDice ++;
        }
    }
    return totalDice;
}


int inputRerollValues( char *input, int numOfDice ) {

    int pass = TRUE;

    if ( numOfDice == 1 ) {

        printf( "Please enter %d value:\n> ", numOfDice);

    } else {

        printf( "Please enter %d values:\n> ", numOfDice);
    }

    if ( legalInput( input ) ) {

        if( totalDigit( input ) != numOfDice ) {

            printf("Incorrect Number of Values.\n");
            pass = FALSE;
        }

    } else {

        pass = FALSE;
    }
    return pass;
}

int rollSome( char * input, int * num ) {

    int pass = FALSE;
    int numOfDice = 0;
    int positions[BUFFERLEN];

    if ( inputRerollDice( input ) ) {

        numOfDice = readRerollDice( input, positions );
        int replaceVal[numOfDice]; 

        if ( inputRerollValues( input, numOfDice )) {

            convertNumbers( input, replaceVal);
            update( num, positions, replaceVal, numOfDice );
            printDiceValues( num );
            pass = TRUE;
        }
    }
    return pass;
}

void update( int num[],  int position[], int value[], int numOfDice ) {

    int i;

    for ( i = 0; i < numOfDice; i ++ ) {

        num[position[i]-1] = value[i];
    }
}

void analyseInputScore(int num [], char * display [], int scores[]) {

    int f[7] = { 0 };
    int straight = 0;
    int sum = 0;
    int i, j, diff1, diff2;

    for ( i = 0; i < 5; i++ ) {

        for ( j = 1; j <= 6; j ++ ) {

            if ( num[i] == j ) {

                f[j] ++;
            }
        }
    }

    for ( i = 1; i <=6; i ++ ) {

        if ( f[i] == 5 ) {

            scores[YAHTZEE] = 50;
        } 

        if ( f[i] >= 4 ) { 

            scores[FOURKIND] = f[i] * i ;

            for ( j = 1; j <= 6; j ++ ){

                if ( f[j] == 1 ) {

                    scores[FOURKIND] += j ;
                }
            }
        }

        if ( f[i] >= 3 ) { 

            scores[THREEKIND] = f[i] * i ;

            for ( j = 1; j <= 6; j ++ ){

                if ( f[j] == 2 ) {

                    scores[FULLHOUSE] = 25;
                    scores[THREEKIND] += ( f[j] * j ) ;
                } 

                if ( f[j] == 1 ) {

                    scores[THREEKIND] += j ;
                }
            }
        }

        if ( f[i] == 1 ) { 

            diff2 = pow( f[i] - f[ i + 1 ], 2 );
            diff1 = pow( f[i] - f[ i - 1 ], 2 );

            if (diff1 == 0 && diff2 == 0 ) {

                straight++;
            }
            if ( straight >= 2 ) {

                scores[XSTRAIGHT] = 30;
            } 
            if ( straight >= 3 ) {

                scores[STRAIGHT] = 40;
                scores[XSTRAIGHT] = 30;
            } 
        }

        if ( f[i] == 2 ) {

            if( i !=1 && i !=6 ){

                diff1 = pow( f[i] - f[ i + 1 ], 2 );
                diff2 = pow( f[i] - f[ i - 1 ], 2 );

                if ( diff1 != 2 && diff2 != 2 ) {

                    straight++;
                }

                if ( straight == 2 ) {

                    scores[XSTRAIGHT] = 30;
                } 
            } else if ( i ==1 ) {

                diff1 = pow( f[i+2] - f[ i + 1 ], 2 );
                diff2 = pow( f[i+3] - f[ i +2 ], 2 );

                if (diff1 == 0 && diff2 == 0 ) {

                    straight++;
                }
            } else if ( i ==6 ) {

                diff1 = pow( f[4] - f[3], 2 );
                diff2 = pow( f[4] - f[5], 2 );

                if (diff1 == 0 && diff2 == 0 ) {

                    straight++;
                }

                if ( straight == 2 ) {

                    scores[XSTRAIGHT] = 30;
                }
            }           
        }
        sum += f[i] * i ;
    }
    scores[CHANCE] = sum;
}
