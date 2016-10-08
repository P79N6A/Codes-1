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
const int MAXN = 1e5 + 111;

char s[MAXN];
int num[26][MAXN];
int pos[26];
int len[26];
bool vis[26];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m;
    scanf("%d%s", &m, s);
    int Len = strlen(s);
    vector<char> ans;
    char mi = 'z';
    for (int r = 0; r < Len; ++r) {
        mi = min(mi, s[r]);
    }
    int l = 0, choose = 0;
    for (int r = 0; r < Len; ++r) {
        int u = s[r] - 'a';
        num[u][len[u]++] = r;
        if (r - l == m - 1) {
            if (l == choose) {
                for (int i = 0; i < 26; ++i) {
                    if (len[i] - pos[i] != 0) {
                        int p = num[i][len[i] - 1];
                        ans.push_back(s[p]);
                        choose = p + 1;
                        break;
                    }
                }
            }
            int v = s[l] - 'a';
            ++pos[v];
            ++l;
        }
    }
    bool ok = 1;
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] != mi) {
            ok = 0;
            break;
        }
    }
    if (!ok) {
        ans.clear();
        l = 0, choose = 0;
        memset(len, 0, sizeof len);
        memset(pos, 0, sizeof pos);
        for (int r = 0; r < Len; ++r) {
            int u = s[r] - 'a';
            num[u][len[u]++] = r;
            if (u == mi - 'a') {
                ans.push_back(mi);
                choose = r + 1;
            }
            if (r - l == m - 1) {
                if (l == choose) {
                    for (int i = 0; i < 26; ++i) {
                        if (len[i] - pos[i] != 0) {
                            int p = num[i][len[i] - 1];
                            ans.push_back(s[p]);
                            choose = p + 1;
                            break;
                        }
                    }
                }
                int v = s[l] - 'a';
                ++pos[v];
                ++l;
            }
        }
        sort(ans.begin(), ans.end());
        char mx = ans.back();
        for (int i = choose; i < Len; ++i) {
            if (s[i] < mx) ans.push_back(s[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        putchar(ans[i]);
    }
    return 0;
}
