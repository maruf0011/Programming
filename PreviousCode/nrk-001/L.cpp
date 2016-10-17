#include<bits/stdc++.h>

using namespace std;

typedef vector<int>VI;
typedef vector<VI> VVI;

int rx[] = {0 , 0 , 1,-1};
int ry[] = {1 , -1 , 0 , 0};

bool find_sol(VVI &g , int r,int c,int target,int dir)
{
    for(int i = 1 ; i<=100 ; i++)
    {
        int nr = r+rx[dir]*i;
        int nc = c+ry[dir]*i;

        if(nr<0 || nr>=g.size() || nc<0 || nc>=g[nr].size()) continue;
        if(g[nr][nc]>=target) return 0;
    }
    return true;
}

int main()
{
    freopen("lucky.in" , "r" , stdin);
    freopen("lucky.out" , "w" , stdout);
    int r,c;
    while(cin>>r>>c)
    {
        VVI g(r,VI(c));

        for(int i = 0 ; i<r ; i++)
            for(int j = 0 ; j<c ; j++)
                cin>>g[i][j];

        int sol = 0;
        for(int i = 0 ; i<g.size() ; i++)
            for(int j = 0 ; j<g[i].size() ; j++)
        {
            for(int k= 0 ; k<4 ; k++)
                sol +=  find_sol(g , i, j , g[i][j] , k);
        }
        cout<<sol<<endl;
    }
    return 0;
}
