#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SPEAKER_PORT	PORTC
#define SPEAKER_DDR  	DDRC
#define SPEAKER_PIN  	7
/*
Do (262 Hz)x38=09,956
Re (294 Hz)x38=11,172 
Mi (330 Hz)x38=12,540 
Fa (349 Hz)x38=13,262
Sol (392 Hz)x38=14,896 
La (440 Hz)x38=16,720 
Si (494 Hz)x38=18,772
Doh (524 Hz)x38=19912
*/
void PLAYNOTE_Do(float frequency)
{
	frequency=9956;
	float duration=10;
	long int i,cycles;
	//int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.0502209);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.0502209);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_Re(float frequency)
{
	frequency=11172;
float duration=10;
	long int i,cycles;
	//int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.0447547);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.0447547);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_Mi(float frequency)
{
	frequency=12540;
float duration=10;
	long int i,cycles;
	//int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.039872);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.039872);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_Fa(float frequency)
{
	frequency=13262;
float duration=10;
	long int i,cycles;
	//int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.0377017);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.0377017);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_Sol(float frequency)
{
	frequency=14896;
float duration=10;	long int i,cycles;
//	int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.033566);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.033566);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_La(float frequency)
{
	frequency=16720;
float duration=10;	long int i,cycles;
	//int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.0299043);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.0299043);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_Si(float frequency)
{
	frequency=18772;
float duration=10;	long int i,cycles;
//	int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.0266354);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.0266354);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_Doh(float frequency)
{
	frequency=19912;float duration=10;	long int i,cycles;
//	int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.0251104);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.0251104);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}

int main(void)
{
	DDRA = 0b00000000;
	unsigned char d;
	while(1)
	{
		d = PINA;
		if(d&0b00000001)
		{
			PLAYNOTE_Do(880);		//		_delay_ms(1);
			/*PLAYNOTE_Re(932);				_delay_ms(1);
			PLAYNOTE_Mi(988);				_delay_ms(1);
			PLAYNOTE_Fa(1047);				_delay_ms(1);
			PLAYNOTE_Sol(1109);				_delay_ms(1);
			PLAYNOTE_La(1109); 				_delay_ms(1);
			PLAYNOTE_Si(1109);				_delay_ms(1);			
			PLAYNOTE_Doh(1109);				_delay_ms(1);
					
			PLAYNOTE_Doh(1109);				_delay_ms(1);
			PLAYNOTE_Si(1109);				_delay_ms(1);
			PLAYNOTE_La(1109);				_delay_ms(1);
			PLAYNOTE_Sol(1109);				_delay_ms(1);
			PLAYNOTE_Fa(1047);				_delay_ms(1);
			PLAYNOTE_Mi(988);				_delay_ms(1);
			PLAYNOTE_Re(932);				_delay_ms(1);
			PLAYNOTE_Do(880);				_delay_ms(1);*/
		}
		else if (d&0b00000010) {
			PLAYNOTE_Re(932);		//		_delay_ms(1);
		}
		else if (d&0b00000100) {
			PLAYNOTE_Mi(988);		//		_delay_ms(1);
		}
		else if (d&0b00001000) {
			PLAYNOTE_Fa(1047);		//		_delay_ms(1);
		}
		else if (d&0b00010000) {
			PLAYNOTE_Sol(1109);		//		_delay_ms(1);
		}
		else if (d&0b00100000) {
			PLAYNOTE_La(1109); 		//		_delay_ms(1);
		}
		else if (d&0b01000000) {
			PLAYNOTE_Si(1109);		//		_delay_ms(1);		
		}
		else if (d&0b10000000) {
			PLAYNOTE_Doh(1109);		//		_delay_ms(1);
		}
	}
}
