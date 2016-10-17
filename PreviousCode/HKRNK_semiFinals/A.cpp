#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define maxx 110000

double dp[maxx];

vector<pair<int,int> >vadj[maxx];
vector<pair<int,int> >vrev[maxx];
vector<int>vorder;

int vis[maxx];
int cmpNo[maxx];
int cmpNoCnt[maxx];
void rec(int u)
{
    if(vis[u]) return;
    vis[u] = true;

    for(int i = 0 ; i<vadj[u].size() ; i++)
    {
        int v = vadj[u][i].first;
        rec(v);
    }

    vorder.push_back(u);
    return;
}


void rec2(int u,int cmp)
{
    if(vis[u]) return;
    vis[u] = true;
    cmpNo[u] = cmp;
    cmpNoCnt[cmp]++;

    for(int i = 0 ; i<vrev[u].size() ; i++)
    {
        int v = vrev[u][i].first;
        rec2(v , cmp);
    }

    return;
}

double solve(int u,int cmp)
{
    if(vis[u]) return 1.0;
    vis[u] = true;
    double ret = 1.0;
    for(int i = 0 ; i<vadj[u].size() ; i++)
    {
        int v = vadj[u][i].first;
        double now = vadj[u][i].second;
        if(cmpNo[v]==cmp)
        {
            ret *= (solve(v,cmp)*now/100.0);
        }

    }

    return ret;
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i = 0  ;i<=n+10 ; i++)
        {
            vadj[i].clear();
            vrev[i].clear();
            vis[i] = 0;
            cmpNoCnt[i] = 0;
        }
        vorder.clear();

        for(int i = 0 ; i<n ; i++)
        {
            int u,p;
            cin>>u>>p;
            vadj[i+1].push_back(make_pair(u , p));
            vrev[u].push_back(make_pair(i+1 , p));
        }

        for(int i = 1 ; i<=n ; i++)
        {
            if(!vis[i])
                rec(i);
        }
        //cout<<"askldf"<<endl;
        memset(vis,  0 , sizeof vis);
        int cmpTag = 1;
        for(int i = ((int)vorder.size())-1 ; i>=0  ; i--)
        {
            if(!vis[vorder[i]])
            {
                rec2(vorder[i] , cmpTag);
                cmpTag++;
            }
        }
        //cout<<"bokkor"<<endl;
        memset(vis, 0 , sizeof vis);
        double sol = 0.0;
        for(int  i= 1 ; i<=n ; i++)
        {
            if(!vis[i] && cmpNoCnt[cmpNo[i]] >=2)
            {
                sol += solve(i , cmpNo[i]);
            }
        }

        printf("%.2lf\n",sol);
    }
    return 0;
}

