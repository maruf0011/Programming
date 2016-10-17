#include <bits/stdc++.h>

#define SZ(a)  (int)a.size()

using namespace std;

typedef long long ll;
typedef vector<ll> VL;
typedef vector<int> VI;

struct pq
{
    int n;
    ll c;
    pq(){}
    pq(int n ,ll c): n(n) , c(c){}
    bool operator<(const pq &b)const
    {
        return c>b.c;
    }
};

struct Csolver
{
    int N ,M;
    VI tail,next,to,from,idx,flag;
    VL cost;
    VI sol;
    Csolver(int N ,int M) : N(N),M(M) , tail(N , -1) , flag(M , 0){}

    void addEdge(int u,int v,int c,int id)
    {
        from.push_back(u);
        to.push_back(v);
        cost.push_back(c);
        next.push_back(tail[u]);
        idx.push_back(id);
        tail[u] = SZ(to)-1;
    }

    void dijkstra(int source)
    {
        VL dist(N, 100000000000LL);

        priority_queue<pq>Q;

        dist[source] = 0;
        Q.push(pq(source, dist[source]));

        while(!Q.empty())
        {
            pq now = Q.top();
            Q.pop();

            if(dist[now.n]!=now.c) continue;

            for(int i = tail[now.n] ; i!=-1 ; i = next[i])
            {
                int v = to[i];
                ll vc = cost[i];

                if(dist[v]>dist[now.n]+vc)
                {
                    dist[v] = dist[now.n]+vc;
                    Q.push(pq(v , dist[v]));
                }
            }
        }
//        for(int i = 0 ; i<N  ; i++)
//            cout<<source<<" "<<dist[i]<<endl;
        for(int i = 0 ; i<to.size() ; i++)
        {
            int u = from[i] , v = to[i];
            ll c = cost[i];
            if(abs(dist[u]-dist[v])==c)
            {
                //cout<<"flag "<<idx[i]<<endl;
                flag[idx[i]] = 1;
            }
        }
        return;
    }

    void process()
    {
        for(int i = 0 ; i<N ; i++)
        {
            //cout<<"okay "<<" --- - \n";
            dijkstra(i);
        }
        for(int i = 0 ; i<M ; i++)
        {
            if(flag[i]==0)
                sol.push_back(i);
        }
    }
};

int main()
{

    freopen("cl.in" , "r+" , stdin);
    freopen("cl.out" , "w+" , stdout);
//    priority_queue<pq>Q;
//
//    Q.push(pq(10, 11));
//    Q.push(pq(10 , 10));
//
//    cout<<Q.top().c<<endl;
    int tcase,cas=1;
    cin>>tcase;

    while(tcase--)
    {
        int n,m;
        cin>>n>>m;
        Csolver cs(n , m);
        int u,v;
        ll c;
        for(int i = 0 ; i<m ; i++)
        {
            cin>>u>>v>>c;
            cs.addEdge(u,v,c,i);
            cs.addEdge(v,u,c,i);
        }

        cs.process();
        cout<<"Case #"<<cas++<<":\n";
        for(int i =  0 ; i<cs.sol.size() ; i++)
            cout<<cs.sol[i]<<endl;
    }
    return 0;
}

/**
4 5
0 1 1
0 2 5
0 3 1
1 2 1
2 3 1
*/
