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
    ll n;
    while (cin >> n) {
        bool flag = 0;
        int a = ceil((double)n / 1234567);
        int b = ceil((double)n / 123456);
        for (int i = 0; i <= a && !flag; ++i) {
            for (int j = 0; j <= b; ++j) {
                ll sum = 123456 * j + 1234567 * i;
                if (sum > n) break;
                ll lef = n - sum;
                if (lef % 1234 == 0) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
