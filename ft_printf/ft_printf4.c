#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putstr(char *str, int *len)
{
	if(str == NULL)
		str = "(null)";
	while(*str)
		*len += write(1, str++, 1);
}

void	ft_putnbr(long long int nbr, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if(nbr < 0)
		{
			nbr *= -1;
			*len += write(1, "-", 1);
		}
	if(nbr >= base)
		ft_putnbr((nbr / base), base, len);
	*len += write(1, &hex[nbr % base], 1);
}


int ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int len = 0;

	while(*format)
	{
		if(*(format)== '%' && (*(format+1)== 's' || *(format+1)== 'd' || *(format+1)== 'x'))
		{
			format++;
			if(*format == 's')
				ft_putstr(va_arg(ap, char *), &len);
			else if(*format == 'd')
				ft_putnbr((long long int)va_arg(ap, int), 10, &len);
			else if(*format == 'x')
				ft_putnbr((long long int)va_arg(ap, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}

	return(va_end(ap), len);
}

// int main(void)
// {
// 	int a = ft_printf("%d, %s %x \n", 10, "caglar", 42);
// 	printf("return:%d \n", a);
// 	int b = printf("%d, %s %x \n", 10, "caglar", 42);
// 	printf("return%d \n", b);
// }