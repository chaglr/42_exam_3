
#include"get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t i = 0;
	while(s[i])
	{
		i++;
	}
	return(i);
}

char *ft_strchr(char *str, int c)
{
	while(*str)
	{
		if(*str == (char)c)
			return((char *)str);
		str++;
	}
	return(NULL);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dst_len)
{
	size_t	size_src = ft_strlen(src);
	size_t i= 0;

	if(dst_len > 0)
	{
		while(i < dst_len-1 && i < size_src)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i]= '\0';
	}
	return(size_src);
}

char *ft_strjoin(char *s1, const char *s2, size_t len_s2)
{
	if(!s1 || !s2)
		return(NULL);
	size_t len_s1 = ft_strlen(s1);
	char *join = malloc(sizeof(char) * len_s2+len_s1+1);
	if(!join)
		return(NULL);
	ft_strlcpy(join, s1, len_s1+1);
	ft_strlcpy(join+len_s1, s2, len_s2+1);
	free(s1);
	return(join);
}

char *ft_strdup(const char *str)
{
	size_t len = ft_strlen(str) + 1;
	char *dup = (char *)malloc(sizeof(char) * len);
	if(!dup)
		return(NULL);
	ft_strlcpy(dup, str, len);
	return(dup);
}

char *get_next_line(int fd)
{
	char *line;
	char *new_line;
	int countread;
	static char buf[BUFFER_SIZE+1];
	int to_copy;

	line = ft_strdup(buf);
	while(!(ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE))>0)
	{
		buf[countread] = '\0';
		line = ft_strjoin(line, buf, countread);
	}

	if(countread == -1)
	{
		//line free /buf ""  //return(null)
		ft_strlcpy(buf, "", BUFFER_SIZE+1);
		return(free(line), NULL);
	}

	if(ft_strlen(line) == 0)
		return(free(line), NULL);

	new_line = ft_strchr(line, '\n');
	if(new_line != NULL)
	{
		//null terminator yeri icin to_copy
		to_copy = new_line - line +1;
		/*??*/ ft_strlcpy(buf, new_line+1, BUFFER_SIZE+1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE+1);
	}
	line[to_copy] = '\0';
	return(line);

}

// int main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	return(0);
// }