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

string s;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m; cin >> n >> m;
    bool flag = 1;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        cin >> s;
        if (s[0] == 'C' || s[0] == 'Y' || s[0] == 'M') {
            flag = 0;
        }
    }
    if (!flag) cout << "#Color\n";
    else cout << "#Black&White\n";
    return 0;
}
