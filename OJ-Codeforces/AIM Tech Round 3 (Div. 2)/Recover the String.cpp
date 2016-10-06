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

int num[MAXN];
char s[MAXN * 10];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int a, b, c, d, len;
    for (len = 1; ; ++len) {
        num[len] = len * (len - 1) / 2;
        if (num[len] > 1e9) break;
    }
    while (~scanf("%d%d%d%d", &a, &b, &c, &d)) {
        int zero = lower_bound(num + 1, num + len, a) - num;
        int one = lower_bound(num + 1, num + len, d) - num;
        if (b + c == 0) {
            if ((a && d)) puts("Impossible");
            else {
                if (a) {
                    if (num[zero] != a) {
                        puts("Impossible");
                        continue;
                    }
                    for (int i = 0; i < zero; ++i) putchar('0');
                }
                else if (d){
                    if (num[one] != d) {
                        puts("Impossible");
                        continue;
                    }
                    for (int i = 0; i < one; ++i) putchar('1');
                }
                else putchar('0');
                puts("");
            }
            continue;
        }
        if (num[zero] != a || num[one] != d || zero * one != b + c) {
            puts("Impossible");
        }
        else {
            int length = zero + one;
            for (int i = 0; i < zero; ++i) s[i] = '0';
            for (int i = zero; i < length; ++i) s[i] = '1';
            s[length] = 0;
            int zp = zero - 1, pos = length - 1, add = one;
            while (c != 0) {
                if (c >= add) {
                    c -= add;
                    swap(s[zp], s[pos]);
                    --pos;
                    --zp;
                }
                else {
                    --add;
                    --pos;
                }
            }
            puts(s);
        }
    }
    return 0;
}
