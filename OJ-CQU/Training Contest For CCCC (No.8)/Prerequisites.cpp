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

map<string, bool> choose;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int k, m;
    string s;
    while (cin >> k && k) {
        cin >> m;
        choose.clear();
        for (int i = 0; i < k; ++i) {
            cin >> s;
            choose[s] = 1;
        }
        int c, r;
        bool ok = 1;
        for (int i = 0; i < m; ++i) {
            cin >> c >> r;
            int cnt = 0;
            for (int j = 0; j < c; ++j) {
                cin >> s;
                if (choose[s]) ++cnt;
            }
            if (cnt < r) {
                ok = 0;
            }
        }
        if (ok) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
