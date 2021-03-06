#include <bits/stdc++.h>

using namespace std;

// Adjacency list implementation of FIFO push relabel maximum flow
// with the gap relabeling heuristic.  This implementation is
// significantly faster than straight Ford-Fulkerson.  It solves
// random problems with 10000 vertices and 1000000 edges in a few
// seconds, though it is possible to construct test cases that
// achieve the worst-case.
//
// Running time:
//     O(|V|^3)
//
// INPUT:
//     - graph, constructed using AddEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain the actual flow values, look at all edges with
//       capacity > 0 (zero capacity edges are residual edges).

#include <cmath>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

struct Edge
{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel
{
    int N;
    vector<vector<Edge> > G;
    vector<LL> excess;
    vector<int> dist, active, count;
    queue<int> Q;

    PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

    void AddEdge(int from, int to, int cap)
    {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    void Enqueue(int v)
    {
        if (!active[v] && excess[v] > 0)
        {
            active[v] = true;
            Q.push(v);
        }
    }

    void Push(Edge &e)
    {
        int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
        if (dist[e.from] <= dist[e.to] || amt == 0) return;
        e.flow += amt;
        G[e.to][e.index].flow -= amt;
        excess[e.to] += amt;
        excess[e.from] -= amt;
        Enqueue(e.to);
    }

    void Gap(int k)
    {
        for (int v = 0; v < N; v++)
        {
            if (dist[v] < k) continue;
            count[dist[v]]--;
            dist[v] = max(dist[v], N+1);
            count[dist[v]]++;
            Enqueue(v);
        }
    }

    void Relabel(int v)
    {
        count[dist[v]]--;
        dist[v] = 2*N;
        for (int i = 0; i < G[v].size(); i++)
            if (G[v][i].cap - G[v][i].flow > 0)
                dist[v] = min(dist[v], dist[G[v][i].to] + 1);
        count[dist[v]]++;
        Enqueue(v);
    }

    void Discharge(int v)
    {
        for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
        if (excess[v] > 0)
        {
            if (count[dist[v]] == 1)
                Gap(dist[v]);
            else
                Relabel(v);
        }
    }

    LL GetMaxFlow(int s, int t)
    {
        count[0] = N-1;
        count[N] = 1;
        dist[s] = N;
        active[s] = active[t] = true;
        for (int i = 0; i < G[s].size(); i++)
        {
            excess[s] += G[s][i].cap;
            Push(G[s][i]);
        }

        while (!Q.empty())
        {
            int v = Q.front();
            Q.pop();
            active[v] = false;
            Discharge(v);
        }

        LL totflow = 0;
        for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
        return totflow;
    }
};

int main()
{
    int tcase,cas=1;

    cin>>tcase;

    while(tcase--)
    {
        int n;
        cin>>n;

        int st,g,s;
        cin>>st>>g>>s;
        s++;


        PushRelabel solver(n*s +2);
        int source = 0;
        int sink = (n*s)+1;

        for(int i = 1 ; i<=n ; i++)
        {
            for(int j = 1 ; j<s ; j++)
            {
                int u = (i-1)*s + j;
                int v = (i-1)*s + j+1;
                solver.AddEdge(u,v,1000);
             }
        }

        solver.AddEdge(source , (st-1)*s+1 , g);

        int m;
        cin>>m;

        for(int i = 0 ; i<m ; i++)
        {
            int v;
            cin>>v;
            solver.AddEdge(v*s , sink , 1000);
        }

        int r;
        cin>>r;
        for(int i =0 ; i<r ; i++ )
        {
            int a,b,p,t;
            cin>>a>>b>>p>>t;

            for(int j = 1 ; j<=s ; j++)
            {
                if((j+t)>s) break;
                int u = (a-1)*s+j;
                int v = (b-1)*s+j+t;
                solver.AddEdge(u,v,p);
            }
        }

        LL sol = solver.GetMaxFlow(source,  sink);
        cout<<sol<<endl;
    }
    return 0;
}
