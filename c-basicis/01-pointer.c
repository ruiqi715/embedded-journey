#include<stdio.h>
int main()
{
    int a=10;
    int b=20;
    //1.声明指针变量
    int *p1=&a;//p1是一个指针变量，存储了a的地址
    int *p2=&b;//p2是一个指针变量，存储了b的地址

    printf("a=%d,b=%d\n",a,b);

    //2.通过指针变量修改a和b的值
    int temp=*p1;
    *p1=*p2;
    *p2=temp;

    printf("a=%d,b=%d\n",a,b);

    return 0;

}