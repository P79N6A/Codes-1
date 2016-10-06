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
const int MAXN = 1e5 + 111;

char p[MAXN];
int nxt[MAXN];

int getNext() {
    int len = strlen(p);
    nxt[0] = -1;
    int k = -1;
    for (int i = 0; i < len;) {
        while (k != -1 && p[k] != p[i]) k = nxt[k];
        nxt[++i] = ++k;
    }
    int loop = len - nxt[len];
    if (len % loop == 0 && len / loop > 1) return 0;
    else return loop - len % loop;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%s", p);
        printf("%d\n", getNext());
    }
    return 0;
}
