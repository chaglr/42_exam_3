#include "get_next_line.h"
char *ft_strchr(char *s, int c)
{
	while(*s)
	{
		if(*s == (char)c) //hata
			return((char *)s);
		s++;
	}
	return(NULL);
}

size_t ft_strlen(const char *s)
{
	size_t i = 0;
	while(s[i])
	{
		i++;
	}
	return(i);
}

size_t ft_strlcpy(char *dst, const char *src, size_t len_dst)
{
	size_t	len_src = ft_strlen(src);
	size_t i = 0;

	if(len_dst > 0)
	{
		while(i < len_src && i < len_dst-1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0'; //hata yaptik// if in disina yazdin.
	}
	return(len_src);
}
char *ft_strjoin(char *s1, const char *s2, size_t len_s2)
{
	char *join;
	if(!s1 || !s2)
		return(NULL);
	size_t len_s1 = ft_strlen(s1);
	join = (char *)malloc(sizeof(char) * len_s1+len_s2+1);
	if(join == NULL)
		return(NULL);
	ft_strlcpy(join, s1,  len_s1+1);
	ft_strlcpy(join+len_s1, s2, len_s2+1);// hata yapiyorsun.
	free(s1);
	return(join);

}

char *ft_strdup(const char *str)
{
	char *dst;
	size_t len = ft_strlen(str)+1;
	dst =(char *)malloc(sizeof(char)* len);//hata yaptin +1 kadar ayirmana gerek yok
	if(dst== NULL )
		return(NULL);
	ft_strlcpy(dst, str, len);
	return(dst);
}

char *get_next_line(int fd)
{
	char *line;
	static char buf[BUFFER_SIZE+1];
	int countread = 0;
	int to_copy = 0;
	char *new_line;

	line = ft_strdup(buf);
	while(!(ft_strchr(line, '\n')) && (countread= read(fd, buf, BUFFER_SIZE))>0)
	{
		buf[countread]= '\0';
		line = ft_strjoin(line, buf, countread);
	}

	if(countread == -1)
	{
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
		return (free(line), NULL);
	}

	if(ft_strlen(line) == 0)
		return(free(line), NULL);

	new_line = ft_strchr(line, '\n');
	if(!(new_line == NULL))
	{
		to_copy = new_line - line +1;
		// ft_strlcpy(buf, new_line, to_copy)//hata yaptin!
		ft_strlcpy(buf, new_line+1, BUFFER_SIZE+1); //hata yaptin
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "",BUFFER_SIZE+1);
	}
	line[to_copy] = '\0';
	return(line);

}

//  int main(void)
//  {
//     int fd;
//     fd = open("test.txt", O_RDONLY);
//     get_next_line(fd);
// 	 get_next_line(fd);
// 	// printf("%s", get_next_line(fd));
//  }