#include <stdio.h>
#include <stdlib.h>

         // XDR toplamlarını bulma 
int xdr_toplam(int dizi[], int baslangic, int son) {
    int toplam = 0;
    for (int i = baslangic; i <= son; i++) {
        toplam ^= dizi[i];
    }
    return toplam;
}

int main() {
    int k;
    printf("Lutfen dizinin boyutunu giriniz: ");
    scanf("%d", &k);

         // Dizi elemanlarını alma
    int dizi[k];
    printf("Lutfen dizinin elemanlarini  giriniz:\n");
    for (int i = 0; i < k; i++) {
        scanf("%d", &dizi[i]);
    }

    // Her alt kümenin XDR toplamını hesaplayarak toplamların toplamını bulma
    int toplam = 0;
    for (int i = 0; i < k; i++) {
        for (int j = i; j < k; j++) {
            toplam += xdr_toplam(dizi, i, j);
        }
    }

    printf("Tum alt kumelerin XDR toplamlarinin toplami: %d\n", toplam);

    return 0;
}