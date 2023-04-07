#include <stdio.h>
#include <stdlib.h>
                            /* En Büyük Ada Yüzölçümü.m x n ikili matris olduğunu düşünün.Bu matrisin değerleri 0 sa deniz, 1 se karayı ifade etmektedir. 
	               Bir adanın alanı, adada 1 değerine sahip hücrelerin sayısıdır.Verilen matristeki bir adanın maksimum alanını döndürür. 
				                            Ada yoksa 0 döndürür. */  
				   
 // Isikay Çetin 1220505031             
									      
#define SATIR 5     // Satır ve sutun değerlerini kendimiz verdik kullanıcıdan almadık.
#define SUTUN 5

int max(int a, int b) {    // iki tamsayı paramtere olarak alır ve bunlardan büyük olan tam sayıyı döndürür.
    if(a>b)
    return a;
    else 
    return b;
}
/* bir adadaki en büyük alanı bulmak için derinlik öncelikli arama (DFS) algoritmasını kullanıbdık.
Bu işlev bir matris, iki tamsayı ve bir ziyaret edilmiş hücreler matrisi alır ve adadaki en büyük alanı hesaplar.*/
 
int DFS(int parca[][SUTUN], int i, int j, int ziyaret[][SUTUN]) {                            
    if (i < 0 || i >= SATIR || j < 0 || j >= SUTUN || ziyaret[i][j] || !parca[i][j]) {       // Eğer koordinatlar geçersizse veya hücre denizse 0 döndür.
        return 0;
    }

    ziyaret[i][j] = 1;                      // ziyaret edilen hücre olarak hesaplanır.
                                                          
    return 1 +                                            // Dört yönde dolaşır ve komşu hücreleri kontrol eder.
	DFS(parca, i + 1, j, ziyaret) +   // Güney
	DFS(parca, i - 1, j, ziyaret) +   // Kuzey
        DFS(parca, i, j + 1, ziyaret) +   // Doğu
	DFS(parca, i, j - 1, ziyaret);    // Batı
}

// En büyük adanın boyutunu hesaplayan ana fonksiyon
int maxAlanBul(int parca[][SUTUN]) {                    // Bu fonksiyon ise en büyük olan adanın alanını hesaplar.
    int maxAlan=0;           // ada büyüklüğü için değişken oluşturduk.
    int i,j;
    int ziyaret[SATIR][SUTUN] =  {0} ;                  // ziyaret edilen hücreleri takip etmek için matris oluşturulur.

    for (i = 0; i < SATIR; i++) {
        for (j = 0; j < SUTUN; j++) {
            if (parca[i][j] && !ziyaret[i][j]) {                    // 1 değerine sahip, ziyaret edilmemiş bir hücre bulunursa
                int alan = DFS(parca, i, j, ziyaret);
                maxAlan = max(maxAlan, alan);     // adanın alanı hesaplanır.
            } 
        }
    }

    return maxAlan;                                   // max alanı döndürür.
}

int main() {
    int parca[SATIR][SUTUN] ={{1, 1, 0, 0, 0},                    // Bunları kendim girdim kullanıcıdan almadım.
                              {1, 1, 0, 0, 1},
                              {0, 1, 0, 1, 1},
                              {0, 1, 0, 0, 0},
		              {1, 1, 0, 0, 1}, };

    printf("En buyuk adanin yuzolcumu: %d", maxAlanBul(parca));

    return 0;
}

