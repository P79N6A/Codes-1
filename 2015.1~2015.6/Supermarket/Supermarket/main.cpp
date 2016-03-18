#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXN = 1e4 + 111;

vector<int> v[MAXN]; // 存一下这一天都有什么商品截止了

int main()
{
    int n, p, d, up;
    while (~scanf("%d", &n))
    {
        up = 0;
        for (int i = 1; i <= 1e4 + 11; ++i) v[i].clear();
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &p, &d);
            up = max(up, d);
            v[d].push_back(p);
        }
        int ans = 0;
        vector<int>::iterator it;
        priority_queue<int> pq;
        for (int i = up; i >= 1; --i)
        {
            if (v[i].size())
            {
                for (it = v[i].begin(); it != v[i].end(); ++it) // 将所有商品放入优先队列
                    pq.push(*it);
                ans += pq.top();
                pq.pop();
            }
            else if (pq.size())
            {
                ans += pq.top();
                pq.pop();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}