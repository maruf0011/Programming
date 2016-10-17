#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;


vector<int>vadj[2100];
vector<int>vrev[2100];

vector<pair<int,int> >vedge;
int vis[2100];
int comp[2100];

vector<int>vorder;


void dfs1(int u)
{
    if(vis[u]) return;
    vis[u] = 1;

    for( int i = 0 ; i< vadj[u].size() ; i++)
    {
        int v =vadj[u][i];
        dfs1(v);
    }
    vorder.push_back(u);
    //vis[u] = 0;
    return;
}

void dfs2(int u,int cnt)
{
    if(vis[u]) return;
    vis[u] = 1;
    comp[u]= cnt;

    for(int i = 0 ; i<vrev[u].size() ; i++)
    {
        int v = vrev[u][i];
        dfs2(v , cnt);
    }
    return;
}

int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        vedge.clear();
        for(int i = 0 ; i<5*m ; i++)
        {
            vadj[i].clear();
            vrev[i].clear();
        }
        vorder.clear();
        for(int i = 0 ; i<m ; i++)
        {
            int u,v;
            cin>>u>>v;
            vedge.push_back(make_pair(u,v));
        }

        int tot_node= m;

        for(int i = 0 ; i<m ; i++)
        {
            for(int j = i+1 ; j<m ; j++)
            {
                if(i==j) continue;
                int u = min(vedge[i].first , vedge[i].second);
                int v = max(vedge[i].first , vedge[i].second);

                int x = vedge[j].first , y = vedge[j].second;
                if((x>=u && x<=v)^(y>=u && y<=v))
                {
                    ///for inside
                    //cout<<"okay "<<endl;
                    vadj[tot_node+i].push_back(j);
                    vadj[tot_node+j].push_back(i);

                    vadj[i].push_back(j+tot_node);
                    vadj[j].push_back(i+tot_node);


                    vrev[j].push_back(tot_node+i);
                    vrev[i].push_back(tot_node+j);

                    vrev[j+tot_node].push_back(i);
                    vrev[i+tot_node].push_back(j);

//                    ///for outside
//                    vadj[tot_node+i+m].push_back(j+m);
//                    vadj[tot_node+j+m].push_back(i+m);
//
//                    cout<<"- "<<tot_node+i<<" "<<(j)<<endl;
//                    cout<<"- "<<tot_node+j<<" "<<(i)<<endl;
////
//                    vrev[j+m].push_back(tot_node+i+m);
//                    vrev[i+m].push_back(tot_node+j+m);
//
//                    ///for in-out
//                    vadj[i].push_back(m+j);
//                    vadj[j].push_back(i+m);
//
//                    vadj[i+m].push_back(j);
//                    vadj[j+m].push_back(i);
//
//                    cout<<"- "<<i<<" "<<(m+j)<<endl;
//                    cout<<"- "<<j<<" "<<(i+m)<<endl;
//
//                    cout<<"- "<<i+m<<" "<<(j)<<endl;
//                    cout<<"- "<<j+m<<" "<<(i)<<endl;
//
//                    vrev[m+j].push_back(i);
//                    vrev[m+i].push_back(j);
//
//                    vrev[i].push_back(m+j);
//                    vrev[j].push_back(i+m);
//
//                    ///for inverse
//                    vadj[i+tot_node].push_back(m+j+tot_node);
//                    vadj[j+tot_node].push_back(i+m+tot_node);
//
//                    vadj[i+m+tot_node].push_back(j+tot_node);
//                    vadj[j+m+tot_node].push_back(i+tot_node);
//
//                    vrev[m+j+tot_node].push_back(i+tot_node);
//                    vrev[m+i+tot_node].push_back(j+tot_node);
//
//                    vrev[i+tot_node].push_back(m+j+tot_node);
//                    vrev[j+tot_node].push_back(i+m+tot_node);

                }
            }
        }

        vorder.clear();

        memset(vis, 0 , sizeof vis);

        int cnt=  0;

        for(int i = 0 ; i<2*tot_node ; i++)
        {
            if(!vis[i])
            {
                dfs1(i);
            }
        }
        memset(vis, 0 , sizeof vis);
        int cmp = 1;
        for(int i = ((int)vorder.size())-1 ; i>=0 ; i--)
        {
            if(!vis[vorder[i]])
            {
                dfs2(vorder[i] , cmp++);
            }
        }
        int f = 0;
        for(int i = 0 ; i<tot_node ; i++)
        {
            if(comp[i]==comp[i+tot_node])
            {
                f=  1;
                break;
            }
        }

        if(!f)
            cout<<"panda is telling the truth..."<<endl;
        else cout<<"the evil panda is lying again"<<endl;
    }
}
