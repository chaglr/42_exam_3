#include <unistd.h>
#include <stdarg.h>

// String yazdırma fonksiyonu
void put_str(char *str, int *len) {
	if (!str) {
		str = "(null)"; // NULL kontrolü
	}
	while (*str) {
		*len += write(1, str++, 1); // Her karakteri tek tek yazdır
	}
}

// Sayısal değerleri belirli bir tabanda yazdırma fonksiyonu
void put_number(long long int number, int base, int *len) {
	char *digits = "0123456789abcdef"; // Sayısal değerler için karakter seti

	// Negatif sayı kontrolü
	if (number < 0) {
		number = -number;
		*len += write(1, "-", 1); // Negatif işareti ekle
	}

	// Sayının daha yüksek basamağını özyinelemeli olarak yazdır
	if (number >= base) {
		put_number(number / base, base, len);
	}

	// En düşük basamağı yazdır
	*len += write(1, &digits[number % base], 1);
}

// Özel printf fonksiyonunun implementasyonu
int printf(const char *format, ...) {
	int len = 0; // Yazdırılan karakter sayısını tutar
	va_list args;
	va_start(args, format); // Değişken argüman listesini başlat

	while (*format) {
		// Format spesifikatörünü kontrol et
		if (*format == '%' && (*(format + 1) == 's' || *(format + 1) == 'd' || *(format + 1) == 'x')) {
			format++;
			if (*format == 's') {
				// String argümanı yazdır
				put_str(va_arg(args, char *), &len);
			} else if (*format == 'd') {
				// Onluk tabanda sayısal argümanı yazdır
				put_number(va_arg(args, int), 10, &len);
			} else if (*format == 'x') {
				// Onaltılık tabanda sayısal argümanı yazdır
				put_number(va_arg(args, unsigned int), 16, &len);
			}
		} else {
			// Format spesifikatörü değilse karakteri direkt yazdır
			len += write(1, format, 1);
		}
		format++;
	}

	va_end(args); // Değişken argüman listesini kapat
	return len; // Yazdırılan toplam karakter sayısını dön
}

// Bu kod bloğu, printf fonksiyonunu ve yardımcı fonksiyonlarını
// daha anlaşılır ve okunabilir hale getirir.
