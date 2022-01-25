#include <bits/stdc++.h>
#define ft(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
 
int n,K,Q;
int d[13],cmin=1e9;
int c[14][14];
int x[14][14];
bool dd[14];
 
int dis = 0;
int car = 1;
int Count[14];
int load[14];
int res =1e9;
int sum_load = 0;
 
void bk(int i)
{
    if(i>n)
    {
        
        res =min(res,dis+c[x[car][Count[car]]][0]);
        
        return;
    }
 
    if(dis+ (n-i+1 - (K-car))*cmin + (K-car)*cmin*2 +cmin >= res 
        or 
        Q*(K-car) +Q-load[car] < sum_load )
    {
        return;
    }
    ft(j,1,n)
    {   
        if(dd[j] == true) continue;
 
        ft(z,0,1)
        {
            if( car+z >K or (Count[car]==0 and z==1)) continue;
            
            dd[j]=true;
 
            dis += c[x[car][Count[car]]][0]*z;
 
            car += z;
            Count[car]++;
            
            x[car][Count[car]]=j;
            
            load[car]+=d[j];
            sum_load-=d[j];
 
            dis += c[x[car][Count[car]-1]][j];
 
            if(load[car]<=Q)
                bk(i+1);
 
            dis -= c[x[car][Count[car]-1]][j];
            load[car]-=d[j];
 
            Count[car]--;
            car -= z;
            sum_load+=d[j];
            
            dis -= c[x[car][Count[car]]][0]*z;
 
            dd[j]=false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
 
    ///system("cls");
    cin>>n>>K>>Q;
    ft(i,1,n)
    {
        cin>>d[i];
        sum_load+=d[i];
    }
    ft(i,0,n)
        ft(j,0,n)
        {
            cin>>c[i][j];
            if(i!=j)
                cmin=min(cmin,c[i][j]);
        }
    
    bk(1);
    cout<<res;
    return 0;
}
