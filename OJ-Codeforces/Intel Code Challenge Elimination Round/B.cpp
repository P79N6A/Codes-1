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

int n;
int p[MAXN];
string ma = "aeiouy";
string s;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i];
    bool flag = 1;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        int cnt = 0;
        for (int j = 0; j < s.length(); ++j) {
            for (int k = 0; k < 6; ++k) {
                if (s[j] == ma[k]) {
                    ++cnt;
                    break;
                }
            }
        }
        flag &= (cnt == p[i]);
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
