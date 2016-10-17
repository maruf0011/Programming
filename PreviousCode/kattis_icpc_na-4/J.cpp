#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> VI;
typedef vector<pair<int,long long> >VP;
typedef vector<VI> VVI;
typedef vector<VP> VVP;


long long fuel_cost[123][100010];

struct pq
{
    int n,f;
    long long c;
    pq(int n,int f,long long c):n(n) , f(f) , c(c){}
    bool operator<(const pq &b)const
    {
        return b.c<c;
    }
};


struct node
{
    int n;
    long long c;
    node(int n,long long c): n(n) , c(c){}
    bool operator<(const node &b)const
    {
        return b.c<c;
    }
};


struct solve
{
    VVP vadj;
    VVI cost;
    VP station;
    VI dist;
    int n , m;
    int tank;
    solve(int n,int m): n(n) ,m(m), cost(m+1 , VI(m+1 ,-1)) , station(m+1) , vadj(n+1) , dist(n+1){}

    void addEdge(int u,int v,int w)
    {
        vadj[u].push_back(make_pair(v,w));
        vadj[v].push_back(make_pair(u,w));
    }

    void dijkstra(int u,int idx)
    {
        for(int i = 0 ; i<=n ; i++)
            dist[i] = (1LL<<60);
        priority_queue<node>Q;

        dist[u] = 0;
        Q.push(node(u , dist[u]));

        while(!Q.empty())
        {
            node now = Q.top();
            Q.pop();
            if(dist[now.n]!=now.c) continue;
            for(int i = 0 ; i<vadj[now.n].size() ; i++)
            {
                int v = vadj[now.n][i].first;
                long long vc = vadj[now.n][i].second;
                if(dist[v]>(dist[now.n]+vc))
                {
                    dist[v] = dist[now.n]+vc;
                    Q.push(node(v,dist[v]));
                }
            }
        }
//        cout<<"for i "<<u<<" "<<idx<<endl;
        for(int i = 0 ; i<station.size()  ; i++)
        {
//            cout<<station[i].first<<" - "<<dist[station[i].first]<<endl;
            if(dist[station[i].first]<=tank)
            {
                if(cost[idx][i]==-1)
                    cost[idx][i] = dist[station[i].first]*1;
                else cost[idx][i] = min(cost[idx][i] , dist[station[i].first]*1);
            }
        }

        return;
    }

    long long get_solution(int u,int v)
    {
        memset(fuel_cost , -1 , sizeof fuel_cost);

        fuel_cost[u][0] = 0;
        priority_queue<pq>Q;
        Q.push(pq(u , 0 , 0));

        while(!Q.empty())
        {
            pq now = Q.top();
            Q.pop();

            if(fuel_cost[now.n][now.f]!=now.c) continue;
            if(now.n==v && now.f==0) return now.c;
            for(int i = 0 ; i<m+1 ; i++)
            {
                if(i==now.n) continue;
                if(cost[now.n][i]==-1) continue;

                for(int j = (int)max(0LL  ,cost[now.n][i]-now.f) ; j<=tank-now.f ; j++)
                {
                    long long vc = station[now.n].second*j;
                    if(fuel_cost[i][now.f+j-cost[now.n][i]]==-1 ||
                       fuel_cost[i][now.f+j-cost[now.n][i]] > now.c+vc)
                    {
                        fuel_cost[i][now.f+j-cost[now.n][i]] = now.c+vc;
                        Q.push(pq(i , now.f+j-cost[now.n][i] ,  now.c+vc));
                    }
                }
            }
        }
        return fuel_cost[v][0];
    }

    long long process(int u,int v)
    {
        station[m] = make_pair(v , 1000000);


        for(int i = 0 ; i<station.size() ; i++)
            dijkstra(station[i].first , i);


//        for(int i = 0 ; i<m+1 ; i++)
//        {
//            for(int j = 0 ; j<=m ; j++)
//                cout<<cost[i][j]<<" ";
//            cout<<endl;
//        }

//        for(int k = 0 ; k<m+1 ; k++)
//            for(int i = 0 ; i<m+1 ; i++)
//                for(int j = 0 ; j<m+1 ; j++)
//                {
//                    if(cost[i][k]==-1 || cost[k][j]==-1) continue;
//                    if(cost[i][j]==-1) cost[i][j] = cost[i][k] +cost[k][j];
//                    else cost[i][j] =min(cost[i][j], cost[i][k] +cost[k][j]);
//                }


        for(int i = 0 ; i<station.size() ; i++)
            if(station[i].first==u) return get_solution(i , m);
        return 0;
    }
};

int main()
{

//    priority_queue<node>Q;
//    Q.push(node(10,11));
//    Q.push(node(10 ,9));
//    cout<<Q.top().c<<endl;
    int n,m,s;

    int tcase,cas=1;
    cin>>tcase;

    while(tcase--)
    {
        cin>>n>>m>>s;
        solve solver(n , s);
        cin>>solver.tank;

        for(int i = 0 ; i<m ; i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            solver.addEdge(x,y,w);
        }

        for(int i = 0 ; i<s ; i++)
        {
            cin>>solver.station[i].first>>solver.station[i].second;
        }

        int u,v;
        cin>>u>>v;

        long long sol = solver.process(u,v);
        cout<<sol<<endl;
    }
    return 0;
}
