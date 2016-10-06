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
const int MAXN = 1e5 + 111;

int a[MAXN];
map<int, int> mp;
set<int> s;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k, x; cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        x = a[i];
        int sta = ++mp[x];
        if (sta == 1) {
            s.insert(x);
        }
        else if (sta == 2) {
            s.erase(x);
        }
        if (++cnt == k) {
            if (s.size()) {
                auto it = s.end(); --it;
                cout << *it << '\n';
            }
            else cout << "Nothing\n";
            x = a[i - k + 1];
            sta = --mp[x];
            if (sta == 1) {
                s.insert(x);
            }
            else if (sta == 0) {
                s.erase(x);
            }
            --cnt;
        }
    }
    return 0;
}
