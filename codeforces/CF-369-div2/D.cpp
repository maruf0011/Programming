#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using ll = long long;

ll bmod(ll b,ll p,ll mod){
  if(p==0) return 1LL;
  ll ret = bmod(b, p/2, mod);
  ret = (ret * ret) % mod;
  if(p&1LL) ret = (ret * b)%mod;
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  int n;

  while(cin>>n){
    VI par(n+1);

    for(int i =1 ; i<=n ; i++){
      cin>>par[i];
    }

    VI dep(n+1, -1);
    VI vis(n+1, 0);
    VI parcolor(n+1, 0);
    VI cycle(n+1, -1);
    VI total(n+1, -1);
    ll sol = 1;

    int viscol = 1;

    for(int i = 1 ; i<=n ; i++) {
      if(vis[i]==0) {
        int u = i;
        vis[u] = viscol;
        parcolor[viscol] = viscol;
        dep[u] = 0;
        total[viscol] = 0;
        while(true) {
          int v = par[u];
          if(vis[v]==0) {
            vis[v] = viscol;
            dep[v] = dep[u]+1;
            total[viscol]++;
            u = v;
          } else if(vis[v] == viscol){
            cycle[viscol] = dep[u]-dep[v]+1;
            total[viscol]++;
            total[viscol] -= cycle[viscol];
            break;
          } else {
            int pc = parcolor[vis[v]];
            parcolor[viscol] = pc;
            total[viscol]++;
            total[pc] += total[viscol];
            total[viscol] = -1, cycle[viscol] = -1;
            break;
          }
        }
        viscol++;
      }
    }
    ll mod = 1000000007LL;
    for(int i =1 ; i<=viscol ; i++) {
      if(total[i]!=-1) {
        ll tmp = bmod(2, cycle[i],mod);
        tmp -= 2;
        tmp += mod;
        tmp %= mod;
        tmp = (tmp * bmod(2, total[i], mod))%mod;
        sol = (sol * tmp)%mod;
      }
    }

    cout<<sol<<endl;
  }
  return 0;
}
