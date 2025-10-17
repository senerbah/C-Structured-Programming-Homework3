# 🧮 UBI 503 – Veri Yapıları ve Algoritmalar (590616 – 2526G) · Ödev 3

**Öğrenci:** Bahtınur Şener  
**Öğrenci No:** 91250000022  
**Tarih:** 17/10/2025  
**Dönem:** 2025–2026 Güz  
**Ders Sorumluları:** Prof. Dr. Geylani KARDAŞ, Arş. Gör. Cemil Aybars URAL  
**Kurum:** Ege Üniversitesi, Uluslararası Bilgisayar Enstitüsü  

---

## 📘 İçerik

Bu repo **Ödev 3** kapsamında geliştirilen **C kaynak kodlarını** içerir.  
Her program, *C How to Program (7th Edition) — Paul & Harvey Deitel* kitabındaki  
fonksiyon konusuna ilişkin alıştırmalardan uyarlanmıştır.

Rapor (PDF) ve ekran görüntüleri **Ege Ders** platformu üzerinden teslim edilmiştir.  
Kaynak kodlar `src/` klasörü altında yer alır.

---

## 🧩 Kapsam

Bu ödev, **fonksiyonlar** konusuna odaklanmaktadır.  
Üç farklı problem üzerinden hem **iteratif** hem **özyinelemeli (recursive)**  
yapıların uygulanması amaçlanmıştır.

### 📄 Dosyalar

| Soru | Konu Başlığı | Dosya Adı |
|------|----------------|------------|
| 5.32 | Harf Tahmin Oyunu | `guess_alphabet.c` |
| 5.35 | Fibonacci (Özyinelemesiz) | `fibonacci.c` |
| 5.39 | Özyinelemeli EBOB (GCD) | `gcd_recursive.c` |

---

## 🔠 5.32 – Harf Tahmin Oyunu (`guess_alphabet.c`)

### 🎯 Problem Tanımı
Bilgisayar **A–Z arası rastgele bir harf** seçer.  
Kullanıcı bu harfi tahmin eder ve program aşağıdaki mesajlardan birini döndürür:

- **Doğru tahmin:** “Great! Your guess is right!”  
- **İlerideyse:** “Way ahead! Please try again.”  
- **Gerideyse:** “Way behind! Please try again.”  

Kullanıcı doğru tahmini bulduğunda, toplam deneme sayısına göre özel mesaj verilir:
| Tahmin Sayısı | Mesaj |
|----------------|-------|
| ≤ 5 | Either you know the secret or you are lucky! |
| = 5 | I guess you know the secret! |
| > 5 | You should be able to do better! |

### ⚙️ Kullanılan Yapılar
- `rand()`, `srand(time(NULL))` → Rastgele harf seçimi  
- `toupper()` → Harfleri büyüğe çevirme  
- `while` döngüsü → Tahmin tekrarları  
- Girdi doğrulama → A–Z aralığı kontrolü  

### 🧠 Algoritma Özeti
1. Rastgele bir harf seçilir (`secret`).  
2. Kullanıcıdan harf girişi alınır (`guess`).  
3. Girdi küçük harfse büyüğe çevrilir.  
4. Karşılaştırma yapılır:
   - `guess < secret` → “Way behind”  
   - `guess > secret` → “Way ahead”  
   - `guess == secret` → “Great!”  
5. Tahmin sayısına göre final mesajı yazdırılır.  

### 📸 Çalışma Örneği
I have selected a character between A and Z.
Try to guess the character selected by me!
What is your guess? g
Way behind! Please try again.
What is your guess? M
Great! Your guess is right!
Either you know the secret or you are lucky!

---

## 🔢 5.35 – Fibonacci (Nonrecursive) (`fibonacci.c`)

### 🎯 Problem Tanımı
(a) `fibonacci(n)` adlı özyinelemesiz fonksiyon, **n. Fibonacci sayısını** hesaplar.  
(b) 64-bit `unsigned long long` türüne sığan **en büyük Fibonacci** sayısını bulur.

### ⚙️ Kullanılan Yapılar
- İteratif döngü: `for`  
- Taşma kontrolü: `if (ULLONG_MAX - b < a)`  
- `limits.h` sabitleri (`ULLONG_MAX`)  
- Fonksiyon tanımı ve çağrısı  

### 🧠 Algoritma Özeti
1. `n=0` ve `n=1` durumlarında doğrudan dönüş yapılır.  
2. İki değişken (a, b) ile ardışık toplama yöntemi kullanılır.  
3. Döngü ile `next = a + b` hesaplanır, değişkenler kaydırılır.  
4. Büyük sayılar için taşma kontrolü yapılır.  
5. `F(93)` değeri 64-bit tamsayıya sığan en büyük Fibonacci sayısıdır.

### 📸 Çalışma Örneği
n giriniz (0..93 önerilir): 50
F(50) = 12586269025
unsigned long long'a sigan en buyuk Fibonacci: F(93) = 12200160415121876738

---

## 🔁 5.39 – Özyinelemeli EBOB (GCD) (`gcd_recursive.c`)

### 🎯 Problem Tanımı
İki sayının EBOB’u (**En Büyük Ortak Bölen**) Öklid algoritması ile bulunur:  
gcd(x, y) = x, eğer y == 0
gcd(x, y) = gcd(y, x % y), aksi halde

Bu tanım **özyinelemeli (recursive)** olarak uygulanır.

### ⚙️ Kullanılan Yapılar
- Fonksiyon içinde özyineleme (recursion)  
- `%` (mod) operatörü ile kalan hesaplama  
- `unsigned long long` → büyük sayı desteği  
- Girdi kontrolü (`scanf` doğrulaması)

### 🧠 Algoritma Özeti
1. Kullanıcıdan iki doğal sayı alınır (`x`, `y`).  
2. Fonksiyon çağrılır: `gcd(x, y)`  
3. Eğer `y == 0` → sonuç `x` döndürülür.  
4. Aksi halde → `gcd(y, x % y)` çağrısı yapılır.  
5. Her çağrıda `y` değeri küçülür, en sonunda `y=0` olur ve sonuç döner.

### 📸 Çalışma Örneği
Iki dogal sayi giriniz (x y): 270 192
gcd(270, 192) = 6

---

## 📑 Rapor Bilgileri

- Her kaynak dosya kapsamlı yorum satırları ile desteklenmiştir.  
- Programlar **yapısal programlama prensiplerine** göre geliştirilmiştir.  
- Rapor bölümleri:
  - Problem Tanımı  
  - Algoritma ve Yöntem  
  - Sözde Kod  
  - Kaynak Kod ve Açıklamaları  
  - Çalışma Ekran Görüntüleri  
  - Sonuç ve Değerlendirme  

Teslim:  
📤 **Ege Ders → Hafta 5: Functions → Homework 3**

---
