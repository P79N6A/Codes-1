#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <string.h>
#include <queue>
using namespace std;

int ans[3000];

struct Trie
{
    int next[200010][130],fail[200010],end[200010], id[200010];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 129;i++)
            next[L][i] = -1;
        id[L] = 0;
        end[L++] = 0;
        return L-1;
    }

    void init()
    {
        L = 0;
        root = newnode();
    }

    void insert(char buf[], int x)
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]] == -1)
                next[now][buf[i]] = newnode();
            now = next[now][buf[i]];
        }
        id[now] = x;
        end[now]++;
    }

    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 129;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() )
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 129;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }

    int query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            now = next[now][buf[i]];
            int temp = now;
            while( temp != root )
            {
                if (end[temp]) {
                    ++ans[id[temp]];
                }
                temp = fail[temp];
            }
        }
        return 0;
    }
    void debug()
    {
        for(int i = 0;i < L;i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],end[i]);
            for(int j = 0;j < 26;j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
};

char buf[3000000];
char s[2000][100];
Trie ac;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while(~scanf("%d", &n))
    {
        scanf("%d",&n);
        ac.init();
        for(int i = 0;i < n;i++)
        {
            scanf("%s",s[i]);
            ac.insert(s[i], i);
        }
        ac.build();
        scanf("%s", buf);
        memset(ans, 0, sizeof ans);
        ac.query(buf);
        for (int i = 0; i < n; ++i) {
            if (ans[i]) {
                printf("%s: %d\n", s[i], ans[i]);
            }
        }
    }
    return 0;
}
