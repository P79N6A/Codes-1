#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
struct Trie
{
    int next[500010][26],fail[500010],end[500010];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 26;i++)
        next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'A'] == -1)
            next[now][buf[i]-'A'] = newnode();
            now = next[now][buf[i]-'A'];
        }
        end[now]++;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 26;i++)
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
        for(int i = 0;i < 26;i++)
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
        for(int i = 0;i < len;i++)
        {
            if (!isupper(buf[i])) continue;
            now = next[now][buf[i]-'A'];
            int temp = now;
            while( temp != root )
            {
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }

};
char que[60][1111];
char buf[2000010];
Trie ac;
int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%s",que[i]);
    }
    scanf("%s",buf);
    for (int i = 0; i < n; ++i) {
        ac.init();
        ac.insert(que[i]);
        ac.build();
        int x = ac.query(buf);
        if (x)
            printf("%s: %d\n",que[i], x);
    }
    return 0;
}
