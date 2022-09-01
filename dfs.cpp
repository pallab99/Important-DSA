#include <bits/stdc++.h>
using namespace std;
vector<int> g[100000];
vector<bool> vis(100000, false);
void dfs(int src)
{
    vis[src] = true;
    cout << src << " ";
    for (auto it : g[src])
    {
        if(!vis[it])
        dfs(it);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
}