#include <bits/stdc++.h>
using namespace std;
const int block = 173;
struct query
{
    int l;
    int r;
    int ind;
};
vector<query>Q;
vector<int>ans;
vector<int>ara;
unordered_map<int,int>freq;
int cnt = 0;
void add(int index)
{
    freq[ara[index]]++;
    if (freq[ara[index]] == 1)
        cnt++;
}
void remove(int index)
{
    freq[ara[index]]--;
    if (freq[ara[index]] == 0)
        cnt--;
}
bool cmp(query f, query s)
{
    if ((f.l / block) != (s.l / block))
        return (f.l / block) < (s.l / block);
    else
        return f.r < s.r;
}
void MOS_ALGO(int q)
{
    sort(Q.begin(),Q.end(),cmp);
    int ML = 0, MR = -1;
    for (int i = 0; i < q; i++)
    {
        int left = Q[i].l, right = Q[i].r;
        while (ML > left)
        {
            ML--;
            add(ML);
        }
        while (MR < right)
        {
            MR++;
            add(MR);
        }
        while (ML < left)
        {
            remove(ML);
            ML++;
        }
        while (MR > right)
        {
            remove(MR);
            MR--;
        }
        ans[Q[i].ind] = cnt;
    }
}
int main()
{
    int n;
    cin >> n;
    ara.resize(n);
    for (int i = 0; i < n; i++)
        cin >> ara[i];
    int q;
    cin >> q;
    Q.resize(q);
    ans.resize(q);
    for (int i = 0; i < q; i++)
    {
        cin >> Q[i].l >> Q[i].r;
        Q[i].ind = i;
        Q[i].l--;
        Q[i].r--;
    }
    MOS_ALGO(q);
    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;
}