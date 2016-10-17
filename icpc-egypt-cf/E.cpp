#include <bits/stdc++.h>

using namespace std;

int pri[] = {2,3};
int grid[110][110][2];
int dp[110][110][2010][2];
int N,M;

int rec(int x,int y,int nowcnt,int now)
{

    int cnt = nowcnt+grid[x][y][now];
    int other = grid[x][y][!now];
    int next,next_cnt , zero;

    if(cnt>other) next_cnt = cnt-other , zero = other , next = now;
    else next_cnt = other - cnt , zero = cnt , next =!now;

    if(x==(N-1) && y==(M-1))
    {
        return zero;
    }

    int &ret = dp[x][y][nowcnt][now];
    if(ret!=-1) return ret;

    ret = 0;

    if(y<(M-1))
    {
        ret = max(ret , rec(x , y+1 , next_cnt , next)+zero);
    }
    else if(x<(N-1))
    {
        ret = max(ret , rec(x+1 , y , next_cnt , next)+zero);
    }
    return ret;
}

int main()
{
    int tcase,cas=1;

    cin>>tcase;
    while(tcase--)
    {
        int n,m;
        cin>>n>>m;
        N = n , M= m;
        memset(grid , 0 , sizeof grid);
        memset(dp , -1 , sizeof dp);

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m  ; j++)
            {
                int val;
                cin>>val;
                for(int k = 0 ; k<2 ; k++)
                {
                    while((val%pri[k])==0)
                    {
                        val /= pri[k];
                        grid[i][j][k]++;
                    }
                }
            }
        }

        cout<<max(rec(0 , 0 , 0 , 0) , rec(0,0,0,1))<<endl;
    }
    return 0;
}
