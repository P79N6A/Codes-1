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
const int MAXN = 51;

string s[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, m;
    while (cin >> n >> m) {
        string tol, ser;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            for (int j = 0; j < m; ++j) s[i][j] = tolower(s[i][j]);
            tol += s[i];
        }
        cin >> ser;
        for (int j = 0; j < ser.length(); ++j) ser[j] = tolower(ser[j]);
        int x = tol.find(ser);
        if (x < tol.length()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
