#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

void test01() 
{
	int a = 10000;
	FILE* pf = fopen("test.txt","wb"); //�Զ����Ƶ���ʽд���ļ���
	fwrite(&a,4,1,pf);  //������д���ļ�������aֵָ��ĵ�ַ�е�����д�뵽�ļ�����
						//����СΪ4�����ݣ�һ����д���ļ�����
	fclose(pf);
	pf = NULL;
}

void test02()   //fputs ʾ��
{
	FILE* pFile;
	//���ļ������ļ������ڣ���ᴴ�������ļ�
	pFile = fopen("myfile.txt","w");
	//�ļ�����
	if (pFile != NULL) 
	{
		fputs("fopen example",pFile); //���ַ�������д�뵽pFileָ��ָ����ļ���
		//�ر��ļ�
		fclose(pFile);
	}
}

void test03() //fputcʾ��
{
	FILE* pFile;
	pFile = fopen("myfile.txt","a");
	if (pFile != NULL) 
	{
		fputc('a',pFile); 
		fclose(pFile);
	}
}

void test04()  //fgetc ʾ��  ���ļ��ж�ȡһ���ַ����������ļ�βû������ʱ����EOF
{
	FILE* pFile;
	pFile = fopen("myfile.txt", "r");
	if (pFile != NULL)
	{
		int c;
		while ((c = fgetc(pFile)) != EOF)  //EOF�����ж��Ƿ�������ļ�β
			printf("%c",c);
		fclose(pFile);
	}
}
				//ֱ�����������ַ��������ļ�β�����Ѷ���size-1���ַ�Ϊֹ
			    //fgets ���ļ��ж�ȡ�ַ���,�����뵽����s��ָ���ڴ�ռ�
				//char *fgets(char* s,int size,FILE* stream);
				//����ֵ���ɹ�����sָ�룬����NULL���ʾ�д�����

void test05() 
{
	FILE* pFILE;
	pFILE = fopen("myfile.txt","r");
	char* s = (char *)malloc(sizeof(char)*100);
	if (s == NULL) 
	{
		perror("malloc failed");
	}
	assert(fgets(s, 100, pFILE));
	printf("%s",s);
	free(s);
	s = NULL;
	fclose(pFILE);
}

void test06() //fread fwrite
{
	FILE* pFile;
	pFile = fopen("myfile1.txt","w+");
	int size_write;
	if (pFile != NULL)
	{
		size_write = fwrite("hello,world",1, strlen("hello,world"), pFile);
		printf("..........\n");
		printf("size_write:%d\n",size_write);
		fclose(pFile);
	}
	//FILE* pFile;
	pFile = fopen("myfile1.txt", "r+");                //   !!!!!
	char* s = (char*)malloc(sizeof("hello,world") + 1);
	if (s == NULL) 
	{
		perror("malloc failed");
	}
	else 
	{
		memset(s, 0, strlen("hello,world")+1);
		int size_fread = fread(s, 1, strlen("hello,world"), pFile);
		printf("size_fread:%d\n", size_fread);
		printf("%s", s);
		free(s);
		s = NULL;
		fclose(pFile);
	}
}
/*
	int fprintf(FILE *stream,const char* format,����);
	��������������streamָ�����ļ��У�ֱ�������ַ�������'\0'Ϊֹ��
	�ɹ�����ʵ��������ַ�����ʧ�ܷ���-1

	int fscanf(FILE *stream,const char* format,����);
	��Ӳ���stream���ļ����ж�ȡ�ַ������ٸ��ݲ���format�ַ�����ת������ʽ������
*/
void test07()  // fprintf example
{
	FILE* pFile;
	pFile = fopen("myfile1.txt","a");
	int i = 100;
	fprintf(pFile,"\nfile context��%d",i);  //\nfile context��100��׷�ӵ��ļ�ĩβ
	fclose(pFile);
}
void text08() 
{
	int i = 0;
	int fs_size = fscanf(stdin,"%d",&i);
	printf("fs_size = %d\n",fs_size);
	int fp_size = fprintf(stdout, "%d", i);
	printf("fp_size = %d\n",fp_size);
}
void test09()  // fscanf fprintf example
{
	FILE* pFile;
	pFile = fopen("myfile1.txt", "w+");
	char str1[20] = { 0 };
	char str2[20] = { 0 };
	char str3[20] = { 0 };
	int i = 0;
	fprintf(pFile,"This is a 100\n");
	rewind(pFile);
	int size = fscanf(pFile,"%s%s%s%d",str1,str2,str3,&i);
	printf("size = %d\n",size);
	printf("%s %s %s %d",str1,str2,str3,i);

	fclose(pFile);
}

void test10() 
{                            // SEEK_CUR  SEEK_END  SEEK_SET
	FILE* pFile;
	pFile = fopen("example.txt","wb");
	fputs("This is an apple.",pFile);
	fseek(pFile,9,SEEK_SET); //ָ���±�ӿ�ͷ�����ƶ���9λ
	fputs(" sam",pFile);
	fclose(pFile);
}
void test11()   //ftell �����ļ����ֽڴ�С
{
	FILE* pFile;
	long size;
	pFile = fopen("myfile.txt","rb");
	if (pFile == NULL)
		perror("Error opening file");
	else
	{
		fseek(pFile, 0, SEEK_END);
		size = ftell(pFile);
		fclose(pFile);
		printf("Size of myfile.txt: %ld bytes.\n", size);
	}
}

void test12() 
{
	int count = 0;
	FILE* pFile;
	pFile = fopen("pFile.txt","w+");
	for (int i = 'A'; i <= 'Z'; i++) 
	{
		fputc(i, pFile);
		count++;
	}
	rewind(pFile);
	char Buffer[27] = { 0 };
	fgets(Buffer, count+1,pFile);
	printf("%s",Buffer);
}
//feof��ʹ��  �ı��ļ� EOF��fgetc�� NULL��fgets��
void test13() 
{
	int c;
	FILE* fp = fopen("test.txt","r");
	if (!fp) 
	{
		perror("File opening failed");
		return EXIT_FAILURE;
	}
	//fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
	while ((c = fgetc(fp)) != EOF) 
	{
		putchar(c);
	}
	//�ж���ʲôԭ�������
	if (ferror(fp)) 
	{
		puts("I/O error when reading");
	}
	else 
	{
		puts("End of file reached successfully");
	}
	fclose(fp);
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
	//text08();
	//test09();
	//test10();
	//test11();
	//test12();
	test13();

	return 0;
}