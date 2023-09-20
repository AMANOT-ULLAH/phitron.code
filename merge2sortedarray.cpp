#include<bits/stdc++.h>
using namespace std;
void mergearr(int a[],int n,int b[],int m,int c[]);
int main ()
{
    int n,m;
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
int c[n+m];
mergearr(a,n,b,m,c);

}

void mergearr(int a[],int n,int b[],int m,int c[])
{
    int i=0,j=0,k=0;
    while (i<n&&j<m)
    {
        if(a[i]>b[j])
        {
            c[k]=a[i];
            k++;
            i++;
        }
        else  {
            c[k]=b[j];
            k++;
            j++;
        }
    }
    while (i<n)
    {
        c[k++]=a[i++];
    }
    while (j<m)
    {
        c[k++]=b[j++];
    }

    for(int i=0;i<n+m;i++)
    {
        cout<<c[i]<<" ";
    }
    
}