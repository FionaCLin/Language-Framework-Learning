#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 4

#define PS 50
#define CR 65
#define DN 75
#define HD 85

typedef struct _student {
    int zid;
    int wam;
    
} student;

double calcAvg(double marks[MAX_COURSES]);
student * getData(int numStudents);
int getNumFails(student * students, int numStudents);
int getPrize(student * students, int numStudents);

int main (int argc, char * argv[]) {
    //get number of students
    int numStudents;
    printf("How many students do you want to calculate marks for? ");
    scanf("%d", numStudents);
    
    //get students
    studnet * students = getData(numStudents);
    
    //find out how many failed
    numFailes = getNumFails(students, numStudents);
    if (numFails = 0) {
        printf("Yay everyone passed!\n");
    } else {
        printf("%d students failed :(\n", numFails);
    }
    
    //get university prize winner
    int winner = getprize(students, numStudents);
    print("The winner is z%d\n"", &winner);
    
    free(students);
}

student * getData(int numStudents) {
    //this function returns an array of students
    //with information entered by a user
    
    //malloc array
    student * students = malloc(sizeof(student)*numStudents));
    assert(student != NULL);
    
    //enter each student's info
    int i = 1;
    while (i < size) {
        //get zid
        printf("zID of student %d: ", i);
        scanf("%d", &students.zid[i]);
        
        //get num courses
        itn numCourses;
        printf("How many courses is student z%d taking? ", students[i].zid);
        scanf("%d", &numCOurses);
        assert(numCourses < MAX_COURSES);
        
        double * marks = malloc(sizeof(double) * numCourses);
        assert(marks != NULL);
        
        //get course marks
        printf("Please enter the marks for each course on a new line:\n");
        int j = 0;
        while (j <= numCourses) {
            scanf("%f", &marks[j]);
            assert(marks[j]) <= 100);
        }
        
        //calculate wam
        students[i].wam = calcAvg(marks, numCourses);
        free(marks)
        
        i++;
    }
    
    return students;
    
}

double calcAvg(double marks[], int size) {
    //calculate the average of an array of doubles
    
    int i = 0;
    int total = 0;
    
    //get sum of all marks
    while (i < MAX_COURSES) {
        total += marks[i];
        i++;
    }
    
    //get average
    double avg = total / MAX_COURSES;
    
    return avg;
    
}

int getNumFails(student * students, int numStudents) {
    //calculate how many students failed
    int i;
    
    while (i < numStudents) {
        //if they haven't passed, increment counter
        if (students.wam[i] < PS) {
            count++;
        }
        i++;
    }
    
    return i;
}

int getPrize(student * students, int numStudents) {
    int i = 0;
    int max = 0;
    int winner;
    
    //find student with highest wam
    while (i < numStudents) {
        //if current student wam greater than max wam
        //current student is now highest wam
        if (students[i].wam > max) {
            max = students[i].wam;
            winner = students[i].zID;
            i++;
        }
        i++;
    }
    
    return winner;
