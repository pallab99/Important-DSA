#include<bits/stdc++.h>
using namespace std;
const int mx=3020;
using ll=long long;
vector<ll>isprime,List;
bitset<mx>prime;
void sieve()
{
    prime.set();
    prime[0]=0;
    prime[1]=0;
    for(ll i=2; i*i<=mx; i++)
    {
        if(prime[i])
            for(ll j=2; i*j<=mx; j++)
            {
                prime[i*j]=0;
            }
    }
    for(ll i=2; i<=mx; i++)
    {
        if(prime[i])
            isprime.push_back(i);
    }
}
void primefact(ll n)
{
    for(ll i=0; isprime[i]*isprime[i]<=n && i<isprime.size(); i++)
    {
        if(n%isprime[i]==0)
        {
            while(n%isprime[i]==0)
            {
                n/=isprime[i];
                List.push_back(isprime[i]);
            }
        }
    }
    if(n>1)
        List.push_back(n);
        sort(List.begin(),List.end());
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

     sieve();
    ll n;
    cin>>n;
     primefact(n);
     for(auto i:List)
     cout<<i<<" ";
     //ll sz=List.size();
     //printf("%lld : %lld\n",n,sz);

}

