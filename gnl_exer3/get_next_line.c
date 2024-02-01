#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
char *get_next_line(int fd);
#endif

#include"get_next_line.h"
char *ft_strchr(char * str, int c)
{
	while(*str)
	{
		if(*str == (char)c)
			return((char *)str);
		str++;
	}
	return(NULL);
}
size_t ft_strlen(const char *str)
{
	size_t i = 0;
	while(str[i])
	{
		i++;
	}
	return(i);
}
size_t ft_strlcpy(char *dst, const char *src, size_t dst_len)
{
	size_t src_len = ft_strlen(src);
	size_t i = 0;

	if(dst_len > 0)
	{
		while(i < dst_len-1 && i < src_len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return(src_len);
}
char *ft_strjoin(char *s1, const char *s2, size_t s2_len)
{
	if(!s1 || !s2)
		return(NULL);
	size_t s1_len = ft_strlen(s1);
	char *join =(char *)malloc(sizeof(char) * s1_len+s2_len+1);
	if(join == NULL)
		return(NULL);
	ft_strlcpy(join, s1, s1_len+1);
	ft_strlcpy(join+s1_len, s2, s2_len+1);
	free(s1);
	return(join);
}
char *ft_strdup(const char *str)
{
	size_t len = ft_strlen(str)+1;
	char * dst=(char *)malloc(sizeof(char)* len);
	ft_strlcpy(dst, str, len);
	return(dst);
}

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE+1];
	char *line;
	char *new_line;
	int countread;
	int to_copy;

	line = ft_strdup(buf);

	while(!(ft_strchr(line, '\n')) && (countread= read(fd, buf, BUFFER_SIZE))>0)
	{
		buf[countread] = '\0';
		line = ft_strjoin(line, buf, BUFFER_SIZE);
	}
	if(ft_strlen(line) == 0)
		return(free(line), NULL);

	if(countread == -1)
	{
		ft_strlcpy(buf, "", BUFFER_SIZE+1); //free line, buf'i temizle, return null
		return(free(line), NULL);
	}

	new_line = ft_strchr(line, '\n');
	//buf a new line i atiyoruz.
	if(new_line != NULL)
	{
		to_copy = new_line - line +1;
		ft_strlcpy(buf, new_line+1, BUFFER_SIZE+1);//unuttuk//
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE+1);
	}
	line[to_copy]= '\0';
	return(line);
}
int main(void)
{
	int fd = open("subject.en.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return(0);
}