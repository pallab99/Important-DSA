#include<bits/stdc++.h>
using namespace std;
//Time complexity : O(V+E)
vector<int>indegree;
vector<int>G[200];
void Topological_sort(int node,int edge)
{
    queue<int>q;
    for(int i=0;i<node;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int>order;
    int cnt=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cnt++;
        order.push_back(u);
        for(auto child:G[u])
        {
            indegree[child]--;
            if(indegree[child]==0)
            q.push(child);
        }
    }
    if(cnt!=node)
    cout<<"cycle";
    else 
    {
        for(auto i:order)
        cout<<i<< " ";
    }
}
int main()
{
    //in a DAG there will be atleast 1 node whose indegree is 0.
    int node,edge;
    cin>>node>>edge;
    indegree.resize(node);
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        indegree[v]++;
    }
    Topological_sort(node,edge);
}