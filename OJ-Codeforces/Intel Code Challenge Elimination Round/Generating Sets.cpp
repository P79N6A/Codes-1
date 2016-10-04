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
        set<int> s;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &y[i]);
            s.insert(y[i]);
        }
        set<int>::iterator it;
        while (1) {
            it = s.end();
            --it;
            int temp = *it;
            bool ok = 1;
            while (temp != 0) {
                if (!s.count(temp)) {
                    s.erase(*it);
                    s.insert(temp);
                    ok = 0;
                    break;
                }
                temp /= 2;
            }
            if (ok) break;
        }

        for (it = s.begin(); it != s.end(); ++it) {
            printf("%d ", *it);
        }
        putchar('\n');
    }
    return 0;
}
