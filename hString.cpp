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
#define ull unsigned long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

char s[MAXN];
ull hs[MAXN], base[MAXN];
map<ull, int> mp[MAXN];

void init() {
    base[0] = 1;
    for (int i = 1; i < MAXN; ++i) base[i] = base[i - 1] * 31;
}

ull getVal(int st, int len) {
    return hs[st] - hs[st + len] * base[len];
}

int main()
{
    init();
    int m, l;
    while (~scanf("%d%d", &m, &l)) {
        scanf("%s", s);
        int len = strlen(s);
        hs[len] = 0;
        for (int i = len - 1; i >= 0; --i) {
            hs[i] = hs[i + 1] * base[1] + s[i] - 'a';
        }

        int ans = 0, up = m * l;
        for (int i = 0; i < l && i + up - 1 < len; ++i) {
            mp[i].clear();
            int st = i;
            for (int j = 0; j < m; st += l, ++j) {
                ull val = getVal(st, l);
                if (mp[i].count(val)) ++mp[i][val];
                else mp[i].insert(make_pair(val, 1));
            }
            if (mp[i].size() == m) ++ans;
        }

        for (int i = l; i + up - 1 < len; ++i) {
            ull val = getVal(i - l, l);
            int v = i % l;
            --mp[v][val];
            if (mp[v][val] == 0) mp[v].erase(val);
            val = getVal(i + up - l, l);
            if (mp[v].count(val)) ++mp[v][val];
            else mp[v].insert(make_pair(val, 1));
            if (mp[v].size() == m) ++ans;
        }

        printf("%d\n", ans);
    }
    return 0;
}
