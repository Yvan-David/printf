#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int n;

	n = printf("%s\n", format);
	return (n);
}
