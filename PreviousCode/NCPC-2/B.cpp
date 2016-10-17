#include<stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[10100][1010];
int match[1010][130];
int par[1010];

string str,pat;

int rec(int cur,int preMatch)
{
    if(preMatch==pat.size()) return 1E7;

    if(cur==str.size()) return 0;

    int &ret= dp[cur][preMatch];
    if(ret!=-1) return ret;

    ret = rec(cur+1 , preMatch)+1;
    ret = min(ret , rec(cur+1 , match[preMatch][str[cur]]));

    return ret;
}


int main()
{
    while(cin>>str>>pat)
    {
        int k = 0;
        par[0] = k;
        for(int i = 1 ; i<pat.size() ; i++)
        {
            while(k>0 && pat[k]!=pat[i])
                k = par[k-1];
            if(pat[k]==pat[i])
                k++;
            par[i] = k;
            //cout<<"par "<<par[i]<<endl;
        }

        for(int i = 0 ; i<pat.size()  ; i++)
        {
            for(int j = 0 ; j<=127 ; j++)
            {
                k = i;
                while(k>0 && pat[k]!=j)
                    k = par[k-1];
                if(pat[k]==j) k++;
                match[i][j] = k;
            }
        }

        memset(dp , -1  ,sizeof dp);
        printf("%d\n",rec(0 , 0));
    }
    return 0;
}
