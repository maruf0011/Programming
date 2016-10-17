#include <bits/stdc++.h>

using namespace std;

#define maxx 100000
#define ll long long

int dp[10100];

bool flag[1100];

void seive()
{
    for(int i = 2 ; i<1100 ; i++)
    {
        if(flag[i]==0)
        {
            for(int j = i+i ; j<1100 ; j+=i)
                flag[j] = 1;
        }
    }
    return;
}


int dsum(int n)
{
    int ret = 0;
    while(n)
    {
        ret = n%10;
        n/=10;
    }
    return ret;
}
int rec(int cur)
{
    //cout<<cur<<"endl "<<endl;
    int ds = dsum(cur);
    if(flag[ds]==0 || ds==1) return 0;

    int &ret= dp[cur];
    if(ret!=-1) return ret;
    ret  = 0;
    for(int i = 2 ; i<=sqrt(cur) ; i++)
    {
        if((cur%i)==0)
        {
            ret |= (!rec(i));
            ret |= (!rec(cur/i));
        }
    }

    return ret;
}

int main()
{
    freopen("cs.in" , "r+" , stdin);
    freopen("cs.out" , "w+" , stdout);
    seive();

    int tcase,cas=1;
    cin>>tcase;
    memset(dp,-1 , sizeof dp);
    while(tcase--)
    {
        int n;
        cin>>n;

        cout<<"Case #"<<cas++<<": ";
        if(!rec(n))
            cout<<"Seymour"<<endl;
        else cout<<"Laurence"<<endl;
    }
    return 0;
}
