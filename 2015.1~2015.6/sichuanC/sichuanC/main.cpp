#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
using namespace std;
typedef long long ll;
int T;
int a[1010];

int main() {
    cin >> T;
    for (int t=1;t<=T;t++){
        printf("Case #%d: ",t);
        queue<int> q;
        int n;
        bool heap=false,bst=false;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",a+i);
        if (n==1 || n==2){
            printf("Both\n");
            continue;
        }
        int flag=0;
        if (a[1]<=a[2] && a[1] <= a[3]) {
            flag=1;
            heap=true;
        }
        else if (a[1]>=a[2] && a[1] >= a[3]){
            flag=2;
            heap=true;
        }
        else if (a[1]<a[2] && a[1]>a[3]){
            flag=3;
            bst=true;
        }
        else if (a[1]>a[2] && a[1]<a[3]){
            flag=4;
            bst=true;
        }
   //     cout << "flag=" << flag << endl;
        
        if (flag==1 || flag==2){
            q.push(1);
        while (!q.empty()){
            int x=q.front();q.pop();
            int temp;
            if (2*x<=n && 2*x+1<=n){
                if (a[x]<=a[x<<1] && a[x]<=a[x<<1|1])
                    temp=1;
                else if (a[x]>=a[x<<1] && a[x]>=a[x<<1|1])
                    temp=2;
                if (temp==flag) {
                    q.push(x*2);
                    q.push(x*2+1);
                }
                else {
                    if (bst) bst=false;
                    if (heap) heap=false;
                    break;
                }
            }
            else if (x*2<=n && x*2+1>n){
                if (a[x]<=a[x<<1])
                    temp=1;
                else if (a[x]>=a[x<<1])
                    temp=2;
                if (temp==flag) {
                    q.push(x*2);
                }
                else {
                    if (heap) heap=false;
                    break;
                }
            }
        }
        }
        else {
            q.push(2);q.push(3);
            while (!q.empty()){
                int x=q.front();q.pop();
                int temp=0;
                if (x<<1 <=n && x*2+1 <=n){
                    if (x%2==0){
                        if (a[x]<a[x<<1] && a[x]>a[x<<1|1] && a[x<<1|1]>a[x>>1])
                            temp=3;
                        else if (a[x]>a[x<<1] && a[x]<a[x<<1|1] && a[x<<1|1] <a[x>>1])
                            temp=4;
                    }
                    else if (x%2){
                        if (a[x]<a[x<<1] && a[x]>a[x<<1|1] && a[x<<1]<a[x>>1])
                            temp=3;
                        else if (a[x]>a[x<<1] && a[x]<a[x<<1|1] && a[x<<1]>a[x>>1])
                            temp=4;
                    }
                    if(temp==flag) {
                        q.push(x*2);
                        q.push(x*2+1);
                    }
                    else {
                        if (bst) bst=false;
                        break;
                    }
                }
                else if (x*2<=n && x*2+1>n) {
                    if (x%2==0) {
                        if (a[x]<a[x<<1] && a[x<<1] >a[x>>1])
                            temp=3;
                        else if (a[x]>a[x<<1] && a[x<<1]<a[x>>1])
                            temp=4;
                    }
                    else if (x%2) {
                        if (a[x]<a[x<<1] && a[x<<1] < a[x>>1])
                            temp=3;
                        else if (a[x]>a[x<<1] && a[x<<1]>a[x>>1])
                            temp=4;
                    }
                    if (temp==flag)
                        q.push(x*2);
                    else{
                        bst=false;
                        break;
                    }
                }
            }
        }
        if (heap) printf("Heap\n");
        else if (bst) printf("BST\n");
        else printf("Neither\n");
    }
    
    return 0;
}


