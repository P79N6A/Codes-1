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
const int MAXN = 1e6 + 111;

struct Trie {
    int nxt[MAXN][26];
    int fail[MAXN];
    int time[MAXN];
    int len = -1, rt = 0;

    Trie() {
        add();
    }

    int add() {
        ++len;
        time[len] = 0;
        for (int i = 0; i < 26; ++i) {
            nxt[len][i] = -1;
        }
        return len;
    }

    void insert(char *s) {
        int l = strlen(s);
        int x = 0;
        for (int i = 0; i < l; ++i) {
            int p = s[i] - 'a';
            if (~nxt[x][p]) x = nxt[x][p];
            else x = nxt[x][p] = add();
        }
        ++time[x];
    }

    void build() {
        queue<int> q;
        fail[rt] = rt;
        for(int i = 0;i < 26;i++) {
            if (nxt[rt][i] == -1) nxt[rt][i] = rt;
            else {
                fail[nxt[rt][i]] = rt;
                q.push(nxt[rt][i]);
            }
        }
        while (q.size()) {
            int now = q.front(); q.pop();
            if (time[fail[now]]) ++time[now];
            for (int i = 0; i < 26; ++i) {
                if (nxt[now][i] == -1) nxt[now][i] = nxt[fail[now]][i];
                else {
                    fail[nxt[now][i]] = nxt[fail[now]][i];
                    q.push(nxt[now][i]);
                }
            }
        }
    }

    bool query(char *s) {
        int l = strlen(s);
        int x = 0;
        for (int i = 0; i < l; ++i) {
            int p = s[i] - 'a';
            x = nxt[x][p];
            if (time[x]) return 1;
        }
        return 0;
    }
};

char s[MAXN];
char f[MAXN];
Trie ac;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        ac.insert(s);
    }
    scanf("%s", f);
    ac.build();
    if (ac.query(f)) puts("YES");
    else puts("NO");
    return 0;
}
