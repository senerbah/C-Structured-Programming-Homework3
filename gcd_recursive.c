/*
 * --------------------------------------------------------------
 *  UBI 503 – Veri Yapıları ve Algoritmalar
 *  Ödev 3 – Soru 5.39 (Recursive GCD)
 *  Yazan  : Bahtınur Şener
 *  Amaç   : İki sayının EBOB’unu (En Büyük Ortak Bölen) 
 *            Öklid algoritması ile ÖZYİNELEMELİ (recursive) olarak bulmak.
 * --------------------------------------------------------------
 */

#include <stdio.h>  // printf, scanf fonksiyonları için

/*
 * --------------------------------------------------------------
 *  gcd(x, y) Fonksiyonu:
 *  -------------------------------------------------------------
 *  Girdi : iki pozitif tam sayı (x, y)
 *  Çıkış : x ve y'nin en büyük ortak böleni (EBOB)
 *
 *  Öklid Algoritması Tanımı:
 *     gcd(x, y) = x, eğer y == 0 ise
 *     gcd(x, y) = gcd(y, x % y), aksi halde
 *
 *  Yani:
 *  - Her çağrıda ikinci sayı (y) 0 olana kadar işlem sürer.
 *  - % işleci, x'in y'ye bölümünden kalanı alır.
 *  - y sıfır olduğunda recursion (özyineleme) durur ve sonuç x olur.
 * --------------------------------------------------------------
 */
unsigned long long gcd(unsigned long long x, unsigned long long y) {
    // 1️⃣ Temel durum: Eğer ikinci sayı 0 olduysa EBOB = x’tir.
    if (y == 0ULL)
        return x;

    // 2️⃣ Özyinelemeli durum:
    //    Öklid kuralına göre, gcd(x, y) = gcd(y, x % y)
    return gcd(y, x % y);
}

int main(void) {
    /*
     * --------------------------------------------------------------
     *  Programın Ana Akışı:
     *  --------------------------------------------------------------
     *  1) Kullanıcıdan iki sayı (x, y) alınır.
     *  2) EBOB hesaplanmak üzere gcd() fonksiyonuna gönderilir.
     *  3) Sonuç ekrana yazdırılır.
     * --------------------------------------------------------------
     */

    unsigned long long x, y; // Büyük tamsayılarla çalışabilmek için 64-bit tip seçildi.

    // Kullanıcıdan iki doğal sayı isteniyor
    printf("Iki dogal sayi giriniz (x y): ");
    if (scanf("%llu %llu", &x, &y) != 2) {
        // Eğer giriş formatı hatalıysa
        printf("Gecersiz giris.\n");
        return 0;
    }

    // 4️⃣ Fonksiyon çağrısı: gcd(x, y)
    //    Hesap tamamlandığında sonuç ekrana yazdırılır.
    printf("gcd(%llu, %llu) = %llu\n", x, y, gcd(x, y));

    // 5️⃣ Program sonu: başarılı bitiş
    return 0;
}
