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
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, x, r, n;
    cin >> t;
    while (t --) {
        cin >> n >> r;
        int sum = 1500;
        while (n --) {
            cin >> x;
            sum += x;
        }
        if (sum == r) cout << "Correct\n";
        else cout << "Bug\n";
    }
    return 0;
}
