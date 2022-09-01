#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>prime;
bitset<20000000>status;
void sieve()
{
    ll n=20000000;
    status.set();
    status[0]=0;
    status[1]=0;
    for(int i=2; i*i<=n; i++)
    {
        if(status[i])
            for(int j=2; i*j<=n; j++)
                status[i*j]=0;
    }
    for(int i=2; i<=n; i++)
    {
        if(status[i])
            prime.push_back(i);
    }
    for(auto i:prime)
    cout<<i<<" ";
}
int main()
{
    sieve();
}
