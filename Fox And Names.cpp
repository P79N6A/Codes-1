#include<cstdio>
#include<queue>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;

char name[MAXN][MAXN];
int in[MAXN];
bool vis[26]; // ��¼�ĸ���ĸ��û������������־���������
vector<int> G[MAXN];

int main()
{
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", name[i] + 1);
    for (int i = 0; i < 26; ++i) G[i].clear(), in[i] = 0, vis[i] = 0;
    bool imp = 0;
    --n;
    for (int i = 0; i < n; ++i) // ÿ�αȽ����������ַ���
    {
        for (int j = 1; j <= 100; ++j)
        {
            if (name[i][j - 1] != name[i + 1][j - 1]) break; // �����ƶ�ֱ�����߲���ͬ
            if (name[i][j] == 0) break;
            if (name[i + 1][j] == 0) // ���ܷ�������ǰ������ͬ������º���һ�������ȶ�������
            {
                imp = 1; break;
            }
            if (name[i][j] == name[i + 1][j]) continue; // ���������ƶ�
            G[name[i][j] - 'a'].push_back(name[i + 1][j] - 'a');
            ++in[name[i + 1][j] - 'a'];
        }
    }

    vector<char> ans;
    queue<int> q;
    int judge = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (G[i].size()) ++judge;  // ͳ����Ҫ���˵�ĸ���
        if (!in[i] && G[i].size())
        {
            ans.push_back(i + 'a');
            vis[i] = 1;
            q.push(i);
        }
    }

    while (q.size())
    {
        int cur = q.front(); q.pop();
        --judge;
        for (int i = 0; i < G[cur].size(); ++i)
        {
            int v = G[cur][i];
            if (--in[v] == 0)
            {
                ans.push_back(v + 'a');
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    if (judge > 0 || imp) printf("Impossible\n");
    else
    {
        for (int i = 0; i < ans.size(); ++i) printf("%c", ans[i]);
        for (int i = 0; i < 26; ++i) if (!vis[i]) printf("%c", i + 'a');
        printf("\n");
    }
    return 0;
}
