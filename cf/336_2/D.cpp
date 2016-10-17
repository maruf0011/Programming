#include <bits/stdc++.h>

using namespace std;

int dp[512][512];
int len[512][512];

int inp[512];

int find_len(int l,int r)
{
    if(l>r) return 0;

    int &ret = len[l][r];
    if(ret!=-1) return ret;

    if(inp[l]==inp[r])
        ret = find_len(l+1 , r-1)+1;
    else ret = 0;
    return ret;
}

int rec(int l,int r)
{
    if(l>=r)
        return 1;

    int &ret = dp[l][r];
    if(ret!=-1) return ret;
    ret = (1<<20);

    int match = find_len(l,r);
    for(int i = 0 ; i<=match ; i++)
        ret = min(ret , rec(l+i , r-i));

    for(int i = l ; i<r ; i++)
        ret = min(ret , rec(l,i)+rec(i+1 , r));

    return ret;
}

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i = 0 ; i<n ; i++)
            cin>>inp[i];
        memset(len , -1 , sizeof len);
        memset(dp , -1 , sizeof dp);

        cout<<rec(0 , n-1)<<endl;
    }
}
