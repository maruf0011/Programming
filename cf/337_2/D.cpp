#include <bits/stdc++.h>

using namespace std;

using VI= vector<int>;
using VVI = vector<VI>;

int main()
{
    int tcase,cas=1;
    int mod = 1000000007;
    string s;
    int n;
    while(cin>>n)
    {
        cin>>s;

        VVI dp(n , VI(n , 0));

        dp[0][0] = 1;

        for(int i = 0 ; i<n-1 ; i++)
        {
            for(int j = 0 ; j<=i ; j++)
            {
                dp[i+1][j] = dp[i][j];
                if(s[i+1]>s[j] && (i-j+1<=1)) dp[i+1][i+1] = (dp[i+1][i+1]+dp[i+1][j])%mod;
                //cout<<dp[i][j]<<' ';
            }
            //cout<<endl;
        }

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<= i ; j++)
                cout<<dp[i][j]<<' ';
            cout<<endl;
        }

        int sol = 0;
        for(int i = 0 ; i<n-1 ; i++)
            sol = (sol + dp[n-1][i])%mod;
        cout<<sol<<endl;
    }
    return 0;
}
