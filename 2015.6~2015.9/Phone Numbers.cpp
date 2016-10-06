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
const int MAXN = 111;
struct F{
    string name;
    int tx, piz, girl, id;
}f[MAXN];

bool cmp1(F a, F b)
{
    return a.tx > b.tx;
}

bool cmp2(F a, F b)
{
    return a.piz > b.piz;
}

bool cmp3(F a, F b)
{
    return a.girl > b.girl;
}

bool cmp4(F a, F b)
{
    return a.id < b.id;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n, m; cin >> n;
	string s;
	for (int i = 0; i < n; ++i)
	{
	    cin >> m >> f[i].name;
	    f[i].id = i;
	    for (int j = 0; j < m; ++j)
	    {
	        cin >> s;
            if (s[0] == s[1] && s[1] == s[3] && s[3] == s[4] && s[4] == s[6] && s[6] == s[7])
                ++f[i].tx;
            else if (s[0] > s[1] && s[1] > s[3] && s[3] > s[4] && s[4] > s[6] && s[6] > s[7])
                ++f[i].piz;
            else
                ++f[i].girl;
        }
	}
	
	int cnt = 0;
	sort(f, f + n, cmp1);
	for (int i = 0; i < n; ++i)
	{
	    if (f[i].tx == f[0].tx)
            ++cnt;
        else break;
    }
    sort(f, f + cnt, cmp4);
	cout << "If you want to call a taxi, you should call:";
	for (int i = 0; i < cnt - 1; ++i)
        cout << ' ' << f[i].name << ',';
    cout << ' ' << f[cnt - 1].name << ".\n";
    
    cnt = 0;
	sort(f, f + n, cmp2);
	for (int i = 0; i < n; ++i)
	{
	    if (f[i].piz == f[0].piz)
            ++cnt;
        else break;
    }
    sort(f, f + cnt, cmp4);
	cout << "If you want to order a pizza, you should call:";
	for (int i = 0; i < cnt - 1; ++i)
        cout << ' ' << f[i].name << ',';
    cout << ' ' << f[cnt - 1].name << ".\n";
    
    cnt = 0;
	sort(f, f + n, cmp3);
	for (int i = 0; i < n; ++i)
	{
	    if (f[i].girl == f[0].girl)
            ++cnt;
        else break;
    }
    sort(f, f + cnt, cmp4);
	cout << "If you want to go to a cafe with a wonderful girl, you should call:";
	for (int i = 0; i < cnt - 1; ++i)
        cout << ' ' << f[i].name << ',';
    cout << ' ' << f[cnt - 1].name << ".\n";
	return 0;
}

