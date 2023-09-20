#include<bits/stdc++.h>
using namespace std;
//mem complexity O(n)
class Array
{
private:
    int *arr;
    int cap;
    int sz;
    void increasesize()
    {
        cap=cap*2;
        int *temp=new int[cap];
        for(int i=0; i<sz; i++)
        {
            temp[i]=arr[i];
        }
        delete [] arr;
        arr=temp;
    }
public:
    Array()
    {
        arr=new int[1];
        cap=1;
        sz=0;
    }
    //time comp
    void push(int x)
    {
        if(cap<=sz)
        {
            increasesize();
        }
        arr[sz]=x;
        sz++;
    }
    //o(sz)
    void Print()
    {
        for(int i=0; i<sz; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int Size()
    {
        return sz;
    }
    void getelement(int idx)
    {
        if(idx>=sz)
        {
            cout<<"not pound"<<endl;

        }
        else
            cout<<arr[idx];
    }
    //o(sz-pos)
    void Insert(int pos,int x)
    {
        if(cap<=sz)
        {
            increasesize();
        }
        for(int i=sz-1;i>=pos;i--)
        {
            arr[i+1]=arr[i];
        }
        arr[pos]=x;
        sz++;
    }
};
int main()
{
    Array a;
    a.push(10);
    a.push(10);
    a.push(10);

    a.Insert(2,123);
    a.Print();
    cout<<a.Size()<<endl;
    for(int i=0; i<a.Size()+2; i++)
    {
        a.getelement(i);
        cout<<endl;
    }

}
