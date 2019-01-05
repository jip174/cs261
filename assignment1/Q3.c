/* CS261- Assignment 1 - Q.3*/
/* Name: Justin Phillips
* Date: 6/27/2018
* Solution description: conert lowers char to uppers and vise versa, converts a string to camel back
*/

#include <stdio.h>
#include <stdlib.h>



char toUpperCase(char ch) {
	/*Convert ch to upper case, assuming it is in lower case currently*/
	return ch - 'a' + 'A';
}

char toLowerCase(char ch) {
	/*Convert ch to lower case, assuming it is in upper case currently*/
	return ch - 'A' + 'a';
}

int stringLength(char s[]) {
	/*Return the length of the string*/

	int a = 0;

	while (s[a] != '\0')
	{
		a++;
	}
	//printf("Length: %d\n", i);
	return a;
	//length = stringLength(a);
	//printf("Length of string: %d\n", a);

}


void camelCase(char* word) {
	/*Convert to camelCase*/
	int length;
	//int i;
	int result = 0;
	int capNext = 1;
	length = stringLength(word);
	char ch[100];

	for (int i = 0; word[i] != '\0'; i++)
	{
		if (word[i] != ' ')
		{
			if (capNext)
			{
				ch[result] = toUpperCase(word[i]);
				capNext = 0;
			}
			else
			{
				ch[result] = word[i];
			}
			result++;
		}
		else
		{
			capNext = 1;

		}
	}
	printf("Results: %s\n", ch);
	ch[result] = '\0';

	for ( int i =0; i < length ; i++)
    {
        word[i]= ch[i];
    }
	/* do
	{
	if ( i == 2 || word[i] == ' ' && word[i+1] > 97)
	{
	word[i+1] = toUpperCase(word[i]);

	}
	else if ( word[i] < 97 && word[i] != ' ')
	{
	word[i] = toLowerCase(word[i]);

	}
	i++;
	}while (i != length);*/

	/*for (int i = 0; i < length; i++ )
	{
	if ( word[i] == '\0')
	{
	break;
	}
	else if ( word[i] == ' ')
	{
	//i++;
	if ( word[i+1] <= 122 && word[i] >= 97)
	{
	word[i] = toUpperCase(word[i]);
	}
	else if ( word[i+1] <= 90 && word[i] >=65)
	{
	word[i] = toLowerCase(word[i]);
	}
	}
	else
	{
	i++;
	}
	}*/





}

int main() {

	char word[100];
	/*Read the string from the keyboard*/
	printf("Enter a string: ");
	//gets(word);
	scanf("%[^\n]%*c", word);
	//printf("%s", word);


	/*Call camelCase*/
	camelCase(word);


	/*Print the new string*/
	printf("New String: %s\n", word);

	return 0;
}