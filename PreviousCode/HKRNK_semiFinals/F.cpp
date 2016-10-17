#include <bits/stdc++.h>

using namespace std;

int dist[10000];

vector<pair<int,int> >vadj[10000];

int bfs(int source,int target,int n)
{
    queue<int>Q;
    memset(dist, -1 , sizeof dist);

    Q.push(source);
    dist[source] = 0;


    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i = 0 ; i<vadj[u].size() ; i++)
        {
            int v = vadj[u][i].first;
            int vc = vadj[u][i].second;

            if(dist[v]==-1)
            {
                dist[v] = dist[u] + vc;
                Q.push(v);
                if(v==target) return dist[v];
            }
        }

    }
    return dist[target];
}

int main()
{
    int tcase,cas=1;
    //cin>>tcase;
    int n,m,k;


    while(cin>>n>>k)
    {


        for(int i = 0 ; i<=n+1  ; i++)
            vadj[i].clear();

        for(int i = 0 ; i<n-1; i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            vadj[u].push_back(make_pair(v,c));
            vadj[v].push_back(make_pair(u,c));
        }

        for(int i = 0 ; i<k ; i++)
        {
            int sz;
            cin>>sz;

            vector<int>tmp(sz );

            for(int j  = 0 ; j<sz ; j++)
                cin>>tmp[j];
            int sol = 0;
            for(int j = 0 ; j<sz ;j++)
                for(int k = j+1 ; k<sz ; k++)
            {
                sol += bfs(tmp[j] , tmp[k] , n);
            }

            cout<<sol<<endl;
        }
    }
    return 0;
}
