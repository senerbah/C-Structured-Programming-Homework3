/*
 * ----------------------------------------------------------
 *  UBI 503 – Veri Yapıları ve Algoritmalar
 *  Ödev 3 – Soru 5.32 (Guess the Alphabet)
 *  Yazan: Bahtınur Şener
 *  Tarih: 17/10/2025
 *
 *  AMAÇ:
 *  Bilgisayar A–Z arası rastgele bir harf seçer.
 *  Kullanıcı bu harfi tahmin etmeye çalışır.
 *  Program, her tahminde "Way ahead" veya "Way behind" mesajları verir.
 *  Doğru tahmin edildiğinde toplam deneme sayısına göre özel mesaj gösterir.
 * ----------------------------------------------------------
 */

#include <stdio.h>   // printf, getchar
#include <stdlib.h>  // rand, srand
#include <time.h>    // time
#include <ctype.h>   // toupper

int main(void) {

    // 1️⃣ Rastgele sayı üreteci tohumlama (her çalıştırmada farklı sonuç)
    srand((unsigned)time(NULL));

    // 2️⃣ A–Z arasında rastgele bir harf seç
    //    'A' ASCII değeri 65 → +0..25 → A–Z arası 26 harf
    char secret = (char)('A' + (rand() % 26));

    // Kullanıcının gireceği harf
    char guess;
    // Tahmin sayısı (kaç denemede bildiğini saymak için)
    int guesses = 0;

    printf("I have selected a character between A and Z.\n");
    printf("Try to guess the character selected by me!\n");

    // 3️⃣ Tahmin döngüsü (doğru bulunana kadar devam eder)
    while (1) {
        printf("What is your guess? ");

        // Kullanıcıdan ilk karakteri oku
        int c = getchar();

        // Eğer boş satır (Enter) girdiyse, bir sonraki gerçek karaktere geç
        while (c == '\n' || c == '\r') {
            c = getchar();
        }

        // İlk karakteri tahmin olarak al
        guess = (char)c;

        // Kullanıcı fazladan karakter yazdıysa (örneğin “AB”), satır sonuna kadar sil
        int d;
        while ((d = getchar()) != '\n' && d != EOF) {
            /* buffer temizleme */
        }

        // Küçük harf girildiyse büyük harfe çevir
        guess = (char)toupper((unsigned char)guess);

        // 4️⃣ Girdi doğrulama
        //    Kullanıcı A–Z arası dışında bir karakter girdiyse uyarı ver
        if (guess < 'A' || guess > 'Z') {
            printf("Please enter a single letter between A and Z.\n");
            continue; // döngünün başına dön
        }

        // Geçerli bir tahmin yapıldı → tahmin sayısını artır
        guesses++;

        // 5️⃣ Tahmin kontrolü
        if (guess == secret) {
            // Doğru tahmin
            printf("Great! Your guess is right!\n");
            break; // döngüden çık
        } 
        else if (guess > secret) {
            // Tahmin edilen harf seçilen harften sonra geliyor (örneğin T > M)
            printf("Way ahead! Please try again.\n");
        } 
        else {
            // Tahmin edilen harf seçilen harften önce geliyor (örneğin G < M)
            printf("Way behind! Please try again.\n");
        }
    }

    // 6️⃣ Sonuç değerlendirmesi
    //    Bu üç koşul bağımsızdır çünkü 5 tahmin durumunda iki mesaj birden çıkmalıdır.
    if (guesses <= 5) {
        printf("Either you know the secret or you are lucky!\n");
    }
    if (guesses == 5) {
        printf("I guess you know the secret!\n");
    }
    if (guesses > 5) {
        printf("You should be able to do better!\n");
    }

    // 7️⃣ Program sonu
    return 0;
}
