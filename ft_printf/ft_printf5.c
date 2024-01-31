#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>

void ft_putstr(const char *s , int *len)
{
	if(!s)
		s = "(null)";
	while(*s)
		*len += write(1, s++, 1);
}

void ft_putnum(long long int nbr, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if(nbr< 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}

	if(nbr >= base)
		ft_putnum(nbr/base, base, len);
	*len+= write(1, &hex[nbr%base],1);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int len  = 0;

	while(*format)
	{
		if((*format == '%') &&(*(format+1)== 's'|| *(format+1)== 'd' || *(format+1)== 'x'))
		{
			format++;
			if(*format == 's')
				ft_putstr(va_arg(ap, char *), &len);
			else if(*format == 'd')
				ft_putnum((long long int)va_arg(ap, int), 10, &len);
			else if(*format == 'x')
				ft_putnum((long long int)va_arg(ap, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;

	}
	return(va_end(ap), len);
}

int main(void)
{
	int a =ft_printf("%d %s %x\n", -250, "caglar", 22);
	printf("%d\n", a);
	int b =printf("%d %s %x\n", -250, "caglar", 22);
	printf("%d\n", b);
}