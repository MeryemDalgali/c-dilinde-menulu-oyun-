#include <stdio.h>
#include <stdlib.h>
#include <time.h> // zaman için 
#include <math.h>
int game1();
int game2();
 int main()
  
 {
   int secim;  // Kullanicinin secimi 

    while (1)  // Sonsuz dongu
    {
        printf("Oyun Secim Menusu\n");
        printf("1. Oyun 1\n");
        printf("2. Oyun 2\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        if (secim == 1)  // Eger secim 1 ise

            game1();  // Oyun 1 fonksiyonunu cagırır
        
        else if (secim == 2)  // Eger secim 2 ise
        
            game2();  // Oyun 2 fonksiyonunu cagırır 
            
 } 
 return 0;
 } 
  
  
int game1()  // Oyun 1 fonksiyonu

{

    float konum;  // Dusman hedef konumu
    float shot;  // Kullanicinin vurusu
    int error;  // Vurus hata miktari
    int score = 0;  
    int basarili_atis = 0;  
    int yakin_atis = 0;  
    float atisin_isabet_orani; 
    //float a;

    for (int i = 1; i <= 4; i++)  // 10 atis yap
    {
        srand(time(0)); // Rastgele sayi uretmek icin  
        konum =5.0;  //rand() % 10 + 1;  // Dusman konumunu random olarak ayarla (1-10 arasi)
        printf("\nDusman belirdi...\n");
       // printf("dusman : %2.1f\n", konum); 
        printf("%d.atis icin dusmanin konumunu tahmin ediniz: ", i); // kullanicidan tahmin aldik 
        scanf("%f", &shot);

        
    
        atisin_isabet_orani =fabs(konum - shot);  // Vurus hata miktarini hesaplayan fonksiyon (mutlak deger)
        /*atisin_isabet_orani= a;
        if (a<0) { 
        atisin_isabet_orani= a*(-1);
        } */

        if (atisin_isabet_orani == 0.0)  // eger vurus basariliysa
        {
            score += 10;  // Puani 10 arttir
            basarili_atis++;  // Basarili vurus sayisini bir artttir
            printf("Tebrikler dogru tahmin! +10 puan kazandin!\n");
            printf("Basarili atis sayiniz %d oldu :)\n", basarili_atis); 
        }
  else if (atisin_isabet_orani <= 0.5)  // eger vurus hata miktarı 0.5 den kucuk ise 
        {  score += 5;  // Puani 5 arttir 
            yakin_atis++;  // Yakin vurus sayisini bir arttır
            printf("Cok yaklastin 5 puan kazandin!\n");
            printf ("Yakin atis sayiniz %d oldu ;)\n ", yakin_atis);
        }
        else if (atisin_isabet_orani > 0.5)
        {   score += 0;  // puani 0 arttir
            error++; // basarisiz vurus sayisini 1 arttir
            printf("Yanlis tahmin! Puan kazanamadin!\n");
            printf("Hata sayiniz %d oldu :(\n ", error);
        }   
     
        
         
    } 
    
     printf("\n**Toplam skorunuz : %d\n", score); 
     printf("**Toplam hataniz: %d\n ", error);
     printf("*Basarili atis sayiniz: %d\n ", basarili_atis);
     printf("*Yakin atis sayiniz: %d\n", yakin_atis);
   
     
    
    return 0; 
}


int game2() // Oyun 2 fonksiyonu  
{
   int random, tahmin, hint[3], i, score = 100;

  // 3 basamakli rakamları birbirinden farklı bir sayi üret 
 /*while (1)  // sonsuz döngü 
 { 
  random = rand() %900 +100 ; // 100 ile 999 arasında rastgele bir sayı üret
  if (random / 100 != random % 10 && (random / 10) % 10 != random / 100 && (random / 10) % 10 != random % 10) // rakamları birbirinden farkli uc basamakli sayi  
    break; // döngüden çık
 }*/ 
 random=693;

  // 10 hakkimiz var
   for (i = 0; i < 10; i++) 
{
   printf("Lutfen 3 basamakli bir tahmin sayisi giriniz: ");
   scanf("%d", &tahmin);
 // Tahmin edilen sayi ile uretilen sayiyi karsilastir ve ipucu sayisi olustur   veya || ile gosterilir
hint[0] = (tahmin / 100 == random / 100) ? 1 : ((tahmin / 100 == (random / 10) % 10 || tahmin/ 100 == random % 10) ? 9 : 0);
hint[1] = ((tahmin / 10) % 10 == (random / 10) % 10) ? 1 : (((tahmin / 10) % 10 == random / 100 || (tahmin/ 10) % 10 == random % 10) ? 9 : 0);
hint[2] = (tahmin % 10 == random % 10) ? 1 : ((tahmin % 10 == random / 100 || tahmin % 10 == (random / 10) % 10) ? 9 : 0);

printf("Ipucu sayiniz: %d%d%d\n", hint[0], hint[1], hint[2]);
// Tahmin dogruysa donguyu ve oyunu bitir
   if (tahmin == random) 
   {
  printf("Tebrikler! Dogru tahmin ettiniz! Skorunuz: %d\n", score);
  break;
   }

       // Tahmin yanlissa skoru azalt
  score -= 10;
}

// Tahmin haklari bittiyse oyunu bitir
if (i == 10)  
{
printf("Tahmin haklariniz bitti. Uzgunuz, kaybettiniz. Skorunuz: %d\n", score);
}

return 0;
}
