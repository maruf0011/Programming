#include <bits/stdc++.h>

using namespace std;

int rx[] = {0 , 0 , -1, 1};
int ry[] = {-1 , 1,0 , 0};

char grid[110][110];
int vis[110][110];
int R,C;
void bfs(int r,int c,int cnt)
{
    queue<int>Q;
    Q.push(r);
    Q.push(c);

    vis[r][c] = cnt;

    while(!Q.empty())
    {
        int nowr = Q.front();Q.pop();
        int nowc = Q.front();Q.pop();

        for(int i = 0 ; i<4 ; i++)
        {
            int nr = nowr+rx[i];
            int nc = nowc+ry[i];
            if(nr<0 || nr>=R || nc<0 || nc>=C || grid[nr][nc]!='1' || vis[nr][nc]==cnt) continue;
            vis[nr][nc] = cnt;
            Q.push(nr);
            Q.push(nc);
        }
    }
    return;
}

int main()
{
    freopen("al.in" , "r" , stdin);
    freopen("al.out" , "w" , stdout);
    int tcase,cas=1;
    cin>>tcase;

    int cnt = 1;

    while(tcase--)
    {
        cin>>R>>C;

        for(int i = 0 ; i<R ; i++)
            for(int j = 0 ; j<C ; j++)
                cin>>grid[i][j];

        int n;
        cin>>n;

        cout<<"Case #"<<cas++<<":\n";
        for(int i = 0 ; i<n ; i++)
        {
            char ch;
            cin>>ch;

            if(ch=='Q')
            {
                cnt++;
                int sol = 0;
                for(int j = 0 ; j<R  ; j++)
                    for(int k = 0 ; k<C ; k++)
                if(grid[j][k]=='1' && vis[j][k]!=cnt){
                    bfs(j,k , cnt);
                    sol++;
                }
                cout<<sol<<endl;
            }
            else
            {
                int x,y;
                cin>>x>>y;
                cin>>grid[x][y];
            }
        }
    }
    return 0;
}
