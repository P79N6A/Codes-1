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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MOD = 10000007;

int cnt = 0;
map<string, int> mp;
vector<int> vs1, vs2;

void make(string &s, vector<int> &v)
{
    string temp;
    for (int i = 0; i < s.length(); ++i)
    {
        if (('9' < s[i] || s[i] < '0') &&  (temp.size()))
        {
            if (!mp[temp]) mp[temp] = ++cnt, v.push_back(cnt);
            else v.push_back(mp[temp]);
            temp.clear();
        }
        temp += s[i];
    }
    if (temp.size())
    {
        if (!mp[temp]) mp[temp] = ++cnt, v.push_back(cnt);
        else v.push_back(mp[temp]);
        temp.clear();
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; cin >> t;
    string s1, s2;
    for (int kase = 1; kase <= t; ++kase)
    {
        cnt = 0; mp.clear(); vs1.clear(); vs2.clear();
        cin >> s1 >> s2;
        make(s1, vs1);
        make(s2, vs2);
    }
    return 0;
}
