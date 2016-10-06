#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
typedef vector<int> V;
const int MAXN = 40;
int lch[MAXN], rch[MAXN];
string sa, sb;
V pre, in;

void init()
{
	pre.clear(), in.clear();
	memset(lch, 0, sizeof lch);
	memset(rch, 0, sizeof rch);
	for (int i = 0; sa[i]; ++i) pre.push_back(sa[i] - 'A' + 1);//下标从1开始
	for (int i = 0; sb[i]; ++i) in.push_back(sb[i] - 'A' + 1); 
}

void build(V& a, V& b)
{
	if (a.size() <= 1 || b.size() <= 1) return;
	int rt = a.front();
	V::iterator it = find(b.begin(), b.end(), rt);
	V lb(b.begin(), it);
	V rb(it + 1, b.end()); //中序左右子树 
	int l = lb.size(), r = rb.size();
	//cout << l << ' ' << r << endl;
	V la(a.begin() + 1, a.begin() + l + 1); // <-就是这里。如果不加一下个根节点还是最底层的那个根节点 
	V ra(a.begin() + l + 1, a.begin() + l + r + 1);
	if (!la.empty()) lch[rt] = la.front();
	if (!ra.empty()) rch[rt] = ra.front();
	build(la, lb); build(ra, rb);
}

void pos(int rt)
{
	if (rt != 0)
	{
		pos(lch[rt]);
		pos(rch[rt]);
		printf("%c", rt - 1 + 'A');
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	while (cin >> sa >> sb)
	{
		//cout << sa << ',' << sb << '\n';
		init();
		//cout << "inital ok" << endl;
		build(pre, in);
		//cout << "build ok" << endl;
		int root = pre.front();
		pos(root);
		cout << '\n';
	}
	return 0;
}

