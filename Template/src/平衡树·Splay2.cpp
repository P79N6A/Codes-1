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

struct Tree {
    ll id, val, num, lazy, sum;
    Tree *left, *right, *fa;
    Tree(int a, int b, Tree *f) {
        id = a;
        val = b;
        lazy = 0;
        left = right = NULL;
        fa = f;
    }
}*root;

void update(Tree *x) {
    x->num = 1;
    x->sum = x->val;

    if (x->left != NULL) {
        x->sum += x->left->sum;
        x->num += x->left->num;
    }
    if (x->right != NULL) {
        x->sum += x->right->sum;
        x->num += x->right->num;
    }
}

void mark(Tree *x, int add) {
    x->lazy += add;
    x->sum += add * x->num;
    x->val += add;
}

void push_down(Tree *x) {
    if (x->lazy == 0) return;
    if (x->left != NULL) mark(x->left, x->lazy);
    if (x->right != NULL) mark(x->right, x->lazy);
    x->lazy = 0;
    update(x);
}

// right-rotate
void rr(Tree* x) {
    Tree* p = x->fa;
    push_down(p);
    push_down(x);
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
    update(p);
    update(x);
}

// left-rotate
void lr(Tree* x) {
    Tree* p = x->fa;
    push_down(p);
    push_down(x);
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
    update(p);
    update(x);
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

Tree* bst_insert(Tree *rt, int id, int val) {
    push_down(rt);
    Tree *ret = NULL;
    if (rt->id < id) {
        if (rt->right != NULL) ret = bst_insert(rt->right, id, val);
        else ret = rt->right = new Tree(id, val, rt);
    }
    else {
        if (rt->left != NULL) ret = bst_insert(rt->left, id, val);
        else ret = rt->left = new Tree(id, val, rt);
    }
    update(rt);
    return ret;
}

void insert(int id, int val) {
    Tree *x = bst_insert(root, id, val);
    splay(x, NULL);
}

Tree* bst_find(Tree *rt, int id) {
    if (rt->id < id) {
        if (rt->right != NULL) {
            Tree *temp = bst_find(rt->right, id);
            if (temp->id <= id) return temp;
            else return rt;
        }
        else return rt;
    }
    else if (rt->id > id) {
        if (rt->left != NULL) return bst_find(rt->left, id);
        else return rt;
    }
    else return rt;
}

Tree* find(int id) {
    Tree *x = bst_find(root, id);
    splay(x, NULL);
    //pr(x->id)
    //pr(root->id)
    //pr(root->left == NULL)
    return x;
}

Tree* findPre(int id) {
    Tree *x = find(id)->left;
    while (x->right) x = x->right;
    return x;
}

Tree* findNext(int id) {
    Tree *x = find(id)->right;
    while (x->left) x = x->left;
    return x;
}

void deleteInterval(int a, int b) {
    if (find(a)->id != a) insert(a, 0);
    if (find(b)->id != b) insert(b, 0);
    Tree* prev = findPre(a);
    Tree* nxt = findNext(b);
    //printf("%d %d\n", prev->val, nxt->val);
    splay(prev, NULL);
    splay(nxt, prev);
    //pr(nxt->left->val)
    nxt->left = NULL;
    update(nxt);
    update(prev);
}

ll query(int a, int b) {
    bool da = 0, db = 0;
    if (find(a)->id != a) insert(a, 0), da = 1;
    if (find(b)->id != b) insert(b, 0), db = 1;
    Tree* prev = findPre(a);
    Tree* nxt = findNext(b);
    //printf("%d %d\n", prev->val, nxt->val);
    splay(prev, NULL);
    splay(nxt, prev);
    ll ret = nxt->left->sum;
    if (da) deleteInterval(a, a);
    if (db) deleteInterval(b, b);
    return ret;
}

void update(int a, int b, int val) {
    bool da = 0, db = 0;
    if (find(a)->id != a) insert(a, 0), da = 1;
    if (find(b)->id != b) insert(b, 0), db = 1;
    Tree* prev = findPre(a);
    Tree* nxt = findNext(b);
    //printf("%d %d\n", prev->val, nxt->val);
    splay(prev, NULL);
    splay(nxt, prev);
    mark(nxt->left, val);
    if (da) deleteInterval(a, a);
    if (db) deleteInterval(b, b);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, a, b, c;
    char op[2];
    scanf("%d", &n);
    root = new Tree(-INF, 0, NULL);
    insert(INF, 0);
    //pr(root->id)
    while (n --) {
        scanf("%s %d %d", op, &a, &b);
        //pr(op)
        if (op[0] == 'M') {
            scanf("%d", &c);
            update(a, b, c);
        }
        else if (op[0] == 'I') {
            insert(a, b);
        }
        else if (op[0] == 'Q') {
            printf("%lld\n", query(a, b));
        }
        else if (op[0] == 'D') {
            deleteInterval(a, b);
        }
        //pr(root->id) pr(root->val) pr(root->sum) pr("========")
    }
    return 0;
}
