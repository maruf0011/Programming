#include <bits/stdc++.h>

using namespace std;

#define maxx 100000
#define ll long long

ll dp[510][5];

string str;
vector<int>seq;

const ll mod = 1000000007LL;

ll rec(int cur,int last)
{
    //cout<< " -> " << cur <<" "<< last<<" "<<endl;
    if(cur==seq.size())
    {
        return (last==3);
    }

    ll &ret = dp[cur][last];

    if(ret!=-1) return ret;


    ret = 0;

    ret += rec(cur+1 , last);

    if((seq[cur]==((last+1))))
        ret += rec(cur+1 , seq[cur]);

    if((last==4 && seq[cur]==0) || (last==3 && seq[cur]==0))
        ret += rec(cur+1 , seq[cur]);

    ret %= mod;

    return ret;
}


int main()
{
    int tcase,cas=1;

    cin>>tcase;

    while(tcase--)
    {
        cin>>str;
        seq.clear();

        for(int i = 0 ; i<str.size() ; i++)
        {
            seq.push_back(str[i]-'a');
        }
        memset(dp , -1 , sizeof dp);
        ll sol = rec(0 , 4);

        cout<<"Case #"<<cas++<<": "<<sol<<endl;
    }
    return 0;
}
