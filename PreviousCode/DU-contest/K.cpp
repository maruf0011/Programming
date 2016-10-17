#include "bits/stdc++.h"

using namespace std;


int dp[1010][252][102];

int data[1010][2];
int n,t;
int mod = 1000000007;
int rec(int cur,int igredients,int remTime)
{
    if(cur==(n))
        return 1;
    int &ret = dp[cur][igredients][remTime];
    if(ret!=-1) return ret;

    ret = 0;

    if(igredients>=data[cur][1])
        ret = (ret + rec(cur+1 , 0 , remTime))%mod;
    if(remTime==0)
        ret = (ret + rec(cur , igredients , t));
    if(igredients<data[cur][0])
        ret = (ret + rec(cur, igredients+1 , max(0 , remTime-1)))%mod;
    return ret;
}

int main()
{

    while(cin>>n>>t)
    {
        memset(dp ,  -1, sizeof dp);

        for(int i = 0 ; i<n ; i++)
            cin>>data[i][0]>>data[i][1];
        cout<<rec(0 , 0 , 0)<<endl;
    }
    return 0;
}
