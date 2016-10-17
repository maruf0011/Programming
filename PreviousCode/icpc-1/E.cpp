#include <bits/stdc++.h>

using namespace std;

#define maxx 200010

vector<int>vadj[maxx];

int dist[maxx];
int parent[maxx];
bool vis[maxx];
int uu,vv;

int dfs(int u,int par)
{
    //cout<<" hehe \n";
    memset(vis, 0 , sizeof vis);

    dist[u] = dist[par]+1;
    parent[u] = par;
    int ret = u;
    vis[u] = true;
    queue<int>Q;
    Q.push(u);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(int i = 0 ; i<vadj[u].size() ; i++)
        {
            int v = vadj[u][i];
            if((u==uu && v==vv) || (u==vv&& v==uu)) continue;
            if(vis[v]==false)
            {
                vis[v] = true;
                dist[v] = dist[u]+1;
                parent[v] = u;
                Q.push(v);
                if(dist[v]>dist[ret]) ret =  v;
            }
        }
    }

//    for(int i = 1 ; i<=4 ; i++)
//        cout<<i<<" "<<dist[i]<<endl;

    return ret;
}
vector<int>order;


pair<int,int> find_idx(int u)
{
    //parent[u] = -1;
    int _start = dfs(u , 0);
    //parent[_start] = -1;
    int _end = dfs(_start , 0);
    int tmpdist=  (dist[_end]+1)/2;

    int cur=  _end;

    while(cur && tmpdist)
    {
        cur = parent[cur];
        tmpdist--;
    }

    return make_pair(cur , (dist[_end]+1)/2);
}

pair<int,pair<int,int> > process(int n)
{
    dist[0] = -1;
    //memset(parent , -1 , sizeof parent);
    int _start = dfs(1 , 0);
    //parent[_start] = -1;
    int _end = dfs(_start , 0);

    int u = _end;
    order.clear();

    //cout<<_start<< " - "<<_end<<endl;
    while(u)
    {
        //cout<<u<<endl;
        order.push_back(u);
        u = parent[u];

    }
    int len = dist[_end]+1;
    //cout<<"done"<<endl;
    pair<int,pair<int,int> >ret;
    if(((int)order.size())%2)
    {
        //len++;
        uu = order[len/2];
        vv = order[(len/2)-1];
        pair<int,int> ret1= find_idx(uu);
        pair<int ,int > ret2 = find_idx(vv);
        ret = make_pair(max(ret1.second , ret2.second) , make_pair(ret1.first , ret2.first));

        uu = order[len/2];
        vv = order[(len/2)+1];
        ret1= find_idx(uu);
        ret2 = find_idx(vv);
        pair<int,pair<int,int> > tmpret = make_pair(max(ret1.second , ret2.second) , make_pair(ret1.first , ret2.first));
        if(tmpret.first < ret.first) ret = tmpret;
    }
    else
    {
        uu = order[len/2];
        vv = order[(len/2)-1];
        pair<int,int> ret1= find_idx(uu);
        pair<int ,int > ret2 = find_idx(vv);
        ret = make_pair(max(ret1.second , ret2.second) , make_pair(ret1.first , ret2.first));
    }
    return ret;
}

int main()
{
    int tcase,cas=1;

    cin>>tcase;

    while(tcase--)
    {
        int n;
        cin>>n;
        uu = vv =-1;

        for(int i = 0 ; i<=n+1 ; i++) vadj[i].clear();
        for(int i = 0 ; i<n-1 ; i++)
        {
            int u,v;
            cin>>u>>v;
            vadj[u].push_back(v);
            vadj[v].push_back(u);
        }

        pair<int,pair<int,int> > sol = process(n);
        cout<<sol.first<<" "<<sol.second.first<<" "<<sol.second.second<<endl;
    }
    return 0;
}
