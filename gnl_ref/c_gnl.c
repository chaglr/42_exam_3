

# include "get_next_line.h"



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

size_t ft_strlen(const char *str)
{
    size_t len = 0;
    while(str[len])
    {
        len++;
    }

    return(len);

}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t src_len = ft_strlen(src);
    int i = 0;

    if(dstsize >0)
    {
        while(i < dstsize -1 && i < src_len)
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }


    return(src_len);

}

char *ft_strdup(const char *src)
{
    char *copy;
    size_t dst_len = ft_strlen(src) +1;
    copy = (char *)malloc(sizeof(char) * dst_len);
    if(copy == NULL)
        return(NULL);
    ft_strlcpy(copy, src, dst_len);
    return(copy);

}

char *ft_strjoin(char *s1, const char *s2, size_t s2_len)
{
    char *join;
    if(!s1 || !s2)
        return(NULL);
    size_t s1_len = ft_strlen(s1);
    join = malloc(sizeof(char)* s1_len + s2_len);
    if(join == NULL)
        return (NULL);
    ft_strlcpy(join, s1, s1_len +1);
    free(s1);
    ft_strlcpy((join+s1_len), s2, s2_len+1);
    return(join);
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    int countread;
    int to_copy;
    char *line;
    char *newline;

    line = ft_strdup(buf);
    //burada line ile buf joinleyip , line nin icine atiyourz
    while(!(ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)) >0)
    {
        buf[countread] = '\0';
       line = ft_strjoin(line, buf, countread);
    }
    //line kontrolu ft_strlen//
    if(ft_strlen(line) == 0)
        return(free(line), NULL);
	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}
 #include <stdio.h>
 #include <fcntl.h>
 int main(void)
 {
    int fd;
    fd = open("test.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
 }