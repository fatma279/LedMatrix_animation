/***************************************************/
/* Author  : fatma                                 */
/* Date    : 20 august 2021                         */
/* version : V03                                   */
/***************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "LEDMRX_interface.h"

/* array of data to display*/
u8 Data[40]={0, 0, 11, 255, 75, 192, 128, 0,0, 0, 11, 255, 75, 64, 16, 0,0, 0, 11, 255, 75, 64, 8, 0,
	        	0, 0, 11, 255, 75, 32, 0, 2,0, 0, 11, 255, 75, 192, 8, 0};
void main(void)
{
	/* initiate system clock */
	 RCC_voidInitSysClock();

	 /* enable clock for peripheral  PORTA*/
	 RCC_voidEnablePeripheralClock( RCC_APB2, RCC_PORTA);

	 /* enable clock for peripheral  PORTB*/
	 RCC_voidEnablePeripheralClock( RCC_APB2, RCC_PORTB);

	 /* initiate systick */
	 STK_voidInit();

	 /* initiate LED MATRIX */
	 HLEDMRX_voidInit();

	 while(1){
		 /* display data on led matrix */
	 HLEDMRX_voidDisplay(Data);
	 }

}
