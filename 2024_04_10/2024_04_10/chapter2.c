/*#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void test01() 
{
	char* a = "-100.23";
	char* b = "200e-2";
	float c;
	c = atof(a) + atof(b);
	printf("c = %.2f\n",c);
}

void test02() 
{
	char a[] = "-100";
	char b[] = " 456";
	int c;
	c = atoi(a) + atoi(b);
	printf("c = %d\n",c);
}

void test03() 
{
	char a[] = "1000000000";
	char b[] = " 234567890";
	long c;
	c = atol(a) + atol(b);
	printf("c = %d\n",c);
}

void test04() 
{
	char a[] = "1000000000";
	char b[] = "123.456";
	char c[] = " 123e-2";
	printf("a =%f\n",strtod(a,NULL));
	printf("b =%f\n",strtod(b,NULL));
	printf("c =%f\n",strtod(c,NULL));
}

void test05() 
{
	char a[] = "1000000000";
	char b[] = "1000000000";
	char c[] = "  ffff";
	printf("a = %d\n",strtol(a,NULL,0));
	printf("b = %d\n",strtol(b,NULL,2));
	printf("c = %d\n",strtol(c,NULL,16));
}

void test06() 
{
	char a[] = "1000000000";
	char b[] = "1000000000";
	char c[] = "  ffff";
	printf("a = %d\n",strtoul(a,NULL,0));
	printf("b = %d\n",strtoul(b,NULL,2));
	printf("c = %d\n",strtoul(c,NULL,16));
}

void test07() 
{
	int a = 217;
	char b;
	printf("before toascii(): a value = %d(%c )\n",a,a);
	b = toascii(a);
	printf("after toascii(): a value = %d(%c )\n",b,b);
}

void test08() 
{
	char s[] = "aBcDeFgH12345;!#$";
	int i;
	printf("before tolower() : %s\n",s);
	for (i = 0; i < sizeof(s); i++)
		s[i] = tolower(s[i]);
	printf("after tolower() : %s\n",s);
}

void test09() 
{
	char s[] = "aBcDeFgH12345;!#$";
	int i;
	printf("before toupper(): %s\n",s);
	for (i = 0; i < sizeof(s); i++)
		s[i] = toupper(s[i]);
	printf("after toupper(): %s\n",s);
}

#define MAX 100
//#define _CRT_NONSTDC_NO_DEPRECATE 
//#define _CRT_SECURE_NO_WARNINGS 1

void test10()
{
	double a = 123.45;
	double b = -1234.56;
	char* ptr = NULL;
	char buf[MAX];
	_gcvt(a, 5, buf);
	printf("a value = %s\n",buf);

	ptr = _gcvt(b,6,buf);
	printf("b value = %s\n",ptr);
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
	//test08();
	//test09();
	test10();
	/*int a = 0;
	scanf("%d",&a);
	printf("a = %d",a);
	
	return 0;
}
*/