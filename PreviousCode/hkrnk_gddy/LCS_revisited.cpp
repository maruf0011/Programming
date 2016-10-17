#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef tuple<int,int,int> iii;

struct lcs
{
    int n;
    VVI inp;
    VVVI vadj;
    vector<iii> _tauple;
    VI dp;
    lcs(int n): n(n) , inp(4,VI(n+1, 0)) , vadj(4 , VVI(n+1)){}

    void input()
    {
        for(int i = 1;  i<=3 ; i++)
            for(int j = 1 ; j<=n ; j++)
                cin>>inp[i][j];
        return;
    }

    int process()
    {
        for(int i = 1 ; i<=3 ; i++)
        {
            for(int j = 1 ; j<=n ; j++)
            {
                vadj[i][inp[i][j]].push_back(j);
            }
        }
        int sol = 1;

        for(int i = 1; i<=n ; i++)
        {
            for(auto x: vadj[1][i])
                for(auto y: vadj[2][i])
                    for(auto z: vadj[3][i])
                        _tauple.push_back(iii{x,y,z});

            sort(_tauple.begin() , _tauple.end());

            dp = VI(_tauple.size() , 1);

            for(int i = 0 ; i<_tauple.size() ; i++)
            {
                for(int j = 0 ; j<i ; j++)
                {
                    if(get<0>(_tauple[i])>get<0>(_tauple[j]) &&
                       get<1>(_tauple[i])>get<1>(_tauple[j]) &&
                       get<2>(_tauple[i])>get<2>(_tauple[j]) )
                            dp[i] = max(dp[i] , dp[j]+1);
                }
                sol = max(dp[i] , sol);
            }
        }
        return sol;
    }
};

int main()
{
    int n;
    int tcase,cas=1;

    cin>>tcase;
    while(tcase--)
    {
        int n;
        cin>>n;
        lcs solve(n);

        solve.input();

        cout<<solve.process()<<endl;
    }
    return 0;
}
