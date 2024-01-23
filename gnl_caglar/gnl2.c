#include "get_next_line.h"
//returns the adress of finding char
char *ft_charfinder(char *str, int c)
{
	while(*str)
	{
		if(*str = (char)c)
			return((char *)str);
	}
	//eger str yoksa
	return (NULL);
}

size_t ft_strlen(const char *s)
{
	size_t i = 0;
	while(s[i])
		i++;
	return(i);
}

size_t ft_strlcpy(char * dst, char *src, size_t dst_size)
{
	//first find the src_size
	size_t size_src = ft_strlen(src);
	int i = 0;
	if(dst_size > 0)
	{
		while(i < dst_size-1 && i < src_size)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
}



//src kopyasini yarat
char	*strdup(const char *src)
{
	char *copy;
	size_t src_len = ft_strlen(src) +1;

	copy =malloc(src_len);
	if(copy == NULL)
		return(NULL);
	ft_strlcpy(copy, src, src_len);
	return(copy);

}

char *strdup(const char *src)
{
	size_t src_len = ft_strlen(src)+1;
	char *copy = malloc(src_len);
	if(copy == NULL)
		return (NULL);
	ft_strlcpy(copy, src, src_len);
	return(copy);
}

char *strdup(const char * src)
{
	size_t src_len = ft_strlen(src) +1;
	char *copy = (char *)malloc(src_len);
	if(copy == NULL)
		return(NULL);
	ft_strlcpy(copy, src, src_len);

	return(len);
}

char *strdup(const char *str)
{
	size_t len = ft_strlen(src) +1;
	char * copy = (char *)malloc(src);
	if(copy == NULL)
		return ( NULL);
	ft_strcpy(copy, str, str_len);
	return(copy);
}


char *str_join(char s1, ci)