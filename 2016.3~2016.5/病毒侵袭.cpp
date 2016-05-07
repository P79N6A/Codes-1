#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <string.h>
#include <queue>
using namespace std;
int total = 0;
set<int> ans;
set<int>::iterator it;
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
        int res = 0;
        bool flag = 1;
        for(int i = 0;i < len && flag;i++)
        {
            now = next[now][buf[i]];
            int temp = now;
            while( temp != root )
            {
                res += end[temp];
                if (end[temp]) {
                    ans.insert(id[temp]);
                    if (ans.size() == 3) {
                        flag = 0;
                        break;
                    }
                    now = root;
                    break;
                }
                temp = fail[temp];
            }
        }
        if (res) ++total;
        return res;
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

char buf[20000];
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
            scanf("%s",buf);
            ac.insert(buf, i + 1);
        }
        ac.build();
        scanf("%d", &m);
        total = 0;
        for (int i = 1; i <= m; ++i) {
            getchar();
            gets(buf);
            ans.clear();
            if (ac.query(buf)) {
                printf("web %d:", i);
                for (it = ans.begin(); it != ans.end(); ++it) printf(" %d", *it);
                putchar('\n');
            }
        }
        printf("total: %d\n", total);
    }
    return 0;
}
