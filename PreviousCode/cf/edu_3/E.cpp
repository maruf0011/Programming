#include <bits/stdc++.h>

using namespace std;

#define maxx 201000
#define X first
#define Y second
#define mp make_pair

using ll = long long;
using vp = vector<pair<pair<int,int> , pair<int,int> > >;

int rnk[maxx];
int par[maxx];
int cost[maxx];

void ini(int n)
{
    memset(rnk , 0,sizeof rnk);
    for(int i = 0 ; i<=n ; i++)
        par[i] = i;
}

int find_par(int x)
{
    if(par[x]!=x) return find_par(par[x]);
    return x;
}


void link(int x,int y,int cst)
{
    if(rnk[x]>rnk[y])
    {
        par[y] = x;
        cost[y] = cst;
    }
    else
    {
        par[x] = y;
        cost[x]=cst;
    }
    if(rnk[x]==rnk[y]) rnk[y]++;
    return;
}
void u_nion(int x,int y,int cst)
{
    link(find_par(x) , find_par(y),cst);
    return;
}

int find_dist(int x)
{
    if(x!=par[x]) return find_dist(par[x])+1;
    return 1;
}


int lca(int u,int v)
{
    int distu = find_dist(u) , distv = find_dist(v);

    int mx = 0;
    while(u!=v)
    {
        if(distu>distv)
        {
            mx = max(mx,cost[u]);
            u = par[u];
            distu--;
        }
        else if(distu<distv)
        {
            mx = max(mx , cost[v]);
            v = par[v];
            distv--;
        }
        else
        {
            mx = max(mx , cost[u]) ; u = par[u] ; distu--;
            mx = max(mx , cost[v]) ; v = par[v] ; distv--;
        }
    }
    return mx;
}

ll kmp(vp &edge,vector<int> &v)
{
    ll ret = 0;
    for(auto &e: edge)
    {
        if(find_par(e.Y.X)!=find_par(e.Y.Y))
        {
            u_nion(e.Y.X , e.Y.Y , e.X.X);
            v[e.X.Y] = 1;
            ret += e.X.X;
        }
    }
    return ret;
}

int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        ini(n+10);

        vector<int>flag(m+10 , 0);

        vp edge(m);

        for(int i = 0 ; i<m ; i++)
        {
            cin>>edge[i].Y.X>>edge[i].Y.Y>>edge[i].X.X;

            edge[i].X.Y = i;
        }

        sort(edge.begin() , edge.end());

        ll sol = kmp(edge , flag);

        vector<ll>vsol(m , sol);

        for(auto &e: edge)
        {
            if(flag[e.X.Y]==0)
            {
                vsol[e.X.Y] -= lca(e.Y.X , e.Y.Y);
                vsol[e.X.Y] += e.X.X;
            }
        }
        for(auto &x: vsol)
            cout<<x<<endl;
    }
    return 0;
}
