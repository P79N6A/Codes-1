#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 1e6 + 111;
int len; //代表总共的节点个数

struct Node{
    int cnt;    //多少个前缀以这个节点结尾
    int nx[26]; //下个字母
    void init() //初始化节点
    {
        cnt = 0;
        memset(nx, -1, sizeof nx);
    }
}node[MAXN];

void insert(char *s)
{
    int i = 0, p = 0; //p 母节点
    while (s[i])
    {
        int x = s[i] - 'a';
        if (node[p].nx[x] == -1) //如果是新结尾
        {
            node[len].init();
            node[p].nx[x] = len++; //node[p].nx[x]的下个节点是
        }
        p = node[p].nx[x];
        ++node[p].cnt;  //又有新东东以我为结尾啦~
        ++i;
    }
}

void query(char *s)
{
    int i = 0, p = 0;
    while (s[i])
    {
        int x = s[i] - 'a';
        if (node[p].nx[x] == -1)
        {
            puts("0");
            return;
        }
        p = node[p].nx[x];
        ++i;
    }
    printf("%d\n", node[p].cnt);
}


int main() {
    int n, m;
    char s[20];
    while (~scanf("%d", &n))
    {
        len = 1;
        node[0].init();
        while (n --)
        {
            scanf("%s", s);
            insert(s);
        }
        scanf("%d", &m);
        while (m --)
        {
            scanf("%s", s);
            query(s);
        }
    }
    return 0;
}
