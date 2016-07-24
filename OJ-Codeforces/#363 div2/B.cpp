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
const int MAXN = 1111;

string mp[MAXN];
int row[MAXN], col[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> mp[i];
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == '*') {
                ++row[i];
                ++col[j];
                ++sum;
            }
        }
    }
    bool flag = 0;
    int r = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int have = row[i] + col[j] - (mp[i][j] == '*');
            if (have == sum) {
                flag = 1;
                r = i, c = j;
                break;
            }
        }
    }
    if (!flag) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << r + 1 << ' ' << c + 1 << '\n';
    return 0;
}
