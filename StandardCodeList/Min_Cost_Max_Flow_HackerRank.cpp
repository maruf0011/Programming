#include <cstdio>
#include <vector>

using namespace std;

const int N = 110, inf = 1000000010;

int n, m, k;

struct Edge
{
    int b, c, u, f, back;
};

class MCMF
{
private:

    int s, t, n;
    vector<Edge> g[N];

public:

    MCMF(int _s, int _t, int _n)
    {
        s = _s;
        t = _t;
        n = _n;
    }

    void addEdge(int a, int b, int c, int u)
    {
        Edge e1 = {b, c, u, 0, g[b].size()};
        Edge e2 = {a, -c, 0, 0, g[a].size()};
        g[a].push_back(e1);
        g[b].push_back(e2);
    }

    int minCostMaxFlow()
    {
        int flow = 0;
        int cost = 0;
        int *state = new int[n];
        int *from = new int[n];
        int *from_edge = new int[n];
        int *d = new int[n];
        int *q = new int[n];
        int qh, qt;
        qh = 0, qt = 0;
        while (true)
        {
            for (int i = 0; i < n; i++) state[i] = 2, d[i] = inf;
            fill(from, from + n, -1);
            state[s] = 1;
            q[qh++] = s;
            d[s] = 0;
            while (qh != qt)
            {
                int v = q[qt++];
                qt %= n;
                state[v] = 0;
                for (int i = 0; i < g[v].size(); i++) if (g[v][i].f < g[v][i].u && d[g[v][i].b] > d[v] + g[v][i].c)
                    {
                        int to = g[v][i].b;
                        d[to] = d[v] + g[v][i].c;
                        from[to] = v;
                        from_edge[to] = i;
                        if (state[to] == 1) continue;
                        if (!state[to])
                        {
                            qt--;
                            if (qt == -1) qt = n - 1;
                            q[qt] = to;
                            state[to] = 1;
                        }
                        else
                        {
                            state[to] = 1;
                            q[qh++] = to;
                            qh %= n;
                        }
                    }
            }
            if (d[t] == inf) break;
            int it = t;
            int addflow = inf;
            while (it != s)
            {
                addflow = min(addflow, g[from[it]][from_edge[it]].u - g[from[it]][from_edge[it]].f);
                it = from[it];
            }
            it = t;
            while (it != s)
            {
                g[from[it]][from_edge[it]].f += addflow;
                g[it][g[from[it]][from_edge[it]].back].f -= addflow;
                cost += g[from[it]][from_edge[it]].c * addflow;
                it = from[it];
            }
            flow += addflow;
        }
        return cost;
    }
};

int main()
{
    scanf("%d %d %d", &m, &n, &k);
    MCMF t(0, n, n + 1);
    for (int i = 0; i < n; i++) t.addEdge(i, i + 1, 0, k);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        t.addEdge(x, y, -z, 1);
    }
    printf("%d\n", -t.minCostMaxFlow());
    return 0;
}
