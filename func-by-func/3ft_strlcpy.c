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
	}
}