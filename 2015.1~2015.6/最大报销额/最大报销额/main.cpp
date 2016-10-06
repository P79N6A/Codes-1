#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double money[33], sum[3], total; //sum[i]:第几类总和;money[i],第i张发票能报销多少

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    while (scanf("%lf %d", &total, &n) && n != 0)
    {
        int len = 0;
        double ans = 0;
        memset(money, 0, sizeof money);
        for (int i = 0; i < n; ++i)
        {
            bool flag = 1;  //是否出现了不属于题目超出题目限制的情况
            memset(sum, 0, sizeof sum);
            char type;
            double cost;
            scanf("%d",&m);
            for (int j = 0; j < m; ++j)
            {
                scanf(" %c:%lf",&type, &cost);
                if (type < 'A' || type > 'C' || cost > 600) //题目限制的情况
                {
                    flag = 0;
                    break;
                }
                sum[type - 'A'] += cost;//sum[0]代表A类物品总和，sum[1]为B类，sum[2]为C类
            }
            double sum_total = sum[0] + sum[1] + sum[2]; //单张发票总和
            if (flag && sum[0] <= 600 && sum[1] <= 600 && sum[2] <= 600 && sum_total <= 1000) //总和满足情况
                money[len++] = sum_total;
        }
        sort(money, money + len);
        for (int i = len - 1; i >= 0; --i) //从大往小加
            if (money[i] <= total){
                ans += money[i];
                total -= money[i];
            }
        printf("%.2f\n", ans);
    }
    return 0;
}