#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 * 1000;

int N;
int joy[MAXN + 10];
vector<int> child[MAXN + 10];
int del[MAXN + 10];
int rs[MAXN + 10];
set<int> st[MAXN + 10];
int root;

int f(int u) {
    int dx = 0;
    st[u].clear();
    st[u].insert(joy[u]);
    for(int v : child[u]) {
        int x = f(v);
        if(st[v].size() > st[u].size()) {
            st[u].swap(st[v]);
            swap(dx, x);
        }
        for(int n : st[v]) {
            if(n+x >= 0) st[u].insert(n + x - dx);
        }
        st[v].clear();
    }
    rs[u] = st[u].size();
    return dx + del[u];
}

int main() {
    freopen("village_fair_2.in", "r", stdin);
  freopen("village_fair_2_ioi.out", "w", stdout);

    int T; scanf("%d", &T);
    for(int cs = 1; cs <= T; cs++) {
        scanf("%d", &N);
        root = -1;
        for(int i = 1; i <= N; i++) {
            scanf("%d", joy+i);
        }
        for(int i = 1; i <= N; i++) {
            child[i] = vector<int>();
        }
        for(int i = 1; i <= N; i++) {
            int par;
            scanf("%d", &par);
            if(par == 0) root = i;
            else child[par].push_back(i);
        }
        for(int i = 1; i <= N; i++) {
            scanf("%d", del+i);
        }
        f(root);
        printf("Case %d:\n", cs);
        for(int i = 1; i <= N; i++) {
            printf("%d\n", rs[i]);
        }
    }
}
