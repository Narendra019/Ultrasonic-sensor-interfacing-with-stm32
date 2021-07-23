#include<NEW.h>
#include<stdio.h>
#include<stdarg.h>
void Ultra_setting();
void delay(int val);
void Tim3_Capture();
void Uart1_config();
void uart_printf(const char *fmt, ...);
uint32_t  timeStamp1 = 0,timeStamp2=0,width=0,Distance=0;
unsigned int flag=0;

void TIM3_IRQHandler()
{

	 uint32_t time = TIM3->CCR1;/* capturing CCR Value into the time variable */
	 flag++;
	 if (flag==1)
	 {
	      timeStamp1=time;
	  }
	 else
	  {
	    	timeStamp2= time;
	        if(timeStamp2>timeStamp1)
	        {
	        	width= timeStamp2-timeStamp1;

	        }
	        else if(timeStamp2<timeStamp1)
	        {
	            width= (0xffff - timeStamp1) + timeStamp2;
	        }

	        /*
	        calculate the range through the time interval between sending trigger signal and
	        receiving echo signal. Formula: uS / 58 = centimeters or uS / 148 =inch; or: the
	        range = high level time * velocity (340M/S) /2 */
	        Distance =width/58;
	        flag=0;
	    	uart_printf("Object is at distance of %d cm \n", Distance );
	   }

}

int main()
{
    //GPIO A configuration
    SystemInit();
    Ultra_setting();
    Uart1_config();
    Tim3_Capture();/*Enable Tim3 capture*/
    while(1)
    {
    	/*You only need to supply a short 10uS pulse to the trigger input to start the ranging, and then the module will send out
    	  an 8 cycle burst of ultrasound at 40 kHz and raise its echo*/
         GPIOA->ODR |=1<<12;/* Turning ON PA12pin */
         delay(100);/* 10 microseconds ON*/
         GPIOA->ODR &=~(1<<12);/* Turning ON PA12 pin */
         delay(1000000);/* 62.5 milliSeconds delay */
    }
}
char buf[512];
void uart_printf(const char *fmt, ...)
{
	int ret;
	va_list args;
	va_start(args, fmt);
	ret = vsnprintf(buf, 512, fmt, args);
	va_end(args);
	if (ret > 0)
	{
		for (int i =0; i < ret; i++)
		{
			USART1->SR = 0;
			USART1->DR = buf[i];
			while(!(USART1->SR & (1<<6)) );
		}
	}
}

void Uart1_config()
{
	RCC->APB2ENR |=USART1_CLK;
	RCC->AHB1ENR |=1;
	GPIOA->MODER |=2<<18;/* Enabling Mode of PA9 tx pin */
	GPIOA->MODER |=2<<20;/*Enabling Mode of PA10 rx pin */
	GPIOA->OSPEEDR |=3<<18;/* Enabling High speed  of PA9*/
	GPIOA->OSPEEDR |=3<<20;/* Enabling High speed of PA10*/
	GPIOA->AFR[1]  |=7<<4;/*Enabling AFR7 of PA9 */
        GPIOA->AFR[1]  |=7<<8;/*Enabling AFR8 of PA10 */
	USART1->CR1 |=USART1_EN;
        USART1->BRR =((3<<0) | (0x68<<4));  /*9600 Baud Rate*/
	USART1->CR1 |=USART1_RE;
	USART1->CR1 |=USART1_TE;
}

void Tim3_Capture()
{
	 //input capture mode
	    RCC->APB1ENR |= 2;      //ENABLE TIMER 3
	    TIM3->PSC = 16;       /*divide by 16-1MHZ -1 microsecond */
	    TIM3->CCMR1 |=TIM2_CCIS;//01: CC1 channel is configured as input, IC1 is mapped on TI1.
	    TIM3->CCER |=1;     //enable CH1 input capture
        TIM3->CCER |=5<<1; //enable 11: noninverted/both edges
	    WRITE(NVIC_ISER0 ,(1<<29));//Enable timer Interrupt.
	    TIM3->DIER =1<<1;  //Bit 1 CC1IE: Capture/Compare 1 interrupt enable
        TIM3->EGR=1<<0;   //Update event Generation
	    TIM3->CR1 = 1;    //enable TIM3
        TIM3->CNT=0;
}

void Ultra_setting()
{
    RCC->AHB1ENR |=1; /* Enabling clock for GPIOA port*/
	GPIOA->MODER |=2<<12;/*Alternative function in PA6 pORT*/
	GPIOA->MODER |=1<<24;/*General Purpose output function in PA12 Port*/
	GPIOA->AFR[0]|=2<<24; /* Alternate function low register is AF1 is TIM3_CH1,PA6 */
	GPIOA->OSPEEDR|=1<<12;/*Medium speed */
}

void delay(int val)
{
	  RCC->APB1ENR |=1<<0;  /* TIM2 clock enabled*/
	  TIM2->CNT=0;
	  TIM2->PSC=1;
	  TIM2->CR1 |=1;
	  while(TIM2->CNT < val);
	  TIM2->SR=0;
}
