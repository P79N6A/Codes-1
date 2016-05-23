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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 3e6 + 111;

struct Trie
{
    int next[MAXN][26], end[MAXN];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 26;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }

    void init()
    {
        L = 0;
        root = newnode();
    }

    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now]++;
    }

    bool query(char buf[]) {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; ++i) {
            if (next[now][buf[i] - 'a'] == -1) return 0;
            now = next[now][buf[i] - 'a'];
        }
        return 1;
    }

    void dfs(int x) {
        for (int i = 0; i < 26; ++i) {
            if (next[x][i] != -1) {
                dfs(next[x][i]);
                next[x][i] = -1;
            }
        }
    }

    void del(char buf[]) {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len - 1; ++i) {
            if (next[now][buf[i] - 'a'] == -1) return;
            now = next[now][buf[i] - 'a'];
        }
        if (next[now][buf[len - 1] - 'a'] == -1) return;
        dfs(now);
    }
};

Trie ac;
char op[20], s[50];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; scanf("%d", &n);
    ac.init();
    while (n --) {
        scanf("%s%s", op, s);
        if (op[0] == 'i') ac.insert(s);
        else if (op[0] == 's') {
            if (ac.query(s)) puts("Yes");
            else puts("No");
        }
        else ac.del(s);
    }
    return 0;
}
