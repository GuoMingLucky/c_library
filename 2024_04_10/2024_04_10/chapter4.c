#define _CRT_SECURE_NO_WARNINGS 1

//ctime()和loacltime()   可以精准显示时间

#include<stdio.h>
#include<time.h>
//#include<unistd.h>
//#include<sys/time.h>

void test01() 
{
	time_t timep;
	time(&timep);
	printf("%s",asctime(gmtime(&timep)));
	//Wed Apr 10 05:59:04 2024
}

void test02() 
{
	long long int seconds = time((time_t *)NULL);
	printf("%lld\n",seconds);
	//1712729245
}

void test03() 
{
	char* wday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	printf("%d/%d/%d ",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
	printf("%s %d: %d: %d\n",wday[p->tm_wday],p->tm_hour,p->tm_min,p->tm_sec);
}                    //2024/4/10 Wed 6: 25: 49

void test04() 
{
	time_t timep;
	time(&timep);
	printf("%s",ctime(&timep));
	//Wed Apr 10 14:36:57 2024
}

/*void test05_()
{
	struct timeval  tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	printf("tv_sec: %d\n",tv.tv_sec);
	printf("tv_usec: %d\n",tv.tv_usec);
	printf("tz_minuteswest: %d\n",tz.tz_minuteswest);
	printf("tz_dsttime: %d\n",tz.tz_dsttime);
}
*/

void test06() 
{
	char* wday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	time_t timep;
	struct tm *p;
	time(&timep);
	p = localtime(&timep);//取得当地时间
	printf("%d/%d/%d ",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
	printf("%s %d: %d: %d\n",wday[p->tm_wday],p->tm_hour,p->tm_min,p->tm_sec);
}    //2024/4/10 Wed 15: 13: 23

void test07() 
{
	time_t timep;
	struct tm* p;
	time(&timep);
	printf("time():%lld\n",timep);
	p = localtime(&timep);
	timep = mktime(p);
	printf("time() -> localtime() -> mktime() : %lld\n",timep);
}   //time() :1712733908
    //time()->localtime()->mktime() : 1712733908

int main() 
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05_();
	//test06();
	test07();

	return 0;
}