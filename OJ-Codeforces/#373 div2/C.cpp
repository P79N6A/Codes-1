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

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 111;

int num[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    string s;
    int n, t;
    while (cin >> n >> t >> s) {
        memset(num, 0x3f, sizeof num);
        for (int i = n - 2; i >= 0; --i) {
            if (s[i + 1] > '4') {
                num[i] = 1;
            }
            else if (s[i + 1] == '4') {
                num[i] = num[i + 1] + 1;
            }
            if (s[i] == '.') {
                num[i - 1] = num[i];
                break;
            }
        }
        int pos;
        for (pos = 0; pos < n; ++pos) {
            if (num[pos] <= t) {
                break;
            }
        }
        if (pos == n) {
            cout << s << '\n';
            continue;
        }
        int judge;
        for (judge = pos; judge >= 0; --judge) {
            if (s[judge] == '9') {
                s[judge] = '0';
            }
            else {
                s[judge] = s[judge] + 1;
                break;
            }
        }
        if (judge == -1) cout << 1;
        for (int i = 0; i <= pos; ++i) {
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}
