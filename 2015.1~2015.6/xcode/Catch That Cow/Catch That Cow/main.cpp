#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 111;
bool flag[MAXN];

struct Node{
    int x, dis;
};


int main() {
    int n, k;
    cin >> n >> k;
    queue<Node> q;
    q.push(Node{n, 0});
    while (!q.empty())
    {
        Node e = q.front(); q.pop();
        if (e.x == k)
        {
            cout << e.dis << '\n';
            break;
        }
        if (e.x + 1 <= 100000 && !flag[e.x + 1])
        {
            q.push(Node{e.x + 1, e.dis + 1});
            flag[e.x + 1] = 1;
        }
        if (e.x - 1 >= 0 && !flag[e.x - 1])
        {
            q.push(Node{e.x - 1, e.dis + 1});
            flag[e.x - 1] = 1;
        }
        if (e.x * 2 <= 100000 && !flag[e.x * 2])
        {
            q.push(Node{e.x * 2, e.dis + 1});
            flag[e.x * 2] = 1;
        }
    }
    return 0;
}
