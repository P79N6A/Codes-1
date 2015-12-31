#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 1e5 + 111;

int maxVal[MAXN], a[MAXN];

int lowbit(int x)
{
    return x & -x;
}

void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        maxVal[i] = a[i];
        for (int j = 1; j < lowbit(i); j <<= 1)  // 与所有涉及到的子区间段最大值比较
        {
            maxVal[i] = max(maxVal[i], maxVal[i - j]);
        }
    }
}

int getMax(int l, int r)
{
    int ret = a[r];
    while (l != r)
    {
        for (r -= 1; r - lowbit(r) >= l; r -= lowbit(r)) // 1.判断是区间是否在查询范围内
        {
            ret = max(ret, maxVal[r]);
        }
        ret = max(ret, a[r]); // 2.如果不在查询范围内，则只能将第r个数加入判断
    }
    return ret;
}

void update(int x, int val, int n) // 单单改变父亲结点是不够的，因为无法确定这段区间中的最大值来自哪里，
{                                  // 所以还需要与子区间进行比较确定最大值
    a[x] = val;
    for (int i = x; i <= n; i += lowbit(i))
    {
        maxVal[i] = val;
        for (int j = 1; j < lowbit(i); j <<= 1)
        {
            maxVal[i] = max(maxVal[i], maxVal[i - j]);
        }
    }
}


int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, a, b, op;
    while (~scanf("%d", &n))
    {
        init(n);
        scanf("%d", &m);
        while (m --)
        {
            scanf("%d%d%d", &op, &a, &b);
            if (op == 0) update(a, b, n);
            else
            {
                if (a > b) swap(a, b);
                printf("%d\n", min(max(getMax(1,a),getMax(b,n)),getMax(a, b)));
            }
        }
    }
    return 0;
}
