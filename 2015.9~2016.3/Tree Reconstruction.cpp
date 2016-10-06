#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;

int pos[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, x;
    while (cin >> n)
    {
        vector<int> bfs, dfs;
        set<int> G[MAXN];
        for (int i = 0; i < n; ++i) cin >> x, bfs.push_back(x), pos[x] = i;
        for (int i = 0; i < n; ++i) cin >> x, dfs.push_back(x);

        stack<int> sta;
        int rt = dfs[0];
        sta.push(rt);
        for (int i = 1; i < n; ++i)
        {
            while(1)
            {
                int cur = sta.top();
                if (cur == rt || pos[cur] + 1 < pos[dfs[i]])
                {
                    G[cur].insert(dfs[i]);
                    sta.push(dfs[i]);
                    break;
                }
                else sta.pop();
            }
        }

        set<int>::iterator it;
        for (int i = 1; i <= n; ++i)
        {
            cout << i << ":";
            for (it = G[i].begin(); it != G[i].end(); ++it)
                cout << ' ' << *it;
            cout << '\n';
        }
    }
    return 0;
}
