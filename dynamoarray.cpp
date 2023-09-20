#include<bits/stdc++.h>
using namespace std;

class Array
{
private:
    int *arr;
    int cap;
    int sz;
    void Increase_size()
    {
        cap=cap*2;
        int *temp=new int[cap];
        for(int i=0;i<sz;i++)
        {
            temp[i]=arr[i];
        }
        delete [] arr;
        arr=temp;
    }
public:
    Array()
    {
        arr=new int [1];
        cap=1;
        sz=0;
    }
    void Push_back(int x)
    {
        if(cap==sz)
        {
            Increase_size();
        }
        arr[sz]=x;
        sz++;
    }
    void print()
    {
        for(int i=0;i<sz;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};

int main()
{
    Array a;
    a.Push_back(10);
    a.Push_back(20);
    a.Push_back(30);
    a.Push_back(40);
    a.Push_back(50);

    a.print();
}
