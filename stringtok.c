#include "main.h"

/**
  * str_tok - function to tokenize a string.
  * @str: string to tokenize.
  * @delim: pointer to our delimiters.
  *
  * Return: return pointer to tokenized string;
  */

char *str_tok(char *str, const char *delim)
{
	char *token, *word;
	int n, i, j = 0, word_indx = 0;

	if (str == NULL)
		return (NULL);
	n = _strlen(str);
	token = malloc(sizeof(char *) * n);
	if (token == NULL)
		return (NULL);
	word = malloc(sizeof(char) * (n + 1));
	if (word == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (_strchr(delim, str[i]))
		{
			word[word_indx++] = '\0';
			token[j++] = *word;
			word = malloc(sizeof(char) * (n + 1));
			if (word == NULL)
			{
				free(token);
				return (NULL);
			}
			word_indx = 0;
		}
		else
		{
			word[word_indx++] = str[i];
		}
	}
	word[word_indx++] = '\0';
	token[j] = '\0';
	free(word);
	return (token);
}
