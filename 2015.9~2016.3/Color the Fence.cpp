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
const int MAXN = 1e6 + 111;

int cost[10];

int main()
{
    int v, mi = INF, minum;
    cin >> v;
    for (int i = 1; i <= 9; ++i) {
        cin >> cost[i];
        if (cost[i] <= mi) {
            mi = cost[i];
            minum = i;
        }
    }

    if (v / mi == 0) cout << -1 << '\n';
    else {
        int lef = v % mi;
        int cnt = v / mi;
        for (int i = 0; i < cnt; ++i) {
            for (int j = 9; j >= minum; --j) {
                if (mi + lef >= cost[j]) {
                    cout << j;
                    lef -= cost[j] - mi;
                    break;
                }
            }
        }
    }
    return 0;
}
