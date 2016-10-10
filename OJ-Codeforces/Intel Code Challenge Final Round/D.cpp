#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

char s[MAXN];
int num[MAXN];
char ans[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m;
    scanf("%d%s", &m, s);
    int n = strlen(s), len = 0, cnt = 0;
    for (int i = 0; i < n - m + 1; ++i) {
        char mi = 'z';
        int pos = 0;
        for (int j = i; j < i + m; ++j) {
            if (s[j] <= mi) {
                mi = s[j];
                pos = j;
            }
        }
        if (++num[s[pos] - 'a'] == 1) {
            ++len;
        }
        i = pos;
    }
    sort(s, s + n);
    for (int i = 0; i < n; ++i) {
        if (!len) break;
        if (num[s[i] - 'a']) {
            if (--num[s[i] - 'a'] == 0) --len;
        }
        ans[cnt++] = s[i];
    }
    ans[cnt] = 0;
    puts(ans);
    return 0;
}
