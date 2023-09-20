
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
     void Pop()
   {
       sz--;
   }

    void Print()
    {
        for(int i=0; i<sz; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
int main ()
{
    Array a;
    a.push(11);
    a.push(12);
    a.push(15);
    a.Print();
    a.Pop();
      a.Print();
      a.Pop();
      a.Print();
      a.Pop();
      a.Print();
}
