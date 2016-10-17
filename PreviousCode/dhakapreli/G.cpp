#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <time.h>

#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
typedef pair<double , double> pdd;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

struct data {
    int city, dist;
    data () {}
    data (int a, int b) {
        city = a, dist = b;
    }
    bool operator < (const data& p) const {
        return dist > p.dist;
    }
};
int static INF = 1E9;
struct Graph {
    int n, m, t;
    vector <double> E;
    vector < vector <pii> > adj;
    vector <int> dist;
    vector < vector <bool> > vis;
    vector < vector <pdd> > dp;


    Graph (int n, int m, int t): n(n), m(m), t(t), E(n+1, 0.0), adj(n+1), dist(n+1, INF), vis(n+2, vector <bool> (t+2, false)),  dp(n+2, vector <pdd> (t+2)) {
        for (int i = 1; i <= n; i++) {
            scanf("%lf", &E[i]);
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(MP(v, w));
            adj[v].pb(MP(u, w));
        }

        Dijkstra();

        pdd ans = Solve(0, t, 0);

        assert(ans.X <= 1.0);

        printf("%.10lf %.10lf\n", ans.X, ans.Y);
    }

    void Dijkstra () {
        dist[0] = 0;
        priority_queue <data> pq;
        pq.push(data(0, 0));

        while (!pq.empty()) {
            data u = pq.top(); pq.pop();
            for (int i = 0; i < sz(adj[u.city]); i++) {
                int v = adj[u.city][i].X;
                int w = adj[u.city][i].Y;
                if (dist[v] > dist[u.city] + w) {
                    dist[v] = dist[u.city] + w;
                    pq.push(data(v, dist[v]));
                }
            }
        }

//////        for(int i = 1 ; i<=n ; i++)
//////            cout<<" i "<<i<<" "<<dist[i]<<endl;
        return;
    }

    pdd Solve (int u, int lft, int now) {
//        cout<<"-> "<<u <<" "<<lft<<" "<<now<<endl;
//        cout<<" "<<dist[u]<<" "<<now<<endl;
        pdd ret = MP(E[u], (dist[u] + now)), tmp = MP(0, 0);

        if (lft == 0) {
            return dp[u][lft] = ret;
        }

        if (vis[u][lft]) {
            return dp[u][lft];
        }

        vis[u][lft] = true;

        int k = sz(adj[u]), cnt = 0;

        for (int i = 0; i < k; i++) {
            int v = adj[u][i].X;
            int w = adj[u][i].Y;
            //if (v == 0) continue;
            cnt++;
            if (w <= lft) {
                pdd tmp1 = Solve(v, lft - w, now + w);
                ret.X += (1.0-E[u])*tmp1.X;
                ret.Y += tmp1.Y;
            } else {
                pdd tmp1 = Solve(v, 0, now + w);
                ret.X += (1.0-E[u])*tmp1.X;
                ret.Y += tmp1.Y;
            }
        }

        if((cnt+(u!=0)))
        {
            ret.X /= (cnt+(u!=0));
            ret.Y /= (cnt+(u!=0));
        }

        return dp[u][lft] = ret;
    }
};

int main() {
//    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
//    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, m, t;
        scanf("%d %d %d", &n, &m, &t);

        printf("Case %d: ", cs + 1);

        Graph Task(n, m, t);
    }

    return 0;
}
