#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//第十四章 格式化输入输出函数

void test01() 
{
	int i = 150;
	int j = -100;
	double k = 3.14149;
	int ret = fprintf(stdout,"%d %f %x\n",j,k,i); // -100 3.141490 96
	printf("ret = %d\n",ret);
	fprintf(stdout,"%2d %*d\n",i,2,i);  //150 150!!!!!
}                     //%2d  参数2会代入格式*中，最后和%2d一样

void test02() 
{
	int i;
	unsigned int j;
	char s[5];
	fscanf(stdin,"%d %x %5[a-z] %*s %f",&i,&j,s,s);
	printf("%d %d %s\n",i,j,s);
	//10 0x1b aaaaaaaa bbbbbbb  //从键盘输入    !!!!!!!
	//10 27 aaaaa				//0x1b经转换成27，忽略b字符串
}
/*  整数
	%d 整数的参数会被转换成——有符号的十进制数字
	%u                     ——无符号的十进制数字
	%o					   ——无符号的八进制数字
	%x 整型数的参数会被转换成—无符号的十六进制数字，并以小写abcdef表示
	%X						 —                    ，并以大写ABCD表示

	浮点型数
	%f double 型的参数会转换会转换成十进制的数字，并取到小数点以下六位，四舍五入
	%e 将double 型的参数以指数（科学记号）形式打印，有一个数字会在小数点前，
	            六位数字在小数点后，而在指数部分会以小写的e来表示
	%E 与%e作用相同，唯一区别是指数部分将以大写的E来表示
	
	字符
	%c 整型数的参数会被转换成unsigned char 型打印出
*/

void test03() 
{
	int i = 150;
	int j = -100;
	double k = 3.14159;
	printf("%d %f %x\n",j,k,i);
	printf("%2d %*d\n",i,2,i);
} //-100 3.141590 96
  //150 150
/*
	%d 输入的数据会被转成——有符号的十进制数字（int）
	%i 输入的数据会被转成——						，若输入的数据以"0x"或"0X"
	   开头代表转换十六进制数字，若以"0"开头的数字则转换八进制数字，其他情况代表十进制
	%o 输入的数据会被转换成——无符号的八进制数字（unsigned int）
	%u 输入的数据会被转换成——无符号的正整数（unsigned int）
	%x 输入的数据为无符号的十六进制数字，转换后存于unsigned int 型变量
		%X 同%x。
	%f 输入的数据为有符号的浮点型数，转换后存于float型变量
		%e %E %g 同%f
	%s 输入数据为以空格字符为终止的字符串
	%c 输入数据为单一字符
	[] 读取数据但只允许括号内的字符。如[a-z]
	[^]读取数据但不允许中括号的 ^ 符号后的字符出现，如[^0-9]
			%[*][size][l][h]type
	返回值：成功返回参数数目，失败则返回-1
*/
void test04() 
{
	int i;
	unsigned int j;
	char s[5];          //*代表该对应的参数数据忽略不保存。size为允许参数输入的数据长度
	scanf("%d %x %5[a-z] %*s %f",&i,&j,s,s);
	printf("%d %d %s\n",i,j,s);              
	         //10 0x1b aaaaaaaa bbbbbbb
		     //10 27 aaaaa
}
void test05() //格式化字符串复制 snprintf
{
	char a[] = "This is string A!";
	char buf[80];
	int ret = snprintf(buf,sizeof(buf),">>> %s <<<\n",a);
	printf("ret = %d\n",ret);
	printf("%s",buf);
}

void test06() //sprintf格式化字符串复制 但——使用此函数的留意堆栈溢出（buffer overflow）
{				//或改用snprintf()
	char* a = "This is string A!";
	char buf[80];
	sprintf(buf,">>> %s <<<\n",a);
	printf("%s",buf);
}

void test07() 
{
	int i;
	unsigned int j;
	char input[] = "10 0x1b aaaaaaaa bbbbbbb";
	char s[5];
	sscanf(input,"%d %x %5[a-z] %*s %f",&i,&j,s,s);  //有问题，栈被破坏了
	printf("%d %d %s\n",i,j,s);  //10 27 aaaaa
} 
//vfprintf  格式化输出数据到文件      参考fprintf()及vprintf()

//vfscanf 格式化字符串输入 参考fscanf()及vprintf().



int main() 
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();

	return 0;
}