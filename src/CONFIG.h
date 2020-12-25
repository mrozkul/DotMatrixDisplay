/*
 * CONFIG.h
 *
 * Created: 20.12.2020 18:23:29
 *  Author: Emre
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#ifndef F_CPU
#define F_CPU 16000000UL // Þayet tanýmlanmadýysa kristalin frekans deðerini tanýmladýk.
#endif

#include <avr/io.h> // Avr'nin input-output kütüphanesini ekledik.
#include <util/delay.h> // Bekleme kütüphanesini ekledik.
#include <avr/interrupt.h> // Versiyon güncellemesinde lazým olacaðý için kesme kütüphanesini ekledik.
#include "_328P_GPIO_.h" // GPIO baþlýk dosyamýzý ekledik.


/* Registerlara ulaþabilmek için öniþlemci
tanýmlamasý yaptýk. Bu sayede yapýlarla uðraþmamýz gerekmeyecek. */

#define __DDRB			GPIO._DDRB_.port		
#define __PORTB			GPIO._PORTB_.port
#define __DDRD			GPIO._DDRD_.port
#define __PORTD			GPIO._PORTD_.port	
#define DATA			GPIO._PORTB_.pins.pin0
#define CLOCK			GPIO._PORTB_.pins.pin1
#define LATCH			GPIO._PORTB_.pins.pin2
#define led				GPIO._PORTB_.pins.pin3	

	
#define delay			2750UL  //Satýr tarama için bekleme süresi tanýmladýk.

/*Fonksiyon prototiplerini tanýmladýk. */

void GPIO_init();
void clock_pulse();
void latch_pulse();
void hex_to_bin(uint8_t);
void satir_tarama(uint8_t);
void alfabe();
void EMRE();
void emoji();

/*Deðiþken tanýmladýk.*/

volatile uint16_t milisaniye;
volatile uint8_t satir;
uint8_t toplam_satir=29;

uint8_t binary[8]; //Geçici dizi tanýmladýk.

uint8_t ALFABE[][8]=
{
	{0x04,0x0A,0x11,0x11,0x1F,0x11,0x11,0x00},//A
	{0x1E,0x11,0x11,0x1E,0x11,0x11,0x1E,0x00},//B
	{0x0F,0x10,0x10,0x10,0x10,0x10,0x0F,0x00},//C
	{0x0F,0x10,0x10,0x10,0x10,0x0F,0x04,0x00},//Ç
	{0x1E,0x11,0x11,0x11,0x11,0x11,0x1E,0x00},//D
	{0x1F,0x10,0x10,0x1F,0x10,0x10,0x1F,0x00},//E
	{0x1F,0x10,0x10,0x1F,0x10,0x10,0x10,0x00},//F
	{0x0F,0x10,0x10,0x17,0x15,0x11,0x0F,0x00},//G
	{0x04,0x0F,0x10,0x17,0x15,0x11,0x0E,0x00},//Ð
	{0x11,0x11,0x11,0x1F,0x11,0x11,0x11,0x00},//H
	{0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00},//I
	{0x04,0x00,0x04,0x04,0x04,0x04,0x04,0x00},//Ý
	{0x10,0x10,0x10,0x10,0x10,0x11,0x0E,0x00},//J
	{0x11,0x12,0x14,0x18,0x14,0x12,0x11,0x00},//K
	{0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0x00},//L
	{0x11,0x1B,0x15,0x11,0x11,0x11,0x11,0x00},//M
	{0x11,0x11,0x19,0x15,0x13,0x11,0x11,0x00},//N
	{0x0E,0x11,0x11,0x11,0x11,0x11,0x0E,0x00},//O
	{0x0A,0x0E,0x11,0x11,0x11,0x11,0x0E,0x00},//Ö
	{0x1E,0x11,0x11,0x1E,0x10,0x10,0x10,0x00},//P
	{0x1E,0x11,0x11,0x1E,0x14,0x12,0x11,0x00},//R
	{0x0F,0x10,0x10,0x0E,0x01,0x01,0x1E,0x00},//S
	{0x0F,0x10,0x1E,0x01,0x1E,0x04,0x00,0x00},//Þ
	{0x1F,0x04,0x04,0x04,0x04,0x04,0x04,0x00},//T
	{0x11,0x11,0x11,0x11,0x11,0x11,0x0E,0x00},//U
	{0x0A,0x00,0x11,0x11,0x11,0x11,0x0E,0x00},//Ü
	{0x11,0x11,0x11,0x11,0x11,0x0A,0x04,0x00},//V
	{0x11,0x11,0x11,0x1F,0x01,0x01,0x1F,0x00},//Y
	{0x1F,0x01,0x02,0x04,0x08,0x10,0x1F,0x00},//Z
};
uint8_t __EMRE[4][8]=
{
	{0x1F,0x10,0x10,0x1F,0x10,0x10,0x1F,0x00},//E
	{0x11,0x1B,0x15,0x11,0x11,0x11,0x11,0x00},//M
	{0x1E,0x11,0x11,0x1E,0x14,0x12,0x11,0x00},//R
	{0x1F,0x10,0x10,0x1F,0x10,0x10,0x1F,0x00}//E
};

uint8_t __emoji[][8]=
{
	{0x00,0x0A,0x00,0x11,0x0E,0x00,0x00,0x00},//:)
	{0x00,0x0A,0x00,0x00,0x0E,0x11,0x00,0x00},//:(
	{0x00,0x0A,0x00,0x00,0x1F,0x00,0x00,0x00},//:|
};



void GPIO_init()
{
	__DDRB = PORT_OUTPUT; // DDRD registeri çýkýþ olarak ayarlandý.
	__DDRD = PORT_OUTPUT; // DDRB registeri çýkýþ olarak ayarlandý.
	__PORTD = PORT_HIGH; // PORTD registerýnýn her biti 1 yapýldý. (255) 
	__PORTB = PORT_LOW; // PORTB registerýnýn her biti 0 yapýldý.
}

/*Shift register'a 1 adet clock pulse göndermek için fonksiyon.*/
void clock_pulse()
{
	CLOCK = 1;	
	_delay_us(1);
	CLOCK = 0;
}

/*Shift registerdaki veriyi çýkýþa aktarabilmek için 1 pulse darbesi veriyoruz.*/
void latch_pulse()
{
	LATCH = 1;
	_delay_us(delay); // Burada ki delay satýr tarama için gerekli olan süre.
	LATCH = 0;
}

/*Hexadecimal olarak aldýðý bilgiyi geçici diziye binary olarak atan fonksiyon.*/
void hex_to_bin(uint8_t hex_sayi) //uint8_t = 0-255 arasý deðer alýr. 
{
	uint8_t i,j; // Döngü için gerekli olan deðiþkenler.
	
	for (i=0;i<8;i++) // Burada 8 bitlik bir sayý için 8 degeri girildi.
	{
		/*
		Burada bit shifting yani bit kaydýrma operatörü ile 
		0-7 ye kadar kaydýrýyor. Kaydýrýlan deðeri j deðiþkenine 
		atýyor.Bu iþlem 8 defa sürüyor.
		*/
		j = hex_sayi >> i;
		
		
		if (j & 1)
		binary[i] = 1;
		else
		binary[i] = 0;
		
		/*
			j eðer bit bazýnda 1'e eþitse geçici dizinin i'ninci elemanýna
			1 yazýlýyor. Deðilse i'ninci elemanýna 0 yazýlýyor.
		*/
		
	}
}

void satir_tarama(uint8_t x) //Ýlgili satýrý yakmak için oluþturulan fonksiyon.
{
	
	switch (x)
	{
		/*Dot Matrix ortak anot olduðu için ilgili satýrý lojik 0 yapmak gerekiyor.*/
		
		case 0:
		__PORTD = 126; //Eðer x == 0 ' a eþitse PORTD = 01111110
		break;
		
		case 1:
		__PORTD = 125; //Eðer x == 1 ' a eþitse PORTD = 01111101
		break;
		
		case 2:
		__PORTD = 123; //Eðer x == 2 ' a eþitse PORTD = 01111011
		break;
		
		case 3:
		__PORTD = 119; //Eðer x == 3 ' a eþitse PORTD = 01110111
		break;
		
		case 4:
		__PORTD = 111; //Eðer x == 4 ' a eþitse PORTD = 01101111
		break;
		
		case 5:
		__PORTD = 95; //Eðer x == 5 ' a eþitse PORTD = 01011111
		break;
		
		case 6:
		__PORTD = 63; //Eðer x == 6 ' a eþitse PORTD = 00111111
		break;
	}
}

void alfabe()
{
	for (uint8_t i=0;i<toplam_satir;i++) //Satýr bilgisinin kaç adet olduguna göre þart koþtuk.
	{
		for (uint8_t tekrar = 0;tekrar < 100;tekrar++) //Ekranda harflerin belli bir süre durmasýný saðlamak için döngü.
		{
			for (uint8_t j=0;j<7;j++) //Matrixin sütünlarýný okumamýz için gereken döngü.
			{
				for (uint8_t a=0;a<2;a++) // 2 Adet dot matrix kullandýðým için harflerin ayný görünmesi amacýyla oluþturulmuþ bir döngü.
				{
					hex_to_bin(ALFABE[i][j]); //Harf dizimizden hex sayý alýnýp, binary'ye çevriliyor.
					for (uint8_t gonder=0;gonder < 5;gonder++) //5 sütunlu bir dot matrix kullandýðým için ' 0' olan verileri göndermiyorum.
					{
						if (binary[gonder] != 0) // Eðer binary dizisinden çektiðimiz data 0'dan farklýysa shift register'a 1 verisi gönder.
						{
							DATA = 1;
							clock_pulse(); 
						}
						else // eðer 0'a eþitse shift register'a 0 verisi gönder.
						{
							DATA = 0;
							clock_pulse();
						}
					}
				}
				
				satir_tarama(satir); 
				latch_pulse();
				satir++;
				satir = (satir == 7)? 0:satir; // Eðer satýr 7'ye eþit ise 0'la deðilse olduðu gibi kalsýn.
			}
		}
	}
}

void EMRE()
{
	for (uint8_t i=0;i<4;i++) // Kaç adet satýrýn olduðunu belirledik.
	{
		for (uint8_t tekrar=0;tekrar<100;tekrar++) // Ekranda harflerin belli bir süre durmasýný saðlamak için döngü.
		{
			for (uint8_t j=0;j<7;j++)//Matrixin sütünlarýný okumamýz için gereken döngü.
			{
				for (uint8_t a=0;a<2;a++)
				{
					hex_to_bin(__EMRE[i][j]);
					for (uint8_t k=0;k<5;k++)
					{
						if (binary[k] != 0)
						{
							DATA = 1;
							clock_pulse();
						}
						else
						{
							DATA = 0;
							clock_pulse();
						}
					}
				}
				
				satir_tarama(satir);
				latch_pulse();
				satir++;
				satir = (satir == 7) ? 0:satir;
			}
		}
	}
}

void emoji()
{
	for (uint8_t i=0;i<3;i++)// Kaç adet satýrýn olduðunu belirledik.
	{
		for (uint8_t tekrar=0;tekrar<100;tekrar++)//Matrixin sütünlarýný okumamýz için gereken döngü.
		{
			for (uint8_t j=0;j<7;j++)
			{
				for (uint8_t a=0;a<2;a++)
				{
					hex_to_bin(__emoji[i][j]);
					for (uint8_t k=0;k<5;k++)
					{
						if (binary[k] != 0)
						{
							DATA = 1;
							clock_pulse();
						}
						else
						{
							DATA = 0;
							clock_pulse();
						}
					}
				}
				
				satir_tarama(satir);
				latch_pulse();
				satir++;
				satir = (satir == 7) ? 0:satir;
			}
		}
	}
}






#endif /* CONFIG_H_ */