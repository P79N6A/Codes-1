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
const int MAXN = 1e5 + 111;

string op[MAXN];
int val[MAXN];
string ans[MAXN * 10];
int ansv[MAXN * 10];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> op[i];
        if (op[i][0] != 'r') cin >> val[i];
    }
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; ++i) {
        if (op[i][0] == 'i') {
            ans[cnt] = op[i];
            ansv[cnt++] = val[i];
            pq.push(val[i]);
        }
        else if (op[i][0] == 'g') {
            if (pq.empty()) {
                pq.push(val[i]);
                ans[cnt] = "insert";
                ansv[cnt++] = val[i];
            }
            int mi = pq.top();
            while (mi < val[i]) {
                ans[cnt++] = "removeMin";
                pq.pop();
                if (pq.empty()) {
                    pq.push(val[i]);
                    ans[cnt] = "insert";
                    ansv[cnt++] = val[i];
                }
                mi = pq.top();
            }
            if (mi > val[i]) {
                ans[cnt] = "insert";
                ansv[cnt++] = val[i];
                pq.push(val[i]);
            }
            ans[cnt] = op[i];
            ansv[cnt++] = val[i];
        }
        else {
            if (pq.empty()) {
                pq.push(1);
                ans[cnt] = "insert";
                ansv[cnt++] = 1;
            }
            pq.pop();
            ans[cnt++] = op[i];
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < cnt; ++i) {
        if (ans[i][0] == 'r') cout << ans[i] << '\n';
        else cout << ans[i] << ' ' << ansv[i] << '\n';
    }
    return 0;
}
