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

const int ADD = 12500000;
const int MAXN = 25000000 + 11;

int a[5];
short num[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    for (int i = 0; i < 5; ++i) scanf("%d", &a[i]);
    for (int i = -50; i <= 50; ++i) {
        int t = i * i * i;
        for (int j = -50; j <= 50; ++j) {
            if (i && j) {
                int sum = t * a[0] + j * j * j * a[1] + ADD;
                ++num[sum];
            }
        }
    }

    int ans = 0;
    for (int i = -50; i <= 50; ++i) {
        int t = i * i * i;
        for (int j = -50; j <= 50; ++j) {
            int t2 = j * j * j;
            for (int k = -50; k <= 50; ++k) {
                if (i && j && k) {
                    int sum = t * a[2] + t2 * a[3] + k * k * k * a[4] + ADD;
                    if (sum > 25000000 || sum < 0) continue;
                    ans += num[sum];
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
