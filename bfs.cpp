#include <bits/stdc++.h>
using namespace std;
vector<int> g[10000];
bool visited[2000];    
int dis[2000];     
void bfs(int source, int n)
{
    queue<int> q;
    q.push(source);
    visited[source] = 1;  
    dis[source] = 0;

    while (!q.empty())                  
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int)g[u].size(); i++)
        {
            int v = g[u][i];
            if (!visited[v])
            {
                visited[v] = 1;
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
    for (int i = 1; i <=n; i++)
        cout <<"distance of " <<i<<" "<<dis[i] << endl;
}
int main()
{
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1, numNodes);
    return 0;
}
