#include <bits/stdc++.h>
using namespace std;
vector<int> d;
void divisors(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                d.push_back(i);
            else
            {
                d.push_back(i);
                d.push_back(n / i);
            }
        }
    }
    sort(d.begin(), d.end());
    for (auto i : d)
        cout << i << " ";
}
int main()
{
    int n;
    cin >> n;
    divisors(n);
}