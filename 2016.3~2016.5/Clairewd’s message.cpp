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

char change[30];
char change2[30];
char s[MAXN], p[MAXN];
int nxt[MAXN];

int kmp() {
    int lenp = strlen(p);
    int lens = lenp;
    nxt[0] = -1;
    int k = -1;
    for (int i = 0; i < lenp;) {
        while (k != -1 && p[k] != p[i]) k = nxt[k];
        ++i;
        ++k;
        nxt[i] = k;
    }

    int i = (lens + 1) / 2, j = 0;
    while (i < lens) {
        while (j != -1 && s[i] != p[j]) j = nxt[j];
        ++i;
        ++j;
    }
    return j;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%s%s", change, p);
        for (int i = 0; i < 26; ++i) change2[change[i] - 'a'] = i + 'a';
        int len = strlen(p);
        for (int i = 0; i < len; ++i) {
            s[i] = change[p[i] - 'a'];
        }
        s[len] = 0;

        int pos = kmp();
        for (int i = 0; i < len - pos; ++i) {
            s[i] = p[i];
            s[i + len - pos] = change2[p[i] - 'a'];
        }
        s[2 * len - 2 * pos] = 0;
        printf("%s\n", s);
    }
    return 0;
}
