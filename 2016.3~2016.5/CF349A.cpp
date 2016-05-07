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
const int MAXN = 1e6 + 111;

int main()
{
    double d, h, v, e;
    double pi = acos(-1);
    while (cin >> d >> h >> v >> e) {
        double r = d / 2;
        double org = pi * r * r * h;
        double per = e * pi * r * r;
        if (v <= per) cout << "NO" << '\n';
        else {
            cout << "YES\n";
            cout << (org) / (v - per) << '\n';
        }
    }
    return 0;
}
