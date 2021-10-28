/* In this project we are going to write a code to intialize Timer 0
	 Mode 1,16 bit mode and generate 5 mili seconds of delay */


#include<reg52.h>               /* Register address included in this file */

void timer_zero_delay();					/* Prototyping of delay function for generating 5ms delay */

/* Main starts */
void main ()
{
	TMOD = 0X01; 			
	
	/* By setting this value to TMOD registerS to timer zero, mode one is 16 bit timer mode */
	

		while(1)/* while loop start */
		{
			
			P1 = 0XFF;	   						/* Port one set to loic high */
			
			timer_zero_delay();				/* calling delay function */
			
			P1 = 0X00;								/* Port one set to logic low */
			
			timer_zero_delay();				/* calling delay function */
			
			
		} /* While loop end */
	
}

/* Main ends here */


void timer_zero_delay()					/* function declaretion for 5msec delay */
{
	/* Generating dealy of 5 milisec for this we set THO to logic 0 and TLO to logic 0xEE 
		 Calculate a value of THx and TLx for generatio of 5 ms delay ?
			
		1 count = 1.085 us 
		how many count for = 5 ms 
		so count is = 4608  (count is 4608)

		(Max count IN 16 bit) 65536 - 4608 = 60928 in Hexadecimal (EE00) 
		 TH0 = 00
	         TL0 = EE
	
	*/
	
	
   TH0 = 0X00;
	 TL0 = 0XEE;
	
	
	 TR0 = 1; 						/* Turn on timer 0 */
	
	/* When timer 0 reach to max count ffff then TF0 flag will set to logic 1 
		for this perticuler condition we are writing some code below */
		
		while (!TF0);
		{
			TR0 = 0 ;  /* Timer set to logic zero to timer set off */
			TF0 = 0 ;  /* To clear timer overflow flag cleard up logic zero set to TRO */
		}
	
	
}

