#include<bits/stdc++.h>
using namespace std;
bitset<100>vis[100];
int n,m;
bool isvalid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m)
    return false;
    if(vis[x][y]==true)
    return false;
    return true;
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(int x,int y)
{
     vis[x][y]=1;
     cout<<x<<" "<<y<<endl;
     for(int i=0;i<4;i++)
     {
         int xx=x+dx[i];
         int yy=y+dy[i];
         if(isvalid(xx,yy))
         dfs(xx,yy);
     }

}
int main()
{
   cin>>n>>m;

   dfs(1,1);
}