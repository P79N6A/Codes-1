
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e6 + 111;

char s[MAXN];
char st[70];
// 匹配串长度500，字符数256个
bitset<505> p[256], match;

int main()
{
    int n, m;
    while (gets(s)) {
    	scanf("%d", &n);
    	for (int i = 0; i < 256; ++i) p[i].reset();
    	match.reset();
    	for (int i = 0; i < n; ++i) {
    		scanf("%d%s", &m, st);
    		for (int j = 0; j < m; ++j) {
    			p[st[j]].set(i);
    		}
    	}
    	int len = strlen(s);
    	bool flag = false;
    	match.set(0);
    	for (int i = 0; i < len; ++i) {
    		match &= p[s[i]];
    		match <<= 1;
    		match.set(0);
    		// 只有一路连续过来才可能在n位置表现为1
    		if (match.test(n)) {
    			flag = true;
    			printf("%d\n", i - n + 2);
    		}
    	}
    	if (!flag) puts("NULL");
    	getchar();
    }
    return 0;
}