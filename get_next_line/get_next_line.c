/*
 * Reads from a file descriptor until a newline character is found or end of file (EOF) is reached.
 *
 * @param fd The file descriptor to read from.
 * @return A pointer to a string containing the read line, or NULL if an error occurs or end of file is reached.
 *         The string must be freed by the caller.
 */
#include "get_next_line.h"

char *get_next_line(int fd)
{
	int i = 0;
	int rd = 0;
	char character;

	if (BUFFER_SIZE <= 0)
		return (NULL);

	char *buffer = malloc(BUFFER_SIZE + 1);
	while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}


/*
	Bu `while` döngüsü, dosyadan (`fd` dosya tanımlayıcısı ile belirtilen) karakter karakter okuma yapar.
	İşte döngünün her bir parçasının açıklaması:

1. **`read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)`
**: `read` fonksiyonu, `fd` dosya tanımlayıcısından bir karakter okur ve bu karakteri `character` değişkenine atar. `
BUFFER_SIZE - BUFFER_SIZE + 1` ifadesi aslında `1` olur, bu da bir karakter okunacağını belirtir.

2. **`rd = read(...)`**: `read` fonksiyonunun döndüğü değer `rd` değişkenine atanır.
Eğer `read` fonksiyonu başarılı bir şekilde çalışırsa, okunan bayt sayısını döndürür.
Eğer bir hata oluşursa `-1` döndürür. Eğer dosyanın sonuna ulaşılmışsa `0` döndürür.

3. **`while ((rd = read(...)) > 0)`**: Döngü, `read` fonksiyonu `0` veya `-1`
döndürene kadar devam eder. Yani, dosyanın sonuna ulaşıldığında veya bir hata oluştuğunda döngü sona erer.

4. **`buffer[i++] = character;`**: Okunan `character` değişkeni, `buffer` dizisinin
`i` indeksli elemanına atanır ve `i` bir artırılır.

5. **`if (character == '\n') break;`**: Eğer okunan karakter bir yeni satır karakteri (`\n`) ise, döngü sona erer.

Bu döngü, dosyadan karakter karakter okuma yapar ve okunan karakterleri `buffer` dizisine ekler.
Eğer bir yeni satır karakteri (`\n`) okunursa veya dosyanın sonuna ulaşılırsa, döngü sona erer.

rd ne işe yarıyor?
`rd` değişkeninin adı burada bir kısaltma olabilir, genellikle "read" ya da "read data" gibi anlamlara gelir.
 Bu değişken, `read` fonksiyonunun döndüğü değeri tutar. Eğer `read` fonksiyonu başarılı bir şekilde çalışırsa,
 okunan bayt (byte) sayısını döndürür. Eğer bir hata oluşursa `-1` döndürür. Eğer dosyanın sonuna ulaşılmışsa
 `0` döndürür.

Bu değişken genellikle dosya okuma işlemlerinde kullanılır, çünkü `read` fonksiyonunun döndüğü değeri kontrol
etmek genellikle önemlidir. Bu değer, okuma işleminin başarılı olup olmadığını ve daha fazla veri olup olmadığını belirlemenizi sağlar.

char by char okuma yapmak neden daha iyi?
`read` fonksiyonu, dosyadan okuma yapar ve okunan veriyi `character` değişkenine atar.
 Bu değişken, `buffer` dizisinin `i` indeksli elemanına atanır ve `i` bir artırılır.
 Bu işlem, dosyadan okunan veriyi `buffer` dizisine ekler.



*/