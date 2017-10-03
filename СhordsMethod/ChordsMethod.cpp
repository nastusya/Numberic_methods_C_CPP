#include <iostream>
#include <math.h>
#include <locale.h>
using namespace std;
double f(double x)
{
return cos(x)-(1/(x+2));
}
double findRoot(double a, double b, double e)
{
while(fabs(f(b)) > e)
{
a = b - ((b - a) * f(b))/(f(b) - f(a));
b = a - ((a - b) * f(a))/(f(a) - f(b));
}
return b;
}
int main()
{
setlocale(LC_ALL,"Russian");
double a, b, e;
cout<<" ������� i�������� a = "; cin>>a;
cout<<" Ki���� i�������� b = "; cin>>b;
cout<<" ������� e = "; cin>>e;
cout<<" ���i�� x = "<<findRoot(a, b, e)<<endl;
cout<<" ���i�� � �i�����i" << f(findRoot(a,b,e)) << endl;
system("pause");
}
