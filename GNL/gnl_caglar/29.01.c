
char *ft_strchr(char *s, int c)
{
	while(*s)
	{
		if(*s = (char)c)
			return((char *)s);
}


size_t ft_strlen(const char *s)
{
	size_t len;
	while(s[len])
		len++;
	return(len);
}


size_t str_len(const char *str);
size_t strlcpy(char *dest, const char *src, size_t dst_len);
char *strdup(const char * str);
char *strjoin(char *s1, const char *s2,size_t src_len);
char *gnl(int fd);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < srcsize && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

1- s1 ve s2  null check yapilir.
2- s1_len hesaplanir.
3- join -> memmory allocate  (s1_len +s2_len) + 1 sizeof(char)
4-memory null check
5-strlcpy ile join, s1, s1_len+1 olarak. joinin icine s1 atilir.
6-strlcpy (join+s1_len)nin icinde s2, s2_len+1 olarak atilir.
7-sonra s1 free yapilip
8-join dondurulur.


char *strjoin(char s1 const char s2, size_t len_s2)
{
	if(!s1 && !s2)
		return (NULL);
	size_t len_s1 = ft_strlen(s1);
	char *join =(char *)malloc((s1_len+s2_len+1)* sizeof(char));
	if(!join)
		return(NULL);
	ft_strlcpy(join, s1, s1_len+1);
	ft_strlcpy((join+s1_len), s2, s2len+1);
	free(s1);
	return(join);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < srcsize && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

char *strjoin(char *s1, const char *s2, size_t s2_len)
{
	if(!s1 || !s2)
		return(NULL);
	size_t len_s1 = ft_strlen(s1);
	char *join= (char *)malloc(sizeof(char) * (s1_len+s2_len+1));
	if(!join)
		return(NULL);
	ft_strlcpy(join, s1, s1_len+1);
	ft_strlcpy(join+s1, s2, s2_len+1);
	free(s1);
	return(join);
}

once len hesapla +1 ekle
sonra malloc ile bellek ayir
bellek hatasu
char *strdup(const char *s)
{
 size_t len = ft_strlen(s)+1;
 char *dup = (char *)malloc((len) * (sizeof(char)));
 if(!dub)
	return(NULL);
 ft_strlcpy(dup, s, len);
 return(dup);
}
size_t ft_strlen(const char * s)
{
	size_t i = 0;
	while(s[i])
	{
		i++;
	}
	return(i);
}

char *ft_strchr(char *s, int c)
{
	while(*s)
	{
		if(*s = (char)c)
			return((char *)s);
		s++;
	}
}


size_t strlcpy(char *dst, const char *src, size_t len_dst)
{
	size_t src_len = ft_strlen(src);
	size_t i;
	while( i < src && i < dst_len-1)
	{
		dst[i] =src[i];
	}
	dst[i] = '\0';
	return(dst_len);
}

size_t strlen(const char *s)

char *strjoin();
char *strdup();

1-statik char buf ayir BUFFER_SIZE+1 kadar
2-buf i line a strdup ile kopyala
3- satırdaki yeni satır karakterini ('\n') arıyor ve bulamazsa, 'read'
fonksiyonunu kullanarak daha fazla veri okuyor. 'read' fonksiyonunun dönüş
değeri 'countread' değişkenine atanıyor ve bu değer sıfırdan büyük olduğu
sürece döngü devam ediyor.

4-buf sonuna \0 ekle
5-line ile buf birlestir (strjoin) line nin icine at.
6-sonra line len kontrol et eger sifirsa return null yap ve line i free le.

7-line nin icinde \n ara ve bunu 'newline' a at
8-eger new_line NULL degilse yani\n bulunduysa to_copy int  yarat = newline - line +1
9-sonra new_line +1 ekleyerek buf in icinde buffsize+1 kadar ekleriz.
10- eger \n yoksa line da 'else' to_copy line tamaminin uzunlugu kadar yapariz.
11-sonra line to_copy uzunluguna '\0' eklenir.
12-line return edilir.
char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE];
	char * line;
	int readcount
	char *newline;
	int to_copy;

	line = strdup(buf);
	while(!(ft_strchr(line, '\n'))&&(readcount=read(fd, buf, BUFFER_SIZE))>0)
	{
		buf[readcount] = '\0';
		line= ft(line, buf, readcount);
	}

	if(ftstrlen(line) == 0)
		return(free(line), NULL);

	new_line = ft_strchr(line, '\n');
	if(new_line != NULL)
	{
		to_copy = new_line - line +1;
		ft_strlcpy(buf,new_line +1, BUFFERSIZE+1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFERSIZE+1);
	}
	line[to_copy] = '\0';
	return(line);


}
------------------------------------------------
char *ft_strchr(char *s, int c)
{
	while(*s)
	{
		if(*s == (char *)c)
			return((char *)s)
		s++;
	}
	return(NULL);

	size_t ft_strlen(const char *s)
	{
		size_t i;
		while(s[i])
		{
			i++;
		}
		return(i);
	}
}
size_t ft_strlcpy(char *dst, const char *src, size_t len_dst)
{
	size_t	len_src = ft_strlen(src);
	size_t i = 0;

	if(dst_len > 0)
	{
		while(i < len_src && i < len_dst-1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0'; //hata yaptik// if in disina yazdin.
	}

	return(len_src)

}
char *ft_strjoin(char *s1, const char *s2, size_t len_s2)
{
	char *join;
	if(!s1 || !s2)
		return(NULL);
	size_t len_s1 = ft_strlen(s1);
	join = (char *)malloc(sizeof(char) * s1_len+s2_len+1);
	if(join == NULL)
		return(NULL);
	ft_strlcpy(join, s1,  len_s1+1);
	ft_strlcpy(join+s1_len, s2, len_s2+1);// hata yapiyorsun.
	free(s1);
	return(join);

}

char *ft_strdup(const char *str)
{
	char *dst;
	size_t len = ft_strlen(str)+1;
	dst =(char *)malloc(sizeof(char)* len);hata yaptin +1 kadar ayirmana gerek yok
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

	line = ft_strdup(buf);
	while(!(ft_strchr(line, '\n')) && (countread= read(fd, buf, BUFFER_SIZE))>0)
	{
		buf[countread]= '\0';
		line = ft_strjoin(line, buf, counterread);
	}

	if(ft_strlen(line) == 0)
		return(free(line), NULL);

	new_line = ft_strchr(line, '\n');
	if(!(new_line == NULL))
	{
		to_copy = new_line - line +1;
		// ft_strlcpy(buf, new_line, to_copy)//hata yaptin!
		ft_strlcpy(buf, new_line+1, BUFFERSIZE+1)
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "",BUFFER_SIZE+1);
	}
	line[to_copy] = '\0';

}