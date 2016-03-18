#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
using namespace std;

const int MAXN = 1e3;

bool num[5];
char op[MAXN];
map<char, int> id; // 变量值映射

int dfs(int &pos) {
    char cur = op[pos];
    if (islower(cur)) return num[id[cur]];

    if (cur == 'N') {
        ++pos;
        return !dfs(pos);
    }
    else {
        ++pos;
        int lson = dfs(pos);
        ++pos;
        int rson = dfs(pos);

        if (cur == 'K') return (lson & rson);
        else if (cur == 'A') return (lson | rson);
        else if (cur == 'E') return (lson == rson);
        else return !(lson == 1 && rson == 0);
    }
}

int main()
{
    id['p'] = 0, id['q'] = 1, id['r'] = 2, id['s'] = 3, id['t'] = 4;

    while (~scanf("%s", op)) {
        if (op[0] == '0') break;
        bool flag = 1;
        for (int i = 0; i < 1 << 5; ++i) { // 枚举所有情况
            for (int j = 0; j < 5; ++j) {
                num[j] = i & (1 << j);
            }
            int pos = 0;
            if (!dfs(pos)) { // 只要一找到假的情况，就可以break了
                flag = 0;
                break;
            }
        }

        if (flag) printf("tautology\n");
        else printf("not\n");
    }
    return 0;
}
