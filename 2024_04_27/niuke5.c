#include <stdio.h>

int main() {
    int m,n = 0;
    int ret = 0;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        ret = 0;
        for(int i=m;i<=n;i++)
        {
            int l1,l2,l3 = 0;
            l1 = i%10;
            l2 = (i/10)%10;
            l3 = (i/100)%10;
            if((l1*l1*l1+l2*l2*l2+l3*l3*l3)==i)
            {
                printf("%d ",i);
                ret = 1;
            }
        }
        if(ret==0)
        {
            printf("no");
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d",&n);
    int Chinese,Math,English = 0;
    int count = 0;
    for(int i =0;i<n;i++)
    {
        scanf("%d%d%d",&Chinese,&Math,&English);
        int average = 0;
        average = (Chinese+Math+English)/3;
        if(average<60)
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
#include <stdio.h>

int main() {
    int count =0;
    for(int i=1;i<2020;i++)
    {   
        int j = i;
        while(j>0)
        {
            if(j%10==9)
            {
                count++;
                break;   
            }else
            {
                j = j/10;
            }
        }    
    }
    printf("%d",count);
    return 0;
}
#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d",&n);
    int count = 0;
    while(n!=1)
    {
        if(n%2!=0)
        {
            n = 3*n+1;
            count++;
        }
        else 
        {
            n = n/2;
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
#include <stdio.h>

int main() {
    int n =0;
    scanf("%d",&n);
    int a = 0;
    int sum =0;
    while (n) 
    {
        a = n%10;
        sum +=a;
        n = n/10; 
    }
    printf("%d",sum);
    return 0;
}
#include <stdio.h>

int main() {
    long long int n = 0;
    scanf("%lld",&n); //Sn=n(a1+an)/2
    long long int sum1 = 0;
    long long int sum2 = 0;
    //求1 - n总的值
    for(int i =1;i<=n;i++)
    {
        sum1 += i;
        sum2 +=sum1;
    }
    printf("%lld",sum2);
    return 0;
}