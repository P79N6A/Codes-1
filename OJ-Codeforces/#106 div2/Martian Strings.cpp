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

string rs, s;
string rp;
int nxt[2][1111], mx[MAXN];

void getnxt(int o, string &s) {
    int i,j;
    j=nxt[o][0]=-1;
    i=0;
    while(i<s.length())
    {
        while(-1!=j && s[i]!=s[j])j=nxt[o][j];
        nxt[o][++i]=++j;
    }
}

bool ok() {
    string p = rp;
    reverse(rp.begin(), rp.end());
    getnxt(0, p);
    getnxt(1, rp);
    int i, j;
    i = j = 0;
    while (i < s.length()) {
        while (-1 != j && p[j] != s[i]) j = nxt[0][j];
        mx[i] = 0;
        if (i) mx[i] = max(mx[i], mx[i - 1]);
        ++i, ++j;
        if (j == p.length()) return 1;
        mx[i - 1] = max(mx[i - 1], j);
    }
    //for (int i = 0; i < s.length(); ++i) printf("%d %d\n", i, mx[i]);
    i = j = 0;
    while (i < rs.length()) {
        while (-1 != j && rp[j] != rs[i]) j = nxt[1][j];
        ++i, ++j;
        //prln(j + mx[rs.length() - 1 - i])
        if (j + mx[rs.length() - i - 1] >= p.length()) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, ans = 0;
    cin >> rs >> n;
    s = rs;
    reverse(rs.begin(), rs.end());
    while (n --) {
        cin >> rp;
        if (rp.size() <= 1) continue;
        if (ok()) {
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}
