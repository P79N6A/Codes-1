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
const int MAXN = 1111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        int type, n, m;
        scanf("%d%d%d", &type, &n, &m);
        if (n == m && n == 1) {
            puts("B");
            continue;
        }
        switch(type) {
            case 1: {
                if (n % 2 && m % 2) puts("G");
                else puts("B");
                break;
            }
            case 2: {
                if (n == m) puts("G");
                else puts("B");
                break;
            }
            case 3: {
                --n, --m;
                if (n == m && n % 3 == 0) puts("G");
                else {
                    if (n > m) swap(n, m);
                    if (m - n == 1 && (n - 1) % 3 == 0) puts("B");
                    else puts("D");
                }
                break;
            }
            case 4: {
                --n, --m;
                if (n < m) swap(n, m);
                n = n - m;
                if(m == (int)(n * ((1 + sqrt(5))) / 2)) puts("G");
                else puts("B");
                break;
            }
        }
    }
    return 0;
}
