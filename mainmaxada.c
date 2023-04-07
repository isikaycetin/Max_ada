#include <stdio.h>
#include <stdlib.h>
                                          
                                          
                     // Isikay Çetin 1220505031             
									      
#define SATIR 5     // Satýr ve sutun deðerlerini kendimiz verdik kullanýcýdan almadýk.
#define SUTUN 5

int max(int a, int b) {    // iki tamsayý paramtere olarak alýr ve bunlardan büyük olan tam sayýyý döndürür.
    if(a>b)
    return a;
    else 
    return b;
}
/* bir adadaki en büyük alaný bulmak için derinlik öncelikli arama (DFS) algoritmasýný kullanýbdýk.
Bu iþlev bir matris, iki tamsayý ve bir ziyaret edilmiþ hücreler matrisi alýr ve adadaki en büyük alaný hesaplar.*/
 
int DFS(int parca[][SUTUN], int i, int j, int ziyaret[][SUTUN]) {                            
    if (i < 0 || i >= SATIR || j < 0 || j >= SUTUN || ziyaret[i][j] || !parca[i][j]) {       // Eðer koordinatlar geçersizse veya hücre denizse 0 döndür.
        return 0;
    }

    ziyaret[i][j] = 1;                      // ziyaret edilen hücre olarak hesaplanýr.
                                                          
    return 1 +                                            // Dört yönde dolaþýr ve komþu hücreleri kontrol eder.
	DFS(parca, i + 1, j, ziyaret) +   // Güney
	DFS(parca, i - 1, j, ziyaret) +   // Kuzey
    DFS(parca, i, j + 1, ziyaret) +   // Doðu
	DFS(parca, i, j - 1, ziyaret);    // Batý
}

// En büyük adanýn boyutunu hesaplayan ana fonksiyon
int maxAlanBul(int parca[][SUTUN]) {                    // Bu fonksiyon ise en büyük olan adanýn alanýný hesaplar.
    int maxAlan=0;           // ada büyüklüðü için deðiþken oluþturduk.
    int i,j;
    int ziyaret[SATIR][SUTUN] =  {0} ;                  // ziyaret edilen hücreleri takip etmek için matris oluþturulur.

    for (i = 0; i < SATIR; i++) {
        for (j = 0; j < SUTUN; j++) {
            if (parca[i][j] && !ziyaret[i][j]) {                    // 1 deðerine sahip, ziyaret edilmemiþ bir hücre bulunursa
                int alan = DFS(parca, i, j, ziyaret);
                maxAlan = max(maxAlan, alan);     // adanýn alaný hesaplanýr.
            } 
        }
    }

    return maxAlan;                                   // max alaný döndürür.
}

int main() {
    int parca[SATIR][SUTUN] = {{1, 1, 0, 0, 0},
                             {1, 1, 0, 0, 1},
                             {0, 1, 0, 1, 1},
                             {0, 1, 0, 0, 0},
				     	     {1, 1, 0, 0, 1}, };

    printf("En buyuk ada yuzolcumu: %d", maxAlanBul(parca));

    return 0;
}

