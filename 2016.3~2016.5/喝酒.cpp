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
    int t, n; cin >> t;
    while (t --) {
        cin >> n;
        int ans = n, bot = n, gai = n;
        while (bot >= 3 || gai >= 4) {
            int cur = bot / 3 + gai / 4;
            ans += cur;
            bot = bot % 3 + cur;
            gai = gai % 4 + cur;
        }
        cout << ans << '\n';
    }
    return 0;
}
