#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, v, w;
    Edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
vector<Edge> G;
int dist[100];
int n, m;
void Bellman_Ford(int src)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto i : G)
        {
            if (dist[i.u] != INT_MAX and dist[i.v] > dist[i.u] + i.w)
                dist[i.v] = dist[i.u] + i.w;
        }
    }
    for (auto i : G)
    {
        if (dist[i.u] != INT_MAX and dist[i.v] > dist[i.u] + i.w)
            cout << "contain negetive weight cycle" << endl;
    }
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G.push_back(Edge(a, b, c));
    }
    Bellman_Ford(1);
}
/*
5 8
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 2 1
4 3 5
5 4 -3
*/