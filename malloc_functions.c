#include "monty.h"
/**
 * _strcmp - function that compares two strings.
 * @s1: string 1
 * @s2: string 2
 * Return: zero if s1 and s2 are equal
 *
 */
int _strcmp(char *s1, char *s2)
{
	int c;

	for (c = 0; s1[c] == s2[c] && s1[c]; c++)
		;
	if (s1[c] > s2[c])
		return (1);
	if (s1[c] < s2[c])
		return (-1);
	return (0);
}

/**
 * _sch - funtion that search if a char in string
 * @s: string
 * @c: char
 * Return: 1 if true,0 if false
 */
int _sch(char *s, char c)
{
	int co= 0;

	while (s[co] != '\0')
	{
		if (s[co] == c)
		{
			break;
		}
		co++;
	}
	if (s[co] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - function that cut a string into delimiters
 * @s: string
 * @d: delimiters
 * Return: delimiters 
 */
char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int x = 0, j = 0;

	if (!s)
		s = ultimo;
	while (s[x] != '\0')
	{
		if (_sch(d, s[x]) == 0 && s[x + 1] == '\0')
		{
			ultimo = s + x + 1;
			*ultimo = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 0)
			x++;
		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 1)
		{
			ultimo = s + x + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[x]) == 1)
		{
			j++;
			x++;
		}
	}
	return (NULL);
}

