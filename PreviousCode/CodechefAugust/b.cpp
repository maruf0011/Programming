#include <bits/stdc++.h>

using namespace std;


typedef vector<int> VI;
typedef vector<VI > VVI;



int main()
{
    int tcase,cas=1;

    cin>>tcase;
    string str[2];
    while(tcase--)
    {
        cin>>str[0] >>str[1];

        VVI dp((str[0].size())+10 , VI(2,-1));

        for(int i = 0 ; i<str[0].size() ; i++)
        {
            for(int j= 0 ; j<2 ; j++)
            {
                dp[i][j] = (1<<30);
                if(!i)
                {
                    if(str[j][i]=='.') dp[i][j] = 0;
                }
                else if(str[j][i]=='.')
                {
                    dp[i][j] = min(dp[i-1][j] , dp[i-1][(j+1)%2]+1);
                }
            }
        }


        int sol = min(dp[str[0].size()-1][0] , dp[str[0].size()-1][1]);
        if(sol>=(1<<30)) cout<<"No"<<endl;
        else cout<<"Yes\n"<<sol<<endl;
    }
    return 0;
}
