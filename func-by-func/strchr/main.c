#include <stdio.h>

char *ft_strchr(char* s, int c)
{
	while(*s)
	{
		if(*s == (char)c)
			return((char *)s);
		s++;
	}
	return(NULL);
}

int main(int argc, char *argv[])
{
	// Argüman sayısını kontrol et
	if (argc != 3) {
		printf("Kullanım: program <string> <karakter>\n");
		return 1;
	}

	char *str = argv[1];
	char ch = argv[2][0]; // Karakter olarak ilk argümanın ilk karakterini al
	char *result;

	result = ft_strchr(str, ch);
	if (result != NULL)
		printf("Karakter '%c' bulundu: %s\n", ch, result);
	else
		printf("Karakter '%c' bulunamadı.\n", ch);

	return 0;
}
