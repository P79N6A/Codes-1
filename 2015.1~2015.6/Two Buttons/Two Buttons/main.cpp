#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#define BUG puts(“I am here!”)
using namespace std;
const int MAXN = 1e4 + 111;
typedef long long ll;
bool vis[MAXN];

struct node{
    int x, cnt;
};

queue<node> q;

int main() {
    int n, m;
    cin >> n >> m;
    q.push(node{n, 0});
    vis[n] = 1;
    while (!q.empty())
    {
        node now = q.front(); q.pop();
        if (now.x - 1 >= 0 && !vis[now.x - 1])
        {
            vis[now.x - 1] = 1;
            if (now.x - 1 == m)
            {
                cout << now.cnt  + 1 << '\n';
                break;
            }
            else q.push(node{now.x - 1, now.cnt + 1});
        }
        if (now.x * 2 <= MAXN && !vis[now.x * 2])
        {
            vis[now.x * 2] = 1;
            if (now.x * 2 == m)
            {
                cout << now.cnt + 1 << '\n';
                break;
            }
            else q.push(node{now.x * 2, now.cnt + 1});
        }
    }
    return 0;
}
