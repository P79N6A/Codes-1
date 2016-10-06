#include <iostream>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    queue<int> soldier, soldier2;
    int n;
    cin >> n;
    int k, tem;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> tem;
        soldier.push(tem);
    }
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> tem;
        soldier2.push(tem);
    }
    int ans = 0;
    while (1)
    {
        if (ans > 1000000)
        {
            cout << -1 << '\n';
            break;
        }
        int top1 = soldier.front(), top2 = soldier2.front();
        soldier.pop(), soldier2.pop();
        if (top1 > top2)
        {
            soldier.push(top2);
            soldier.push(top1);
        }
        else{
            soldier2.push(top1);
            soldier2.push(top2);
        }
        ++ans;
        if (soldier.empty())
        {
            cout << ans << ' ' << 2 << '\n';
            break;
        }
        if (soldier2.empty())
        {
            cout << ans << ' ' << 1 << '\n';
            break;
        }
    }
    return 0;
}


/*#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

typedef pair<string, string> P;
int n, k1, k2;
map<P, bool> mp;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    while(cin >> n) {
        deque<int> l, r;
        mp.clear();
        cin >> k1;
        string s, t;
        for(int i = 1; i <= k1; ++i) {
            int x; cin >> x;
            l.push_back(x); s += char(x + '0');
        }
        cin >> k2;
        for(int i = 1; i <= k2; ++i) {
            int x; cin >> x;
            r.push_back(x); t += char(x + '0');
        }
        mp[P(s, t)] = true;
        bool cycle = false;
        int ans = 0;
        //cout<<s <<' '<<t<<endl;
        while(!l.empty() && !r.empty()) {
            int ll = l.front(), rr = r.front();
            l.pop_front(); r.pop_front();
            char cl = s[0], cr = t[0];
            s.erase(0, 1); t.erase(0, 1);
            if(ll < rr) {
                r.push_back(ll);
                r.push_back(rr);
                t = t + cl + cr;
            } else {
                l.push_back(rr);
                l.push_back(ll);
                s = s + cr + cl;
            }
            //cout<< s << ' '<<t<<endl;
            if(mp.count(P(s, t))) {
                cycle = true;
                break;
            } else mp[P(s, t)] = true;
            ++ans;
        }
        if(cycle) cout << "-1\n";
        else {
            cout << ans;
            if(l.empty()) cout << " 2\n";
            else cout << " 1\n";
        }
    }
    return 0;
}*/