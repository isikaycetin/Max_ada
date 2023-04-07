# Max_ada

Amac:

MxN ikili matris olduğunu düşünürsek bu matrisin değerleri 0 sa deniz, 1 se karayı ifade etsin. 
Bir adanın alanı, adada 1 değerine sahip hücrelerin sayısıdır. Verilen matristeki bir adanın maksimum alanını döndürür. Ada yoksa 0 döndürür.
Buna göre 1 lerden olusan en büyük alanı bulan c kodu

Calisma Sekli:

Bu matriste yer alan adalardan en büyüğünün yüzölçümünü hesaplamak için bir DFS(Derinlik Öncelikli Arama) algoritması kullanılır.
İlk olarak, DFS fonksiyonu bir adanın bir hücresinden başlayarak, diğer adanın tüm hücrelerine kadar ilerler ve bir adanın yüzölçümünü hesaplar.
DFS fonksiyonu, işlemi devam ettirirken matrisin sınırlarına ulaştığında ya da zaten ziyaret edilmiş bir hücreye ulaştığında durur.
Daha sonra ana fonksiyon olan "maxAlanBul" fonksiyonu, DFS fonksiyonunu çağırarak, matristeki tüm adaların yüzölçümlerini hesaplar ve 
ardından en büyük adanın yüzölçümünü döndürür.
Ana fonksiyon, bir matrisi oluşturur, "maxAlanBul" fonksiyonunu çağırır ve sonucunu yazdırarak programın sonlandırır.
