#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
int main()
{
	int m, n, count = 0;
	scanf("%d %d", &m, &n);
	int tmp = m ^ n;   //-1      11111111 11111111 11111111 11111111  
	while (tmp)        //-2      11111111 11111111 11111111 11111101
	{
		tmp = tmp & (tmp - 1); //10000000 00000000 00000000 00000011  -1&-2 =>-3
		count++;               //11111111 11111111 11111111 11111101  -3的补码
	}                   //-4     11111111 11111111 11111111 11111011  -4的补码
	printf("%d", count); //      11111111 11111111 11111111 11111001
	return 0;                 // 10000000 00000000 00000000 00000111  -3&-4的补码
}  */                                                                  //-7

//int main()
//{
//	int m;
//	scanf("%d", &m);                   //7  0000 0111
//	printf("奇数位二进制序列为:>");    //1  0000 0001
//	for (int i = 31; i > 0; i -= 2)
//		printf("%d", (m >> i) & 1);   
//	printf("\n偶数位二进制序列为:>");
//	for (int i = 30; i >= 0; i -= 2)
//		printf("%d", (m >> i) & 1);
//	return 0;
//}
//
//int main() 
//{
//	int a = 60;     //0011 1100
//	int b = 45;     //0010 1101
//	int c = a ^ b;  //0001 0001
//	printf("%d",c); //17
//
//	return 0;
//}
//两数交换，不涉及临时变量
//int main() 
//{
//	int a = 5;
//	int b = 7;
//	
//	a = a ^ b;
//	b = a ^ b;//a^b^b = a^0 = a;
//	a = a ^ b;//a^b^a = b^0 = b; 
//	printf("a = %d\nb = %d\n",a,b);
//
//	return 0;
//}
/*
数组nums包含从0到n的所有整数，但其中缺了一个。
请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
*/

//int missArrofNum(int *arr,int len) 
//{
//	int ret = 0;
//	for (int i =0;i<len;i++) 
//	{
//		ret = ret ^ i ^ arr[i];
//	}
//	return ret ^ len;
//}
//
//int main() 
//{
//	int arr[] = {9,8,7,6,4,3,2,1,0};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int ret = missArrofNum(arr,len);
//	printf("ret = %d\n",ret);
//
//	return 0;
//}

//练习题三
//代码实现：求一个整数存储在内存中的二进制中1的个数
//int main() 
//{
//	int a = -1;
//	int count = 0;
//	while (a) 
//	{
//		a = a & (a - 1);
//		count++;
//	}
//	printf("count = %d\n",count);
//	return 0;
//}
//原理：n&(n-1)
// 每一次运算完一次之后，末尾的一位1会消失
//减1的作用就是为了让二进制最后一个1的后面变为0
/*
练习题四
输入一个整数n, 判断n是不是2的次方. 1 2 4 8 16 32
是输出1,否则输出0
输入 : 16
输出 : 1
输入 : 9
输出 : 0
*/
//原理：n^(n-1)
//2的次方的二进制只能有一个1，且在最高位，比如：
//10000 (2的4次方 16)
//100000(2的5次方 32)
//那么只要 n & (n - 1)的结果是0，就说明n是2的次方
//n - 1的作用是什么吗 ?
//把二进制中的最后一个1的后面全部变为0

//int main() 
//{
//	int a = 9;
//	int ret = (a & (a - 1)) == 0 ? 1 : 0;
//	printf("ret = %d\n",ret);
//	
//	return 0;
//}
/*
练习题五
输入两个整数，求两个整数二进制中相同位置不同数字的位置有多少个 ?
输入 : 22 33
输出 : 5
输入 : 1999 2299
输出 : 7
*/
//int main() 
//{
//	int a = 1999;
//	int b = 2299;
//	int ret = a ^ b;  //变相求ret值中的二进制内存中有1的个数
//	int count = 0;
//	while(ret)
//	{
//		ret = ret & (ret - 1);
//		count++;
//	}
//	printf("则这两个整数二进制中相同位置不同是数字的位置有%d个\n",count);
//
//	return 0;
//}
//判断奇偶数
//int main() 
//{
//	int num = 11;
//	int ret = num & 1;  //32位中有31位都是为0，最后一个bit位决定是0（偶数）还是1（奇数）
//	if (ret)
//		printf("奇数\n");
//	else
//		printf("偶数\n");
//
//	return 0;
//}

//  
int main() 
{
	int num = 10; //0000 1010
	int ret;
	ret = num & (-num);
	
	printf("ret = %d\n",ret);
	return 0;
}