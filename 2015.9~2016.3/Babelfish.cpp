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
const int MAXN = 3e6 + 111;

struct N {
    bool ok;
    char word[15];
    int nx[26];
    void init() {
        ok = 0;
        memset(nx, -1, sizeof nx);
    }
}node[MAXN];

int cnt = 0;

void insert(char *org, char *en) {
    int i = 0, p = 0;
    while (org[i]) {
        int x = org[i] - 'a';
        if (node[p].nx[x] == -1) {
            node[++cnt].init();
            node[p].nx[x] = cnt;
        }
        p = node[p].nx[x];
        ++i;
    }
    node[p].ok = 1;
    for (i = 0; en[i]; ++i) {
        node[p].word[i] = en[i];
    }
}

bool query(char *s) {
    int i = 0, p = 0;
    while (s[i]) {
        int x = s[i] - 'a';
        if (node[p].nx[x] == -1) {
            return 0;
        }
        p = node[p].nx[x];
        ++i;
    }
    if (node[p].ok) printf("%s\n", node[p].word);
    else return 0;
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    char s[30];
    char en[15], org[15];
    cnt = 0;
    node[0].init();
    while (gets(s)) {
        if (s[0] == '\0') break;
        sscanf(s, "%s%s", en, org);
        insert(org, en);
    }

    while (~scanf("%s", org)) {
        if (!query(org)) printf("eh\n");
    }

    return 0;
}
