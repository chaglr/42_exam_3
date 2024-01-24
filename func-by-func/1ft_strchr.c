char *ftt_strchr(char *str, int c)
{
	while(*str)
	{
		if(*str == (char)c)
			return((char *)str);
	}
	return(NULL);
}