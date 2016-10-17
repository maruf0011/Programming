#include <bits/stdc++.h>

#define sz(a) ((int)a.size())

using namespace std;

vector<string>v;

int dp[303][303][303];
int dp_match[303][303];

int match(int a,int b)
{
    if(dp_match[a][b]!=-1) return dp_match[a][b];
    int ret = 0;
    for(int i = 0 ; i<min(v[a].size() , v[b].size()) ; i++)
    {
        if(v[a][i]==v[b][i]) ret++;
        else break;
    }
    dp_match[a][b] = dp_match[b][a] = ret;
    return ret;
}


int rec(int cur,int prev,int rem)
{
    if(cur==(int)v.size())
    {
        if(rem==0) return (int)v[prev].size();
        return (1<<26);
    }
    int &ret = dp[cur][prev][rem];

    if(ret!=-1) return ret;

    ret = (1<<26);

    ret = min(ret ,rec(cur+1 , prev , rem));
    int m = match(cur,prev);
    if(ret>0) ret = min(ret , rec(cur+1 , cur, rem-1) + (sz(v[prev]) - m) + (sz(v[cur])-m) +1 );
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("din.txt" , "r" ,stdin );
    freopen("dout.txt" , "w" , stdout);
    int tcase,cas=1;

    cin>>tcase;
    while(tcase--)
    {
        v.clear();

        string str;
        v.push_back("");

        int n,k;
        cin>>n>>k;

        for(int i = 0 ; i<n ; i++)
        {
            cin>>str;
            v.push_back(str);
        }
        sort(v.begin()  ,v.end());

//        for(auto x: v)
//            cout<<x<<endl;

        memset(dp , -1 ,sizeof dp);
        memset(dp_match , -1 , sizeof dp_match);

        cout<<"Case #"<<cas++<<": "<<rec(1 , 0 , k)<<endl;
    }
    return 0;
}
