/*
  �뵽�����������������뵽�˶��֣�ȴû���뵽��ô
  ʹ�ö��ֵõ���ʱ�䡣��һ��ģ���������̵�����= =
  һֱ�ھ���ʱ��;���֮��Ĺ�ϵ
  �������double��֪������ѭ��������TLE��
 */
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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;
const double eps = 1e-10;

double n, len, v1, v2, k;

bool ok(double T) {
    double st = 0, ed = len;
    int cnt = n;
    while (cnt > k) {
        double t1 = (ed - st - T * v1) / (v2 - v1); // ���������ʹ�����λ�û��ѵ�ʱ��
        double t2 = t1 * (v2 - v1) / (v1 + v2);  // �������ص�ʱ��
        st += (t1 + t2) * v1;
        T -= (t1 + t2);
        cnt -= k;
    }
    return T * v2 - (ed - st) > -eps; // ���ȫ���ϳ�����ʱ�乻�������յ�
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%lf%lf%lf%lf%lf", &n, &len, &v1, &v2, &k);
    double ans = -1, l = 0, r = len / v1;
    for (int i = 0; i < 100; ++i) {
        double mid = (r + l) / 2.0;
        if (ok(mid)) {
            ans = mid;
            r = mid;
        }
        else l = mid;
    }
    printf("%.10f\n", ans);
    return 0;
}
