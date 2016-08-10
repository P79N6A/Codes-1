#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 11;

char s[MAXN], s2[MAXN], s3[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase = 0, n;
    while (~scanf("%d", &n) && n) {
        priority_queue<pii> pq[2];
        int p[2] = {0, 1}, val;
        printf("Case #%d:\n", ++kase);
        for (int i = 0; i < n; ++i) {
            scanf("%s%s", s, s2);
            if (s[1] == 'u') {
                scanf("%d", &val);
                int x = p[s2[0] - 'A'];
                pq[x].push(make_pair(i, val));
            }
            else if (s[1] == 'o') {
                int x = p[s2[0] - 'A'];
                printf("%d\n", pq[x].top().second);
                pq[x].pop();
            }
            else {
                scanf("%s", s3);
                int &x1 = p[s2[0] - 'A'], &x2 = p[s3[0] - 'A'];
                if (pq[x1].size() > pq[x2].size()) {
                    while (pq[x2].size()) {
                        pq[x1].push(pq[x2].top());
                        pq[x2].pop();
                    }
                }
                else {
                    while (pq[x1].size()) {
                        pq[x2].push(pq[x1].top());
                        pq[x1].pop();
                    }
                    swap(x1, x2);
                }
            }
        }
    }
    return 0;
}
