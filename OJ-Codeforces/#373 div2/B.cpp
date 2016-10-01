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
const int MAXN = 1e5 + 111;

int n;
string s;
int col[2];
int a[MAXN];

int solve(int c) {
    int len[2];
    len[0] = len[1] = 0;
    col[0] = c;
    col[1] = 1 - c;
    for (int i = 0; i < n; ++i) {
        int x = i % 2;
        if (a[i] != col[x]) {
            ++len[x];
        }
    }
    return max(len[0], len[1]);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (cin >> n >> s) {
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'r') a[i] = 0;
            else a[i] = 1;
        }
        cout << min(solve(0), solve(1)) << '\n';
    }
    return 0;
}
