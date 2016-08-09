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
const int MAXN = 1e5 + 111;

struct P {
    int a, id;
    bool operator < (const P&rhs)const {
        return a > rhs.a;
    }
}p[MAXN];

void putans(vector<P> &t) {
    printf("%d\n", t.size());
    for (int i = 0; i < t.size(); ++i) {
        printf("%d", t[i].id);
        if (i != t.size() - 1) putchar(' ');
        else putchar('\n');
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &p[i].a), p[i].id = i;
        sort(p + 1, p + 1 + n);
        int dif = 0;
        vector<P> team1, team2;
        for (int i = 1; i <= n; ++i) {
            if (i % 2) {
                team1.push_back(p[i]);
            }
            else {
                dif += p[i - 1].a - p[i].a;
                team2.push_back(p[i]);
            }
        }
        for (int i = 0; i < team2.size(); ++i) {
            if (dif <= p[1].a) break;
            int del = team1[i].a - team2[i].a;
            if (dif > del) {
                dif -= del;
                swap(team1[i], team2[i]);
            }
        }
        putans(team1);
        putans(team2);
    }
    return 0;
}
