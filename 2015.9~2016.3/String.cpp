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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int m, l;
char s[MAXN];

struct Trie
{
    int next[500010][26], end[500010];
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
    bool insert(char buf[])
    {
        int len = l;
        int now = root;
        for(int i = 0;i < len;i++)
        {
            //printf("%c", s[i]);
            if(next[now][buf[i]-'a'] == -1)
            next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        //printf("\n");
        if (end[now]) return 1;
        end[now]++;
        return 0;
    }
};

Trie ac;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &m, &l)) {
        scanf("%s", s);
        int len = strlen(s) - m * l + 1;
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            bool ok = 1;
            ac.init();
            for (int j = i; j < i + m * l; j += l) {
                if (ac.insert(&s[j])) {
                    ok = 0;
                    break;
                }
            }
            if (ok) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
