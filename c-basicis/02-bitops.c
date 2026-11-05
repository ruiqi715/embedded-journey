/*#include<stdio.h>
#include<string.h>//引入字符串处理库，为了安全地复制名字
typedef struct{//定义结构体（设计打包盒图纸）
               //typedef struct意思是：我要定义一个结构体类型，名字叫做Student
int id;//学号
char name[20];//盒子里装一个字符数组，叫名字（最多19个字符+1个结束符'\0'）
}Student;

int main(){
    Student s1={1001,"Alice"};//使用结构体（根据图纸造一个真实的学生）
                              //造了一个学生叫s1,学号是1001，名字是Alice
    Student *p=&s1;//指针访问（拿房间卡访问打包盒）
                   //p是一个指针变量，存储了s1的地址
    printf("id=%d,name=%s\n",p->id,p->name);//通过指针访问结构体成员,不能用p.id和p.name,因为p是一个指针变量，不能直接访问结构体成员
                                            //p->id表示：指针p指向的学生的学号
                                            //p->name表示：指针p指向的学生的名字
    Student class1[2]={
        {1002,"Bob"},
        {1003,"Charlie"}
    };//造了一个班级（数组），里面有两个学生，学号分别是1002和1003，名字分别是Bob和Charlie
    for (int i=0;i<2;i++){
        printf("id=%d,name=%s\n",class1[i].id,class1[i].name);//class1[i]就是数组里具体的一个学生，直接用.访问成员
      } 
      return 0;                                                                                
}*/



#include<stdio.h>
#include<stdint.h>//引入stdint.h头文件，里面定义了各种整数类型的别名,为了使用uint8_t类型
int main(){
    uint8_t reg=0x00;;//模拟一个8位寄存器（想象成一排8个电灯开关，初始全关）
    printf("initial state:0x%02X\n",reg);//打印初始状态，%02X表示以16进制打印，宽度为2，不足补0
    reg|=(1<<3);//打开第三位（置位）
                //1<<3就是把1 往左推三格，变成00001000（即0x08）
                //|=就是把这一位强行变成1，其他位不变
    printf("open the third:0x%02X\n",reg);//打印设置后的状态
    reg|=(1<<5);//先打开第五位（为了演示关闭）
    printf("open the fifth one again:0x%02X\n",reg); 
    reg &=~(1<<5);
    printf("close the fifth:0x%02X\n",reg);//关闭第五位（清位）
                                       //~（1<<5）就是把00100000取反，变成11011111
                                       //&=就是按位与，把第5位强行变成0，其他位不变
    if(reg&(1<<2)){
        printf("second state:open(1)\n");//查询第二位（判断某位）
                                         //reg&(1<<2)就是看第二位是不是1

    }   else{
        printf("second state:close(0)\n");
    }
    return 0;                                           
}

