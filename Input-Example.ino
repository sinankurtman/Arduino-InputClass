#include "input.h"

giris g;

int fiyat;

void setup() {
  Serial.begin(9600);
}
void loop() {
  String str = g.input("Ürünün fiyatını giriniz:");
    fiyat = str.toInt();
    Serial.println(fiyat);

    if (fiyat >= 100)
    {
      Serial.println("Ödeyeceğiniz Toplam Fiyatta değişiklik yapılmayacak");
    }
    else
    {
      Serial.println("Ödeyeceğiniz Toplam Fiyata 5 tl kargo bedeli eklenecek");
    }
}
