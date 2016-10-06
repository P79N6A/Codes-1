#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;

const int MAXN = 1110;

struct Lesson{
    int day;
    int score;
    bool operator < (const Lesson& t)const
    {
        if (score == t.score) //分数相同，优先截至时间近的
            return day < t.day;
        else return score > t.score; //按分数高的排列
    }
}lesson[MAXN];

bool used[MAXN];


int main() {
    int t; scanf("%d", &t);
    while (t --)
    {
        memset(used, 0, sizeof used);
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &lesson[i].day);
        for (int i = 0; i < n; ++i) scanf("%d", &lesson[i].score);
        sort(lesson, lesson + n);
        int ans = 0, j;
        for (int i = 0; i < n; ++i)
        {
            for (j = lesson[i].day; j > 0; --j)
            {
                if (!used[j]) //有没有日期空出可以写作业
                {
                    used[j] = 1;
                    break;
                }
            }
            if (j == 0)  //没有就只能加入罚时了
                ans += lesson[i].score;
        }
        printf("%d\n", ans);
    }
    return 0;
}
