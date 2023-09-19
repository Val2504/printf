#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the format to be used to produce the output
 *
 * Return: the outputted format
 */
int _printf(const char *format, ...)
{
	int chara_tracker = 0;

	va_list list_of_args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list_of_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chara_tracker++;
		}

		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}

			else if (*format == '%')
			{
				write(1, format, 1);
				chara_tracker++;
			}

			else if (*format == 'c')
			{
				char c = va_arg(list_of_args, int);

				write(1, &c, 1);
				chara_tracker++;
			}

			else if (*format == 's')
			{
				char *str = va_arg(list_of_args, char*);
				int str_len = 0;

				while (str[str_len])
				{
					str_len++;
				}
				write(1, str, str_len);
				chara_tracker += str_len;
			}
		}
		format++;
	}

	va_end(list_of_args);

	return (chara_tracker);
}
