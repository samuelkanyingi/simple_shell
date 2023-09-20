#include "listme.h"
/**
 * mycustom_strstr - find substring in a string
 * @hay_stack:string
 * @needle:substring
 * Return:pointer to beginning of found substring
 */
char *mycustom_strstr(const char *hay_stack, const char *needle)
{
	while (*hay_stack)
	{
		const char *hay = hay_stack;
		const char *need = needle;

		for (; *hay && *need && *hay == *need; hay++, need++)
		{
			hay++;
			need++;
		}
		if (*need == 0)
		{
			return ((char *)hay_stack);
		}
		hay_stack++;
	}
	return  (NULL);
}
