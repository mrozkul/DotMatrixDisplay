/*
 * CONFIG.h
 *
 * Created: 20.12.2020 18:23:29
 *  Author: Emre
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#ifndef F_CPU
#define F_CPU 16000000UL // �ayet tan�mlanmad�ysa kristalin frekans de�erini tan�mlad�k.
#endif

#include <avr/io.h> // Avr'nin input-output k�t�phanesini ekledik.
#include <util/delay.h> // Bekleme k�t�phanesini ekledik.
#include <avr/interrupt.h> // Versiyon g�ncellemesinde laz�m olaca�� i�in kesme k�t�phanesini ekledik.
#include "_328P_GPIO_.h" // GPIO ba�l�k dosyam�z� ekledik.


/* Registerlara ula�abilmek i�in �ni�lemci
tan�mlamas� yapt�k. Bu sayede yap�larla u�ra�mam�z gerekmeyecek. */

#define __DDRB			GPIO._DDRB_.port		
#define __PORTB			GPIO._PORTB_.port
#define __DDRD			GPIO._DDRD_.port
#define __PORTD			GPIO._PORTD_.port	
#define DATA			GPIO._PORTB_.pins.pin0
#define CLOCK			GPIO._PORTB_.pins.pin1
#define LATCH			GPIO._PORTB_.pins.pin2
#define led				GPIO._PORTB_.pins.pin3	

	
#define delay			2750UL  //Sat�r tarama i�in bekleme s�resi tan�mlad�k.

/*Fonksiyon prototiplerini tan�mlad�k. */

void GPIO_init();
void clock_pulse();
void latch_pulse();
void hex_to_bin(uint8_t);
void satir_tarama(uint8_t);
void alfabe();
void EMRE();
void emoji();

/*De�i�ken tan�mlad�k.*/

volatile uint16_t milisaniye;
volatile uint8_t satir;
uint8_t toplam_satir=29;

uint8_t binary[8]; //Ge�ici dizi tan�mlad�k.

uint8_t ALFABE[][8]=
{
	{0x04,0x0A,0x11,0x11,0x1F,0x11,0x11,0x00},//A
	{0x1E,0x11,0x11,0x1E,0x11,0x11,0x1E,0x00},//B
	{0x0F,0x10,0x10,0x10,0x10,0x10,0x0F,0x00},//C
	{0x0F,0x10,0x10,0x10,0x10,0x0F,0x04,0x00},//�
	{0x1E,0x11,0x11,0x11,0x11,0x11,0x1E,0x00},//D
	{0x1F,0x10,0x10,0x1F,0x10,0x10,0x1F,0x00},//E
	{0x1F,0x10,0x10,0x1F,0x10,0x10,0x10,0x00},//F
	{0x0F,0x10,0x10,0x17,0x15,0x11,0x0F,0x00},//G
	{0x04,0x0F,0x10,0x17,0x15,0x11,0x0E,0x00},//�
	{0x11,0x11,0x11,0x1F,0x11,0x11,0x11,0x00},//H
	{0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00},//I
	{0x04,0x00,0x04,0x04,0x04,0x04,0x04,0x00},//�
	{0x10,0x10,0x10,0x10,0x10,0x11,0x0E,0x00},//J
	{0x11,0x12,0x14,0x18,0x14,0x12,0x11,0x00},//K
	{0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0x00},//L
	{0x11,0x1B,0x15,0x11,0x11,0x11,0x11,0x00},//M
	{0x11,0x11,0x19,0x15,0x13,0x11,0x11,0x00},//N
	{0x0E,0x11,0x11,0x11,0x11,0x11,0x0E,0x00},//O
	{0x0A,0x0E,0x11,0x11,0x11,0x11,0x0E,0x00},//�
	{0x1E,0x11,0x11,0x1E,0x10,0x10,0x10,0x00},//P
	{0x1E,0x11,0x11,0x1E,0x14,0x12,0x11,0x00},//R
	{0x0F,0x10,0x10,0x0E,0x01,0x01,0x1E,0x00},//S
	{0x0F,0x10,0x1E,0x01,0x1E,0x04,0x00,0x00},//�
	{0x1F,0x04,0x04,0x04,0x04,0x04,0x04,0x00},//T
	{0x11,0x11,0x11,0x11,0x11,0x11,0x0E,0x00},//U
	{0x0A,0x00,0x11,0x11,0x11,0x11,0x0E,0x00},//�
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
	__DDRB = PORT_OUTPUT; // DDRD registeri ��k�� olarak ayarland�.
	__DDRD = PORT_OUTPUT; // DDRB registeri ��k�� olarak ayarland�.
	__PORTD = PORT_HIGH; // PORTD register�n�n her biti 1 yap�ld�. (255) 
	__PORTB = PORT_LOW; // PORTB register�n�n her biti 0 yap�ld�.
}

/*Shift register'a 1 adet clock pulse g�ndermek i�in fonksiyon.*/
void clock_pulse()
{
	CLOCK = 1;	
	_delay_us(1);
	CLOCK = 0;
}

/*Shift registerdaki veriyi ��k��a aktarabilmek i�in 1 pulse darbesi veriyoruz.*/
void latch_pulse()
{
	LATCH = 1;
	_delay_us(delay); // Burada ki delay sat�r tarama i�in gerekli olan s�re.
	LATCH = 0;
}

/*Hexadecimal olarak ald��� bilgiyi ge�ici diziye binary olarak atan fonksiyon.*/
void hex_to_bin(uint8_t hex_sayi) //uint8_t = 0-255 aras� de�er al�r. 
{
	uint8_t i,j; // D�ng� i�in gerekli olan de�i�kenler.
	
	for (i=0;i<8;i++) // Burada 8 bitlik bir say� i�in 8 degeri girildi.
	{
		/*
		Burada bit shifting yani bit kayd�rma operat�r� ile 
		0-7 ye kadar kayd�r�yor. Kayd�r�lan de�eri j de�i�kenine 
		at�yor.Bu i�lem 8 defa s�r�yor.
		*/
		j = hex_sayi >> i;
		
		
		if (j & 1)
		binary[i] = 1;
		else
		binary[i] = 0;
		
		/*
			j e�er bit baz�nda 1'e e�itse ge�ici dizinin i'ninci eleman�na
			1 yaz�l�yor. De�ilse i'ninci eleman�na 0 yaz�l�yor.
		*/
		
	}
}

void satir_tarama(uint8_t x) //�lgili sat�r� yakmak i�in olu�turulan fonksiyon.
{
	
	switch (x)
	{
		/*Dot Matrix ortak anot oldu�u i�in ilgili sat�r� lojik 0 yapmak gerekiyor.*/
		
		case 0:
		__PORTD = 126; //E�er x == 0 ' a e�itse PORTD = 01111110
		break;
		
		case 1:
		__PORTD = 125; //E�er x == 1 ' a e�itse PORTD = 01111101
		break;
		
		case 2:
		__PORTD = 123; //E�er x == 2 ' a e�itse PORTD = 01111011
		break;
		
		case 3:
		__PORTD = 119; //E�er x == 3 ' a e�itse PORTD = 01110111
		break;
		
		case 4:
		__PORTD = 111; //E�er x == 4 ' a e�itse PORTD = 01101111
		break;
		
		case 5:
		__PORTD = 95; //E�er x == 5 ' a e�itse PORTD = 01011111
		break;
		
		case 6:
		__PORTD = 63; //E�er x == 6 ' a e�itse PORTD = 00111111
		break;
	}
}

void alfabe()
{
	for (uint8_t i=0;i<toplam_satir;i++) //Sat�r bilgisinin ka� adet olduguna g�re �art ko�tuk.
	{
		for (uint8_t tekrar = 0;tekrar < 100;tekrar++) //Ekranda harflerin belli bir s�re durmas�n� sa�lamak i�in d�ng�.
		{
			for (uint8_t j=0;j<7;j++) //Matrixin s�t�nlar�n� okumam�z i�in gereken d�ng�.
			{
				for (uint8_t a=0;a<2;a++) // 2 Adet dot matrix kulland���m i�in harflerin ayn� g�r�nmesi amac�yla olu�turulmu� bir d�ng�.
				{
					hex_to_bin(ALFABE[i][j]); //Harf dizimizden hex say� al�n�p, binary'ye �evriliyor.
					for (uint8_t gonder=0;gonder < 5;gonder++) //5 s�tunlu bir dot matrix kulland���m i�in ' 0' olan verileri g�ndermiyorum.
					{
						if (binary[gonder] != 0) // E�er binary dizisinden �ekti�imiz data 0'dan farkl�ysa shift register'a 1 verisi g�nder.
						{
							DATA = 1;
							clock_pulse(); 
						}
						else // e�er 0'a e�itse shift register'a 0 verisi g�nder.
						{
							DATA = 0;
							clock_pulse();
						}
					}
				}
				
				satir_tarama(satir); 
				latch_pulse();
				satir++;
				satir = (satir == 7)? 0:satir; // E�er sat�r 7'ye e�it ise 0'la de�ilse oldu�u gibi kals�n.
			}
		}
	}
}

void EMRE()
{
	for (uint8_t i=0;i<4;i++) // Ka� adet sat�r�n oldu�unu belirledik.
	{
		for (uint8_t tekrar=0;tekrar<100;tekrar++) // Ekranda harflerin belli bir s�re durmas�n� sa�lamak i�in d�ng�.
		{
			for (uint8_t j=0;j<7;j++)//Matrixin s�t�nlar�n� okumam�z i�in gereken d�ng�.
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
	for (uint8_t i=0;i<3;i++)// Ka� adet sat�r�n oldu�unu belirledik.
	{
		for (uint8_t tekrar=0;tekrar<100;tekrar++)//Matrixin s�t�nlar�n� okumam�z i�in gereken d�ng�.
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