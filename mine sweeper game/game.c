#include <stdlib.h>
#include <string.h>
#include <stdio.h>
const char BOOM = 'b';
const char symbols[]={'*','1','2','3','4','5','6','7','8','+','|','-','f',BOOM};

int height=0, width=0; //width==>column=x height==>row==y
int flags=10;
char input;
char *errorMessage;
char *gridPtr;
char *printedGridPtr;

void initialiseGrid(char grid[height][width]);
void printGrid();
int checkInput(char currentStep,int column ,int row);
int isValidCoordinate(int x, int y);
int countBooms(int x, int y);
char getCell(int column, int row, char *gridPointer);
void updateCell(int column,int row,char update);
void flagCell(int column, int row);
void unflagCell(int column, int row);
int uncoverCell(int column, int row);

int main(int argc,char** argv){
// scan for g height and width instruction,
// instruction start without g or height and
// width is not [0,100] also width*height>10
// invalid instruction and game terminate
	scanf(" %c %d %d",&input,&width,&height);
	printf("%c %d %d\n",input,width,height);
	int error= checkInput('g',width,height);
	if(error>0){
		printf("%s",errorMessage);
	}else{
//initialise 2 grid with given width and height
//1 for display and the other for record the booms.
		char grid[height][width];
		gridPtr=&grid;
		initialiseGrid(grid);
		char printedGrid[height][width];
		initialiseGrid(printedGrid);
		printedGridPtr=&printedGrid[0][0];

// scan for 10 b row column instructions
		int column=-1, row=-1;
		for(int i =0;i<10;i++){
			scanf(" %c %d %d",&input,&column,&row);
			printf("%c %d %d\n",input,column,row );
			// instruction start without b or row and
			// column is not [0,height-1],[0,width-1]
			// also not allow place booms in the same cell.
			// invalid instruction and game terminate
			int error= checkInput('b',column,row);
			if(error>0){
				printf("%s",errorMessage);
				return 0;
			}else{
				/*2 record the booms co-ordinates*/
				grid[row][column] = symbols[13];
			}
		}
		if(errorMessage=='\0'){
			printGrid(printedGrid);
		}

		for(int i = 1; i<=width*height;i++){
			int result=-2;
			int column=-1, row=-1;
			scanf(" %c %d %d",&input,&column,&row);
			printf("%c %d %d\n",input,column,row );
			int error=checkInput('u',column,row);
			if(error>0){
				printf("%s",errorMessage);
				break;
			}else{
				if (input == 'f'){
					flagCell(column, row);
				}
				if (input == 'F'){
					unflagCell(column, row);
				}
				if (input == 'u'){
					result= uncoverCell(column, row);
					if (result ==-1){
						printf("%s \n", "Lost");
						break;
					}
				}
			}
			if(result!=-1){
				printGrid();
			}
			if(i==width*height){
				printf("%s\n","won");
			}
		}
	}
	return 0;
}
/**
 * Check if the given coordinates are inside the grid of cells.
 *
 * @param x - the x coordinate (column) of the cell
 * @param y - the y coordinate (row) of the cell
 * @return true if the given coordinates are inside the grid of cells; false
 *         otherwise.
 */
int isValidCoordinate(int x, int y){
	return (x<width && x>=0 && y<height && y>=0);
}
/**
* initialising the original state for a Grid. Populates '*' to the give grid.
* @param grid[][] - two dimensional char array
*/
void initialiseGrid(char grid[height][width]){
 	for(int i=0;i<height;i++){
 		for(int j=0;j<width;j++){
			grid[i][j]=symbols[0];
 	   }
  	}
}


/*3.input checking--pass the current step and the new input column and row to
the function to check if it valid
checks globle input char is valid to currents tep also validate the
column and row are within the range according to the current step*/
int checkInput(char currentStep,int column ,int row){
	int count=0;
	//check input is valid for current step
	if(currentStep=='g'){
		if(input!=currentStep){
			errorMessage="Invalid operation,you should enter g.\n";
			count++;
		}
		else if(column<0 ||column >101){
			errorMessage="Width must be between 0 to 100.\n";
			count++;
		}
		else if(row<0 ||row >101){
			errorMessage="Column must be between 0 to 100.\n";
			count++;
		}
		else if(row*column<10){
			errorMessage="Grid must have at least 10 cells.\n";
			count++;
		}
	}else{
		int result= isValidCoordinate(column,row);
		if(result==0){
			errorMessage="Coordinate is outside of the grid.\n";
				count++;
		}
		if(currentStep=='b'){
			if(input!=currentStep){
				errorMessage="Invalid operation,you should enter b.\n";
				count++;
			}
			char retriveCell = getCell(column, row, gridPtr);
			if(retriveCell=='b'){
				errorMessage="Target cell has engaged.\n.";
				count++;
			}
		}else if(currentStep=='u'){
			if(!(input=='f'&& input==currentStep && input == 'F')){
				errorMessage="Invalid operation,you should enter u or f.\n";
				count++;
			}else if(input=='f'){
				if(flags==0){
					errorMessage="You run out of flags\n.";
					count++;
				}
			}
			char retriveCell = getCell(column, row, printedGridPtr);
			if(retriveCell!='*'){
				errorMessage="Target cell has engaged.\n.";
				count++;
			}

		}

	}
	return count;
}
/*4.get content of the cell*/
char getCell(int column, int row, char *gridPointer){
	char *original;
	original = gridPointer; // maybe we can convert to array name pointer.
	int element=(row*width)+column;
	char result = *(gridPointer+element);
	gridPointer = original;
	return result;
}
/*5.update content of the cell*/
void updateCell(int column,int row, char update){
	char *original;
	original = printedGridPtr;
	int element=(row*width)+column;
	*(printedGridPtr+element) = update;
	printedGridPtr = original;
}

/**
 * Count the number of booms in the 8 cells surrounding the
 * given coordinates.
 * @param x - the x coordinate (column) of the cell
 * @param y - the y coordinate (row) of the cell
 * @return the number of booms of the cell at the given
 *         coordinates; or 0 if the coordinates are invalid.
 */
int countBooms(int x, int y){
	int numOfBooms=0;
	for(int i=y-1;i<y+2;i++){
		for(int j=x-1;j<x+2;j++){
			if(!(j==y && i==x)){
			//if(i!=y || j!=x){
				if(isValidCoordinate(j,i)){
					if(getCell(i,j,gridPtr)=='b'){
						numOfBooms++;
					}
				}
			}
		}
	}
	return numOfBooms;
}

int uncoverCell(int column,int row){
	char targetCell = getCell(column, row, gridPtr);
	if (targetCell == 'b'){
		return -1;
	}
	else{
		int booms = countBooms(column, row);
		updateCell(column, row, symbols[booms]);
		return booms;
	}
}

void flagCell(int column,int row){
	updateCell(column,row,symbols[12]);
	flags--;
}
void unflagCell(int column,int row){
        updateCell(column,row,symbols[0]);
        flags++;
}
void printGrid(){
	for(int i=0;i<height+2;i++){
		for(int j=0;j<width+2;j++){
			if(i==0||i==height+1){
				if(j==0||j==width+1){
					putchar(symbols[9]);
				}else{
 					putchar(symbols[11]);
 				}
 		   }else{
 			   if(j==0||j==width+1){
				   putchar(symbols[10]);
 			   }else{
				   putchar(getCell(j-1,i-1, printedGridPtr));
 			   }
 		   }
		}
		putchar('\n');
	 }
}
