#include "bits/stdc++.h"

using namespace std;

using ll = long long;

#define maxx 50000

using VL = vector<ll>;

ll rec(int cur,ll mul,int sign,ll n,VL &pl) {
  if(cur==-1) {
    return (mul>1)*(n/mul)*sign;
  }

  ll ret = 0;
  ret += rec(cur-1, mul, sign, n,pl);
  ret += rec(cur-1, mul*pl[cur], sign*(-1), n, pl);

  return ret;
}

ll calc(ll p,ll q,ll n) {
  VL pl;
  ll to = sqrt(p);
  ll tmp = p;
  for(int i = 2;  i<=sqrt(tmp) ; i++) {
    if((tmp%i) == 0) {
      pl.push_back(i);
      while(!(tmp%i)) {
        tmp /= i;
      }
    }
  }

  if(tmp!=1) pl.push_back(tmp);
  ll ret = q-p - (rec((int)pl.size()-1, 1, -1, q, pl) - rec((int)pl.size()-1, 1, -1, p, pl));
  // cout<<"++> "<<rec((int)pl.size()-1, 1, -1, q, pl)<<endl;
  // cout<<rec((int)pl.size()-1, 1, -1, p, pl)<<endl;
  // cout<<p<<" - "<<q<<" -- "<<ret<<endl;
  return ret;
}
int main(){
  ll n;

  while(cin>>n){
    ll sq = sqrt(n);
    ll sol = 0;
    for(int i = 2 ; i<=sq ; i++){
      sol += calc(i, n/i, n);
    }
    cout<<sol<<endl;
  }
  return 0;
}
