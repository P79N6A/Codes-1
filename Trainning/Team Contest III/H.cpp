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
    freopen("hash.in", "r", stdin);
    freopen("hash.out", "w", stdout);
    int n; scanf("%d", &n);
    int j = 0, k = 0;
    for (int i = 0; i < n; ++i) {
        for (int l = 0; l < 500; ++l) {
            if (l == j || l == k) {
                printf("bB");
            }
            else printf("aa");
        }
        if (++k == 500) {
            k = ++j;
        }
        putchar('\n');
    }
    return 0;
}
