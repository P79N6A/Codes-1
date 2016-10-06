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
const int MAXN = 5e6 + 111;

char s[MAXN], p[MAXN];
int nxt[MAXN], lens, lenp;
char ans[MAXN];
int cp[MAXN];

void getnxt() {
    nxt[0] = -1;
    int k = -1;
    for (int i = 0; i < lenp;) {
        while (~k && p[i] != p[k]) k = nxt[k];
        ++i;
        ++k;
        nxt[i] = k;
    }
}

void kmp() {
    getnxt();
    int i = 0, j = 0, cnt = 0;
    while (i < lens) {
        ans[cnt] = s[i];
        while (~j && s[i] != p[j]) j = nxt[j];
        ++i;
        ++j;
        if (j == lenp) {
            cnt -= lenp;
            j = cp[cnt];
        }
        cp[cnt] = j;
        ++cnt;
    }
    ans[cnt] = 0;
    puts(ans);
}

int main()
{
    #ifdef LOCAL
    //freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%s%s", p, s)) {
        lenp = strlen(p), lens = strlen(s);
        kmp();
    }
    return 0;
}
