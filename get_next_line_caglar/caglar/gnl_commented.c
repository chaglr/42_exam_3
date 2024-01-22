#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>  // open fonksiyonu için
#include <unistd.h> // close fonksiyonu için

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(src) + 1;
	dst = malloc(len);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, len);
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2, size_t len)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = len;
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy((join + s1_len), s2, s2_len + 1);
	free(s1);
	return (join);
}

char    *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];  // Static buffer tanımla, her çağrıda sıfırdan başlamasın
	char        *line;                // Okunan satırı tutacak değişken
	char        *newline;             // Yeni satır karakterini bulmak için kullanılacak
	int         countread;            // Okunan karakter sayısını tutacak
	int         to_copy;              // Kopyalanacak karakter sayısı

	line = ft_strdup(buf);            // Buffer'daki veriyi line'a kopyala
	// Line içinde yeni satır karakteri yoksa ve okuma başarılıysa döngüye devam et
	while (!(ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[countread] = '\0';        // Okunan verinin sonuna null karakter ekle
		line = ft_strjoin(line, buf, countread);  // Okunan veriyi line'a ekle
	}
	// Eğer line boşsa, NULL dön
	if (ft_strlen(line) == 0)
		return (free(line), NULL);

	newline = ft_strchr(line, '\n');  // Line içinde yeni satır karakterini ara
	if (newline != NULL)              // Eğer yeni satır karakteri varsa
	{
		to_copy = newline - line + 1; // Yeni satır karakterine kadar olan kısmı kopyala
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1); // Kalan kısmı buffer'a kopyala
	}
	else                              // Yeni satır karakteri yoksa
	{
		to_copy = ft_strlen(line);    // Tüm line'ı kopyala
		ft_strlcpy(buf, "", BUFFER_SIZE + 1); // Buffer'ı temizle
	}
	line[to_copy] = '\0';             // Line'ın sonuna null karakter ekle
	return (line);                    // Sonuç olarak elde edilen line'ı dön
}




int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY); // 'test.txt' isimli dosyayı aç
    if (fd == -1)
    {
        perror("Dosya açılamadı");
        return (1);
    }

     while ((line = get_next_line(fd)) != NULL)
     {
        printf("%s", line = get_next_line(fd));
        free(line);
     }

    close(fd);
    return (0);
}
