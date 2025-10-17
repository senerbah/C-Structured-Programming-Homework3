/*
 * --------------------------------------------------------------
 *  UBI 503 – Veri Yapıları ve Algoritmalar
 *  Ödev 3 – Soru 5.35 (Fibonacci)
 *  Yazan  : Bahtınur Şener
 *  Amaç   : (a) Özyinelemesiz fibonacci(n) hesaplama
 *           (b) unsigned long long'a sığan en büyük Fibonacci'yi bulma
 * --------------------------------------------------------------
 */

#include <stdio.h>   // printf, scanf
#include <limits.h>  // ULLONG_MAX (64-bit üst sınır)

/*
 * Bölüm A — fibonacci(n):
 * --------------------------------------------------------------
 *  - Girdi : n (unsigned int)
 *  - Çıkış : F(n) (unsigned long long)
 *  - Yöntem: Özyinelemesiz (iteratif) hesap; O(n) zaman, O(1) bellek
 *  - Not   : 64-bit sınırı nedeniyle güvenli üst sınır pratikte n ≤ 93'tür.
 */
unsigned long long fibonacci(unsigned int n) {
    // 1) Temel durumlar
    if (n == 0) return 0ULL;
    if (n == 1) return 1ULL;

    // 2) Kaydırmalı toplama için iki değişken tutuyoruz:
    //    a = F(0), b = F(1)
    unsigned long long a = 0ULL;
    unsigned long long b = 1ULL;

    // 3) 2'den n'e kadar F(i) üret:
    //    next = a + b  ->  F(i)
    //    a = b; b = next  ->  bir sonraki adım için kaydır
    for (unsigned int i = 2; i <= n; ++i) {
        unsigned long long next = a + b; // n ≤ 93 iken taşma olmaz
        a = b;
        b = next;
    }
    return b; // b = F(n)
}

int main(void) {
    /*
     * Bölüm B — Kullanıcıdan n alma ve F(n) yazdırma
     * --------------------------------------------------------------
     *  - Girdi kontrolü yapılır; geçersizse program sonlandırılır.
     */
    unsigned int n;
    printf("n giriniz (0..93 onerilir): ");
    if (scanf("%u", &n) != 1) {
        printf("Gecersiz giris.\n");
        return 0;
    }

    // 1) F(n)'i hesapla ve yazdır
    //    Not: %llu -> unsigned long long yazdırma biçimi
    printf("F(%u) = %llu\n", n, fibonacci(n));

    /*
     * Bölüm C — 64-bit'e sığan en büyük Fibonacci'yi otomatik bulma
     * --------------------------------------------------------------
     *  - Mantık: Bir sonraki adımda a+b toplaması ULLONG_MAX'i aşacaksa dur.
     *  - Böylece son geçerli b = F(idx) ekrana yazdırılır.
     */
    unsigned long long a = 0ULL, b = 1ULL; // F(0), F(1)
    unsigned int idx = 1;                  // b şu an F(1)

    while (1) {
        // Taşma testi: a + b > ULLONG_MAX ise taşma olur
        // Güvenli kontrol: (ULLONG_MAX - b) < a  <=>  a + b > ULLONG_MAX
        if (ULLONG_MAX - b < a) {
            // Bir adım daha gidersek taşma olacak; şu anki b, sığan en büyük F
            break;
        }

        // Güvenliyse bir sonraki Fibonacci'ye ilerle
        unsigned long long next = a + b;
        a = b;
        b = next;
        idx++; // Artık b = F(idx)
    }

    printf("unsigned long long'a sigan en buyuk Fibonacci: F(%u) = %llu\n", idx, b);

    return 0;
}
