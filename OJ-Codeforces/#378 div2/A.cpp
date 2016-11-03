#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

string s;
string p = "AEIOUY";

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int ans = 0;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        int x = p.find(s[i]);
        ++cnt;
        if (x != -1) {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt + (cnt ? 1 : 0));
    cout << ans << '\n';
    return 0;
}