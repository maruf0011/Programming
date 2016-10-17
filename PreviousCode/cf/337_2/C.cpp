#include <bits/stdc++.h>

using namespace std;

char grid[512][512];
int dp[512][512][2];

int main()
{
    int r,c;
    int q;

    while(cin>>r>>c)
    {
        for(int i =  0 ; i<r ; i++)
            for(int j = 0 ; j<c ; j++)
                cin>>grid[i][j];

        memset(dp , 0 , sizeof dp);

        for(int i = 0 ; i<r ; i++)
        {
            for(int j = 0 ; j<c ; j++)
            {
                if(i==0 && j==0) continue;
                for(int k = 0 ; k<2 ; k++)
                {
                    if(k==0 && j!=0)
                    {
                        dp[i][j][k] = dp[i][j-1][k];
                        if(grid[i][j]=='.' && grid[i][j-1]=='.') dp[i][j][k]++;
                    }
                    else if(k==1 && i!=0)
                    {
                        dp[i][j][k] = dp[i-1][j][k];
                        if(grid[i][j]=='.' && grid[i-1][j]=='.') dp[i][j][k]++;
                    }
                }
            }
        }

//        for(int i = 0 ; i<5 ; i++)
//        {
//            for(int j = 0 ; j<5 ; j++)
//                cout<<dp[i][j][0]<<' ';
//            cout<<endl;
//        }
//        cout<<endl;
//        for(int i = 0 ; i<5 ; i++)
//        {
//            for(int j = 0 ; j<5 ; j++)
//                cout<<dp[i][j][1]<<' ';
//            cout<<endl;
//        }

        cin>>q;

        for(int i = 0 ; i<q ; i++)
        {
            int r1,c1,r2,c2;

            cin>>r1>>c1>>r2>>c2;
            r1--;
            c1--;
            r2--;
            c2--;
            int sol = 0;
            for(int i= r1 ; i<=r2 ; i++)
                sol += (dp[i][c2][0] - dp[i][c1][0]);

            for(int j = c1 ; j<=c2  ; j++)
                sol += (dp[r2][j][1] -dp[r1][j][1] );

            cout<<sol<<endl;
        }
    }
    return 0;
}
