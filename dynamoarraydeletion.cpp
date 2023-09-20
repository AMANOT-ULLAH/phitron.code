#include<bits/stdc++.h>
using namespace std;

class Array
{
private:
    int *arr;
    int sz;
    int cap;
    void increase()
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
        arr=new int[1];
        cap=1;
        sz=0;
    }
 void Push(int x)
   {
       if(cap<=sz)
       {
           increase();
       }
       arr[sz]=x;
       sz++;
   }
   //size=cap/2; then cap=cap/2
   //O(1)
   void Pop()
   {
       sz--;
   }
   //o(sz)
   void Erase(int pos)
   {
       if(pos>=sz)
        cout<<"doesnt exist"<<endl;
       for(int i=pos+1;i<sz;i++)
       {
           //swap(arr[i+1],arr[i]);
           arr[i-1]=arr[i];
       }
       sz--;
   }
   void print()
   {
       for(int i=0;i<sz;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
   }
};

int main()
{
    Array a;
    a.Push(1888);
    a.Push(13);
    a.Push(15);
    a.Push(15);
    a.print();
    a.Pop();
     a.print();
     a.Erase(0);
     a.print();
}
