#include "listme.h"
/**
 * custom_strlen- function to get length of string
 * @string: string to get length
 * Return:length of string
 */
size_t custom_mystrlen(const char *string)
{
	size_t len;

	len = 0;

	for (; string[len] != '\0'; len++)
	{

	}
	return (len);
}
/**
 * custom_strcmp - function that compares two strings
 * @string1: first string
 * @string2:second string
 * Return: intger as outcome of comparison
 */
int custom_strcompare(const char *string1, const char *string2)
{
	while (*string1 != '\0' &&  *string2 != '\0')
	{
		if (*string1 < *string2)
		{
			return (-1);
		}
		else if (*string1 > *string2)
		{
			return (1);
		}
		string1++;
		string2++;
	}
	if (*string1 == '\0' && *string2 == '\0')
	{
		return (0);
	}
	else if (*string1 != '\0')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}
