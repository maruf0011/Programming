#include <bits/stdc++.h>

using namespace std;

int r,c;
int used[15][15];
int vis[15][15][4];
char grid[15][15];

int tot_sol = 0;

int rx[] = {0 , 1 , 0, -1};
int ry[] = {1 , 0 , -1 , 0};

int dfs(int x,int y,int dir)
{
    if(x<0 || x>=r || y<0 || y>=c || grid[x][y]=='*') return 1;

    if(vis[x][y][dir]) return 0;
    vis[x][y][dir] = true;
    if(used[x][y]==0) tot_sol++;
    used[x][y] = 1;

    int ret = dfs(x+rx[dir] , y+ry[dir] , dir);
    dir = (dir+1)%4;
    if(ret) ret = dfs(x+rx[dir] , y+ry[dir] , dir);
    dir = (dir+1)%4;
    if(ret) ret = dfs(x+rx[dir] , y+ry[dir] , dir);
    dir = (dir+1)%4;
    if(ret) ret = dfs(x+rx[dir] , y+ry[dir] , dir);
    return 0;
}

int main()
{
    int tcase,cas=1;
    int w,h;
    while(cin>>r>>c)
    {
        int x,y,dir;
        for(int i = 0 ; i<r ; i++)
        {
            for(int j = 0 ; j<c ; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]!='.' && grid[i][j]!='*')
                {
                    x = i,y = j;
                    if(grid[i][j]=='R') dir = 0;
                    if(grid[i][j]=='D') dir = 1;
                    if(grid[i][j]=='L') dir = 2;
                    if(grid[i][j]=='U') dir = 3;
                }
            }
        }

        memset(used , 0 , sizeof used);
        memset(vis , 0 ,sizeof vis);
        tot_sol =0;

        dfs(x,y,dir);

        cout<<tot_sol<<endl;


    }
    return 0;
}
