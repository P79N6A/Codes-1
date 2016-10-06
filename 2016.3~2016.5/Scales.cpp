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
const int MAXN = 111;

int base[MAXN], num[MAXN];
int add[MAXN], minu[MAXN];

void init() {
    base[0] = 1;
    for (int i = 1; i <= 18; ++i) {
        base[i] = 3 * base[i - 1];
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    init();
    while (~scanf("%d", &n)) {
        int cnt1 = 0, cnt2 = 0;
        int len = 0;
        while (n) {
            num[len++] = n % 3;
            n /= 3;
        }
        for (int i = 0; i < len; ++i) {
            if (num[i] == 1) {
                add[cnt1++] = i;
            }
            else if (num[i] == 2) {
                minu[cnt2++] = i;
                ++i;
                while (i < len && num[i] != 0) {
                    if (num[i] == 1) minu[cnt2++] = i;
                    ++i;
                }
                add[cnt1++] = i;
            }
        }
        printf("%d", cnt2);
        for (int i = 0; i < cnt2; ++i) printf(" %d", base[minu[i]]);
        printf("\n%d", cnt1);
        for (int i = 0; i < cnt1; ++i) printf(" %d", base[add[i]]);
        putchar('\n');
    }
    return 0;
}
