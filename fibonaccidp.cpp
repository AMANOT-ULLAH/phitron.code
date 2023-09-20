#include<bits/stdc++.h>
using namespace std;
int save[100];
int called=0;

int fibo(int n)
{

    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(save[n]!=0)
        return save[n];
    int x=fibo(n-1);
    called++;
    int y=fibo(n-2);
    called++;

    return save[n]=x+y;;
}
int main()
{
    int n;
    cin>>n;


    cout <<"fibo : "<<fibo(n)<<endl;
    cout<<"call : "<<called;

}
