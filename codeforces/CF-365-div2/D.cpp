#include "bits/stdc++.h" 

#define fr first
#define sc second

using namespace std;


using ll = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VP = vector<pair<pair<int, int>, int>>;

struct solve{
  int n,m;
  map<int,int>mp;
  VI seg;
  VI value;
  VI number;
  VP query;
  VI sol;
  solve(int n,int m):n(n), m(m),sol(m), seg(4*n+10, 0), value(n+10), number(n+10), query(m) {}

  solve(){}
  void giveInput(VI &inp, VP &q) {
    number = inp;
    query = q;
  } 
  void update(int cur,int st,int ed,int x,int val){
    if(st==ed){
      seg[cur] = val;
      return;
    }
    int mid = (st+ed)/2;
    if(x<=mid)
      update(cur*2,st,mid,x,val);
    else update(cur*2+1, mid+1,ed,x,val);
    seg[cur] = seg[cur*2]^seg[cur*2+1];
    return;
  }

  int find_sol(int cur,int st,int ed,int l,int r){
    if(st>r || ed<l) return 0;
    if(st>=l && ed<=r) {
      return seg[cur];
    }

    int mid = (st+ed)/2;

    return find_sol(cur*2,st,mid,l,r)^find_sol(cur*2+1,mid+1,ed, l, r);
  }

  void process(){
    sort(query.begin(), query.end());
    value[0] = 0;
    for(int i = 1 ; i<=n ; i++){
      value[i] = value[i-1]^number[i];
    }
    int curPos = 1;
    for(auto &x: query){
      while(curPos<=x.fr.fr){
        int lastIndex = mp[number[curPos]];
        if(lastIndex > 0){
          update(1,1,n,lastIndex,0);
        }
        mp[number[curPos]] = curPos;
        update(1,1,n,curPos, number[curPos]);
        curPos++;
      }
      sol[x.sc] = find_sol(1, 1, n, x.fr.sc, x.fr.fr)^(value[x.fr.sc-1]^value[x.fr.fr]);
    }

    for(auto &x: sol){
     cout <<x<<endl;
    }
  }
};

int main(int argc, char const *argv[])
{
  //ios_base::sync_with_stdio(false);
  int n,m;
  while(cin>>n){
    VI inp(n+1);
    for(int i = 1 ; i<=n ; i++){
      scanf(" %d",&inp[i]);
    }
    cin>>m;
    VP q(m);
    for(int i= 0 ; i<m ; i++){
      scanf(" %d %d",&q[i].fr.sc,&q[i].fr.fr);
      q[i].sc = i;
    }
    solve s(n,m);
    s.giveInput(inp,q);
    s.process();
  }
  return 0;
}
