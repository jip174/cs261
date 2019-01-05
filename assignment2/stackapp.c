/* CS261- Assignment 2*/
/* Name: Justin Phillips
* Date: 7/8/2018
* Solution description:
*/
/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */	
	if (s == '\0') // check to see if it is empty
		return 1;

	DynArr *stack;
	stack = newDynArr(10); // intialize array 

	char next = nextChar(s);

	while (next != '\0')
	{
		if (next == 40 || next == 91 || next == 123)
		{
			pushDynArr(stack, next);
		}
		else if (next == 41 || next == 93 || next == 125)
		{
			if (isEmptyDynArr(stack))
			{
				return 0;
			}
			if (next == 41 && topDynArr(stack) != 40) //asc code for ), (
			{
				deleteDynArr(stack);
				return 0;
			}
			else if (next == 41 && topDynArr(stack) == 40)
			{
				popDynArr(stack);
			}
			if (next == 93 && topDynArr(stack) != 91) // asc code for ],[
			{
				deleteDynArr(stack);
				return 0;
			}
			else if (next == 93 && topDynArr(stack) == 91)
			{
				popDynArr(stack);
			}
			if (next == 125 && topDynArr(stack) != 123) // asc code for },{
			{
				deleteDynArr(stack);
				return 0;
			}
			else if (next == 125 && topDynArr(stack) == 123)
			{
				popDynArr(stack);
			}
		}
		next = nextChar(s);
	}
	if (isEmptyDynArr(stack))
	{
		deleteDynArr(stack);
			return 1;
	}
	else
	{
		deleteDynArr(stack);
			return 0;
	}

	
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

