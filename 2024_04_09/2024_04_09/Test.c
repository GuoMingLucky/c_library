#include<stdio.h>
#include<ctype.h>

void test01() 
{
	char str[] = "123c@#FDsP[e?";
	int i;
	for (i = 0; str[i] != 0; i++)             //字母
		if (isalnum(str[i]))printf("%c is an alphanumeric character\n",str[i]);
}

void test02() 
{
	char str[] = "123c@#FDsP[e?";
	int i;
	for (i = 0; str[i] != 0; i++)
		if (isalpha(str[i]))
			printf("%c is an alphabetic character\n",str[i]);
}

void test03() 
{
	int i;
	for (i = 125; i < 130; i++)
		if (isascii(i))
			printf("%d is an ascii character : %c\n", i, i);
		else
			printf("%d is not an ascii character\n",i);
}

void test04() 
{
	char str[] = "123c @# FD	sP[e?";
	int i = 0;
	for (; str[i] != 0; i++)
		if (isblank(str[i]))printf("str[%d] is blank character: %d\n",i,str[i]);
}

void test_05() 
{
	int i = 0;
	char str[] = "first line \n second line \n";
	while (!iscntrl(str[i]))   
	{
		putchar(str[i]);
		i++;
	}
}

void test06() 
{
	char str[] = "123c@#FDsP[e?";
	int i = 0;
	for (; str[i] != 0; i++)
		if (isdigit(str[i]))
			printf("%c is an digit character\n",str[i]);
}                            //数字

void test_07()
{
	char str[] = "a5 @;";
	int i;
	for (i = 0; str[i] != 0; i++)
		if(isgraph(str[i]))      //不能打印空格
		printf("str[%d] is printable character: %c\n",i,str[i]);
}

void test08() 
{
	char str[] = "123c@#FDsP[e?";
	int i;
	for (i = 0; str[i] != 0; i++)
		if (islower(str[i])) printf("%c is a lower-case character\n",str[i]);
}

void test_09() 
{
	char str[] = "a5 @;";
	int i = 0;
	for (; str[i] != 0; i++) 
		if (isprint(str[i]))  //可以打印空格
			printf("str[%d] is printable character: %c\n",i,str[i]);
}

void test10() 
{
	char str[] = "123c @# FD\tsP[e?\n";
	int i = 0;
	for (i = 0; str[i] != 0; i++)
		if (isspace(str[i]))
			printf("str[%d] is a white-space character: %d\n",i,str[i]);
}

void test11() 
{
	char str[] = "123c@ #FDsP[e?";
	int i = 0;
	for (; str[i] != 0; i++)
		if (ispunct(str[i])) printf("%c\n",str[i]);
}

void test12() 
{
	char str[] = "123c@#FDsP[e?";
	int i = 0;
	for (; str[i] != 0; i++)
		if (isupper(str[i])) printf("%c is a an uppercase character\n",str[i]);
}

void test13() 
{
	char str[] = "123c@#FDsP[e?";
	int i;
	for (i = 0; str[i] != 0; i++)
		if (isxdigit(str[i])) printf("%c is a hexadcimal digits\n",str[i]);
}

int main() 
{
	//test01();
	//test02();
	//test03();
	//test04();
	///test_05();
	//test06();
	//test_07();
	//test08();
	//test_09();
	//test10();
	//test11();
	//test12();
	//test13();

	return 0;
}