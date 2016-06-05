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
    int n; cin >> n;
    int up = pow(2, n);
    int ans = 0;
    for (int i = 0; i < up; ++i) {
        int t = i;
        int cnt = 0;
        while (t) {
            if (t & 1) {
                ++cnt;
                if (cnt == 2) {
                    ++ans;
                    break;
                }
            }
            else cnt = 0;
            t >>= 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
