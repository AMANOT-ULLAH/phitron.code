#include<bits/stdc++.h>
using namespace std;

vector<int> mergsrt(vector<int>a)
{
    if(a.size()<=1)
        return a;

    int mid=a.size()/2;

    vector<int>b;
    vector<int>c;

    for(int i=0;i<mid;i++)
    {
        b.push_back(a[i]);
    }
    for(int i=mid;i<a.size();i++)
    {
        c.push_back(a[i]);
    }

    vector<int>sorted_b=mergsrt(b);
    vector<int>sorted_c=mergsrt(c);
    vector<int>sorted_a;
    int idx1=0,idx2=0;

    for(int i=0; i<a.size(); i++)
    {
        if(idx1==sorted_b.size())
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
        else if(idx2==sorted_c.size())
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else if(sorted_b[idx1]<sorted_c[idx2])
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }


    }

    return sorted_a;
}


int main()
{
    int n;
    cin>>n;

    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int>ans=mergsrt(a);
    for(int i=0; i<a.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
}



/*

O(n)=nlog n


এখানে ১০,৬,৭,৪ ভেক্টরটা  মেইন থেকে কল হবে।
            দুইটা ভাগে ভাগ হবে বি তে ১০ যাবে এবং সি তে ৬ ৭ ৪ যাবে ।
                সরটেড এ বি তে ১০ রিটার্ন করবে  অন্যদিকে সি আবার ভাগ হবে এবং সর্টেড এরে তে থাকবে ,  দুইটা ভাগে ভাগ হয়ে  ৬য়ার ৭ ৪ এ ভাগ হবে ।
                       এভাবে করে সিঙ্গেল না হওয়া পর্যন্ত ভাংবে , এরপরে সিঙ্গেল গুলা সর্ট হবে মানি কনকর হবে ,

*/
