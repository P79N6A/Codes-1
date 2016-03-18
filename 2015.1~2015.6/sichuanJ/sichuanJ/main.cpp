//
//  main.cpp
//  sichuanJ
//
//  Created by Link on 15/6/6.
//  Copyright (c) 2015年 郭子尧. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
char str[1000010],br[1000010];
int min(int x,int y){
    return x<y?x:y;
}
int main(int argc, const char * argv[]) {
    int t,kase = 0;
    cin>>t;
    while(t--){
        int bn = 0, len = 0,sum = 0,d = 0,b1 = 0,b0 = 0,msum = 0;
        memset(str,0,sizeof str);
        memset(br,0,sizeof br);
        cin>>str;
        len=strlen(str);
        for(int i=0;i<len;i++){
            if(str[i]=='B') bn++;
            else br[bn]++;
        }
        br[0]+=br[bn];
        b0=bn/2;
        b1=(bn+1)/2;
        for(int i=0;i<bn;i++) {
            sum+=min(bn-i,i)*br[i];
        }
        msum=sum;
        for(int i=0;i<b0;i++) d+=br[i];
        for(int i=b1;i<bn;i++) d+=br[i];
        //cout << br[0] << ' ' << br[1] << endl;
        for(int i=2;i<=bn;i++){
            d+=2*br[i-2]-br[(i-2+b0)%(bn)]-br[(i-2+b1)%(bn)];
            //cout << 'i' << i << ':' << br[(i-2+b0)%(bn)] << ' ' << br[(i-2-b1)%(bn)] << endl;
            sum+=d;
            msum=min(msum,sum);
        }
        cout<<"Case #"<<++kase<<": "<<msum<<endl;
    }
    return 0;
}
