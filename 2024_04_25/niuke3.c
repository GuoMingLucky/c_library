#include <stdio.h>

int main() {
    int n = 0;
    double sum = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sum +=(float)1/i; 
    }
    printf("%.6lf",sum);
    return 0;
}
#include <stdio.h>

int main() {
    int n = 0;
    int sum = 0;
    int sum2 = 0;
    scanf("%d",&n);
    for(int i =n;i>0;i--)
    {
        if(i%2==0)
        {
            sum -=i; 
        }
        else 
        {
            sum2 +=i;
        }
    }
    printf("%d",sum+sum2);
    return 0;
}
#include <stdio.h>

int main() {
    for(int i = 1;i<=9;i++)
    {
        for(int j =1;j<=i;j++)
        {
            printf("%d*%d=%2d ",j,i,i*j); //%2d--12或者 9
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
 // 质数定义：大于1的自然数，除了1和本身外，不能被其他自然数整除
int main() {
    int count = 0;
    int n =1;
    for(int i =100;i<1000;i++)
    {
        n = 1;
        for(int j = 2;j<i;j++)
        {
            if (i%j==0) {
                n = 0;
                break;
            }
        }
        if(n)
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
#include <stdio.h>

int main() {
    int N = 0;
    scanf("%d",&N);
    int count1,count2 = 0;
    for(int i = 1;i<=N;++i)
    {
        if(i%2==0)
        {
            count1++;
        }else
        {
            count2++;
        }
    }
    printf("%d %d",count1,count2-1);

    return 0;
}
#include <stdio.h>

long long int add(long long int n)
{
    if(n<0)
        return 0 ;
    else 
        return n+add(n-1);
}

int main() {
    long long int n = 0;
    scanf("%lld",&n);
    long long int ret = add(n);
    printf("%lld",ret);
    return 0;
}