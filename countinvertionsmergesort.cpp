
#include<bits/stdc++.h>
using namespace std;

vector<int> mergsrt(vector<int>& a, long long& inv)
{
    if(a.size() <= 1)
        return a;

    int mid = a.size() / 2;

    vector<int> b;
    vector<int> c;

    for(int i = 0; i < mid; i++)
    {
        b.push_back(a[i]);
    }
    for(int i = mid; i < a.size(); i++)
    {
        c.push_back(a[i]);
    }

    vector<int> sorted_b = mergsrt(b, inv);
    vector<int> sorted_c = mergsrt(c, inv);
    vector<int> sorted_a;
    int idx1 = 0, idx2 = 0;

    while (idx1 < sorted_b.size() || idx2 < sorted_c.size()) {
        if (idx1 == sorted_b.size()) {
            sorted_a.push_back(sorted_c[idx2++]);

        } else if (idx2 == sorted_c.size()) {
            sorted_a.push_back(sorted_b[idx1++]);

        } else if (sorted_b[idx1] <= sorted_c[idx2]) {
            sorted_a.push_back(sorted_b[idx1++]);

        } else {
            sorted_a.push_back(sorted_c[idx2++]);

            inv += (sorted_b.size() - idx1); 
        }
    }

    return sorted_a;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long inv = 0;
    vector<int> ans = mergsrt(a, inv);

    cout <<  inv << endl;


}
