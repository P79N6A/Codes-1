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
const int MAXN = 1e3 + 111;

int num[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n;
    cin >> t;
    while (t --) {
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; ++i) cin >> num[i], sum += num[i];
        int temp = num[0];
        for (int i = 1; i < n; ++i) {
            temp = __gcd(temp, num[i]);
        }
        cout << temp << ' ' << sum / temp << '\n';
    }
    return 0;
}
