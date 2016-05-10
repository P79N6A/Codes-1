#include <iostream>
#include <string.h>
#include <cstdio>
#define  size 30
using namespace std;

int nline;

int dif = 1;

enum
{
    top ,
    rit ,
    bom ,
    lef
};

struct square
{
    int dig[4];
    int count ;
}squares[size];

int resultsqu[size];

int S_top;

int AK = 0;

void dfs(int j )
{

    j++;

    if(j == nline * nline)
    {
        AK = 1;
        return;

    }


    int i;
    for( i = 0 ; i < dif;i++)
    {
        if(squares[i ].count )
        {
            if( j   >= nline )
            {
               if( squares[resultsqu[j  - nline] ].dig[bom] != squares[i ].dig[top])continue;
            }
            if( j   % nline != 0 )//不是每一行的第一个
            {
                if(squares[resultsqu[j-1] ].dig[rit] != squares[ i ].dig[lef] ) continue;
            }

           resultsqu[j] = i;
            //**************把这个放进去********


            //状态压入

            if(AK) return;
            squares[i ].count --;

            dfs(j);

            //状态弹出
            squares[i ].count ++;
            resultsqu[j] = -1 ;
        }
        if(AK) return;

    }

}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    int k = 1;
    int f = 0;
    int t , r , b, l;
   while(scanf("%d",&nline),nline)
   {
       if(f)printf("\n");
       f = 1;


       int i = 0 ,j = 0 ;
        dif = 0;
       for(; i < nline*nline ;i++)
       {
         scanf("%d%d%d%d",&t,&r,&b,&l);
         for(j = 0; j < dif  ;j++)
         {
             if( ( squares[j].dig[top] == t  )&& (squares[j].dig[rit] == r)  &&  (squares[j].dig[bom] == b ) &&(squares[j].dig[lef] == l))
                 {
                     squares[j].count++;
                     break;
                 }
         }
         if(j == dif )
         {
             squares[dif].dig[top] = t ;
             squares[dif].dig[rit] = r;
             squares[dif].dig[bom] = b ;
             squares[dif].dig[lef] = l;
             squares[dif].count = 1;
             dif++;
         }
       }

       //输入部分
       S_top = 0;
       //memset(boolture,0,sizeof(boolture));
       AK = 0;

       dfs(-1);

       printf("Game %d: ", k++);
       if(AK)printf("Possible\n");
       else printf("Impossible\n");

   }
   //getchar();
    return 0;
}
