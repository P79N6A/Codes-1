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
const int MAXN = 5e5 + 111;

struct Trie
{
    int next[MAXN][26], fail[MAXN], end[MAXN];
    int rt, L;

    int newnode()
    {
        for (int i = 0; i < 26; ++i)
            next[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }

    void init()
    {
        L = 0;
        rt = newnode();
    }

    void insert(char buf[])
    {
        int len = strlen(buf);
        int cur = rt;
        for (int i = 0; i < len; ++i)
        {
            int v = buf[i] - 'a';
            if (next[cur][v] == -1)
                next[cur][v] = newnode();
            cur = next[cur][v];
        }
        end[cur]++;
    }

    void build()
    {
        queue<int> q;
        fail[rt] = rt;
        for (int i = 0; i < 26; ++i)
        {
            if (next[rt][i] == -1) next[rt][i] = rt;
            else
            {
                fail[next[rt][i]] = rt;
                q.push(next[rt][i]);
            }
        }
        while (q.size())
        {
            int cur = q.front(); q.pop();
            for (int i = 0; i < 26; ++i)
            {
                if (next[cur][i] == -1) next[cur][i] = next[fail[cur]][i];
                else
                {
                    fail[next[cur][i]] = next[fail[cur]][i];
                    q.push(next[cur][i]);
                }
            }
        }
    }

    int query(char buf[])
    {
        int len = strlen(buf);
        int cur = rt;
        int ret = 0;
        for (int i = 0; i < len; ++i)
        {
            cur = next[cur][buf[i] - 'a'];
            int temp = cur;
            while (temp != rt)
            {
                ret += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return ret;
    }
};

char buf[1000100];
Trie ac;

int main()
{
    int t, n; scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);
        ac.init();
        while (n --)
        {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s", buf);
        printf("%d\n", ac.query(buf));
    }
    return 0;
}
