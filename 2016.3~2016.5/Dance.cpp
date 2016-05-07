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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1111;

bool flag[6];
bool notok[MAXN];
string s[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    string t;

    while (getline(cin, t)) {
        memset(flag, 0, sizeof flag);
        memset(notok, 0, sizeof notok);
        stringstream ss(t);
        int cnt = 0;
        while (ss >> s[cnt++]);

        int twirl = 0, hop = 0, dip = 0;
        cnt -= 1;
        for (int i = 0; i < cnt; ++i) {
            if (s[i] == "dip") {
                ++dip;
                bool ok = 0;
                if (i > 0 && s[i - 1] == "jiggle") ok = 1;
                if (i > 1 && s[i - 2] == "jiggle") ok = 1;
                if (i < cnt - 1 && s[i + 1] == "twirl") ok = 1;
                if (i < cnt - 2 && s[i + 2] == "twirl") ok = 1;
                if (!ok) {
                    flag[1] = 1;
                    notok[i] = 1;
                }
            }
            if (s[i] == "twirl") ++twirl;
            if (s[i] == "hop") ++hop;
        }

        if (cnt < 3 || s[cnt - 1] != "clap" || s[cnt - 2] != "stomp" || s[cnt - 3] != "clap")
            flag[2] = 1;

        if (twirl && !hop) flag[3] = 1;

        if (s[0] == "jiggle") flag[4] = 1;

        if (dip == 0) flag[5] = 1;

        vector<int> ans;
        for (int i = 1; i <= 5; ++i) {
            if (flag[i])
                ans.push_back(i);
        }

        cout << "form";
        if (ans.size() == 0) cout << " ok";
        else {
            if (ans.size() == 1)
                cout << " error " << ans[0];
            else cout << " errors " << ans[0];
            for (int i = 1; i < ans.size() - 1; ++i) {
                cout << ", " << ans[i];
            }
            if (ans.size() > 1) cout << " and " << ans.back();
        }
        cout << ":";
        for (int i = 0; i < cnt; ++i) {
            cout << ' ';
            if (notok[i]) cout << "DIP";
            else cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}
