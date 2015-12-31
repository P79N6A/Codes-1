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
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int a;
    string b, c;
    cin >> a >> b >> c;
    if (c == "week") {
        if (a <= 6 && a >= 5)
            cout << 53 << '\n';
        else cout << 52 << '\n';
    }
    else if (a <= 29) cout << 12 << '\n';
    else if (a <= 30) cout << 11 << '\n';
    else cout << 7 << '\n';
    return 0;
}
