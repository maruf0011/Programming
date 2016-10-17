#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

VI a,b,c;
VVI nxt;

VVVI dp;

int rec(int i,int j,int k)
{
    //cout<<i<<" "<<j<<" "<<k<<endl;
    if(i==a.size() || j==b.size() || k==c.size())
        return 0;

    int &ret = dp[i][j][k];

    if(ret!=-1) return ret;

    ret = 0;

    if(a[i]==b[j] && nxt[a[i]][k]!=-1)
    {
        //cout<<"match ed"<<endl;
        ret = max(ret , rec(i+1 , j+1 , nxt[a[i]][k]+1)+1);
    }
    else
    {
        ret = max(rec(i+1 , j  , k ) , rec(i, j+1 , k));
    }
    return ret;
}


int main()
{
    int n;
    int tcase,cas=1;
    cin>>tcase;
    while(tcase--)
    {
        cin>>n;
        a = VI(n+1 , 0);
        b = VI(n+1 , 0);
        c = VI(n+1 , 0);
        dp =VVVI(n+1, VVI(n+1 , VI(n+1 , -1)));

        for(int i = 1  ; i<=n ; i++)
            cin>>a[i];
        for(int i = 1 ; i<=n ; i++)
            cin>>b[i];
        for(int i = 1 ; i<=n ; i++)
            cin>>c[i];

        nxt = VVI(n+1 , VI(n+1 , -1));

        for(int i = 1 ; i<=n  ; i++)
        {
            for(int j = n ; j>=1 ; j--)
            {
                if(c[j]==i)
                    nxt[i][j] = j;
                else
                {
                    if(j!=n) nxt[i][j] = nxt[i][j+1];
                }
            }
        }

//        for(int i = 1 ; i<=n ; i++)
//        {
//            for(int j = 1 ; j<= n ; j++)
//                cout<<nxt[i][j]<<' ';
//            cout<<endl;
//        }

        int sol = rec(1 , 1 , 1);
        cout<<sol<<endl;

        //find_sol(1,1,1);
    }
    return 0;
}
