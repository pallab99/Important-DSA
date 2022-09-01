///Have faith in god.
#include<bits/stdc++.h>
using namespace std;

const int INF =1000000000;

vector<pair<int,int>>adj[1000];
///-----------------Main code---------------------///
int main()
{

      freopen("input.txt","r" ,stdin);
      int n,m,a,b,w;
      cin>>n>>m;
      while(m--)
      {
          cin>>a>>b>>w;
          adj[a].push_back({b,w});
          adj[b].push_back({a,w});
      }
      vector<int>D(n+1,INF);
      D[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,1});

    while(!q.empty())
    {
        pair<int,int> p = q.top();
        q.pop();

        int u = p.second, dist = p.first;
        if(dist > D[u]) continue;

        for(pair<int,int> pr : adj[u])
        {
            int v = pr.first;
            int next_dist = dist + pr.second;
            if(next_dist < D[v])
            {
                D[v] = next_dist;
                q.push({next_dist,v});
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<D[i]<<" ";
    return 0;
}


