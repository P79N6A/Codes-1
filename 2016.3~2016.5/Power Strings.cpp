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

int nxt[MAXN];
char p[MAXN];

void getNext() {
    nxt[0] = -1;
    int k = -1;
    int len = strlen(p);
    for (int i = 0; i < len;) {
        while (k != -1 && p[i] != p[k]) k = nxt[k];
        nxt[++i] = ++k;
    }
    int ans = len / (len - nxt[len]);
    if (len % (len - nxt[len]) != 0) ans = 1;
    printf("%d\n", ans);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%s", p) && p[0] != '.') {
        getNext();
    }
    return 0;
}
