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

int nxt[MAXN];

void getNext(char *t) {
    nxt[0] = -1;
    int len = strlen(t);
    int k = -1;
    for (int i = 0; i < len;) {
        while (k != -1 && t[i] != t[k]) k = nxt[k];
        ++i;
        ++k;
        nxt[i] = k;
    }
}

int kmp(char *s, char *p) {
    getNext(p);
    int lens = strlen(s), lenp = strlen(p);
    int i = 0, j = 0;
    while (i < lens) {
        while (j != -1 && s[i] != p[j]) j = nxt[j];
        ++i;
        ++j;
    }
    if (i == lens)
        return j;
    return 0;
}

char a[MAXN], b[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%s%s", a, b)) {
        int ans1 = kmp(a, b);
        int ans2 = kmp(b, a);
        if (ans1 > ans2) {
            printf("%s%s", a, b + ans1);
        }
        else if (ans2 > ans1) {
            printf("%s%s", b, a + ans2);
        }
        else {
            if (strcmp(a, b) < 0) {
                printf("%s%s", a, b + ans1);
            }
            else {
                printf("%s%s", b, a + ans2);
            }
        }
        putchar('\n');
    }
    return 0;
}
