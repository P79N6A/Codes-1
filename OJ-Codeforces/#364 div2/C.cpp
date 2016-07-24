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

string s;
int n;
int a[MAXN];
bool vis[111];
int num[111];

int getid(char x) {
    if (islower(x)) {
        return x - 'a';
    }
    else return x - 'A' + 26;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
     ios_base::sync_with_stdio(0);
    cin >> n >> s;
    int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
        a[i] = getid(s[i]);
        if (!vis[a[i]]) ++sum;
        vis[a[i]] = 1;
    }
    int ans = INF, cnt = 0, r = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && cnt != sum) {
            int u = a[r];
            if (!num[u]) {
                ++cnt;
            }
            ++num[u];
            ++r;
        }
        if (cnt == sum) ans = min(ans, r - l);
        if (--num[a[l]] == 0) {
            --cnt;
        }
    }
    cout << ans << '\n';
    return 0;
}
