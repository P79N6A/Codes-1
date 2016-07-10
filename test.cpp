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

bool hash1[26][26];
bool hash2[26][26][26];
bool ok[2][MAXN];
string s;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (cin >> s) {
        vector<string> ans;
        memset(hash1, 0, sizeof hash1);
        memset(hash2, 0, sizeof hash2);
        memset(ok, 0, sizeof ok);
        int len = s.length();
        ok[0][len] = ok[1][len] = 1;
        int cnt = 1;
        for (int i = len - 2; i > 4; --i) {
            ++cnt;
            if (cnt >= 2 && (ok[0][i + 2] || ok[1][i + 2])) {
                if (!hash1[s[i] - 'a'][s[i + 1] - 'a']) {
                    hash1[s[i] - 'a'][s[i + 1] - 'a'] = 1;
                    ans.push_back(s.substr(i, 2));
                }
                ok[1][i] = 1;
                if (s.substr(i - 2, 2) != s.substr(i, 2)) ok[0][i] = 1;
            }
            if (cnt >= 3 && (ok[1][i + 3] || ok[0][i + 3])) {
                if (!hash2[s[i] - 'a'][s[i + 1] - 'a'][s[i + 2] - 'a']) {
                    hash2[s[i] - 'a'][s[i + 1] - 'a'][s[i + 2] - 'a'] = 1;
                    ans.push_back(s.substr(i, 3));
                }
                ok[2][i] = 1;
                if (s.substr(i - 3, 3) != s.substr(i, 3)) ok[1][i] = 1;
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}
