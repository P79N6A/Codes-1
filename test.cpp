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
    string s;
    cin >> s;
    cout << s.length() << '\n';
    for (int i = 0; i < s.length(); ++i)
    {
        int k = 0;
        for (int j = 0; j < 4; ++j)
        {
            k = k + s[i + j] - '0';
            if (j < 3) k *= 8;
        }
        printf("%c", k);
        i += 3;
    }
    cout << '\n';
    return 0;
}
