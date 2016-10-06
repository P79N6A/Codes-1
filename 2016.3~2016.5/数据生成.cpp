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

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    double st, et, x = 0.125, estime = 0;
    int cnt = 0;
    srand((unsigned)time(NULL));
    for (int i = 1; i <= 30; ++i) {
        cout << i << '\n';
        for (int j = 0; j < i; ++j) {
            cout << rand() % 100000000 << ' ';
        }
        cout << endl;
    }
    return 0;
}
