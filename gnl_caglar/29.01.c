
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
char *get_next_line(int fd)
{

}