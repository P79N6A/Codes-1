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
const int MAXN = 3e3 + 111;

bool has[MAXN];
int a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), has[i] = 0;
        bool ok = 1;
        for (int i = 1; i < n; ++i) {
            int del = abs(a[i] - a[i + 1]);
            has[del] = 1;
        }
        for (int i = 1; i < n; ++i) {
            if (!has[i]) {
                ok = 0;
                break;
            }
        }
        if (!ok) printf("Not jolly\n");
        else printf("Jolly\n");
    }
    return 0;
}
