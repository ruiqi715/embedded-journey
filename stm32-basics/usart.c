/*#include"stm32f10x.h"//包含STM32F10x系列的头文件，定义了所有的寄存地址
#include<stdio.h>//为使用printf函数

//1.简易软件延时函数
void Delay_ms(unsigned int ms){
	unsigned int i,j;
	//外层循环控制毫秒数
	for(i=0;i<ms;i++)
	//内层循环空转，消耗时间
	for(j=0;j<8000;j++);
}
	
	//2.串口1初始化函数
	void USART1_Init(void){
		//第一步：开启时钟
		//RCC-APB2ENR控制APB2总线的外设时钟，不开启外设就没电，不工作
		RCC->APB2ENR |=(1<<2);//第二位是IOPA，开启GPIOA的时钟（因为串口用的是PA9和PA10）
		RCC->APB2ENR |=(1<<14);//第14位是USART1,开启串口1的时钟
		
		//第二步：配置GPIO引脚模式
		//PA9是发送（TX），PA10是接收（RX）。它们由CRH寄存器（管8-15号引脚）控制
		//每个引脚占4个bit,PA9占4-7位，PA10占第8-11位
		
		//配置PA9（TX）：
		GPIOA->CRH &=~(0xF<<4);//先清零第4-7位，把原来的设置抹掉
		GPIOA->CRH |=(0xB<<4);//写入1011（0xB）：复用推挽输出，最大速度50MHz.因为是给串口用的，所以要选“复用”
		
		//配置PA10(RX):
		GPIOA->CRH &= ~(0xF<<8);//先清零8-11位
		GPIOA->CRH |=(0x4<<8);//写入0100（0xB）：浮空输入，串口接收专用
		
		//第三步：配置串口参数（8N1，115200）
		//BRR寄存器存放波特率。72MHz系统时钟下，115200波特率算出来的值是0x0271
		USART1->BRR=0x0271;
		
		//CR1是控制寄存器1，里面是一堆开关
		USART1->CR1 |=(1<<13) |(1<<3) |(1<<2);//第13位UE(USART Enable):总开关，开启串口；
		                                      //第三位TE(Transmitter Enable):开启发送功能；
												                  //第二位RE(Receiver Enable):开启接收功能
		           
								//注：字长8位,无校验，1位停止位，在这个芯片里默认就是这样的，不写就是默认配置
							}

//3.printf重定向
//电脑上的printf打印到屏幕，单片机的printf我们需要让它发送到串口
//C语言的库函数在打印时，底层会是一个个调用fputc这个函数
//所以我们要重写（重定向）fputc,让字符不要乱跑，统统塞进串口的发送寄存器里
int fputc(int ch,FILE *f){
USART1->DR=ch;//把要打印的字符，写进数据寄存器（DR），硬件会自动把它发出去

//等待发送完成：SR是状态寄存器，第六位是TC(Transmission Complete)
//这一步是等待，只要第六位是0，说明还没发完，就在while里卡着；变成了1才往下走
while((USART1->SR&0x40)==0);
return ch;//返回这个字符
}


//4.主函数
int main(void){
	USART1_Init();//调用上面的初始化函数，把串口配好
	
	int tick=1;//定义一个计数器变量，初始值为1
	while(1){
		//使用printf打印变量。\r\n是换行符（回车+换行），不然串口助手会连成一行
		printf("tick=%d\r\n",tick);
		tick++;
		Delay_ms(500);//调用延时函数，等待500毫秒
	}
}*/




#include "stm32f10x.h" // 包含头文件
#include <stdio.h>     // 包含标准库以便使用printf

// 简易软件延时
void Delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++) {
        for(j = 0; j < 8000; j++) {
            // 空循环，消耗时间
        }
    }
}

// 串口1初始化函数
void USART1_Init(void) {
    // 1. 开启时钟 (GPIOA 和 USART1)
    RCC->APB2ENR |= (1 << 2);  
    RCC->APB2ENR |= (1 << 14); 

    // 2. 配置 GPIO (PA9发送，PA10接收)
    GPIOA->CRH &= ~(0xF << 4); 
    GPIOA->CRH |= (0xB << 4);  // PA9 复用推挽输出
    GPIOA->CRH &= ~(0xF << 8); 
    GPIOA->CRH |= (0x4 << 8);  // PA10 浮空输入

    // 3. 配置串口参数 (115200波特率)
    USART1->BRR = 0x0271; 
    
    // 4. 开启串口总开关、发送、接收、接收中断
    USART1->CR1 |= (1 << 13) | (1 << 3) | (1 << 2) | (1 << 5); 

    // 5. 配置 NVIC (嵌套向量中断控制器)
    NVIC->ISER[1] |= (1 << 5); 
}

// 串口发送重定向 (printf)
int fputc(int ch, FILE *f) {
    USART1->DR = ch; 
    while((USART1->SR & 0x40) == 0); 
    return ch;
}

// 串口1中断服务函数
void USART1_IRQHandler(void) {
    char data; 
    
    // 检查是不是真的接收到了数据
    if((USART1->SR & (1 << 5)) != 0) {
        data = USART1->DR; // 读出数据
        
        // 1. 回显
        printf("接收到: %c\r\n", data);
        
        // 2. 控制LED
        if(data == '1') {
            GPIOC->ODR &= ~(1 << 13); // 点亮 PC13
        } else if (data == '0') {
            GPIOC->ODR |= (1 << 13);  // 熄灭 PC13
        }
    }
}

// 主函数
int main(void) {
    // 初始化 PC13 用于控制 LED
    RCC->APB2ENR |= (1 << 4);   // 开启 GPIOC 时钟
    GPIOC->CRH &= ~(0xF << 20); // 清空 PC13 配置
    GPIOC->CRH |= (0x2 << 20);  // PC13 推挽输出
    GPIOC->ODR |= (1 << 13);    // 默认熄灭

    USART1_Init(); // 初始化串口并开启中断

    int tick = 1;  

    while(1) {
        printf("Heartbeat: %d\r\n", tick); 
        tick++;         
        Delay_ms(1000);  
    }
}