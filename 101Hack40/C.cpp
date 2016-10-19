#include "bits/stdc++.h"



using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

void ps(set<int>&s,string tag){
  cout<<tag<<endl;
  for(auto &x: s){
    cout<<x<<' ';
  }
  cout<<endl;
}

int main(){
  int n,m;
  while(cin>>n>>m){
    VVI adj(n);
    VI in(n, 0);
    VI in2(n, 0);
    int u,v;
    for(int i=0; i<m ; i++){
      cin>>u>>v;
      u--,v--;
      in2[v]++;
      in[v]++;
      adj[u].push_back(v);
    }

    set<int>S;

    for(int i = 0 ; i<n ; i++){
      if(in[i]==0) {
        S.insert(i);
      }
    }

    VI order(n);
    for(auto &x: order){
      cin>>x;
      x--;
    }

    int mxIdx = -1;

    VI f(n,0);

    for(int i = 0 ; i<n  ; i++){
      auto it = S.find(order[i]);
      it++;
      if(it!=S.end()){
        f[i] = 1;
        mxIdx = i;
      }
      S.erase(order[i]);
      for(auto &v: adj[order[i]]){
        in[v]--;
        if(in[v]==0) {
          S.insert(v);
        }
      }
    }

    S.clear();

    for(int i= 0 ; i<n ; i++){
      if(!in2[i]) S.insert(i);
    }
    VI sol(n);
    for(int i = 0 ; i<n && mxIdx!=-1 ; i++){
      auto it = S.find(order[i]);
      if(mxIdx==i) {
        it++;
      } else if(i>mxIdx) {
        it = S.begin();
      }

      int u = *it;

      S.erase(it);

      for(auto &v: adj[u]) {
        in2[v]--;
        if(!in2[v]) S.insert(v);
      }
      sol[i] = u;
    }

    if(mxIdx!=-1) {
      for(auto &u: sol){
        cout<<u+1<<' ';
      }
      cout<<endl;
    } else cout<<"-1"<<endl;
  }
  return 0;
}
