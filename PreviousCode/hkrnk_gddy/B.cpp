#include <bits/stdc++.h>

using namespace std;

#define maxx 1510

int rank1[maxx*maxx];
int par1[maxx*maxx];

int rank2[maxx*maxx];
int par2[maxx*maxx];

void init(int n)
{
    memset(rank1 , 0 , sizeof rank1);
    memset(rank2 , 0 , sizeof rank2);

    for(int i = 0 ; i<=n ; i++)
    {
        par1[i] = par2[i] = i;
    }
    return;
}

int find_par1(int x)
{
    if(par1[x]!=x) return par1[x] = find_par1(par1[x]);
    return x;
}

int find_par2(int x)
{
    if(par2[x]!=x) return par2[x] = find_par2(par2[x]);
    return x;
}

void u_nion1(int x,int y)
{
    if(rank1[x]>rank1[y])
        par1[y] = x;
    else par1[x] = y;

    if(rank1[x]==rank1[y]) rank1[y]++;
    return;
}

void u_nion2(int x,int y)
{
    if(rank2[x]>rank2[y])
        par2[y] = x;
    else par2[x] = y;

    if(rank2[x]==rank2[y]) rank2[y]++;
    return;
}

typedef vector<bool> VB;
typedef vector<VB > VVB;
int rx[] = {0 , -1 , -1 , 0 , 1,1};
int ry[] = {-1 , 0 , 1 , 1 , 0 , -1};

bool v[2][maxx*maxx];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m)
    {
        VB vis(n*n+100  , false);

        init(n*n +100);

        memset(v, 0 , sizeof v);

        for(int i = 0 ; i<m ; i++)
        {
            int x,y;
            cin>>x>>y;
            int xx = (x-1)*n+y;
            if(vis[xx]) continue;
            vis[xx] = true;
            v[i%2][xx] = true;

//            cout<<" -> "<<xx<<endl;
        }


        for(int i = 1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=n ; j++)
            {
                for(int k = 0 ; k<6 ; k++)
                {
                    if(i+rx[k]<1 || i+rx[k]>n || j+ry[k]<1 || j+ry[k]>n) continue;
                    int uu = (i-1)*n+j;
                    int vv = (i+rx[k]-1)*n+j+ry[k];

                    if(v[0][uu] && v[0][vv])
                    {
                        //cout<<uu<<" 0 "<<vv<<endl;
                        if(find_par1(uu)!=find_par1(vv)) u_nion1(find_par1(uu) , find_par1(vv));
                    }
                    if(v[1][uu] && v[1][vv])
                    {
                        //cout<<uu<<" 1 "<<vv<<endl;
                        if(find_par1(uu)!=find_par1(vv)) u_nion1(find_par1(uu) , find_par1(vv));
                    }
                }
            }
        }
        int isokay2 = 0;
        for(int i = 1 ; i<=n && !isokay2 ; i++)
            for(int j = 0 ; j<n && !isokay2 && v[1][i] ; j++)
            {
                if(v[1][n*n-j])
                    if(find_par1(i)==find_par1(n*n-j)) isokay2 = 1;
            }

        int isokay1 = 0;
        for(int i = 1 ; i<=n*n && !isokay1 ; i+=n)
            for(int j = n ; j<=n*n && !isokay1 && v[0][i] ; j+=n )
            {
                if(v[0][j])
                    if(find_par1(i)==find_par1(j)) isokay1 = 1;
            }

        if((isokay1+isokay2)==0)
            cout<<"NEITHER"<<endl;
        else if(isokay1)
            cout<<"ROMANS"<<endl;
        else cout<<"PERSIANS"<<endl;
    }
    return 0;
}
