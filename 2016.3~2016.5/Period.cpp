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

int nxt[MAXN], n;
char p[MAXN];

void getNext() {
    nxt[0] = -1;
    int k = -1;
    for (int i = 0; i < n;) {
        while (k != -1 && p[k] != p[i]) k = nxt[k];
        nxt[++i] = ++k;
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase = 0;
    while (~scanf("%d", &n) && n) {
        printf("Test case #%d\n", ++kase);
        scanf("%s", p);
        getNext();
        for (int i = 0; i <= n; ++i) {
            if (nxt[i] > 0 && (i % (i - nxt[i]) == 0))
                printf("%d %d\n", i, i / (i - nxt[i]));
        }
        putchar('\n');
    }
    return 0;
}
