#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define M 100005
vector<ll> prime;
bitset<M> status;
void sieve()
{
    ll n = M;
    status.set();
    status[0] = 0;
    status[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (status[i])
            for (int j = 2; i * j <= n; j++)
                status[i * j] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (status[i])
            prime.push_back(i);
    }
}
ll totientSieve(ll n)
{
    ll res = n;
    // this loop runs sqrt(n / ln(n)) times
    for (ll i = 0; prime[i] * prime[i] <= n; i++)
    {
        if (n % prime[i] == 0)
        {
            // subtract multiples of p[i] from r
            res -= (res / prime[i]);
            // Remove all occurrences of p[i] in n
            while (n % prime[i] == 0)
                n /= prime[i];
        }
    }
    // when n has prime factor greater
    // than sqrt(n)
    if (n > 1)
        res -= (res / n);
    return res;
}
int main()
{
    sieve();
    cout << totientSieve(7);
}