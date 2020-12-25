/*
 * 5x7DotMatrix.c
 * 7x10 boyutunda ayný harfleri 2 adet 5x7 dot matrixinde gösteren uygulama.
 * Versiyon güncellemesi ile kayan yazý ve lookup tablosu gibi þeyler gelecek.
 * Yeterli bilgiye eriþtiðimde dýþarýdan girilen kelimeleri gösterecek.
 * Created: 14.12.2020 18:10:46
 * Author : Emre
 */ 
#include "src/CONFIG.h" // Yapýlandýrma baþlýk dosyasý eklendi.Tüm algoritma burada.



int main(void)//Ana fonksiyonumuz
{
	GPIO_init();//Genel amaçlý giriþ çýkýþ pinlerinin giriþ-çýkýþ yapýlandýrmasý.
	satir = 0; // satýr tarama için gereken 0-7 arasýndaki deðer atama baþlangýcý

	
	 while (1) //sonsuz döngü
	 { 
		EMRE();
		alfabe();
		emoji();
		/*
		tanýmlanmýþ fonksiyonlar
		*/
	 }
    
		
}


