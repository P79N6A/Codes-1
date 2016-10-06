#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#include<string>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;

struct Edge
{
    int to, nxt, id;
    bool flag;
}edge[MAXN * 2];

string s[MAXN];
int n, ans[MAXN], in[33], out[33], tot, head[33], cnt;

void init()
{
    tot = 0;
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
    memset(head, -1, sizeof head);
}

void add_edge(int u, int v, int id)
{
    edge[tot].to = v;
    edge[tot].flag = 0;
    edge[tot].id = id;
    edge[tot].nxt = head[u];
    head[u] = tot++;
}

void dfs(int u)
{
    for (int i = head[u]; ~i; i = edge[i].nxt)
    {
        if (!edge[i].flag)
        {
            edge[i].flag = 1;
            dfs(edge[i].to);
            ans[cnt++] = edge[i].id;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t --)
    {
        cin >> n;
        init();

        for (int i = 1; i <= n; ++i) cin >> s[i];
        sort(s + 1, s + n + 1);
        int st = 26;
        for (int i = n; i >= 1; --i) // 链式前向星是倒着遍历边，所以倒着来，最后就是顺着字典序了
        {
            int u = s[i][0] - 'a', v = s[i].back() - 'a';
            add_edge(u, v, i);
            ++in[v], ++out[u];
            st = min(st, min(u, v));
        }

        int cnt1 = 0, cnt2 = 0;
        // 判断欧拉回路/欧拉通路
        for (int i = 0; i < 26; ++i)
        {
            if (out[i] - in[i] == 1)
            {
                ++cnt1;
                st = i;
            }
            else if (out[i] - in[i] == -1)
                ++cnt2;
            else if (out[i] - in[i] != 0)
                cnt1 = 3;
        }

        if (!(cnt1 == cnt2 && cnt1 <= 1))
        {
            cout << "***\n";
            continue;
        }

        cnt = 0;
        dfs(st);
        if (cnt != n)
        {
            cout << "***\n";
            continue;
        }

        for (int i = n - 1; i >= 0; --i)
        {
            cout << s[ans[i]];
            if (i > 0) cout << '.';
            else cout << '\n';
        }
    }
    return 0;
}
