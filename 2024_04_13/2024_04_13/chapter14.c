#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//��ʮ���� ��ʽ�������������

void test01() 
{
	int i = 150;
	int j = -100;
	double k = 3.14149;
	int ret = fprintf(stdout,"%d %f %x\n",j,k,i); // -100 3.141490 96
	printf("ret = %d\n",ret);
	fprintf(stdout,"%2d %*d\n",i,2,i);  //150 150!!!!!
}                     //%2d  ����2������ʽ*�У�����%2dһ��

void test02() 
{
	int i;
	unsigned int j;
	char s[5];
	fscanf(stdin,"%d %x %5[a-z] %*s %f",&i,&j,s,s);
	printf("%d %d %s\n",i,j,s);
	//10 0x1b aaaaaaaa bbbbbbb  //�Ӽ�������    !!!!!!!
	//10 27 aaaaa				//0x1b��ת����27������b�ַ���
}
/*  ����
	%d �����Ĳ����ᱻת���ɡ����з��ŵ�ʮ��������
	%u                     �����޷��ŵ�ʮ��������
	%o					   �����޷��ŵİ˽�������
	%x �������Ĳ����ᱻת���ɡ��޷��ŵ�ʮ���������֣�����Сдabcdef��ʾ
	%X						 ��                    �����Դ�дABCD��ʾ

	��������
	%f double �͵Ĳ�����ת����ת����ʮ���Ƶ����֣���ȡ��С����������λ����������
	%e ��double �͵Ĳ�����ָ������ѧ�Ǻţ���ʽ��ӡ����һ�����ֻ���С����ǰ��
	            ��λ������С����󣬶���ָ�����ֻ���Сд��e����ʾ
	%E ��%e������ͬ��Ψһ������ָ�����ֽ��Դ�д��E����ʾ
	
	�ַ�
	%c �������Ĳ����ᱻת����unsigned char �ʹ�ӡ��
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
	%d ��������ݻᱻת�ɡ����з��ŵ�ʮ�������֣�int��
	%i ��������ݻᱻת�ɡ���						���������������"0x"��"0X"
	   ��ͷ����ת��ʮ���������֣�����"0"��ͷ��������ת���˽������֣������������ʮ����
	%o ��������ݻᱻת���ɡ����޷��ŵİ˽������֣�unsigned int��
	%u ��������ݻᱻת���ɡ����޷��ŵ���������unsigned int��
	%x ���������Ϊ�޷��ŵ�ʮ���������֣�ת�������unsigned int �ͱ���
		%X ͬ%x��
	%f ���������Ϊ�з��ŵĸ���������ת�������float�ͱ���
		%e %E %g ͬ%f
	%s ��������Ϊ�Կո��ַ�Ϊ��ֹ���ַ���
	%c ��������Ϊ��һ�ַ�
	[] ��ȡ���ݵ�ֻ���������ڵ��ַ�����[a-z]
	[^]��ȡ���ݵ������������ŵ� ^ ���ź���ַ����֣���[^0-9]
			%[*][size][l][h]type
	����ֵ���ɹ����ز�����Ŀ��ʧ���򷵻�-1
*/
void test04() 
{
	int i;
	unsigned int j;
	char s[5];          //*����ö�Ӧ�Ĳ������ݺ��Բ����档sizeΪ���������������ݳ���
	scanf("%d %x %5[a-z] %*s %f",&i,&j,s,s);
	printf("%d %d %s\n",i,j,s);              
	         //10 0x1b aaaaaaaa bbbbbbb
		     //10 27 aaaaa
}
void test05() //��ʽ���ַ������� snprintf
{
	char a[] = "This is string A!";
	char buf[80];
	int ret = snprintf(buf,sizeof(buf),">>> %s <<<\n",a);
	printf("ret = %d\n",ret);
	printf("%s",buf);
}

void test06() //sprintf��ʽ���ַ������� ������ʹ�ô˺����������ջ�����buffer overflow��
{				//�����snprintf()
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
	sscanf(input,"%d %x %5[a-z] %*s %f",&i,&j,s,s);  //�����⣬ջ���ƻ���
	printf("%d %d %s\n",i,j,s);  //10 27 aaaaa
} 
//vfprintf  ��ʽ��������ݵ��ļ�      �ο�fprintf()��vprintf()

//vfscanf ��ʽ���ַ������� �ο�fscanf()��vprintf().



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