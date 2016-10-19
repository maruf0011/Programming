#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll bmod(ll b,ll p,ll m){
  if(p==0) return 1LL;
  ll ret = bmod(b, p/2LL, m);
  ret = (ret*ret)%m;
  if(p&1LL) ret = (ret*b)%m;

  return ret;
}

int main(){
  ll n,k;
  ll mod = 1000003LL;
  while(cin>>n>>k){
    if(n<63 && k>(1LL<<n)) {
      cout<<"1 1"<<endl;
      continue;
    }

    ll powN = bmod(2, n,mod);
    ll denom = bmod(powN, k-1, mod);

    ll idx = k-1;
    ll gcdPow = 0;
    while(idx){
      gcdPow += (idx/2LL);
      idx/=2LL;
    }
    
    ll decValue = bmod(2LL, gcdPow, mod);
    ll invValue = bmod(decValue, mod-2LL, mod);

    ll nom = 0LL;

    if(k<mod) {
      nom = 1LL;
      for(int i = 1; i<k ; i++){
        nom = (nom * (((powN-(ll)i)%mod)+mod)%mod)%mod;
      }
    }

    nom = (denom-nom)%mod;
    nom += mod;
    nom %= mod;

    nom = (nom*invValue)%mod;

    denom = (denom * invValue)%mod;

    cout<<nom<<' '<<denom<<endl;

  }
  return 0;
}
//1000000000000000000 1000000000000000000