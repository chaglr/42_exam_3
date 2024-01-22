

ft_strchr(char *s, int c)
{
	while(*s)
	{
		if(*s == (char *)c)
			return(*s)
	}
	return (NULL);
}
size_t ft_strlen(const char *s)
{
	size_t i = 0;
	while(s[i])
		i++;
	return(i);
}
//char src[] = "Merhaba dünya";
//char dst[10];
//size_t max_copy_size = 10;

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t srcsize =ft_strlen(src);
	int i = 0;
	//hedef>0 -> hedef var olmasi gerekiyor ve i'nin dstsize-1 ve srcsize gecmemesi gerekiyor.
	if(dstsize >0)
	{
		while((i<dstsize-1) && (i<srcsize))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

char *ft_strdup(const char *src)
{
	char *dst;
	size_t src_len + 1 ; //+1 null char
	dst = malloc(len);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, src_len);
	return(dst);
}

char *ft_strjoin(char *s1, const char *s2, size_t s2_len)
{
	size_t s1_len, s2_len;
	char *joined;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof(char *) * (s1_len + s2_len + 1));
	if(!join)
		return(NULL);
		//once s1 i joine ekler.. ft_strlen sondaki null  karakteri almadigindan +1 gerekiyor.
	ft_strlcpy(join, s1, s1_len + 1);
	//sonra joinden s1'in sonuna gideriz (join+s1_len) ve s2'yi ekleriz s2_len kadar.
	ft_strlcpy(join + s1_len, s2, len + 1);
	//Eski String'in Serbest Bırakılması: s1 string'i için ayrılan bellek free kullanılarak serbest bırakılır.
	free(s1);
	return(join);
}

char *get_next_line(int fd)
{
//Bu satırda, buf isimli statik bir karakter dizisi tanımlanıyor. Bu dizinin boyutu, BUFFER_SIZE
// sabiti ile belirlenir ve sonuna ekstra bir karakter için yer bırakılır (null karakter).
//Statik olması, fonksiyonun birden fazla çağrılması durumunda bu tamponun içeriğini korumasını sağlar.
	static char buf[BUFFER_SIZE + 1];
	char *line;
	char *newline;
	int countread;
	int to_copy;

	line = ft_strdup(buf);
	// \n bulana kadar okuma yap ve okuma da basarili olsun.
	//ve de \n ulasila kadar calis.
	while (!(ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		//This ensures that buf contains a valid C string, which ends with a null character.
		buf[countread] = '\0';
		//burada da  read ile okuduguuz buf i line icine atariz
		line = ft_strjoin(line, buf, countread);
	}

	//eger okume bossa line bellegini temizler null dondururuz.
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
//mevcut lineda \n ara varsa new_line a at
	newline = ft_strchr(line, '\n');
	//eger yeni satir \n  varsa
	if (newline != NULL)
	{
		//newline - line + 1 hesaplaması, kopyalanacak satırın uzunluğunu belirler.
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

