#include <stdio.h>
#include <stdlib.h>
                                          
                                          
                     // Isikay �etin 1220505031             
									      
#define SATIR 5     // Sat�r ve sutun de�erlerini kendimiz verdik kullan�c�dan almad�k.
#define SUTUN 5

int max(int a, int b) {    // iki tamsay� paramtere olarak al�r ve bunlardan b�y�k olan tam say�y� d�nd�r�r.
    if(a>b)
    return a;
    else 
    return b;
}
/* bir adadaki en b�y�k alan� bulmak i�in derinlik �ncelikli arama (DFS) algoritmas�n� kullan�bd�k.
Bu i�lev bir matris, iki tamsay� ve bir ziyaret edilmi� h�creler matrisi al�r ve adadaki en b�y�k alan� hesaplar.*/
 
int DFS(int parca[][SUTUN], int i, int j, int ziyaret[][SUTUN]) {                            
    if (i < 0 || i >= SATIR || j < 0 || j >= SUTUN || ziyaret[i][j] || !parca[i][j]) {       // E�er koordinatlar ge�ersizse veya h�cre denizse 0 d�nd�r.
        return 0;
    }

    ziyaret[i][j] = 1;                      // ziyaret edilen h�cre olarak hesaplan�r.
                                                          
    return 1 +                                            // D�rt y�nde dola��r ve kom�u h�creleri kontrol eder.
	DFS(parca, i + 1, j, ziyaret) +   // G�ney
	DFS(parca, i - 1, j, ziyaret) +   // Kuzey
    DFS(parca, i, j + 1, ziyaret) +   // Do�u
	DFS(parca, i, j - 1, ziyaret);    // Bat�
}

// En b�y�k adan�n boyutunu hesaplayan ana fonksiyon
int maxAlanBul(int parca[][SUTUN]) {                    // Bu fonksiyon ise en b�y�k olan adan�n alan�n� hesaplar.
    int maxAlan=0;           // ada b�y�kl��� i�in de�i�ken olu�turduk.
    int i,j;
    int ziyaret[SATIR][SUTUN] =  {0} ;                  // ziyaret edilen h�creleri takip etmek i�in matris olu�turulur.

    for (i = 0; i < SATIR; i++) {
        for (j = 0; j < SUTUN; j++) {
            if (parca[i][j] && !ziyaret[i][j]) {                    // 1 de�erine sahip, ziyaret edilmemi� bir h�cre bulunursa
                int alan = DFS(parca, i, j, ziyaret);
                maxAlan = max(maxAlan, alan);     // adan�n alan� hesaplan�r.
            } 
        }
    }

    return maxAlan;                                   // max alan� d�nd�r�r.
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

