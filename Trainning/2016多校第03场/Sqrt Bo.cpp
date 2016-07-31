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

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    string s;
    while (cin >> s) {
        if (s.length() > 10) cout << "TAT\n";
        else {
            double sum = 0;
            for (int i = 0; i < s.length(); ++i) {
                sum *= 10;
                sum += s[i] - '0';
            }
            if (sum < 1) cout << "TAT\n";
            else {
                int ans = 0;
                for (ans = 0; ans <= 5; ++ans) {
                    if (sum == 1) {
                        break;
                    }
                    sum = (int)sqrt(sum);
                }
                if (ans > 5) cout << "TAT\n";
                else cout << ans << '\n';
            }
        }
    }
    return 0;
}
