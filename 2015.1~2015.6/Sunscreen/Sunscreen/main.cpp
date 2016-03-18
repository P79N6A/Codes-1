#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 3000;
priority_queue<int, vector<int>, greater<int> > pq; //使用优先队列存储spf的最大值
typedef pair<int, int> P;
P cow[MAXN], bot[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    int c, l;
    cin >> c >> l;
    for (int i = 0; i < c; ++i) cin >> cow[i].first >> cow[i].second;
    for (int i = 0; i < l; ++i) cin >> bot[i].first >> bot[i].second;
    sort(cow, cow + c), sort(bot, bot + l);
    int num = 0, ans = 0;
    for (int i = 0; i < l; ++i)
    {
        while (num < c && cow[num].first <= bot[i].first) //bot[i]能敷上的牛
        {
            pq.push(cow[num].second);
            ++num;
        }
        while (!pq.empty() && bot[i].second)
        {
            int tem = pq.top(); pq.pop(); //优先把最大值小的敷掉~
            if (tem < bot[i].first) continue;
            ++ans;
            bot[i].second--;
        }
    }
    cout << ans << '\n';
    return 0;
}