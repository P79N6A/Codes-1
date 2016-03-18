#include<cstdio>

const int MAXN = 3e4 + 111;

int dis[MAXN], num[MAXN], p[MAXN];

void init()
{
    for (int i = 1; i <= 3e4 + 11; ++i)
    {
        p[i] = i;
        dis[i] = 0;
        num[i] = 1;
    }
}

int find(int x)
{
    if (x == p[x]) return x;
    int fa = p[x];
    p[x] = find(p[x]);
    dis[x] += dis[fa]; // 更新距离
    return p[x];
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    p[x] = y;
    dis[x] += num[y];
    num[y] += num[x];
}

int main()
{
    init();
    int p;
    scanf("%d", &p);
    while (p --)
    {
        char op[2];
        int a, b;
        scanf("%s", op);
        if (op[0] == 'M')
        {
            scanf("%d%d", &a, &b);
            unite(a, b);
        }
        else
        {
            scanf("%d", &a);
            find(a); // 把dis[a]更新成到根节点的距离
            printf("%d\n", dis[a]);
        }
    }
    return 0;
}