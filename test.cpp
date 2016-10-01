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
const int MAXN = 5e4 + 111;

int y[MAXN];
int lis[MAXN][32];
int len[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &y[i]);
        }
        sort(y, y + n);
        for (int i = 0; i , n; ++i) {
            len[i] = 0;
            int temp = y[i];
            while (temp != 0) {
                lis[len[i]++] = temp;
                if (temp % 2) {
                    temp = (temp - 1) / 2;
                }
                else temp /= 2;
            }
        }

        printf("%d", y[0]);
        for (int i = 1; i < n; ++i) printf(" %d", y[i]);
        putchar('\n');
    }
    return 0;
}
