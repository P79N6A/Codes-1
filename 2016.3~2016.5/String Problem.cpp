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
const int MAXN = 2e6 + 111;

char s[MAXN];
int nxt[MAXN];
int lens;

void kmp(char *p) {
    nxt[0] = -1;
    int k = -1;
    for (int i = 0; i < lens;) {
        while (k != -1 && p[k] != p[i]) k = nxt[k];
        ++i;
        ++k;
        nxt[i] = k;
    }
    int ans = 0, i = 0, j = 0;
    int up = lens * 2 - 1;
    while (i < up) {
        while (j != -1 && s[i] != p[j]) j = nxt[j];
        ++i;
        ++j;
        if (j == lens) {
            ++ans;
            j = nxt[j];
        }
    }
    printf(" %d", ans);
}

void MM1() {
    int i = 0, j = 1, ans = -1;
    while (i < lens && j < lens) {
        int k = 0;
        while (k < lens && s[i + k] == s[j + k]) ++k;
        if (k == lens) {
            ans = min(i, j);
            break;
        }
        if (s[i + k] > s[j + k]) i = max(i + k + 1, j + 1);
        else j = max(j + k + 1, i + 1);
    }
    if (ans == -1) ans = min(i, j);
    printf("%d", ans + 1);
    kmp(s + ans);
}

void MM2() {
    int i = 0, j = 1, ans = -1;
    while (i < lens && j < lens) {
        int k = 0;
        while (k < lens && s[i + k] == s[j + k]) ++k;
        if (k == lens) {
            ans = min(i, j);
            break;
        }
        if (s[i + k] < s[j + k]) i = max(i + k + 1, j + 1);
        else j = max(j + k + 1, i + 1);
    }
    if (ans == -1) ans = min(i, j);
    printf(" %d", ans + 1);
    kmp(s + ans);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%s", s)) {
        lens = strlen(s);
        for (int i = 0; i < lens; ++i) {
            s[lens + i] = s[i];
        }
        MM1();
        MM2();
        putchar('\n');
    }
    return 0;
}
