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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 31;

int c[MAXN][MAXN];
int sum[MAXN];

void init() {
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    // 长度为i的排列有C[26][i]个
    for (int i = 1; i <= 10; ++i) {
        sum[i] = sum[i - 1] + c[26][i];
    }
}

char s[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 1; i < len; ++i) {
        if (s[i] <= s[i - 1]) {
            puts("0");
            return 0;
        }
    }
    int ans = sum[len - 1];
    for (int i = 0; i < len; ++i) {
        char st = (!i ? 'a' : s[i - 1] + 1);
        while (st < s[i]) {
            ans += c['z' - st][len - 1 - i];
            ++st;
        }
    }
    printf("%d\n", ans + 1);
    return 0;
}
