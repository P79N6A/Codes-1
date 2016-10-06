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
#define pr(x) cout << #x << " = " << (x) << " I ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 11;

char s[2];
// c[i][j]: 集合中满足i为约数，最小值f为j的数量
int c[MAXN][20];
// d[i]: 两方同时除以i后，集合中最小的f是多少？用二进制存放
int d[MAXN];
// 素因子个数
int num[MAXN];

inline void init() {
    num[1] = 0;
    for (int i = 2; i < MAXN; ++i) {
        if (!num[i]) {
            num[i] = 1;
            for (int j = i + i; j < MAXN; j += i) {
                int temp = j;
                while (temp % i == 0) {
                    ++num[j];
                    temp /= i;
                }
            }
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase = 0, n, x;
    init();
    while (~scanf("%d", &n) && n) {
        printf("Case #%d:\n", ++kase);
        memset(c, 0, sizeof c);
        memset(d, 0, sizeof d);
        set<int> in;
        while (n --) {
            scanf("%s%d", s, &x);
            if (s[0] == 'I') {
                if (in.count(x)) continue;
                in.insert(x);
                for (int i = 1; i * i <= x; ++i) {
                    if (x % i == 0) {
                        int a = i, b = x / i;
                        if (++c[a][num[b]] == 1) {
                            d[a] |= (1 << num[b]);
                        }
                        if (++c[b][num[a]] == 1) {
                            d[b] |= (1 << num[a]);
                        }
                    }
                }
            }
            else if (s[0] == 'D') {
                if (!in.count(x)) continue;
                in.erase(x);
                for (int i = 1; i * i <= x; ++i) {
                    if (x % i == 0) {
                        int a = i, b = x / i;
                        if (--c[a][num[b]] == 0) {
                            d[a] ^= (1 << num[b]);
                        }
                        if (--c[b][num[a]] == 0) {
                            d[b] ^= (1 << num[a]);
                        }
                    }
                }
            }
            else {
                int ans = INF;
                if (in.size()) {
                    for (int i = 1; i * i <= x; ++i) {
                        if (x % i == 0) {
                            int a = i, b = x / i;
                            int ma = 0, mb = 0;
                            for (; ma < 22; ++ma) {
                                if (d[a] & (1 << ma)) break;
                            }
                            for (; mb < 22; ++mb) {
                                if (d[b] & (1 << mb)) break;
                            }
                            //printf("(%d %d) -> (%d %d)\n", a, b, ma, mb);
                            if (ma ^ 22)
                                ans = min(ans, num[b] + ma);
                            if (mb ^ 22)
                                ans = min(ans, num[a] + mb);
                        }
                    }
                }
                if (ans == INF) ans = -1;
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
