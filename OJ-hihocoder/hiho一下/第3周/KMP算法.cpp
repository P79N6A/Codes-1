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

int kmp(char *s, char *p) {
    int lens = strlen(s);
    int lenp = strlen(p);

    nxt[0] = -1;
    int k = -1;
    for (int i = 0; i < lenp;) {
        while (~k && p[k] != p[i]) k = nxt[k];
        ++i;
        ++k;
        if (p[i] == p[k]) nxt[i] = nxt[k];
        else nxt[i] = k;
    }
    //for (int i = 0; i < lenp; ++i) printf("%d ", nxt[i]); putchar('\n');

    int ret = 0;
    int j = 0;
    for (int i = 0; i < lens; ++i) {
        while (~j && s[i] != p[j]) j = nxt[j];
        ++j;
        if (j == lenp) {
            ++ret;
            j = nxt[j];
        }
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    while (n --) {
        scanf("%s%s", p, s);
        printf("%d\n", kmp(s, p));
    }
    return 0;
}
