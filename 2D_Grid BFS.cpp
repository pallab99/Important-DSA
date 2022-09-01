#include <bits/stdc++.h>
using namespace std;
bitset<100> vis[100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
bool isvalid(int x, int y)
{
   return (x >= 0 && x < 5 && y >= 0 && y < 5 && !vis[x][y]);
}
struct node
{
    int x;
    int y;
};

void bfs(int sx, int sy)
{
    queue<node> Q;
    Q.push({sx, sy});
    vis[sx][sy] = 1;

    while (!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (isvalid(next_x, next_y))
            {
                vis[next_x][next_y] = 1;
                Q.push({next_x, next_y});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    bfs(1, 1);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
}