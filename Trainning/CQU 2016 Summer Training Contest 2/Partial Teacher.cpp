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

int a[MAXN];
string s;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        a[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (s[j] == 'L' && a[j] <= a[j + 1]) {
                a[j] = a[j + 1] + 1;
            }
            else if (s[j] == 'R' && a[j] >= a[j + 1]) {
                a[j + 1] = a[j] + 1;
            }
            else if (s[j] == '=') a[j + 1] = a[j] = max(a[j], a[j + 1]);
        }
    }
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    return 0;
}
