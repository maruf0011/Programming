#include <bits/stdc++.h>

using namespace std;

#define maxx 20000

vector< pair<int,int> >vadj[maxx];

int dist[maxx];

struct node
{
    int n,c;
    node(int n,int c): n(n) , c(c){}

    bool operator<(const node &b) const
    {
        return b.c<c;
    }
};

int dijkstra(int st_node,int edNode)
{

    for(int i = 0 ; i<maxx ; i++)
        dist[i] = (1<<30);

    priority_queue<node>Q;
    Q.push(node(st_node , 0));

    dist[st_node] = 0;

    while(!Q.empty())
    {
        node now = Q.top();
        Q.pop();

        if(dist[now.n]!=now.c) continue;

        int curnod = (now.n/24)+ 1;

        if(curnod==edNode) return dist[now.n];

        for(int i = 0 ; i<vadj[now.n].size() ; i++)
        {
            int v = vadj[now.n][i].first;
            int vc = vadj[now.n][i].second;

            if(dist[v] > now.c + vc)
            {
                dist[v] = now.c+vc;
                Q.push(node(v , dist[v]));
            }
        }
    }
    return -1;
}

int main()
{
    freopen("al.in" , "r+" ,stdin);
    freopen("al.out" , "w+" , stdout);
//    priority_queue<node>Q;
//    Q.push(node(10,11));
//    Q.push(node(10 , 10));
//    Q.push(node(10 , 9));
//
//    cout<<Q.top().c<<endl;
    int tcase,cas=1;

    cin>>tcase;

    while(tcase--)
    {
        int n,m,k;

        cin>>n>>m>>k;

        for(int i = 0 ; i<maxx ; i++)
            vadj[i].clear();

        vector<int>vcost(24, 0);

        for(int i = 0 ; i<m ; i++)
        {
            int u , v;
            cin>>u>>v;
            for(int i  = 0 ; i<24 ; i++)
            {
                int cost;
                cin>>cost;
                int j = i;
                int u1=(u-1)*24 + j;
                int v1 = (v-1)*24 + (cost+j)%24;

                vadj[u1].push_back(make_pair(v1 , cost));

                int u2=(u-1)*24 + (cost+j)%24;
                int v2 = (v-1)*24 + j;
                vadj[v2].push_back(make_pair(u2 , cost));
            }
        }

        for(int i = 1 ; i<=n ; i++)
        {
            for(int j  = 0 ; j<24 ; j++)
            {
                vadj[(i-1)*24 + j].push_back(make_pair(((i-1)*24 + (j+1)%24) , 1));
            }
        }
        cout<<"Case #"<<cas++<<":";
        for(int i = 0 ; i<k ; i++)
        {
            int s,d;
            cin>>d>>s;
            int snode = s;
            int edNode = d;

            int sol = dijkstra(snode , edNode);

            cout<<" "<<sol;
        }
        cout<<endl;
    }
}
