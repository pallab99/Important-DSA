#include <bits/stdc++.h>
using namespace std;
int Parent[10000], Rank[10000];
void init(int n)
{
    for (int i = 1; i <= n; i++)
        Parent[i] = i, Rank[i] = 1;
}
int Find(int u)
{
    if (u == Parent[u])
        return u;
    return Parent[u] = Find(Parent[u]);
}
void Union(int u, int v)
{
    int p = Find(u);
    int q = Find(v);
    if (p != q)
    {
        if (Rank[p] < Rank[q])
            swap(p, q);
        Rank[p] += Rank[q];
        Parent[q] = p;
    }
}
bool isFriend(int u, int v)
{
    return Find(u) == Find(v);
}
int main()
{
    int n;
    cin >> n;
    init(n);
    Union(4, 8);
    Union(4, 7);
    cout << Find(7) << ' ' << Rank[4] << ' ';
    cout << isFriend(7, 8);
}
