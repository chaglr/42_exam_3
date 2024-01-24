#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void ft_putstr(const char *str, int *len)
{
	if(str == NULL)
		*str = "(null)";
	while(*str)
		*len += write(1, str++, 1);
}

void ft_putnbr(long long int nbr, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if(nbr < 0)
		{
			nbr *= -1;
			*len += write(1, "-", 1);
		}
	if(nbr >= base)
		ft_putnbr(nbr /base, base, len);
	*len += write(1, &hex[nbr % base], 1);
}

int ft_printf(const char *format, ...)
{
	va_list(ap);
	va_start(ap, format);

	if((*format == '%') && (*(format+1) == 's' || *(format+1) == 'd' || *(format+1) == 'x'))
	{
		format++;

	}
}