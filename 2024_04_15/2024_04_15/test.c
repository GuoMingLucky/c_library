#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

void test01() 
{
	int a = 10000;
	FILE* pf = fopen("test.txt","wb"); //以二进制的形式写到文件中
	fwrite(&a,4,1,pf);  //将数据写至文件流。把a值指向的地址中的数据写入到文件流中
						//将大小为4的数据，一次性写到文件流中
	fclose(pf);
	pf = NULL;
}

void test02()   //fputs 示例
{
	FILE* pFile;
	//打开文件，若文件不存在，则会创建并打开文件
	pFile = fopen("myfile.txt","w");
	//文件操作
	if (pFile != NULL) 
	{
		fputs("fopen example",pFile); //将字符串数据写入到pFile指针指向的文件中
		//关闭文件
		fclose(pFile);
	}
}

void test03() //fputc示例
{
	FILE* pFile;
	pFile = fopen("myfile.txt","a");
	if (pFile != NULL) 
	{
		fputc('a',pFile); 
		fclose(pFile);
	}
}

void test04()  //fgetc 示例  从文件中读取一个字符，若读到文件尾没有数据时返回EOF
{
	FILE* pFile;
	pFile = fopen("myfile.txt", "r");
	if (pFile != NULL)
	{
		int c;
		while ((c = fgetc(pFile)) != EOF)  //EOF可以判断是否读到了文件尾
			printf("%c",c);
		fclose(pFile);
	}
}
				//直到读到换行字符，读到文件尾或者已读了size-1个字符为止
			    //fgets 从文件中读取字符串,并存入到参数s所指的内存空间
				//char *fgets(char* s,int size,FILE* stream);
				//返回值，成功返回s指针，返回NULL则表示有错误发生

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
	int fprintf(FILE *stream,const char* format,……);
	将结果输出到参数stream指定的文件中，直到出现字符串结束'\0'为止。
	成功返回实际输出的字符数，失败返回-1

	int fscanf(FILE *stream,const char* format,……);
	会从参数stream的文件流中读取字符串，再根据参数format字符串来转换并格式化数据
*/
void test07()  // fprintf example
{
	FILE* pFile;
	pFile = fopen("myfile1.txt","a");
	int i = 100;
	fprintf(pFile,"\nfile context：%d",i);  //\nfile context：100把追加到文件末尾
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
	fseek(pFile,9,SEEK_SET); //指针下标从开头往后移动到9位
	fputs(" sam",pFile);
	fclose(pFile);
}
void test11()   //ftell 计算文件的字节大小
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
//feof的使用  文本文件 EOF（fgetc） NULL（fgets）
void test13() 
{
	int c;
	FILE* fp = fopen("test.txt","r");
	if (!fp) 
	{
		perror("File opening failed");
		return EXIT_FAILURE;
	}
	//fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
	while ((c = fgetc(fp)) != EOF) 
	{
		putchar(c);
	}
	//判断是什么原因结束的
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