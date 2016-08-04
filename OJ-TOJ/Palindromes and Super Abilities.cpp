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
const int MAXN = 1e5 + 111;
const int N = 26 ;

struct Palindromic_Tree {
    int next[MAXN][N] ;//nextָ�룬nextָ����ֵ������ƣ�ָ��Ĵ�Ϊ��ǰ�����˼���ͬһ���ַ�����
    int fail[MAXN] ;//failָ�룬ʧ�����ת��failָ��ָ��Ľڵ�
    int cnt[MAXN] ; //��ʾ�ڵ�i��ʾ�ı��ʲ�ͬ�Ĵ��ĸ���������ʱ����Ĳ�����ȫ�ģ����count()������һ���Ժ������ȷ�ģ�
    int num[MAXN] ; //��i��β�Ļ��Ĵ���������������������num��ӣ����ϴ�����Ϊ�������л��ĸ�����
    int len[MAXN] ;//len[i]��ʾ�ڵ�i��ʾ�Ļ��Ĵ��ĳ���
    int S[MAXN] ;//�����ӵ��ַ�
    int last ;//ָ����һ���ַ����ڵĽڵ㣬������һ��add
    int n ;//�ַ�����ָ��
    int p ;//�ڵ�ָ��

    int newnode ( int l ) {//�½��ڵ�
        for ( int i = 0 ; i < N ; ++ i ) next[p][i] = 0 ;
        cnt[p] = 0 ;
        num[p] = 0 ;
        len[p] = l ;
        return p ++ ;
    }

    void init () {//��ʼ��
        p = 0 ;
        newnode (  0 ) ;
        newnode ( -1 ) ;
        last = 0 ;
        n = 0 ;
        S[n] = -1 ;//��ͷ��һ���ַ�����û�е��ַ�����������
        fail[0] = 1 ;
    }

    int get_fail ( int x ) {//��KMPһ����ʧ�����һ���������
        while ( S[n - len[x] - 1] != S[n] ) x = fail[x] ;
        return x ;
    }

    int add ( int c ) {
        c -= 'a' ;
        S[++ n] = c ;
        int ret = 0;
        int cur = get_fail ( last ) ;//ͨ����һ�����Ĵ���������Ĵ���ƥ��λ��
        if ( !next[cur][c] ) {//���������Ĵ�û�г��ֹ���˵��������һ���µı��ʲ�ͬ�Ļ��Ĵ�
            int now = newnode ( len[cur] + 2 ) ;//�½��ڵ�
            fail[now] = next[get_fail ( fail[cur] )][c] ;//��AC�Զ���һ������failָ�룬�Ա�ʧ�����ת
            next[cur][c] = now ;
            num[now] = num[fail[now]] + 1 ;
            ++ret;
        }
        last = next[cur][c] ;
        cnt[last] ++ ;
        return ret;
    }

    void count () {
        for ( int i = p - 1 ; i >= 0 ; -- i ) cnt[fail[i]] += cnt[i] ;
        //�����ۼӶ��ӵ�cnt����Ϊ���fail[v]=u����uһ����v���ӻ��Ĵ���
    }
}tree ;

char s[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%s", s);
    int len = strlen(s);
    tree.init();
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        printf("%d", ans += tree.add(s[i]));
        if (i != len - 1) putchar(' ');
        else putchar('\n');
    }
    return 0;
}
