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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    string s = "经常有人问我，ACM是什么，有什么意义。我回答，大概是一个逼格很高的比赛，大概是一个很好玩的游戏吧。ACM国际大学生程序设计竞赛(英文全称：ACM International Collegiate Programming Contest（ACM-ICPC或ICPC）是由国际计算机学会（ACM）主办的，一项旨在展示大学生创新能力、团队精神和在压力下编写程序、分析和解决问题能力的年度竞赛。经过近30多年的发展，ACM国际大学生程序设计竞赛已经发展成为最具影响力的大学生计算机竞赛。赛事目前由IBM公司赞助。-来自百度百科而如今大三，专业课繁多，一切都快要结束的时候，却发现自己已经逐渐习惯了这种氛围，ACM这一路走来，有过快乐和失望，也有过期待和迷茫。从一开始奢望ACM带给我什么，到现在却发现自己更喜欢的是这过程，ACM现在对于自己而言更像是一个竞技游戏，满腔的热忱都投入到了它身上，只为玩得开心。我相信现在在每一个ACMer心里，ACM是一场游戏，没有爱过的人，不会懂。如今将此题献给你们，希望未来的路上你们可以风雨无阻，努力去追寻自己喜欢的事物。所谓梦想，不是一开始的勇不可当，而是永不停息的疯狂。本题作为签到题，无输入，请输出题目描述中ACM出现的次数，以换行结束。";
    string cmp = "ACM";
    int ans = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'A')
        {
            string temp = s.substr(i, 3);
            if (temp == cmp) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
