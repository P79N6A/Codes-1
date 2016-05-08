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
const int MAXN = 5e3 + 111;

int ball[MAXN];
int num[MAXN];
int occ[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        memset(num, 0, sizeof num);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &ball[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            int mx = 0, col = -1;
            memset(occ, 0, sizeof occ);
            for (int j = i; j < n; ++j) {
                ++occ[ball[j]];
                if (occ[ball[j]] > mx) {
                    mx = occ[ball[j]];
                    col = ball[j];
                }
                else if (occ[ball[j]] == mx && ball[j] < col) {
                    col = ball[j];
                }
                ++num[col];
            }
        }
        for (int i = 0; i < n; ++i) {
            printf("%d", num[i + 1]);
            if (i != n - 1) putchar(' ');
            else putchar('\n');
        }
    }
    return 0;
}
