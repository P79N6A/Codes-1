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
const int MAXN = 1e6 + 111;

struct P {
    int id;
    int pr;
    P(int a, int b) {
        id = a;
        pr = b;
    }
    bool operator < (const P &t)const {
        return pr < t.pr;
    }
};

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    multiset<P> s;
    multiset<P>::iterator it;
    int op, a, b;
    while (~scanf("%d", &op) && op) {
        if (op == 1) {
            scanf("%d%d", &a, &b);
            s.insert(P(a, b));
        }
        else if (op == 2) {
            if (s.size() == 0) {
                cout << 0 << '\n';
                continue;
            }
            it = s.end();
            --it;
            cout << (*it).id << endl;
            s.erase(*it);
        }
        else if (op == 3) {
            if (s.size() == 0) {
                cout << 0 << '\n';
                continue;
            }
            it = s.begin();
            cout << (*it).id << endl;
            s.erase(*it);
        }
    }
    return 0;
}
