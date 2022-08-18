#include <stdarg.h>
#include <stddef.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int count = 0;
	int i;

	va_list data;
	va_start(data, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
		}
		else if (format[i] == '%' && format[i + 1] != ' ')
		{
			switch(format[i + 1])
			{
				case 'c':
					count += _putchar(va_arg(data, int));
					break;
				case 's':
					if ((va_arg(data, char *)) == NULL)
							print_string("(null)");
					count += print_string(va_arg(data, char *));
					break;
				case '%':
					count += _putchar(format[i]);
					break;
			}
			i = i + 1;
		}
	}
	return (count);
}
