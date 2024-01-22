#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void put_str(char *str, int *len)
{
	if(str == NULL)
		str = "(null)";
	while(*str)
		*len +=write(1, str++, 1);
}

void put_nbr(long long int nbr, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if(nbr < 0)
	{
		nbr *= -1;
		*len += write(1,"-", 1);
	}

	if(nbr>= base)
		put_nbr(nbr / base, base, len);

	*len += write(1, &hex[nbr % base], 1);
}

int ft_printf(const char *format, ...)
{
	int len = 0;
	va_list ap;
	va_start(ap, format);

	while(*format)
	{
		if(*format == '%' && (*(format+1)== 's' || *(format+1)== 'd' || *(format+1)== 'x' ))
			{
				format++;
				if(*format == 's')
					put_str(va_arg(ap, char *), &len);
				else if(*format == 'd')
					put_nbr((long long int)va_arg(ap, int), 10, &len);
				else if(*format == 'x')
					put_nbr((long long int)va_arg(ap, unsigned int), 16, &len);
			}
			else
				len +=write(1, format, 1);
			format++;
	}
	return(va_end(ap),len);
}

int main(void)
{
	int a =ft_printf("%d %s %x\n", -250, "caglar", 22);
	printf("%d\n", a);
	int b =printf("%d %s %x\n", -250, "caglar", 22);
	printf("%d\n", b);
}