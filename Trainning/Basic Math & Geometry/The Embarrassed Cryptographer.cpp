/*
 原来取膜运算还能进化= =
 新技能get，长整数取模减少取模次数优化时间
*/
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
const int MAXN = 1e6 + 111;

bool ok[MAXN];
int prime[MAXN], cnt;

inline void init() {
    for (int i = 2; i < MAXN; ++i) {
        if (!ok[i]) {
            prime[cnt++] = i;
            for (int j = i << 1; j < MAXN; j += i) ok[j] = 1;
        }
    }
}

char s[111];
int num[111];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    int m;
    while (scanf("%s%d", s, &m) && !(s[0] == '0' && m == 0)) {
        bool flag = 1;
        int up = upper_bound(prime, prime + cnt, m - 1) - prime - 1;
        int len = strlen(s), u;
        memset(num, 0, sizeof num);
        int indx = 0;
        for (int i = 0; i < len; i += 5) {
            for (int j = 0; j < 5 && i + j < len; ++j) {
                num[indx] *= 10;
                num[indx] += s[i + j] - '0';
            }
            ++indx;
        }
//        for (int i = 0; i < indx; ++i) cout << num[i];
        for (int i = 0; i <= up; ++i) {
            u = prime[i];
            ll sum = 0;
            for (int j = 0; j < indx; ++j) {
                sum *= 100000;
                sum += num[j];
                sum %= u;
            }
            if (sum == 0) {
                flag = 0;
                break;
            }
        }
//        for (int i = 0; i <= up; ++i) {
//            u = prime[i];
//            int sum = 0;
//            for (int j = 0; j < len; ++j) {
//                sum *= 10;
//                sum += s[j] - '0';
//                sum %= u;
//            }
//            if (sum == 0) {
//                flag = 0;
//                break;
//            }
//        }
        if (flag) printf("GOOD\n");
        else printf("BAD %d\n", u);
    }
    return 0;
}
