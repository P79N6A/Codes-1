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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

char org[MAXN], s[MAXN];

int main()
{
    gets(org);
    int cnt = 0, len = strlen(org);
    for (int i = 0; i < len; ++i) {
        if (isalpha(org[i]) || org[i] == ' ') continue;
        s[cnt++] = org[i];
    }
    int ans = 0;
    for (int i = 0; i < cnt; ++i) {
        if (s[i] == '(') {
            if (i + 1 >= cnt || s[i + 1] != ')') ++ans;
        }
        else if (s[i] == ')') {
            if (i - 1 < 0 || s[i - 1] != '(') ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
