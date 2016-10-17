#include <bits/stdc++.h>

using namespace std;

char grid[1100][1100];
int dist[1100][1100][3];

int rx[] = {0 , 0 , 1, -1};
int ry[] = {1 , -1 , 0 , 0};

void bfs(int n,int m,char st,int idx)
{
    queue<int>Q;

    for(int i = 1 ; i<=n ; i++)
        for(int j = 1  ; j<=m ; j++)
            if(grid[i][j]==st) Q.push(i) , Q.push(j) , dist[i][j][idx] = 0;


    while(!Q.empty())
    {
        int nowr = Q.front();Q.pop();
        int nowc = Q.front();Q.pop();

        for(int i = 0  ; i<4 ; i++)
        {
            int nr = nowr+rx[i];
            int nc = nowc+ry[i];
            if(nr<1 || nr>n || nc<1 || nc>m || dist[nr][nc][idx]!=-1 || grid[nr][nc]=='#') continue;
            dist[nr][nc][idx] = dist[nowr][nowc][idx]+1;
            Q.push(nr);
            Q.push(nc);
        }
    }
    return;
}

int find_value(int n,int m,int idx)
{
    int id1 = (idx+1)%3;
    int id2 = (idx-1+3)%3;
    int mn1=-1 , mn2 = -1;
    for(int i = 1  ; i<= n  ; i++)
        for(int j =1 ; j<=m ; j++)
        {
            if(dist[i][j][idx]!=0) continue;
            if(dist[i][j][id1]!=-1)
                if(mn1==-1 || mn1>dist[i][j][id1]) mn1 = dist[i][j][id1];
            if(dist[i][j][id2]!=-1)
                if(mn2==-1 || mn2>dist[i][j][id2]) mn2 = dist[i][j][id2];
        }

    if(mn1!=-1 && mn2!=-1) return mn1+mn2-2;
    return -1;
}

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        memset(dist , -1 , sizeof dist);
        for(int i = 1 ; i<=n ; i++)
            for(int j =1 ; j<=m  ; j++)
                cin>>grid[i][j];

        vector<char>v;
        v.push_back('1');
        v.push_back('2');
        v.push_back('3');

        for(int i = 0 ; i<v.size(); i++)
            bfs(n,m,v[i],i);

        int sol = -1;
        for(int i = 0 ; i<v.size() ; i++)
        {
            int tmp = find_value(n , m , i);
            if(tmp==-1) continue;
            if(sol ==-1 || sol>tmp) sol = tmp;
        }


        for(int i  =1 ; i<=n ; i++)
            for(int j = 1 ; j<=m ; j++)
        {
            if(grid[i][j]!='.') continue;
            int tmp  = 0 ;
            for(int k = 0; k<v.size() ; k++)
            {
                if(dist[i][j][k]==-1)
                {
                    tmp = -1;break;
                }
                tmp += dist[i][j][k];
            }
            if(tmp!=-1)
            {
                tmp -= 2;
                if(sol==-1 || sol>tmp) sol = tmp;
            }
        }

        cout<<sol<<endl;
    }
    return 0;
}
