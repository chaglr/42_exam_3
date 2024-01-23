
// bir karakter dizisinde belirli bir karakteri arar ve bulduğunda o karakterin adresini döndürür.
char *ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char *)c)
			return (*s)
	}
	return (NULL);
}

// ft_strlen(line) fonksiyonu line'ın uzunluğunu (null karakteri hariç) döndürür.
size_t ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return (i);
}
// char src[] = "Merhaba dünya";
// char dst[10];
// size_t max_copy_size = 10;

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t srcsize = ft_strlen(src);
	int i = 0;
	// hedef>0 -> hedef var olmasi gerekiyor ve
	if (dstsize > 0)
	{
		//i'nin dstsize-1 ve srcsize gecmemesi gerekiyor.
		while ((i < dstsize - 1) && (i < srcsize))
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
	size_t src_len + 1; //+1 null char
	dst = malloc(len);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, src_len);
	return (dst);
}
// join char arrayinin başını return eder.
char *ft_strjoin(char *s1, const char *s2, size_t s2_len)
{
	size_t s1_len, s2_len;
	char *joined;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof(char *) * (s1_len + s2_len + 1));
	if (!join)
		return (NULL);
	// once s1 i joine ekler.. ft_strlen sondaki null  karakteri almadigindan +1 gerekiyor.
	ft_strlcpy(join, s1, s1_len + 1);
	// sonra joinden s1'in sonuna gideriz (join+s1_len) ve s2'yi ekleriz s2_len kadar.
	ft_strlcpy(join + s1_len, s2, len + 1);
	// Eski String'in Serbest Bırakılması: s1 string'i için ayrılan bellek free kullanılarak serbest bırakılır.
	free(s1);
	return (join);
}

char *get_next_line(int fd)
{
	// Bu satırda, buf isimli statik bir karakter dizisi tanımlanıyor. Bu dizinin boyutu, BUFFER_SIZE
	//  sabiti ile belirlenir ve sonuna ekstra bir karakter için yer bırakılır (null karakter).
	// Statik olması, fonksiyonun birden fazla çağrılması durumunda bu tamponun içeriğini korumasını sağlar.
	static char buf[BUFFER_SIZE + 1];
	char *line;
	char *newline;
	int countread;
	int to_copy;

	line = ft_strdup(buf);
	// \n bulana kadar okuma yap ve okuma da basarili olsun.
	// ve de \n ulasila kadar calis.
	while (!(ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		// This ensures that buf contains a valid C string, which ends with a null character.
		buf[countread] = '\0';
		// burada da  read ile okuduguuz buf i line icine atariz
		line = ft_strjoin(line, buf, countread);
	}
	// eger okume bossa line bellegini temizler null dondururuz.
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	// mevcut lineda \n ara varsa new_line a at
	newline = ft_strchr(line, '\n');
	// eger yeni satir \n  varsa
	if (newline != NULL)
	{
		// newline - line + 1 hesaplaması, kopyalanacak satırın uzunluğunu belirler.
		// newline ılk karakterı - linenın ilk karakteri
		to_copy = newline - line + 1;
		// ft_strlcpy ile newline'dan sonraki veri buf'a kopyalanır. Bu, sonraki get_next_line çağrısında kullanılmak üzere buf'ı günceller.
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	// ya dosyanin sonuna ulasildi ya da okunan veri tam satiri karsilamiyor.
	// eger yeni satir yoksa buf i temizleriz. zaten line icinde oldugu icin veri buf tutmaya gerek yok.
	else
	{
		//line string'inin tam uzunluğunu almak. Bu, line içinde yeni satır karakteri ('\n') olmadığı anlamına gelir ve bu durumda
		//line'ın tamamı bir sonraki işlem için kullanılmalıdır.
		to_copy = ft_strlen(line);
		// buff temizleriz
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}

// get_next_line fonksiyonunun else bloğunda buf'ın temizlenmesi, belirli bir amaca hizmet eder. Bu blok, okunan line içerisinde bir
// yeni satır karakteri ('\n') bulunmadığı durumlarda çalışır. Yani, okunan veri tam bir satırı içermiyor veya dosyanın sonuna ulaşılmış
// olabilir. İşte bu durumda buf'ın temizlenmesinin nedenleri:

// Sonraki Okuma İçin Hazırlık: get_next_line fonksiyonu bir sonraki çağrıda tekrar kullanılacaksa, buf'ın temiz olması gerekir.
// Bu, yeni okuma işleminin önceki verilerden etkilenmemesi için önemlidir.

// Kalan Veriyi Saklamak: Eğer line içinde yeni satır karakteri yoksa, bu genellikle okunan tüm verinin bir satırı tamamlamadığını gösterir.
// Bu durumda, line zaten okunan tüm veriyi içerir ve buf'ta kalan veriye ihtiyaç yoktur. Bu nedenle, buf temizlenir.

// Hatalı Veri Okuma Riskini Azaltmak: buf temizlenmezse, sonraki get_next_line çağrısında eski veriyle karışık yeni veri okuma riski oluşur.
// Bu, yanlış veya eksik veri okunmasına yol açabilir.
