char *ftt_strchr(char *str, int c)
{
	while(*str)
	{
		if(*str == (char)c)
			return((char *)str);
	}
	return(NULL);
}

char *ft_strchr(char *s, int c)
{
	while(*s)
	{
		if((*s== (char)c)
			return((char *)s);

	}
	return(NULL);
}

char *ft_strchr(char* str, int c)
{
	while(*str)
	{
		if(*s == (char)c)
			return((char *)s);
		s++;
	}
}