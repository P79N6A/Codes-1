#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;
int a[MAXN], num[MAXN];
vector<int> v;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++num[a[i]];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (num[i] == 0)
            v.push_back(i);
    }
    int len = 0;
    for (int i = 0; i < n; ++i)
    {
        if (num[a[i]] > 1 || a[i] > n)
        {
            --num[a[i]];
            a[i] = v[len++];
        }
    }
    cout << a[0];
    for (int i = 1; i < n; ++i)
        cout << ' ' << a[i];
    cout << '\n';
	return 0;
}

