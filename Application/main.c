#include "stm32f4xx.h"



static void init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

	// Clock Enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);

	// Config PG13 als Digital-Ausgang
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
}


void SysTick_Handler(void)
{
	static int i = 0;
	if (i > 999)
	{
		i = 0;
		GPIO_ToggleBits(GPIOG, GPIO_Pin_13);
	}
	else
		i++;
}


int main(void)
{
    SystemInit();
    SystemCoreClockUpdate();
    init();
    SysTick_Config(SystemCoreClock / 1000);     // 1kHz Systick

    while(1)
    {
    }
}
