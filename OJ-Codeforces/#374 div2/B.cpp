#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;

string pass[MAXN];
int len[MAXN];
int alen = 0;
string ans;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> pass[i], len[i] = pass[i].length();
    cin >> ans;
    alen = ans.length();
    sort(len, len + n);
    int p;
    for (p = 0; p < n; ++p) {
        if (len[p] == alen) {
            break;
        }
    }
    int i;
    for (i = p; i >= 0; --i) {
        if (len[i] == len[p]) continue;
        else break;
    }
    int sum = 0, cnt = 0;
    for (int j = 1; j <= i + 2; ++j) {
        if (cnt == k) {
            cnt = 0;
            sum += 5;
        }
        ++sum;
        ++cnt;
    }
    cout << sum;
    sum = 0, cnt = 0;
    for (i = p; i < n; ++i) {
        if (len[i] == len[p]) continue;
        else break;
    }
    for (int j = 1; j <= i; ++j) {
        if (cnt == k) {
            cnt = 0;
            sum += 5;
        }
        ++sum;
        ++cnt;
    }
    cout << ' ' << sum << '\n';
    return 0;
}
