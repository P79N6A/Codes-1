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
    string s = "�����������ң�ACM��ʲô����ʲô���塣�һش𣬴����һ���Ƹ�ܸߵı����������һ���ܺ������Ϸ�ɡ�ACM���ʴ�ѧ��������ƾ���(Ӣ��ȫ�ƣ�ACM International Collegiate Programming Contest��ACM-ICPC��ICPC�����ɹ��ʼ����ѧ�ᣨACM������ģ�һ��ּ��չʾ��ѧ�������������ŶӾ������ѹ���±�д���򡢷����ͽ��������������Ⱦ�����������30����ķ�չ��ACM���ʴ�ѧ��������ƾ����Ѿ���չ��Ϊ���Ӱ�����Ĵ�ѧ�����������������Ŀǰ��IBM��˾������-���԰ٶȰٿƶ���������רҵ�η��࣬һ�ж���Ҫ������ʱ��ȴ�����Լ��Ѿ���ϰ�������ַ�Χ��ACM��һ·�������й����ֺ�ʧ����Ҳ�й��ڴ�����ã����һ��ʼ����ACM������ʲô��������ȴ�����Լ���ϲ����������̣�ACM���ڶ����Լ����Ը�����һ��������Ϸ����ǻ���ȳ���Ͷ�뵽�������ϣ�ֻΪ��ÿ��ġ�������������ÿһ��ACMer���ACM��һ����Ϸ��û�а������ˣ����ᶮ����񽫴����׸����ǣ�ϣ��δ����·�����ǿ��Է������裬Ŭ��ȥ׷Ѱ�Լ�ϲ���������ν���룬����һ��ʼ���²��ɵ�����������ͣϢ�ķ�񡣱�����Ϊǩ���⣬�����룬�������Ŀ������ACM���ֵĴ������Ի��н�����";
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
