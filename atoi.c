#include "listme.h"
/**
 * custom_atoi -convert string to integer
 * @string:string to convert
 * Return:integer
 */
int custom_atoi(const char *string)
{
	int num_sign = 1;
	int res = 0;

	for (; *string == ' '; string++)
	{
		string++;
	}
	if (*string == '-')
	{
		num_sign  = -1;
	}
	else if (*string == '+')
	{
		string++;
	}
	for (; *string >= '0' && *string <= '9'; string++)
	{
		res = res * 10 + (*string - '0');
	}
	return (num_sign * res);
}
