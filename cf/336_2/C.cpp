#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

using VI  = vector<int>;
using VP = vector<pair<int,int> >;


int main()
{
    int n;
    while(cin>>n)
    {
        VP inp(n);
        VI pos;
        for(auto &in: inp)
        {
            cin>>in.x>>in.y;
            pos.push_back(in.x);
        }

        sort(inp.begin() , inp.end());
        sort(pos.begin() , pos.end());

        VI dp(n , 0);

        dp[0] = 1;
        int st = 0;
        int sol = 1;

        for(int i = 1 ; i<inp.size() ; i++)
        {
            st = lower_bound(pos.begin() , pos.end() , inp[i].x-inp[i].y) - pos.begin();
            dp[i] = st-1 >=0 ? dp[st-1] : 0 ;
            dp[i] += 1;
            sol = max(sol , dp[i]);
        }

        cout<<n-sol<<endl;
    }
    return 0;
}
