/* CS261- Assignment 1 - Q.2*/
/* Name: Justin Phillips
 * Date: 6/27/2018
 * Solution description: swap variables after initially randomizing them
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int *c){
    /*Swap the addresses stored in the pointer variables a and b*/
   int temp = *a;
   *a = *b;
   *b = temp;
    /*Decrement the value of integer variable c*/
    (*c) =(*c)-1;
    
    /*Return c*/
            return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    srand(time(NULL));
    int x = rand() % 10+1;
    int y = rand() % 10+1;
    int z = rand() % 10+1;
    /*Print the values of x, y and z*/
    printf("X: %d\n", x);
    printf("Y: %d\n", y);
    printf("Z: %d\n", z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int returnFoo = foo(&x,&y,&z);
    
    /*Print the values of x, y and z*/
    printf("X: %d\n", x);
    printf("Y: %d\n", y);
    printf("Z: %d\n", z);
    
    /*Print the value returned by foo*/
    printf("Values returned by foo: %d\n", returnFoo );
    
    return 0;
}
//Is the return value different than the value of integer z? why or why not?

// Yes the return value is different than the value of z because only is copy 
//changed in foo not the real thing
    


