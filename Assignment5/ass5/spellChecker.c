#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
	char *word;

	while (!feof(file))
	{
		word = nextWord(file);
		if (word)
		{
			hashMapPut(map, word, 1);
		}
	}
	free(word);
}
//levenshteinDist This function calculates the levenshtein distance between strings and returns
//the value.
//https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
int levenshteinDist(char *s1, char *s2) {
	unsigned int x, y, s1len, s2len;
	s1len = strlen(s1);
	s2len = strlen(s2);
	unsigned int matrix[s2len + 1][s1len + 1];
	matrix[0][0] = 0;
	for (x = 1; x <= s2len; x++)
		matrix[x][0] = matrix[x - 1][0] + 1;
	for (y = 1; y <= s1len; y++)
		matrix[0][y] = matrix[0][y - 1] + 1;
	for (x = 1; x <= s2len; x++)
		for (y = 1; y <= s1len; y++)
			matrix[x][y] = MIN3(matrix[x - 1][y] + 1, matrix[x][y - 1] + 1, matrix[x - 1][y - 1] + (s1[y - 1] == s2[x - 1] ? 0 : 1));
	return (matrix[s2len][s1len]);
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
	// FIXME: implement
	HashMap* map = hashMapNew(1000);

	FILE* file = fopen("dictionary.txt", "r");
	clock_t timer = clock();
	loadDictionary(file, map);
	timer = clock() - timer;
	printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
	fclose(file);

	char inputBuffer[256];
	int quit = 0;
	while (!quit)
	{
		printf("Enter a word or \"quit\" to quit: ");
		scanf("%s", inputBuffer);

		// Implement the spell checker code here..
		

		int distance;
		char *input = &inputBuffer[0];
		int minDist = 1000;
		for (int i = 0; i < map->capacity; i++)
		{
			HashLink * temp = map->table[i];
			if (temp != 0)
			{
				while (temp != 0)
				{
					distance = levenshteinDist(input, temp->key);
					hashMapPut(map, temp->key, distance);
					if (distance < minDist)
					{
						minDist = distance;
					}
					temp = temp->next;
				}
			}
		}

		if (hashMapContainsKey(map, inputBuffer))
		{
			printf("%s correct spelling \n", inputBuffer);
		}
		else
		{
			int j = 0;
			while (j < 5)
			{
				for (int i = 0; i < map->capacity; i++)
				{
					HashLink *current = map->table[i];
					if (current != 0)
					{
						while (current != 0)
						{
							if (current->value == minDist)
							{
								printf("Did you mean? %s \n", current->key);
								j++;
							}
							current = current->next;
							if (j == 5)
							{
								current = 0;
								i = map->capacity;
								break;
							}
						}
					}
				}
				minDist++;
			}
		}
		if (strcmp(inputBuffer, "quit") == 0)
		{
			quit = 1;
		}

	}
	hashMapDelete(map);
	return 0;
}





	