#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e3 + 111;
struct N{
    int p, v;
    N(int a, int b):p(a), v(b){}
    bool operator <(const N &t)const
    {
        return p > t.p;
    }
};
vector<N> S, B;


int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, s, p, v;
    char d;
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> d >> p >> v;
        if (d == 'S')
        {
            bool flag = 1;
            for (int j = 0; j < S.size(); ++j)
            {
                if (S[j].p == p)
                {
                    flag = 0;
                    S[j].v += v;
                }
            }
            if (flag) S.push_back(N(p, v));
        }
        else
        {
            bool flag = 1;
            for (int j = 0; j < B.size(); ++j)
            {
                if (B[j].p == p)
                {
                    flag = 0;
                    B[j].v += v;
                }
            }
            if (flag) B.push_back(N(p, v));
        }
    }
    sort(S.begin(), S.end());
    sort(B.begin(), B.end());
    int up = min((int)S.size(), s);
    int down = S.size() - up;
    for (int i = down; i < S.size(); ++i)
    {
        cout << "S " << S[i].p << ' ' << S[i].v << '\n';
    }
    up = min((int)B.size(), s);
    for (int i = 0; i < up; ++i)
    {
        cout << "B " << B[i].p << ' ' << B[i].v << '\n';
    }
    return 0;
}
