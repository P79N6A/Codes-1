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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

struct P {
    int x, dis;
    P(int a, int b):x(a),dis(b){}
};

bool vis[100100];

int main()
{
    int n, k;
    cin >> n >> k;
    queue<P> q;
    q.push(P(n, 0));
    while (q.size()) {
        P cur = q.front(); q.pop();
        if (cur.x == k) {
            printf("%d\n", cur.dis);
            break;
        }
        if (cur.x > 0 && !vis[cur.x - 1]) {
            vis[cur.x - 1] = 1;
            q.push(P(cur.x - 1, cur.dis + 1));
        }
        if (cur.x < 100000 && !vis[cur.x + 1]) {
            vis[cur.x + 1] = 1;
            q.push(P(cur.x + 1, cur.dis + 1));
        }
        if (cur.x * 2 <= 100000 && !vis[cur.x * 2]) {
            vis[cur.x * 2] = 1;
            q.push(P(cur.x * 2, cur.dis + 1));
        }
    }
    return 0;
}
