/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/
#include<stdio.h>
#include<stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

uint32_t* UCLK = (uint32_t*)0x4002101C;
uint32_t* PACLK =(uint32_t*)0x40021014;
uint32_t* PAMOD =(uint32_t*)0x48000000;


uint32_t* UCR1 = (uint32_t*)0x40004400;
uint32_t* UCR2 = (uint32_t*)0x40004404;
uint16_t* UBRR = (uint16_t*)0x4000440C;
uint8_t* UTDR =   (uint8_t*)0x40004428;
uint32_t* UISR = (uint32_t*)0x4000441C;
uint8_t* URDR =   (uint8_t*)0x40004424;



int main(void)
{

	*UCLK |= (1<<17);
	// rcc clock enable for apb1 usart2

	*PACLK |= (1<<17);
		// rcc clock enable for ahb GPIOA

	*PAMOD |= (0x2<<4);
	//mod PA TX set to alternate push-pull

	*UCR1 &= ~(1<<12);
	*UCR1 &= ~(1<<28);
	// wordlength 8 bits set

	*UBRR=0x1.388p+8;
	//baud rate set for 36MHZ APB1 as 115200

	*UCR2 &= ~(0x3<<12);
	// stop bit set as 1bit

	*UCR1 |= 0xD;
	// UE TE RE enable
	while (1) {

	  if (*UISR & 1<<5) //if RX is not empty
	  {
	   char temp = *URDR; //fetch the data received
	   *URDR = temp;  //send it back out
	   while (!(*UISR & 1<<6)); //wait for TX to be complete


	  }

	 }


}
