#include <bits/stdc++.h>

using namespace std;

int dp[100];

int rec(int now,int k)
{
    if(now<k) return 0;


    int &ret = dp[now];
    if(ret!=-1) return ret;

    set<int>tmp;
    int mx = 0;
    for(int i = 0 ; i<=now-k ; i++)
    {
        int r = rec(i , k)^rec(now-k-i , k);
        tmp.insert(r);
        mx = max(mx ,r);
    }

    for(int i =0 ; i<=mx+1 ; i++)
    {
        if(tmp.count(i)==0)
        {
            ret = i;break;
        }
    }
    return ret;
}

int main()
{
//    memset(dp , -1 , sizeof dp);
//    for(int i = 1 ; i<=10  ; i++)
//        for(int j = 1 ; j<=i ; j++)
//    {
//        cout<<"i "<<i<<" j "<<j<<" "<<(rec(i,j) ? "Alice" : "Bob")<<endl;
//    }

    int tcase,cas=1;
    cin>>tcase;
    while(tcase--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;

        int cnt = 0;
        int a = 0,b = 0;
        int sol = 0;
        for(int i = 0 ; i<s.size() ; i++)
        {
            if(s[i]=='0')
            {
                if(cnt<=0)
                {
                    cnt = 0;
                }
                else sol ^= !(cnt%2);
                cnt = 0;
            }
            else cnt++;
        }

        if(cnt<=0)
        {
            cnt = 0;
        }
        else sol ^= !(cnt%2);

        cout<<(sol ? "Alice" : "Bob")<<endl;

    }
    return 0;
}
