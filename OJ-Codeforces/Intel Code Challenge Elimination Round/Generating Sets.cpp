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

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        map<int, bool> mp;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &y[i]);
            mp[y[i]] = 1;
        }
        sort(y, y + n);
        for (int i = n - 1; i >= 0; --i) {
            int temp = y[i];
            while (temp != 0) {
                if (!mp[temp]) {
                    y[i] = temp;
                    mp[y[i]] = 0;
                    mp[temp] = 1;
                    break;
                }
                temp /= 2;
            }
        }

        printf("%d", y[0]);
        for (int i = 1; i < n; ++i) printf(" %d", y[i]);
        putchar('\n');
    }
    return 0;
}
