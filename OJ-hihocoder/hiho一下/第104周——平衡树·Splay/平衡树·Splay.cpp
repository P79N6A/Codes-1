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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

struct Tree {
    int val;
    Tree *left, *right, *fa;
}*root;

// right-rotate
void rr(Tree* x) {
    if (x->fa == NULL) return;
    Tree* p = x->fa;
    x->fa = p->fa;
    if (p->fa == NULL) {
        root = x;
    }
    else {
        if (p->fa->left == p) p->fa->left = x;
        else p->fa->right = x;
    }
    p->left = x->right;
    if (x->right != NULL)
        x->right->fa = p;
    x->right = p;
    p->fa = x;
}

// left-rotate
void lr(Tree* x) {
    if (x->fa == NULL) return;
    Tree* p = x->fa;
    x->fa = p->fa;
    if (p->fa == NULL) {
        root = x;
    }
    else {
        if (p->fa->left == p) p->fa->left = x;
        else p->fa->right = x;
    }
    p->right = x->left;
    if (x->left != NULL)
        x->left->fa = p;
    x->left = p;
    p->fa = x;
}

// let y be the father of x
void splay(Tree* x, Tree* y) {
    while (x->fa != y) {
        Tree* p = x->fa;
        if (p->fa == y) {
            if (p->left == x) rr(x);
            else lr(x);
        }
        else {
            Tree* g = p->fa;
            if (g->left == p) {
                if (p->left == x) {
                    rr(p);
                    rr(x);
                }
                else {
                    lr(x);
                    rr(x);
                }
            }
            else {
                if (p->right == x) {
                    lr(p);
                    lr(x);
                }
                else {
                    rr(x);
                    lr(x);
                }
            }
        }
    }
}

Tree* bst_insert(int val) {
    Tree* rt = root;
    Tree* nt;
    nt = (Tree *) malloc(sizeof(Tree));
    nt->val = val;
    nt->left = nt->right = nt->fa = NULL;

    if (root == NULL) {
        root = nt;
        return nt;
    }
    while (1) {
        if (rt->val >= val) {
            if (rt->left != NULL)
                rt = rt->left;
            else {
                nt->fa = rt;
                rt->left = nt;
                return nt;
            }
        }
        else {
            if (rt->right != NULL)
                rt = rt->right;
            else {
                nt->fa = rt;
                rt->right = nt;
                return nt;
            }
        }
    }
}

void insert(int val) {
    Tree *x = bst_insert(val);
    splay(x, NULL);
}

Tree* bst_find(int val) {
    Tree* rt = root;
    Tree* ans = NULL;
    int judge = -INF;
    while (1) {
        if (rt->val <= val && rt->val >= judge) {
            ans = rt;
            judge = rt->val;
        }
        if (rt->val > val) {
            if (rt->left != NULL) {
                rt = rt->left;
            }
            else break;
        }
        else if (rt->val < val){
            if (rt->right != NULL) {
                rt = rt->right;
            }
            else break;
        }
        else break;
    }
    return ans;
}

Tree* find(int val) {
    Tree *x = bst_find(val);
    splay(x, NULL);
    return root;
}

Tree* findPre(int val) {
    Tree *x = find(val)->left;
    while (x->right) x = x->right;
    return x;
}

Tree* findNext(int val) {
    Tree *x = find(val)->right;
    while (x->left) x = x->left;
    return x;
}

int deleteInterval(int a, int b) {
    Tree* prev = findPre(a);
    Tree* nxt = findNext(b);
    //printf("%d %d\n", prev->val, nxt->val);
    splay(prev, NULL);
    splay(nxt, prev);
    //pr(nxt->left->val)
    nxt->left = NULL;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, a, b;
    char op[2];
    scanf("%d", &n);
    insert(-INF);
    insert(INF);
    while (n --) {
        //pr("========")
        scanf("%s %d", op, &a);
        if (op[0] == 'D') {
            scanf("%d", &b);
            if (find(a)->val != a) {
                insert(a);
            }
            if (find(b)->val != b) {
                insert(b);
            }
            //pr("begin:")
            deleteInterval(a, b);
        }
        else if (op[0] == 'I') {
            insert(a);
        }
        else {
            printf("%d\n", find(a)->val);
        }
    }
    return 0;
}
