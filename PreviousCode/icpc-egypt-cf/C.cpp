#include <bits/stdc++.h>

using namespace std;

int par[100100],rnk[100100];
int tme[100100];
//vector<int>v[10010];

int find_par(int u)
{
    if(par[u]!=u) return find_par(par[u]);
    else return u;
}

void link(int u,int v,int t)
{
    if(rnk[u]>rnk[v])
    {
        par[v] = u;
        tme[v] = t;
    }
    else
    {
        par[u] = v;
        tme[u] = t;
    }
    if(rnk[u]==rnk[v]) rnk[v]++;
    return;
}

void u_nion(int u,int v,int t)
{
    link(find_par(u) , find_par(v) ,t);
    return;
}

int find_dep(int u)
{
    if(par[u]!=u) return find_dep(par[u])+1;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tcase,cas=1;

    cin>>tcase;

    while(tcase--)
    {
        int n,m;
        cin>>n>>m;
        for(int i = 0 ; i<n+10 ; i++)
            par[i] = i , rnk[i] = 0;

//        map<pair<int,int>,int>mpIndx;

        for(int i = 0 ; i<m ; i++)
        {
            int x,u,v;
            cin>>x>>u>>v;
            //assert(u!=v);
            if(x==1)
            {
                if(find_par(u)!=find_par(v))
                {
                    u_nion(u,v,i+1);
                }
            }
            else
            {
                if(find_par(u)!=find_par(v))
                    cout<<"-1"<<endl;
                else
                {
                    int depu = find_dep(u);
                    int depv = find_dep(v);
                    int sol  =0 ;

                    while(u!=v)
                    {
                        if(depu>depv)
                        {
                            depu--;
                            sol = max(sol , tme[u]);
                            u = par[u];
                        }
                        else if(depu<depv)
                        {
                            depv--;
                            sol = max(sol , tme[v]);
                            v = par[v];
                        }
                        else
                        {
                            depu--;
                            sol = max(sol , tme[u]);
                            u = par[u];
                            depv--;
                            sol = max(sol , tme[v]);
                            v = par[v];
                        }
                    }

                    cout<<sol<<endl;
                }
            }
        }
    }
    return 0;
}

/**
1
4 100
1 1 2
2 1 2
1 2 3
2 1 3
2 1 4
*/
