#ifndef proje
#define proje
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void degerleri_atama();     // tahtaya elmas ve askerlerin yerleştirildiği method
void elmas_Atama(int);      // elmasları tahtadaki konumlarına atama yapılan method
void asker_Atama(int);      // askerlerin tahtadaki konumlarına atama yapılan method
void asker_kontrol(int);    // oyuncunun askerlere yakalanıp yakalanmmadığını kontrol eden method
int konum_yazdir(int, int); // o andaki tahtayı ve oyuncunun konumunu yazdıran method
void hareket();             // klavyeden girdi alınıp oyuncunun ilerlemesini sağlayan method
void E_kalan_mesafe();      // oyuncu ile elmaslar arasındaki mesafeyi hesaplayıp yazdıran method
void kontrol();             // oyuncunun tüm yıldızları alıp almadığını kontrol raden kod
void ata();                 // elmasların ne kadar ilerleyeceğini diziden random olarak seçen method
int arr[] = {-1, 0, 1};     // askerlerin random olarak yerleştirmek için ne kadar ilerlemesinin gerktiğinin seçildiği dizi
int satir = 0;
int sutun = 0;
int o_satir = 2;
int o_sutun = 4;
int can = 3;           // oyuncunun canı
int ilk_durum[10][10]; // en sonda oyunun ilk halini ekrana bastırmak için oluşturduğum dizi
int tahta[10][10];     // 10 x 10 boyutunda oyun alanı
int deger[5];
char secim;     // oyuncunun hareket yönü değişkeni
struct askerler // askerlerin adresini tutmak için kullandığım struct yapısı
{
    int A_satir;
    int A_sutun;
};
typedef struct askerler asker; // askerleri daha rahat tanımlamak için yaptığım tip dönüşümü
struct elmaslar                // elmaslsarın adresini tutmak için kullandığım struct yapısı
{
    int E_satir;
    int E_sutun;
};
typedef struct elmaslar elmas; // elmasları daha rahat tanımlamak için yaptığım tip dönüşümü
asker askerler[5];             // asker tipinde oluşturulan ifadeler
elmas elmaslar[5];             // elmas tipinde oluşturulan ifadeler
void degerleri_atama()
{
    tahta[o_satir][o_sutun] = 1;

    for (int e = 0; e < 5; e++) 
    {
        do
        {
            elmas_Atama(e);
        } while (tahta[elmaslar[e].E_satir][elmaslar[e].E_sutun] != 0);

        tahta[elmaslar[e].E_satir][elmaslar[e].E_sutun] = 3;
    }
    for (int a = 0; a < 5; a++)
    {
        do
        {
            asker_Atama(a);
        } while (askerler[a].A_satir == -1 || askerler[a].A_satir == 10 || askerler[a].A_sutun == -1 || askerler[a].A_sutun == 10 || askerler[a].A_sutun == 4 && askerler[a].A_satir == 2);
        tahta[askerler[a].A_satir][askerler[a].A_sutun] = 4;
    }
    memcpy(ilk_durum, tahta, sizeof(tahta)); // tahta' nın içindeki her şeyi ilk_durum' a kopyalayan kod
    for (int i = 0; i < 5; i++)              // elmasları ve askerleri gizleyen kod
    {
        tahta[askerler[i].A_satir][askerler[i].A_sutun] = 0;
        tahta[elmaslar[i].E_satir][elmaslar[i].E_sutun] = 0;
    }
}
void elmas_Atama(int i)
{
    deger[i] = 3;
    elmaslar[i].E_satir = rand() % 10;
    elmaslar[i].E_sutun = rand() % 10;
}
void ata()
{
    do
    {
        satir = rand() % 3;
        sutun = rand() % 3;
    } while (satir == 1 && sutun == 1);
}
void asker_Atama(int i)
{
    ata();
    askerler[i].A_satir = elmaslar[i].E_satir + arr[satir];
    askerler[i].A_sutun = elmaslar[i].E_sutun + arr[sutun];
}
void asker_kontrol(int i)
{
    if (o_satir == askerler[i].A_satir)
    {
        if (o_sutun == askerler[i].A_sutun)
        {
            can--;
            if (can > 0)
            {
                tahta[o_satir][o_sutun] = 0; // oyuncunun yakalandığı yeri silen kod
                o_satir = 2;
                o_sutun = 4;
                printf("\n*** Muhafiza yakalandiniz devan etmek icin herhangi bir tusa basin!!! ***\n\n");
                getch();
                konum_yazdir(o_satir, o_sutun);
            }
            else
            {
                system("cls");
                printf("Caniniz bittigi icin Oyunu kaybettiniz!!! :( :( :( :( :( :( \n ");
                int k = 0;
                while (k < 10) // tahtanın üst index değerleri için yazılmış döngü
                {
                    if (k == 0)
                    {
                        printf("   ");
                    }
                    printf(" _%d_", k);
                    k++;
                }
                printf("\n");

                for (int i = 0; i < 10; i++)
                {
                    printf("%d: |", i); // tahtanın sol index değerleri için yazılmış ifade
                    for (int j = 0; j < 10; j++)
                    {
                        printf("_%d_|", ilk_durum[i][j]); // tahtanın içini yazdıran ifade
                    }
                    printf("\n");
                }
                printf("\n");
            }
        }
    }
}
int konum_yazdir(int g_satir, int g_sutun)
{
    system("cls");
    printf("Karakteri hareket ettirmek icin 'w','a','s','d' tuslarini kullanmalisiniz!!! \n\n");
    tahta[o_satir][o_sutun] = 1; // oyuncuya 1 değeri atanıp tahtada fark edilmesi sağlanmıştır
    int k = 0;
    while (k < 10) // tahtanın üst index değerleri için yazılmış döngü
    {
        if (k == 0)
        {
            printf("   ");
        }
        printf(" _%d_", k);
        k++;
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d: |", i); // tahtanın sol index değerleri için yazılmış ifade
        for (int j = 0; j < 10; j++)
        {
            printf("_%d_|", tahta[i][j]); // tahtanın içini yazdıran ifade
        }
        printf("\n");
    }
    printf("\n");
    printf("su anki konumunuz: (%d,%d) \n", o_satir, o_sutun); // anlık kkonumu yazdıran kod
}
void hareket()
{
    printf("Gitmek istediginiz yonu girin: ");
    secim = getche();
    printf("\n");
    if (secim == 'w' || secim == 'W' || secim == 'a' || secim == 'A' || secim == 's' || secim == 'S' || secim == 'd' || secim == 'D')
    {
        switch (secim)
        {
        case 'w':
            if (o_satir != 0) // bu ifade oyuncunun tahta dışına çıkmasını önlüyor
            {
                o_satir = o_satir - 1;           // oyuncuyu 1 adım yukarı ilerleten kod
                tahta[o_satir + 1][o_sutun] = 0; // karakterin eski yerine 0 yazıyor
                konum_yazdir(o_satir, o_sutun);  // yeni konumu yazdırıyor
            }
            else
            {
            printf("Lutfen tahtanin disina cikmayin!!!\n"); // tahtanın dışına çıkılmaması için ekrana basılan geri bildirim
            }
            break;
        case 'W':
            if (o_satir != 0) // bu ifade oyuncunun tahta dışına çıkmasını önlüyor
            {
                o_satir = o_satir - 1;           // oyuncuyu 1 adım yukarı ilerleten kod
                tahta[o_satir + 1][o_sutun] = 0; // karakterin eski yerine 0 yazıyor
                konum_yazdir(o_satir, o_sutun);  // yeni konumu yazdırıyor
            }
            else
            {
            printf("Lutfen tahtanin disina cikmayin!!!\n"); // tahtanın dışına çıkılmaması için ekrana basılan geri bildirim
            }
            break;
        case 'a':
            if (o_sutun != 0)
            {
                o_sutun = o_sutun - 1; // bir adım sola ilerleten kod
                tahta[o_satir][o_sutun + 1] = 0;
                konum_yazdir(o_satir, o_sutun);
            }
            else
            {
                printf("Lutfen tahtanin disina cikmayin!!!\n");
            }
            break;
        case 'A':
            if (o_sutun != 0)
            {
                o_sutun = o_sutun - 1; // bir adım sola ilerleten kod
                tahta[o_satir][o_sutun + 1] = 0;
                konum_yazdir(o_satir, o_sutun);
            }
            else
            {
                printf("Lutfen tahtanin disina cikmayin!!!\n");
            }
            break;
        case 's':
            if (o_satir != 9)
            {
                o_satir = o_satir + 1; // bir adım aşağı ilerleten kod
                tahta[o_satir - 1][o_sutun] = 0;
                konum_yazdir(o_satir, o_sutun);
            }
            else
            {
                printf("Lutfen tahtanin disina cikmayin!!!\n");
            }
            break;
        case 'S':
            if (o_satir != 9)
            {
                o_satir = o_satir + 1; // bir adım aşağı ilerleten kod
                tahta[o_satir - 1][o_sutun] = 0;
                konum_yazdir(o_satir, o_sutun);
            }
            else
            {
                printf("Lutfen tahtanin disina cikmayin!!!\n");
            }
            break;
        case 'd':
            if (o_sutun != 9)
            {
                o_sutun = o_sutun + 1; // bir adım sola ilerleten kod
                tahta[o_satir][o_sutun - 1] = 0;
                konum_yazdir(o_satir, o_sutun);
            }
            else
            {
                printf("Lutfen tahtanin disina cikmayin!!!\n");
            }
            break;
        case 'D':
            if (o_sutun != 9)
            {
                o_sutun = o_sutun + 1; // bir adım sola ilerleten kod
                tahta[o_satir][o_sutun - 1] = 0;
                konum_yazdir(o_satir, o_sutun);
            }
            else
            {
                printf("Lutfen tahtanin disina cikmayin!!!\n");
            }
            break;
        }
        for (int i = 0; i < 5; i++)
        {
            asker_kontrol(i);
        }
    }
    else
    {
        printf("Hatali giris yaptiniz Tekrar girin!!! \n"); // hatalı karakter girildiğinde ekrana basılan geri bildirim
    }
}
void E_kalan_mesafe()
{
    printf(" %d caniniz var!!!\n", can); // oyuncunun canını yazdıran kod
    for (int i = 0; i < 5; i++)
    {
        if (elmaslar[i].E_satir != o_satir || elmaslar[i].E_sutun != o_sutun) // elmasın üzerine gelene kadar yazdırmayı sağlayan kod
        {
            if (deger[i] == 3)
            {
                printf("%d. Elmasa olan uzakliginiz : %d\n", i + 1, abs(o_satir - elmaslar[i].E_satir) + abs(o_sutun - elmaslar[i].E_sutun));
            }
            else
            {
                printf("%d. Elmasi aldiniz!!!\n", i + 1); // elması ilk aldığında çalışan kod
            }
        }
        else
        {
            deger[i] = 0;
            printf("%d. Elmasi aldiniz!!!\n", i + 1); // elması aldıktan sonra çalışan kod
        }
    }
}
void kontrol()
{
    do
    {
        E_kalan_mesafe();
        hareket();
        int sayac = 0;
        for (int i = 0; i < 5; i++)
        {
            if (deger[i] == 0)
            {
                sayac++;
            }
        }
        if (sayac == 5)
        {
            system("cls");
            printf(" *** Tebrikler oyunu kazandiniz... *** :) :) :) \n ");
            int k = 0;
            while (k < 10) // tahtanın üst index değerleri için yazılmış döngü
            {
                if (k == 0)
                {
                    printf("   ");
                }
                printf(" _%d_", k);
                k++;
            }
            printf("\n");
            for (int i = 0; i < 10; i++)
            {
                printf("%d: |", i); // tahtanın sol index değerleri için yazılmış ifade
                for (int j = 0; j < 10; j++)
                {
                    printf("_%d_|", ilk_durum[i][j]); // tahtanın içini yazdıran ifade
                }
                printf("\n");
            }
            printf("\n");
            break;
        }
    } while (can > 0);
}
#endif
