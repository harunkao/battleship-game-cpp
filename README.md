# C++ Amiral Battı Oyunu (Battleship Game) 🚢

Bu proje, C++ kullanılarak geliştirilmiş klasik Amiral Battı oyununun konsol tabanlı bir versiyonudur. Temel dizi operasyonları ve oyun mantığı üzerine odaklanmıştır.

## 🛠 Teknik Özellikler
* **Rastgele Gemi Yerleştirme:** Gemiler her oyunda `srand(time(0))` fonksiyonu ile rastgele konumlara yerleştirilir.
* **Akıllı Çevreleme Mantığı:** Gemilerin birbirine temas etmemesi için yerleştirilen geminin çevresi otomatik olarak işaretlenir ve çakışmalar önlenir.
* **Dinamik Harita Görünümü:** Kullanıcı vurduğu noktaları (x), boş hamlelerini (-) ve batırdığı gemileri (o) anlık olarak görebilir.
* **Girdi Doğrulama:** Kullanıcının harita dışı (1-8 dışı) giriş yapması veya aynı noktayı tekrar vurması gibi hatalı durumlar kontrol edilir.

## 🎮 Nasıl Oynanır?
1. Oyunu bir C++ derleyicisi ile derleyin.
2. Konsol ekranında size sorulan Satır ve Sütun değerlerini (1-8 arası) girin.
3. Toplam 8 gemiyi batırdığınızda oyun kazanılır ve toplam deneme sayınız görüntülenir.
