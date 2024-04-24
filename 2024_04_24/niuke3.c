#include <stdio.h>

int main() {
    int year,month,date = 0;
    int year1,month1,date1 = 0;
    scanf("%d %d %d",&year,&month,&date);
    scanf("%d %d %d",&year1,&month1,&date1);
    if(year<=year1)
    {
        printf("yes\n");
    }else if(year==year1 && month<=month1)
    {
        printf("yes");
    }
    else if(year==year1 && month==month1 && date<=date1)
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    return 0;
}
#include <stdio.h>

int main() {
    int a,b,c = 0;
    while (scanf("%d %d %d",&a,&b,&c)!=EOF) 
    {
        if (a+b>c && a+c>b && b+c>a)
        {
            if (a==b||b==c||c==a) 
            {
                if(a==b &&b==c && a==c)
                {
                     printf("Equilateral triangle!\n");
                     //break;
                }
                else
                {
                    printf("Isosceles triangle!\n");
                            //Isosceles triangle!
                    //break;
                }
            }
            else 
            {
                printf("Ordinary triangle!\n");
               // break;
            }
        }
        else 
        {
            printf("Not a triangle!\n");
            //break;
        }
    }
    return 0;
}
#include <stdio.h>

int main() {
    int t = 0;
    while(scanf("%d",&t) != EOF)
    {
        if(t>0)
            printf("%d\n",1);
        else if(t==0)
        {
            printf("0.5\n");
        }else {
            printf("0\n");
        }
    }
    return 0;
}
#include <stdio.h>

int main() {
    int num = 0;
    while(scanf("%d",&num) != EOF)
    {
    switch(num)
    {
        case 200:
            printf("OK\n");
            break;
        case 202:
            printf("Accepted\n");
            break;
        case 400:
            printf("Bad Request\n");
            break;
        case 403:
            printf("Forbidden\n");
            break;
        case 404:
            printf("Not Found\n");
            break;
        case 500:
            printf("Internal Server Error\n");
            break;
        case 502:
            printf("Bad Gateway\n");
            break;
        default:
            break;
    }
    }
    return 0;
}