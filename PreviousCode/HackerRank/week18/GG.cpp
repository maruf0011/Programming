#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main()
{
    string str;
    int n , m;
    while(cin>>n>>m)
    {
        cin>>str;
        VVI dp(n , VI(n , 0));
        VVI add(n , VI(n , 0));

        dp[0][0] = 1;
//        dp[0][1] = 1;
        //n = str.size();
        for(int i = 0 ; i<=n-1 ; i++){
            ll sum = 0;
            if(str[i-1]=='L'){
                for(int j = 0+(i==0) ; j<=i ; j++){
                    dp[i][j] = sum;
                    sum = (sum + dp[i-1][j])%m;
                }
            }
            else{
                for(int j = i ; j>=0+(i==0) ; j-- ){
                    dp[i][j] = sum;
                    sum = (sum + j-1>=0 ? dp[i-1][j-1] : 0)%m;
                }
            }
        }

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
                cout<<dp[i][j]<<' ';
            cout<<endl;
        }
        ll sol = 0;
        for(int i = 0 ; i<=n-1  ; i++)
        {
            sol = (sol + dp[n-1][i]);
        }
        cout<<sol<<endl;
    }
    return 0;
}


/**
8 100
GLGLGLL
1 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0
2 2 1 0 0 0 0 0
0 2 4 5 5 0 0 0
16 16 14 10 5 0 0 0
0 16 32 46 56 61 61 0
0 0 16 48 94 50 11 72
91
*/
