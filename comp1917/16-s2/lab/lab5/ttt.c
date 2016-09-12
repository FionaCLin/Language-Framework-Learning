#include <stdio.h>

#define TRUE     1
#define FALSE    0

#define SIZE     3

#define NONE    -1
#define NOUGHTS  0
#define CROSSES  1
#define EMPTY    2

void  scanBoard( int board[SIZE][SIZE] );
void printBoard( int board[SIZE][SIZE] );
int   getWinner( int board[SIZE][SIZE] );

int main( void )
{
    int board[SIZE][SIZE];
    int winner = NONE;

    printf("Please enter the board:\n");
    scanBoard( board );

    printf("Here is the board:\n");
    printBoard( board );

    // INSERT CODE HERE

    winner =  getWinner( board );
    if ( winner == NOUGHTS ) {
        printf("\nNoughts Win\n");
    } else if ( winner == CROSSES ) {
        printf("\nCrosses Win\n");
    } else {
        printf("\nNo Winner\n");
    }
    return 0;
}

// INSERT CODE FOR  scanBoard()
void  scanBoard( int board[SIZE][SIZE] ) {
    int i;
    int j;
    for ( i = 0; i < SIZE ; i ++ ) {
        for ( j = 0; j < SIZE ;  ) {
            char c = getchar();
            if ( c != '\n' ){
                if ( c != ' ' ) {
                    board[i][j] = c - '0';
                    j ++;
                }
            }

        }
    }
}


// INSERT CODE FOR printBoard()
void printBoard( int board[SIZE][SIZE] ) {
    int i;
    int j;
    for ( i = 0; i < SIZE ; i ++ ) {
        for ( j = 0; j < SIZE ;  ) {
            int field = board[i][j];
            if ( field == NOUGHTS ) {
                putchar( 'O' );
            } else if ( field == CROSSES ) {
                putchar( 'X' );
            } else if ( field == EMPTY ) {
                putchar( '.' );
            }
            j ++;
            putchar( ' ' );
        }
        putchar( '\n' );
    }
}


// INSERT CODE FOR getWinner()


int getWinner( int board[SIZE][SIZE] ) {
    int win = NONE ;
    int i;
    int j;
    i = 1;
    //for this \ analog
    if ( board[i-1][i-1] == board[i][i] 
            && board[i][i] == board[i][i+1] ) {

        if ( board[i][i] == 0 ){
            win = NOUGHTS;
        } else if ( board[i][i] == 1 ) {
            win = CROSSES;
        }

            //for this / analog
    } else if ( board[i-1][i+1] == board[i][i] 
            && board[i][i] == board[i+1][i-1] ) {
       
       if (board[i][i] == 0 ){
            win = NOUGHTS;
        } else if ( board[i][i] == 1 ) {
            win = CROSSES;
        }

    } else {
        i = 1;
        j = 1;
            //h
            if ( board[i][j-1] == board[i][j] 
                    && board[i][j] == board[i][j+1] ) {
                if (board[i][i] == 0 ){
                    win = NOUGHTS;

                } else if ( board[i][i] == 1 ) {
                    win = CROSSES;
                }

            } else if ( board[j-1][i] == board[j][i] 
                    && board[j][i] == board[j+1][i] ) {
                //v
                if (board[i][i] == 0 ){
                    win = NOUGHTS;

                } else if ( board[i][i] == 1 ) {
                    win = CROSSES;
                }

            }
    }
    return win;
}
