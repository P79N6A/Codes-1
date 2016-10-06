#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define ll long long
#define pr(x) cout << "#x = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;

int p[MAXN], e[MAXN]; //p:���׽�� e:��¼���
bool exist[MAXN];  //��¼������Щ����Ǵ��������ϵ�

void init()
{
    for (int i = 0; i < MAXN; ++i)
    {
        exist[i] = 0;
        p[i] = i;
        e[i] = 0;
    }
}

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

bool unite(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b) return 0; //�γɻ���
    p[a] = b;
    return 1;
}

int main()
{

    int kase = 0, a, b, root;
    while (~scanf("%d%d", &a, &b) && a != -1)
    {
        bool flag = 1;
        if (a == 0 && b == 0) goto ed; //����
        init();
        root = a;
        ++e[b];
        exist[a] = exist[b] = 1;
        if (!unite(a, b)) flag = 0;
        while (scanf("%d%d", &a, &b) && (a || b))
        {
            exist[a] = exist[b] = 1;
            ++e[b];
            if (!unite(a, b)) flag = 0;
        }
        root = find(root);
        for (int i = 0; i < MAXN; ++i) //��ɭ�� + ���ǲ���������
        {
            if (exist[i] && (find(i) != root || e[i] > 1))
            {
                flag = 0;
                break;
            }
        }
        ed:
        if (flag) printf("Case %d is a tree.\n", ++kase);
        else printf("Case %d is not a tree.\n", ++kase);
    }
    return 0;
}
