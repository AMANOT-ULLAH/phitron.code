//memory O(n) for n number input
//for this code ,decreasing swaping loop for same pass, decreasing the comperison with last value
// for this reason advanced bubble sort decreasing the complexity O(n^2)==((n-1)*n)/2



#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int pass=0; pass<n; pass++)
    {
        int last =n-1-pass;
        bool sorted=true;
        for(int j=0; j<=last-1; j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                sorted=false;
            }
        }
        if(sorted)
            break;
        cout<<"after pass"<<pass<<" :";
        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    cout<<"after sorting: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
