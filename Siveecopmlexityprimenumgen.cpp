#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>primes;
    vector<bool>visited(n+1);
    for(int i=2;i<=n;i++)
    {
        if(visited[i]==false)//if(!visited[i])
        {
            primes.push_back(i);
            for(int x=2;i*x<=n;x++)
            {
                visited[i*x]=true;
            }
        }
    }
    cout<<primes.size()<<endl;
    for(int i=0;i<primes.size();i++)
    {
        cout<<primes[i]<<" ";
    }
    cout<<endl;
}
/*
O(n*n) it is not
outer loop O(n)
inner loop --O(ln n)
i=2....n/2 times iteration
i=3....n/3
i=4....0 iteration ,n/4
i=5....n/5
......
i=n....n/n.....
sum the iteration , n/2+n/3+n/4+n/5+........n(1+1/2+1/3+.....)harmonic series
sum of this series=ln n;

O(nlogn); ************

for multiplz visited  array , here we see this harmonic series
*/
