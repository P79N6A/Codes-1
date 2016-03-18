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
const int MAXN = 2e3 + 111;

char s[MAXN][MAXN];
// a:右上方  b:左下方
bool ar[MAXN], ac[MAXN], br[MAXN], bc[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (s[i][j] == '1' && ar[i] + ac[j] != 1) {
                ar[i] ^= 1;
                ac[j] ^= 1;
                ++ans;
            }
            else if (s[i][j] == '0' && ar[i] + ac[j] == 1) {
                ar[i] ^= 1;
                ac[j] ^= 1;
                ++ans;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (s[i][j] == '1' && br[i] + bc[j] != 1) {
                br[i] ^= 1;
                bc[j] ^= 1;
                ++ans;
            }
            else if (s[i][j] == '0' && br[i] + bc[j] == 1) {
                br[i] ^= 1;
                bc[j] ^= 1;
                ++ans;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int x = bc[i] + br[i] + ac[i] + ar[i];
        if (s[i][i] == '1' && x % 2 == 0) ++ans;
        else if (s[i][i] == '0' && x % 2) ++ans;
    }

    printf("%d\n", ans);
    return 0;
}
