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
const int MAXN = 311;
char s[MAXN];
bool failed;
struct Node{
	int v;
	bool have_value;
	Node *left, *right;
	Node():have_value(0), left(NULL), right(NULL){}
};
Node *root;

void remove_tree(Node *u)
{
	if(u == NULL) return;
	remove_tree(u->left);
	remove_tree(u->right);
	delete u;
}

Node* newroot()
{
	return new Node;
}

void addnode(int v, char* s)
{
	Node* u = root;
	for(int i = 0; s[i] ; ++i)
	{
		if(s[i] == 'L')
		{
			if(u->left == NULL) u->left = newroot();
			u = u->left;
		}
		else if( s[i] == 'R' )
		{
			if(u->right == NULL) u->right = newroot();
			u = u->right;
		}
	}
	if(u->have_value) failed = 1;
	u->v = v;
	u->have_value = 1;
}

bool read()
{
	failed = 0;
	remove_tree(root);
	root = newroot();
	while(1)
	{
		if(scanf("%s", s)!= 1) return 0;
		if(!strcmp(s,"()")) break;
		int v;
		sscanf(&s[1], "%d", &v);
		addnode(v, strchr(s, ',') + 1);
	}
	return 1;
}

bool bfs(vector<int>& ans)
{
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while( !q.empty() )
	{
		Node* u = q.front(); q.pop();
		if( !u->have_value ) return 0;
		ans.push_back(u->v);
		if(u->left != NULL ) q.push(u->left);
		if(u->right != NULL) q.push(u->right); 
	}
	return 1;
}

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	while(read())
	{
		vector<int> ans;
		if( !bfs(ans) ) failed = 1;
		if( failed )
			printf("not complete\n");
		else
		{
			printf("%d", ans[0]);
			for( int i = 1; i < ans.size(); ++i)
				printf(" %d",ans[i]);
			putchar('\n');
		}
	}
	return 0;
}

