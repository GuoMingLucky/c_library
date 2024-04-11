#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

void test01()
{
	char* s = "0123456789012345678901234567890";
	char* p;
	p = strchr(s,'5');   //index不行  //查找字符串中第一次出现的指定字符
	printf("%s\n",p);
}

void test02() 
{
	char* s = "0123456789012345678901234567890";
	char* p;
	p = memchr(s,'5',10);  //在某一内存范围中查找一特定字符
	printf("%s\n",p);
}

void test03() 
{
	char* a = "aBcDeF";
	char* b = "AbCdEf";
	char* c = "aacdef";
	char* d = "aBcDeF";
	                             //比较内存内容
	printf("memcmp(a,b) : %d\n",memcmp((void *)a,(void *)b,6));
	printf("memcmp(a,c) : %d\n",memcmp((void *)a,(void *)c,6));
	printf("memcmp(a,d) : %d\n",memcmp((void *)a,(void *)d,6));
}

void test04() 
{
	char a[30] = "string(a)";
	char b[30] = "string\0string";
	int i;
	strcpy(a,b);
	printf("strcpy(): ");  //strcpy(): string a)

	for (i = 0; i < 30; i++)
		printf("%c ",a[i]);
	memcpy(a,b,30);        //不会因为\0而结束
	printf("\nmemcpy(): ");  //memcpy(): string string
	for (i = 0; i < 30; i++)
		printf("%c ",a[i]);
}

/*void test05()
{         //linux 特有的函数
	char a[] = "This_is_memfrob";
	printf("Before first memfrob () : %s \n",a);
	memfrob(a,strlen(a));
	printf("After first memfrob () : %s \n",a);
	memfrob(a,strlen(a));
	printf("After second memfrob () : %s \n",a);
}*/

void test06() 
{
	char a[30] = "string (a) ";
	char b[30] = "string\0string";
	int i;
	strcpy(a,b);
	printf("strcpy () : ");
	for (i = 0; i < 30; i++)
		printf("%c ",a[i]);
	memcpy(a,b,30);
	printf("\nmemcpy() : ");
	for (i = 0; i < 30; i++)
		printf("%c ",a[i]);
	printf("\n");
	memmove(a,b,30);
	printf("\nmemmove() : ");
	for (i = 0; i < 30; i++)
		printf("%c ",a[i]);
}/*strcpy () : s t r i n g  ( a )
memcpy() : s t r i n g  s t r i n g

memmove() : s t r i n g  s t r i n g*/

void test07() 
{
	char s[30];
	memset(s,'A',sizeof(s));
	s[29] = '\0';
	printf("%s\n",s);
}

void test08() 
{
	char* s = "0123456789012345678901234567890";
	char* p;

	p = strrchr(s,'5');  //rindex在这里不能运行
	printf("%s\n",p);
}

/*void test09()
{
	char* a = "aBcDeF";
	char* b = "AbCdEf";
	if (!strcasecmp(a, b))    //strcasecmp不能运行
		printf("%s = %s\n",a,b);
}*/

void test10() 
{
	char a[30] = "string (1) ";
	char b[] = "string (2) ";
	printf("before strcat () : %s\n",a); //string (1)
	printf("after strcat () : %s\n",strcat(a,b));//string (1) string (2)
}

void test11() 
{
	char* a = "aBcDeF";
	char* b = "AbCdEf";
	char* c = "aacdef";
	char* d = "aBcDeF";

	printf("strcmp(a , b) : %d\n",strcmp(a, b));
	printf("strcmp(a , c) : %d\n",strcmp(a, c));
	printf("strcmp(a , d) : %d\n",strcmp(a, d));
}

void test12()  //返回字符串中连续不含指定字符串内容的字符数
{
	char* str = "Linux was first developed for 386/486-based PCs.";
	printf("%d\n",strcspn(str, " "));
	printf("%d\n",strcspn(str,"/-"));
	printf("%d\n",strlen("Linux was first developed for 386"));
	printf("%d\n",strcspn(str,"1234567890"));
	printf("%d\n",strlen("Linux was first developed for"));
}

void test_13() 
{
	char a[] = "strdup";
	char* b;
	b = _strdup(a);
	printf("b[] = \"%s\"\n",b);  //b[] = "strdup"
}
/*
void test14() 
{
	char a[] = "strfry";
	int i;
	for (i = 0; i < 4; i++)
		printf("a[] = \"%s\"\n",strfry(a));
}
*/
/*void test15()
{                         //无法使用
	char* a = "aBcDeF";
	char* b = "AbCdEf";
	if (!strncasecmp(a, b,3))
		printf("%s = %s\n", a, b);
}*/

void test16() 
{
	char a[30] = "string (1) ";
	char b[] = "string (2) ";
	printf("before strcat () : %s\n",a);
	printf("after strcat () : %s\n",strncat(a,b,6));
}

void test17()
{
	char* a = "abcdef";
	char* b = "abcdeF";
	printf("%d\n", strncmp(a, b, 6));
}

void test18() 
{
	char* s = "0123456789012345678901234567890";
	char* p;
	p = strpbrk(s,"a1 839");
	printf("%s\n",p);           //123456789012345678901234567890
	p = strpbrk(s,"4398");
	printf("%s\n",p);         //3456789012345678901234567890
}

void test19() 
{
	int len;
	const char str1[] = "ABCDEFG";
	const char str2[] = "ABCD";

	len = strspn(str1,str2);
	printf("初始段匹配长度 %d\n", len);
}

void test20() 
{
	char* s = "0123456789012345678901234567890";
	char* p;               //返回指定字符串第一次出现的地址
	p = strstr(s,"901");  //9012345678901234567890
	printf("%s\n",p);
}

void test21() 
{
	char str[] = "This is - www.runoob.com - website";
	const char s[2] = "-";
	char* token;
	//获得第一个子字符串
	token = strtok(str,s);
	//继续获取其他的子字符串
	while (token != NULL) 
	{
		printf("%s\n",token);
		token = strtok(NULL,s);
	}
}

int main() 
{
	//test01();
	//test02();
	//test03();
	//test04();
	printf("hehe\n");
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	//test11();
	//test12();
	//test_13();
	//test_14();
	//test15();
	//test16();
	//test17();
	//test18();
	//test19();
	//test20();
	test21();

	return 0;
}