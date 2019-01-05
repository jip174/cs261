/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *students= malloc(10*sizeof(struct student));
     /*Return the pointer*/
             return students;
}

void generate(struct student* students){
     /*Generate random and unique IDs and random scores for ten students, 
IDs being between 1 and 10, scores between 0 and 100*/
     for( int i =0; i < 10 ; i++)
    {
        int studId = rand() %10 +1;
        for (int j =0; j < 10 ; j++)
        {
            if (students[j].id == studId)
            {
                studId = rand() % 10 +1;
                j--;
            }
        }
        students[i].id = studId;
        int studScore = rand () % 100 +1;
        students[i].score = studScore;
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
     for (int i = 0 ; i < 10 ; i++)
     {
         printf(" Student Id: %d Student Score: %d\n", students[i].id, students[i].score);
     }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int total=0;
     int min = students[0].score;
     int max = 0;
     double ave;

     for ( int i =0; i < 10 ; i++)
     {
         total = total + students[i].score;
         if(students[i].score < min)
         {
             min = students[i].score;
         }
         if(students[i].score > max)
         {
             max = students[i].score;
         }
     }
     ave = total/10;
     printf("Min: %d", min);
     printf("Max: %d", max);
     printf(" Average: %.2f", ave);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
             free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*Call allocate*/
            stud= allocate();
    
    /*Call generate*/
    generate(stud);
    /*Call output*/
    output(stud);
    /*Call summary*/
    summary(stud);
    /*Call deallocate*/
    deallocate(stud);
    return 0;
}

