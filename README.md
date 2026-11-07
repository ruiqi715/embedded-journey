# embedded-journey
hello I'm ruiqi715.
-**What I am learning**:C++basics and microcontroller development,
-**Goal for this week**:Complete the development environment setup and light up the first LED!

Track my daily progress.Keep it up!#Embedded Journey(嵌入式之旅)
##1.项目简介
这是我的嵌入式学习记录仓库，用于记录从C语言基础到STM32硬件开发的完整过程。


##2.硬件清单
-开发板：STM32F103C8T6最小系统板（蓝丸）
-调试器：ST-LINK V2
-其他：杜邦线，USB数据线


##3.遇到的问题与解决
-**问题一：Keil芯片包一直装不上**
-*现象*：安装.pack文件卡死，设备列表里找不到STM32。
-*解决*：关闭杀毒软件，通过手动解压.pack文件放入Keil的包装目录，并删除旧的索引文件解决。
-**问题二：STM-LINK连不上，报错Cannot enter Debug Model**
-*现象*：设备管理器出现未知USB设备，驱动带黄色感叹号。
-*解决*：判断为ST-LINK固件太老，下载SIM32CubeProgrammer强制刷入最新固件。
-**问题三：代码编译器报错Target not created**
-*现象*：工程里同时存在main.c和led.c,包含两个main函数。
-*解决*：在Keil左侧右键移除多余的main.c文件，只保留一个入口函数。
-**问题四：烧录后灯不亮**
-*解决*：配置了Reset and Run,并了解到C8T6板载的PC13是低电平点亮。


##4.如何复现
1.准备好STM32最小系统板和ST-LINK。
2.安装Keil MDK5及STM32F1xx DFP支持包。
3.打开对应目录下的工程文件，编译并烧录。

