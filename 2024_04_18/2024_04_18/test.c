#include<stdio.h>
#include<stdlib.h>

//预处理
//#define MAX 1000
#define REG register
#define DO_FOREEVER1 for(;;)
#define DO_FOREEVER2 while(1)
#define CASE break;case
#define DEBUG_PRINT printf("file:%s\tline:%d\t \
							date:%s\ttime:%s\n" ,\
							__FILE__,__LINE__,    \
							__DATE__,__TIME__)
#define MAX(a,b) ((a)>(b) ? (a):(b))
//#define MAX(a, b) ((a) > (b) ? (a) : (b)) 

/*
#define MALLOC(num,type)\
	(type)malloc(num*sizeof(type))
//使用
MALLOC(10,int)  //类型作为参数
//预处理器替换之后：
MALLOC(10,int) (int)malloc(10*sizeof(int))
*/

void test01() 
{
	printf("%s\n%d\n%s\n%s\n",     \
		__FILE__,				   \
		__LINE__,				   \
		__DATE__,				   \
		__TIME__				   \
		);
}
test02() 
{
	DO_FOREEVER2
	{
		//printf("MAX:%d\n",MAX);
		//Sleep(1000);
		DEBUG_PRINT;
	}
}
void test03() 
{
	int x = 8;
	int y = 5;
	int ret = MAX(x, y);
	printf("ret = %d",ret);
}
               //printf("the value of ""a"" is %d", a)
#define PRINT(n) printf("the value of "#n" is %d",n)

void test04() 
{
	int a =10;
	PRINT(a);  //the value of a is 10
}
/*
int int_max(int x,int y) 
{
	return x > y ? x : y;
}

float float_max(int x, int y)
{
	return x > y ? x : y;
}*/
#define GENERIC_MAX(type)       \
type type##_max(type x,type y)  \
{                               \
	return (x > y ? x : y);     \
}

GENERIC_MAX(int)
GENERIC_MAX(float)

void test05() 
{
	//调用函数
	int m = int_max(5,6);
	printf("m = %d\n",m);
	float n = float_max(1.2f,4.5f);
	printf("n = %f\n",n);
}
//条件编译
#define __DEBUG__
//#undef __DEBUG__
void test06() 
{
	int i = 0;
	int arr[10] = {0};
	for (i = 0; i < 10; i++) 
	{
		arr[i] = i;
		#ifdef __DEBUG__
		printf("%d\n",arr[i]);
		#endif
	}
}
/*
常见的条件编译指令：
1. 
#if  常量表达式
	//。。。
#endif
//常量表达式由预处理器求值
如：
#define __DEBUG__ 1
#if __DEBUG__
      ...
#endif
2.多个分支的条件编译
#if 常量表达式
	//……
#elif 常量表达式
	//……
#else 
	//……
#endif
3.判断是否被定义
#if defined(symbol)
#ifdef symbol

#if !defined(symbol)
#ifndef symbol

4.嵌套指令
#if define(OS_UNIX)
	#ifdef OPTION1
		unix_version_option1();
	#endif
	#ifdef OPTION2
		unix_version_option2();
	#endif
#elif defined(OS_MSDOS)
	#ifdef OPTION2
		msdos_version_option2();
	#endif
#endif
*/
 
void test07() 
{
	char c = 'a';  //0110 0001
	printf("字符 'a' 的比特表示为：\n");
	for (int i = 7; i >= 0; i--) {        //0000 0001
		printf("%d: %d\n", i, (c >> i) & 1);
		//0000 0000  0000 0001  0000 0011
		//0000 0110  0000 1100  0001 1000
		//0011 0000  0110 0001  
	}
}
void test08() 
{
	int num = -1;  //10000000 00000000 00000000 00000001
	int i = 0;	   //11111111 11111111 11111111 11111111
	int count = 0;
	for (i = 0; i < 32; i++) 
	{                      //00000000 00000000 00000000 00000001
		if (num & (1 << i))
			count++;
	}
	printf("二进制中1的个数 = %d\n",count);
}

int main() 
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();

	return 0;
}