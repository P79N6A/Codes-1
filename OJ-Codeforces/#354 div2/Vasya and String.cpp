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
const int MAXN = 1e5 + 111;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k;
    string s;
    while (cin >> n >> k >> s) {
        int mx = 0;
        for (int l = 0, r = 0, cnt = s[0] == 'b'; l < s.length(); ++l) {
            //if (r < l) r = l;
            while (cnt + (s[r + 1] == 'b') <= k && r + 1 < s.length()) {
                if (s[++r] == 'b') ++cnt;
            }
            mx = max(mx, r - l + 1);
            if (s[l] == 'b') --cnt;
        }
        for (int l = 0, r = 0, cnt = s[0] == 'a'; l < s.length(); ++l) {
            //if (r < l) r = l;
            while (cnt + (s[r + 1] == 'a') <= k && r + 1 < s.length()) {
                if (s[++r] == 'a') ++cnt;
            }
            mx = max(mx, r - l + 1);
            if (s[l] == 'a') --cnt;
        }
        cout << mx << '\n';
    }
    return 0;
}
