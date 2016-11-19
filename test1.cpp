#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

string s = "ftp://红旅动漫@wt3.hltm.cc:22/红旅首发-www.hltm.net海贼王";

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/out.txt", "w", stdout);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    for (int i = 461; i <= 500; ++i) {
        cout << s << i << ".rmvb\n";
    }
    return 0;
}