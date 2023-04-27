#include "main.h"

/**
* _strcat - function that concatenates two strings.
* @s1: first string
* @s2: secod string
*
*Return:NULL in case of failure but pointer to new string incase of success
*/

char *_strcat(char *s1, char *s2)
{
	char *concat_str;
	int index, concat_index = 0, len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	/*finding length*/
	for (index = 0; s1[index]; index++)
		len1++;
	for (index = 0; s2[index]; index++)
		len2++;

	concat_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat_str == NULL)
		return (NULL);

	/*concatinating*/
	for (index = 0; s1[index]; index++)
		concat_str[concat_index++] = s1[index];

	for (index = 0; s2[index]; index++)
		concat_str[concat_index++] = s2[index];
	concat_str[concat_index] = '\0';

	return (concat_str);
}

