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
const int MAXN = 1e4 + 111;

string s[MAXN];

int MM(int x, int len) {
    int i = 0, j = 1;
    while (i < len && j < len) {
        int k = 0;
        while (k < len && s[x][i + k] == s[x][j + k]) ++k;
        if (k == len) return min(i, j);
        if (s[x][i + k] > s[x][j + k]) i = max(i + k + 1, j + 1);
        else j = max(j + k + 1, i + 1);
    }
    return min(i, j);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    ios_base::sync_with_stdio(0);
    while (cin >> n) {
        map<string, bool> mp;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            int len = s[i].length();
            s[i] += s[i];
            mp[s[i].substr(MM(i, len), len)] = 1;
        }
        cout << mp.size() << '\n';
    }
    return 0;
}
