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
const int MAXN = 222;

int nxt[MAXN];

bool cmp(char *a, char *b, int len) {
    for (int i = 0; i < len; ++i) {
        if (a[i] < b[i]) return 1;
        else if (a[i] > b[i]) return 0;
    }
    return 0;
}

void getNext(char *p, int len) {
    nxt[0] = -1;
    int k = -1;
    for (int i = 0; i < len; nxt[++i] = ++k) {
        while (k != -1 && p[k] != p[i]) k = nxt[k];
    }
}

bool kmp(char *s, char *p, int lenp) {
    int i = 0, j = 0;
    int len = strlen(s);
    while (i < len) {
        while (j != -1 && s[i] != p[j]) j = nxt[j];
        ++i;
        ++j;
        if (j == lenp) return 1;
    }
    return 0;
}

char s[5000][MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
        }
        char *ans;
        int up = strlen(s[0]);
        int len = 0;
        for (int i = 0; i < up; ++i) {
            for (int j = i; j < up; ++j) {
                if (j - i + 1 < len) continue;
                if (j - i + 1 == len && cmp(ans, s[0] + i, len)) continue;
                getNext(s[0] + i, j - i + 1);
                char *t = s[0] + i;
                bool flag = 1;
                for (int k = 1; k < n; ++k) {
                    if (!kmp(s[k], t, j - i + 1)) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    ans = t;
                    len = j - i + 1;
                }
            }
        }
        if (len == 0) {
            printf("IDENTITY LOST\n");
        }
        else {
            for (int i = 0; i < len; ++i) putchar(ans[i]);
            putchar('\n');
        }
    }
    return 0;
}
