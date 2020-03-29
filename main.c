#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Araba{
    int yakit;
    int mevcut_hiz;
    int dayaniklilik;
    float konumu;
    int kaza_kaydi;
};
struct Kullanici{
    char isim[20];
    int deneyim;
    struct Araba araba;
};
struct Kullanici *degerAta( struct Kullanici *p ){
    p->deneyim=0;
    p->araba.mevcut_hiz=20;
    p->araba.dayaniklilik=100;
    p->araba.yakit=100;
    p->araba.mevcut_hiz=20;
    p->araba.kaza_kaydi=0;

}

struct Kullanici *hizlan( struct Kullanici *p ){
    p->araba.mevcut_hiz+=5;
    p->araba.konumu+=((p->araba.mevcut_hiz)-(2.5));
    return p;
}
struct Kullanici *yakit_gunceli( struct Kullanici *p ){

    p->araba.yakit-=(p->araba.mevcut_hiz/5);
    return p;
}

struct Kullanici *yavasla( struct Kullanici *p ){
    p->araba.mevcut_hiz-=5;
    p->araba.konumu+=((p->araba.mevcut_hiz)+(2.5));
    return p;
}

int zarAt(){
    int rastgele;
    srand(time(NULL));
    rastgele=rand()%7;
    return rastgele;
}

struct Kullanici *yakit_kaybi(struct Kullanici *p){
    p->araba.yakit-=20;
return p;
}

struct Kullanici *kazayap(struct Kullanici *p){
    p->araba.kaza_kaydi+=1;
    p->araba.dayaniklilik-=(p->araba.kaza_kaydi*5);
    return p;
}

int main() {
    int secenek,zar=0;
    int tur=1;
    int x=0;
    struct Araba *tut;
    struct Kullanici user;
    tut=&user;
    degerAta(tut);
printf("Isminizi giriniz... ");
scanf("%s",&user.isim);
   while(1){
       if(user.araba.konumu>=100){
           printf("%s\n",user.isim);
           printf("Kazandin!!! Puanin:%d\n",user.deneyim);
           break;
       }
       else if(user.araba.dayaniklilik<50||user.araba.yakit<=0||user.deneyim<0){
           printf("Game Over x(\n");
           break;
       }
       //1.asama
       zar=zarAt();
       if(zar==1){
           printf("Hizlaniyorsun \n");
           hizlan(tut);
           user.deneyim+=10;

           printf("Mevcut hiz %d mevcut konum %f \n",user.araba.mevcut_hiz,user.araba.konumu);
       }
       else if (zar==2){
           printf("Yavasliyorsun \n");
           yavasla(tut);
           user.deneyim+=5;
           printf("Mevcut hiz %d mevcut konum %f \n",user.araba.mevcut_hiz,user.araba.konumu);
       }
       else if(zar==3){
           printf("-20 yakit \n");
           yakit_kaybi(tut);

           printf("Yakit %d \n",user.araba.yakit);
       }
       else if(zar==5||zar==4){
           printf("Kaza yaptin \n");
           kazayap(tut);

           if(tur!=1){
           user.deneyim-=10;
           }
           printf("Dayaniklilik %d \n",user.araba.dayaniklilik);
       }
       else{
           printf("Pas \n");
       }
       //2. asama
       yakit_gunceli(tut);

       printf("Yakit %d \n",user.araba.yakit);
       //3.asama
       while(1) {
           printf("Yapmak istediginiz islemi seceniz \n");
           printf("Secenekler\n1. 5 hizlan(1)\n2. 5 yavasla(2)\n3. 10 galon yakit ekle(3)\n4. cikis yap(0)");
           scanf("%d", &secenek);
           if (secenek == 1 && user.araba.mevcut_hiz <= 95) {
               hizlan(tut);
               user.deneyim += 10;
               printf("Mevcut hiz %d mevcut konum %f\n", user.araba.mevcut_hiz, user.araba.konumu);
               break;
           } else if (secenek == 2) {
               yavasla(tut);
               user.deneyim += 5;
               printf("Mevcut hiz %d mevcut konum %f\n", user.araba.mevcut_hiz, user.araba.konumu);
               break;
           } else if (secenek == 3) {
               user.araba.yakit += 20;
               user.araba.konumu += user.araba.mevcut_hiz;
               user.deneyim -= 3;
               printf("Mevcut hiz %d mevcut konum %f\n", user.araba.mevcut_hiz, user.araba.konumu);
               break;
           } else if (secenek == 0) {
               printf("Cikis yapiliyor...\n");
               x = 1;
               break;
           } else {
               printf("Fatal Error x( \n");
           }
       }
       if(x==1){
           break;
       }

   }


    return 0;
}
