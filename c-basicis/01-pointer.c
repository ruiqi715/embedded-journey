/*#include<stdio.h>
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

}*/


/*#include<stdio.h>
int main()
{
    int arr[]={10,20,30,40,50};
    int *p=arr;//p指向数组的第一个元素（10）
    int lenghth=5;

    printf("the length of the array is:");
    for(int i=0;i<lenghth;i++){
        //*(p+i)表示指针p向后偏移i个元素，取出对应的值
        printf("%d ",*(p+i));
    }
    printf("\n");
    return 0;
}*/



/*#include<stdio.h>
                                                      //自己写一个计算字符串长度的函数
int my_strlen(char *s){                               //定义一个自己写的函数，名字叫my_strlen
                                                      //括号里的（char *s):你要传给我一个字符串的起始门牌号（指针）
                                                      //签名档int意思是：这个函数算完之后会给你返回一个整数（也就是长度）
    int count=0;                                      //准备一个计数器，一开始是零，用来记我们走了多少个房间（字符）
    while(*s!='\0'){                                  //当指针s指向的字符不是'\0'时，继续循环
        count++;                                      //长度加一
        s++;                                          //指针s向后移动一个字符
    }
    return count;                                     //循环结束后，把统计好的总步数（长度）返回给调用者

}

int main(){
    char str[]="Hello";                               //在内存里开一个走廊，名字叫str，里面放了H、e、l、l、o、\0
    int len=my_strlen(str);                           //调用my_strlen函数，把str的起始门牌号传给它，返回的长度存到len里
    printf("the length of %s is:%d\n",str,len);
    return 0;
}*/




/*#include<stdio.h>
int main(){
    char *names[]={"Apple","Banana","Cherry"};        //定义了一个名叫names的数组，char*说明这个数组里装的每一个元素，都是
                                                       “字符指针”（也就是字符串的门牌号），大括号里装了三个字符串，它们分别
                                                       存放在内存的不同地方，names数组把它们串在了一起
    for(int i=0;i<=3;i++){                            
                                                      //%s对应后面的nams[i],(names[i]就是取出了第i张写着字符串地址的房卡)
        printf("Fruit %d:%s\n",i+1,names[i]);
    }
    return 0;                                                   
}*/





#include<stdio.h>

    int add(int a,int b){                              //定义一个函数，名字叫add，括号里的a和b是两个整数参数,算完后返回一个整数结果
                                                       
        return a+b;                                    //把a和b相加的结果返回给调用者
                               
    }
    int main(){
        int (*p_func)(int,int)=add;                    //定义一个函数指针变量p_func，
                                                       //p_func是一个指针，它指向的函数必须接收两个int,并返回一个int
                                                       //=add:把指针直接指向刚才写好的add函数
        int result=p_func(3,5);                        //通过函数指针调用add函数，传入3和5，返回的结果存到result里   
        printf("Calulate via function pointer:3+5=%d\n",result);
        return 0;
    }
