/*
 * 5x7DotMatrix.c
 * 7x10 boyutunda ayn� harfleri 2 adet 5x7 dot matrixinde g�steren uygulama.
 * Versiyon g�ncellemesi ile kayan yaz� ve lookup tablosu gibi �eyler gelecek.
 * Yeterli bilgiye eri�ti�imde d��ar�dan girilen kelimeleri g�sterecek.
 * Created: 14.12.2020 18:10:46
 * Author : Emre
 */ 
#include "src/CONFIG.h" // Yap�land�rma ba�l�k dosyas� eklendi.T�m algoritma burada.



int main(void)//Ana fonksiyonumuz
{
	GPIO_init();//Genel ama�l� giri� ��k�� pinlerinin giri�-��k�� yap�land�rmas�.
	satir = 0; // sat�r tarama i�in gereken 0-7 aras�ndaki de�er atama ba�lang�c�

	
	 while (1) //sonsuz d�ng�
	 { 
		EMRE();
		alfabe();
		emoji();
		/*
		tan�mlanm�� fonksiyonlar
		*/
	 }
    
		
}


