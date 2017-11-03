#include <iostream> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <iomanip> 
using namespace std;
 void fff(double *x,double *f){
   	f[0]=4*x[0]*x[0]+x[1]*x[1]-4;
   	f[1]=x[0]-x[1]*x[1]+1;
   }
int main(void){
   double x[2]={2.0,2.0},x_old[2]={2.0,2.0},J[2][2],f[2],x_[2],f_[2];
   double ee=0.0001,h=0.00001;
   bool cond_N;
   int n=2;
   double INVERS[2][2],E[2][2];
   double V[2][2],C[2][2],P[2],X[2],Y[2];
   for(int i=0;i<n;i++)
   	for(int j=0;j<n;j++)
   		if(i==j) E[i][j]=1;
		else E[i][j]=0; 
   do
   {
   	cond_N=false;
   	fff(x,f);
   	for(int i=0;i<n;i++)
   		for(int j=0;j<n;j++)
		   {
   			for(int k=0;k<n;k++)
   				x_[k]=x[k];
   				x_[j]=x[j]+h;
   				fff(x_,f_);
   				J[i][j]=(f_[i]-f[i])/h;
	   }
	for(int b=0;b<n;b++)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				V[i][j]=J[i][j];
				P[i]=E[i][b];
			}
		for(int k=0;k<n;k++){
			Y[k]=P[k]/V[k][k];
			for(int i = k+1;i<n;i++)
			{
				P[i]+=-V[i][k]*Y[k];
				for(int j=k+1;j<n;j++)
				{
					C[k][j]=V[k][j]/V[k][k];
					V[i][j]+=-V[i][k]*C[k][j];	
				}
			}
		}
		X[n-1]=Y[n-1];
		for(int i=n-2;i>=0;i--)
		{
			X[i]=0;
			for(int j=i+1;j<n;j++)
				X[i]+=C[i][j]*X[j];
			X[i]=Y[i]-X[i];
			}
		for(int i=0;i<n;i++)
			INVERS[i][b]=X[i];
		}
		for(int i=0;i<n;i++)
		{
			x[i]=0;
			for(int j=0;j<n;j++)
				x[i]+=INVERS[i][j]*f[j];
				x[i]=x_old[i]-x[i];
			}

		/**for(int i=0;i<n;i++){
			cout<<x[i];
		}*/
		for(int i=0;i<n;i++)
		{
			cond_N=cond_N || fabs((x[i]-x_old[i])/x[i]*100)>ee;
			x_old[i]=x[i];
		}
	}
   while(cond_N);
   cout<<"Rozv : ";
   for(int i=0;i<n;i++){
   	cout<<"\t\n"<<x[i] <<endl;
   }
   cout<<4*x[0]*x[0]+x[1]*x[1]-4<<endl;
   	cout<<x[0]-x[1]*x[1]+1;
}
