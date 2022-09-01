#include <bits/stdc++.h>
using namespace std;
struct MST
{
    int u, v, w;
    MST(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator<(const MST &p) const
    {
        return w < p.w;
    }
};
int par[100];
vector<MST> G;
void Make_Set(int n)
{
    for (int i = 1; i <=n; i++)
        par[i] = i;
}
int find(int u)
{
    if (u == par[u])
        return u;
    return par[u] = find(par[u]);
}
int Kruskal(int n)
{
    Make_Set(n);
    sort(G.begin(), G.end());
    int cnt = 0, sum = 0;
    for (auto i : G)
    {
        int u = find(i.u);
        int v = find(i.v);
        if (u != v)
        {
            par[u] = v;
            cnt++;
            sum += i.w;
            if (cnt == n - 1)
                break;
        }
    }
    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        //do this if the nodes are 0 based
        //a++,b++;
        G.push_back(MST(a, b, c));
    }
    cout << "Cost ----> " << Kruskal(n);
}
/*
5 5 
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
*/