#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 1e6 + 111;

int nx[MAXN], ans[MAXN], pr[MAXN]; //nx:节点的后一个节点  pr:节点的前一个节点
bool vis[MAXN];

int main()
{
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &a, &b);
        nx[a] = b;
        pr[b] = a;
        vis[a] = vis[b] = 1; //记录都有什么编号出现过，用于查找位置为奇数同学
    }
    int pos = 2;
    for (int i = nx[0]; i; i = nx[i], pos += 2) //偶数位置的同学
    {
        ans[pos] = i;
        vis[i] = 0;
    }
    for (pos = 1; ; ++pos) //查找任意一个奇数位置的同学
    {
        if (vis[pos]) break;
    }
    while (pr[pos]) //往前遍历
    {
        pos = pr[pos];
    }
    int start = pos;
    pos = 1;
    for (int i = start; i; i = nx[i], pos += 2) //记录答案
    {
        ans[pos] = i;
    }
    
    printf("%d", ans[1]);
    for (int i = 2; i <= n; ++i)
        printf(" %d", ans[i]);
    printf("\n");
    return 0;
}