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
        for (int j = 1; j < lowbit(i); j <<= 1)  // �������漰��������������ֵ�Ƚ�
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
        for (r -= 1; r - lowbit(r) >= l; r -= lowbit(r)) // 1.�ж��������Ƿ��ڲ�ѯ��Χ��
        {
            ret = max(ret, maxVal[r]);
        }
        ret = max(ret, a[r]); // 2.������ڲ�ѯ��Χ�ڣ���ֻ�ܽ���r���������ж�
    }
    return ret;
}

void update(int x, int val, int n) // �����ı丸�׽���ǲ����ģ���Ϊ�޷�ȷ����������е����ֵ�������
{                                  // ���Ի���Ҫ����������бȽ�ȷ�����ֵ
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
