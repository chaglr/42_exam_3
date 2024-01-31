//src dan dst a dstsize kadar kopyalama yapar.
//iki ayri bellek biriminden src dan dst a bunlarin hangisi kucukse o kadar
//src ye kopyalama yapar.

// char src[] = "Merhaba dünya";
// char dst[10];
// size_t max_copy_size = 10;

//istedigimiz len kadar, src den dest a kopyalama yapiyoruz
char *ftt_strlcpy(char *dest, const char src, size_t len)
{
	size_t len_src = ft_strlen(src);
	size_t i = 0;
//yazilacak bir hedef oldugunu kontrol et. bu yoksa kopyalama yapamayiz. burada dest sıze manual olarak verıyoruz
// o nedenle dogru rakam verilmis mi onu konrol ediyoruz aslinda.
	if(len > 0) //eger kopyalama hedefi varsa
	{
		//len_src ft_strlen hesapladigimizdan NULL terminator icermez. fakat len manual olarak verdigimizden
		// null terminator'i icerir.
		while ( i < len_src && i < len-1)
		{
			dst[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return(len_src);
	}
}
// char src[] = "Merhaba dünya";
// char dst[10];
// size_t max_copy_size = 10;

char *strlcpy(char *s1, const char s2, size_t len_s1)
{
	size_t len_s2 = ft_strlen(s2);
	size_t i = 0;

	while(i < len_s1 -1 && i < len_s2 )
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return(len_s2);

}