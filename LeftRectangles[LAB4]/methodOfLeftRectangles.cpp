#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int a,n,i;
float b,h,x,s;
int main()
{
printf("Interval [a;b]\n");
printf("a=");
scanf("%d",&a);
printf("b=");
scanf("%f",&b);
printf("K-st tochok \n");
scanf("%d",&n);
h=(float) (b-a)/n;
printf("h=%f",h);

x=a;
s=0;
for(i=0;i<=(n-1);i++)
{
s+=(x*x)+(5*x);
x=x+h;
}
printf("\nResult : ");
printf("s=%.2f \n",s);



system("PAUSE");
return 0;
}
