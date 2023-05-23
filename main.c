#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "methods.h"
int main()
{
    printf("****************** KISA BIR BILGILANDIRME ******************\n");
    printf("\nKarakteri hareket ettirmek icin 'w','a','s','d' tuslarini kullanmalisiniz!!! \n");
    printf("\nTahtada 5 elmas ve 5 asker vardir ve askerler elmaslardan 1 adim uzakta olacak sekilde yerlestirilmistir. \n");
    printf("\nIlk olarak 10 x 10 luk Tahtanin (2,4) adresindesiniz askere her hakalandiginizda basa doneceksiniz.\n");
    printf("\nElmaslara olan uzakliginiz altta sayi olarak verilecektir altta yazan sayi elmasa ulasmak icin atmaniz gerken minimum adim sayisini vermektedir.\n");
    printf("\nToplam 3 caniniz vardir anlik olarak gosterilecektir.\n");
    printf("\nHer asker yakalandiginizda 1 caniniz gidecek caniniz bitince oyunu kaybedeceksiniz.\n");
    printf("\nOyunu kazanmak icin yapmaniz gereken caniniz bitmeden tum elmaslari almaktir \n");
    printf("\nOyun bittiginde elmaslarin ve askerlerin konumu ekrana basilacaktir elmaslar '3' askerler '4' ile gosterilecektir \n" );
    printf("\n***Artik hazirsiniz oyuna baslamak icin herhangi bir tusa basin iyi sanslar ve iyi eglenceler. :) :) :) *** \n\n");
    getchar();
    system("cls");
    srand(time(NULL));
    degerleri_atama();
    konum_yazdir(o_satir, o_sutun);
    kontrol();
    getchar();
}
