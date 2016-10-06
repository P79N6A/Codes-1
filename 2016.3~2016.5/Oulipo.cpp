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

char s[MAXN], p[MAXN];
int nxt[MAXN];

int kmp() {
    int lens = strlen(s), lenp = strlen(p);
    nxt[0] = -1;
    int k = -1;
    for (int i = 0; i < lenp;) {
        while (k != -1 && p[i] != p[k]) k = nxt[k];
        ++i;
        ++k;
        if (p[i] != p[k]) nxt[i] = k;
        else nxt[i] = nxt[k];
    }

    int ans = 0;
    int i = 0, j = 0;
    while (i < lens) {
        while (j != -1 && s[i] != p[j]) j = nxt[j];
        ++i;
        ++j;
        if (j == lenp) {
            ++ans;
            j = nxt[j];
        }
    }
    return ans;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%s%s", p, s);
        printf("%d\n", kmp());
    }
    return 0;
}
