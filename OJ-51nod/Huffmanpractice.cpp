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
    int n;
    cin >> n;
    multiset<int> s;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s.insert(x);
    }
    int ans = 0;
    while (s.size() > 1) {
        int temp = *s.begin();
        s.erase(s.begin());
        temp += *s.begin();
        s.erase(s.begin());
        ans += temp;
        //pr(temp)
        s.insert(temp);
    }
    cout << ans << '\n';
    return 0;
}
