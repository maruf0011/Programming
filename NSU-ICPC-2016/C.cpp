#include "bits/stdc++.h"

#pragma comment(linker, "/STACK:2000000")

#define maxx 100100

using namespace std;

using VI = vector<int>;

vector<int>vadj[maxx];
set<int>vuni[maxx];
int joy[maxx];
int cost[maxx];
int par[maxx];
int addValue[maxx];
int sol[maxx];

void dfs(int u) {
  if(((int)vadj[u].size()) == 0) {
    par[u] = u;
    if(joy[u]>=0) vuni[u].insert(joy[u]);
  }

  for(auto &v: vadj[u]) {
    dfs(v);
    if(par[u]==-1) {
      par[u] = par[v];
      addValue[u] = addValue[v] + cost[v]; 
      while(!vuni[par[u]].empty() && *vuni[par[u]].begin()+addValue[u] < 0) 
        vuni[par[u]].erase(vuni[par[u]].begin());
      vuni[par[u]].insert(joy[u]-addValue[u]);
    } else {
      for(auto &x: vuni[par[v]]) {
        if(x+addValue[v]+cost[v] < 0 ) continue;
        vuni[par[u]].insert(x+addValue[v]+cost[v]-addValue[u]);
      }
    }
  }
  sol[u] = vuni[par[u]].size();
  return;
}

int main(int argc, char const *argv[])
{
  freopen("village_fair_2.in", "r", stdin);
  freopen("village_fair_2_maruf.out", "w", stdout);

  //ios_base::sync_with_stdio(false);

  int tcase,cas=1;

  cin>>tcase;

  while(tcase--) {
    int n;
    cin>>n;
    memset(addValue, 0, sizeof addValue);
    memset(sol, -1, sizeof sol);
    memset(par, -1, sizeof par);

    for(int i = 1;  i<maxx ; i++) {
      vadj[i].clear();
      vuni[i].clear();
    }
    for(int i = 1 ; i<=n ; i++) {
      cin>>joy[i];
    }
    for(int i = 1 ; i<=n ; i++) {
      int v;
      cin>>v;
      if(v) {
        vadj[v].push_back(i);
      }
    }

    for(int i=1 ; i<=n ; i++) {
      cin>>cost[i];
    }
    dfs(1);
    cout<<"Case "<<cas++<<":"<<endl;
    for(int i = 1 ; i<=n ; i++) {
      cout<<sol[i]<<endl;
    }
    //if(cas==1) break;
  }
  return 0;
}