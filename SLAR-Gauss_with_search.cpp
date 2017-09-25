#include <iostream> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <iomanip> 
using namespace std;

int main(void){
    int n = 4, h, w, z , inx[4] = {0,1,2,3};
    double A[4][4] = {
	{0,2.62+0.2*1,4.1,1.9},
	{3.92,8.45,7.78-0.2*1,2.46},
	{3.77,7.21+0.2*1,8.04,2.28},
	{2.21,3.65-0.2*1,1.68,6.69}};
double B[4]={-10.65+0.2*1,12.21,15.45-0.2*1,-8.35};
double V[4][4],C[4][4],P[4],X[4],Y[4];
double max, value;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        {V[i][j] = A[i][j]; P[i]=B[i];}

for(int k=0;k<n;k++)
{
    max=fabs(V[k][k]);h=k;w=k;
    for(int l=k;l<n;l++)
        for(int f=k;f<n;f++)
            if(max<fabs(V[l][f]))
            {
                max=fabs(V[l][f]);
                h=l;
                w=f;
            }
    value=P[k]; P[k]=P[h]; P[h]=value;
    for(int d=0;d<n;d++){
        value=V[k][d];
        V[k][d]=V[h][d];
        V[h][d]=value;
    }
    z=inx[k];
    inx[k]=inx[w];
    inx[w]=z;
    for(int d=0;d<n;d++)
    {
        if(d<k){
            value=C[d][k];
            C[d][k]=C[d][w];
            C[d][w]=value;
        }
        else{
            value=V[d][k];
            V[d][k]=V[d][w];
            V[d][w]=value;
        }
    }
    Y[k]=P[k]/V[k][k];
    for(int i=k+1;i<n;i++)
    {
        P[i]+=V[i][k]*Y[k];
        for(int j=k+1;j<n;j++)
        {
            C[k][j]=V[k][j]/V[k][k];
            V[i][j]+=-V[i][k]*C[k][j];
        }
    }
}

for(int i=0;i<n;i++)
X[i]=0;
X[n-1]=Y[n-1];
for(int i=n-2;i>=0;i--)
{
    for(int j=i+1;j<n;j++)
        X[i]+=C[i][j]*X[j];
    X[i]=Y[i]-X[i];
}

}
