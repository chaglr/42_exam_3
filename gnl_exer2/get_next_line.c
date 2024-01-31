#include"get_next_line.h"

size_t ft_strlen(char * s)
{
	size_t i = 0;
	while(s[i]
	{
		i++;
	})
	return(i);
}

char *ft_strchr(char *str, int c)
{
	while(*s)
	{
		if(*str == (char)c)
			return((char *)str);
		s++;
	}
	return(NULL);
}

size_t ft_strlcpy(char *dst, const char *src, size_t len_dst)
{
	size_t len_src =ft_strlen(src);
	size_t i = 0;
	if(len_dst > 0)//
	{
		while(i < len_src && i < len_dst-1)
		{
			dst[i] = src[i];
			i++
		}
		dst[i] = '\0';
	}

	return(len_src);
}

char *strjoin(char *s1, const char *s2, size_t s2_len)
{
	if(!s1 || !s2)
		return(NULL);

	s1_len = ft_strlen(s1);
	char *join;
	join = (char *)malloc(sizeof(char)* s2_len+s1_len+1);
	if(join == NULL)
		return(NULL);
	ft_strlcpy(join, s1, s1_len+1);
	ft_strlcpy(join+s1_len, s2, s2_len+1);
	free(s1);
	return(join);
}

char* strdup(char *str)
{
	size_t len = ft_strlen(str)+1;
	char *dup =(char *)malloc(sizeof(char) * len);
	if(dub == NULL)
		return(NULL);
	ft_strlcpy(dup, str, len);
	return(dup);

}

char *get_next_line(int fd)
{
	char *line
}