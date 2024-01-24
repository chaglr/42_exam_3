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

//join two char array
char *str_join(char s1, const char s2, size_t s2_len)
{
	//len belirle
	//malloc la join e lenler +1 kadar bellek ata
	//ft_strlcpy ile s1 i s1_len kadar joine ekle.
	//ft_strcpy ile join+s1_len, e s2 yi  s2_len+1 kadar ekle
	//s1 freele
	//join return et.
	if(!s1 || !s2)
		return (NULL);
	size_t s1_len = ft_strlen(s1);
	char * join = (char *)malloc((s1_len + 1 + s2_len)*sizeof(char);
	ft_strlcpy(join, s1, s1_len+1);
	ft_strlcpy((join + s1_len), s2, s2len+1);
	free(s1);
	return(join);
}

char *strjoin(char *s1, const char *s2, size_t s2_len)
{
	if(!s1 || !s2)
		return (NULL);
	size_t len = ft_strlen(s1);
	char * join = (char *)malloc(sizeof(char) * s2_len + s1_len +1);
	ft_strlcpy(join, s1, s1_len +1);
	ft_strlcpy((join +s1_len),s2, s2_len+1);
	free(s1);
	return(join);
}