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
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    string a;
    int b, c;
    bool flag = 0;
    for (int i = 0; i < n; ++i) {
            cin >> a >> b >> c;
        if (b >= 2400 && c - b > 0) flag = 1;
    }
    if (flag) cout << "YES\n";
        else cout << "NO\n";
    return 0;
}
