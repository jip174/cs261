/* CS261- Assignment 1 - Q. 0*/
/* Name: Justin Phillips
 * Date: 6/27/2018
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){
  
     /*Print the value and address of the integer pointed to by iptr*/
    printf(" Value of ptr: %d. Address of the int pointed to %p\n", *iptr, &iptr);
          
     /*Increment the value of the integer pointed to by iptr by 5*/
    (*iptr) += 5;
          
     /*Print the address of iptr itself*/
    printf("Address of the ptr: %p\n", &iptr);
}


void fooB(int* iptr) {

    /*Print the value and address of the integer pointed to by jptr*/
    printf("Value of ptr: %d\n", *iptr);

    /*Decrement jptr by 1*/
    (*iptr)--;

    /*Print the address of jptr itself*/
    printf("Address of the ptr: %p\n", &iptr);
}


int main(){
    srand(time(NULL));
    /*Declare an integer x and initialize it randomly to a value in [0,10] */
    int x;
    x = rand() % 10 + 1;
    
    /*Print the value and address of x*/
    printf("Address of x: %p\n", &x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*Print the value of x*/
    printf("Value of x: %d\n", x);
    
    /*Call fooB() with the address of x*/
    fooB(&x);
    
    /*Print the value and address of x*/
    printf("Value of x: %d\n", x);
 
	//are the value	and	address	of x different than	the	value and address
	//that were	printed	before the call	to fooB(..)? Why or	why	not?
   
	// yes the value is different but the address is the same as fooa but different from the starting
	// address
    return 0;
}


