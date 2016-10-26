#include "bits/stdc++.h"

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

#define maxx 1000100

int BIT[maxx];

void add(int pos,int val,int mxc) {
  // cout<<"add for "<<pos<<" val "<<val<<" mxc "<<mxc<<endl;
  while(pos<=mxc) {
    // cout<<"pos - "<<pos<<endl;
    BIT[pos] += val;
    pos += (pos & (-pos));
  }
  return;
}

int get(int pos) {
  // cout<<"get "<<pos<<endl;
  int ret = 0;
  while(pos>0) {
    // cout<<"pos - "<<pos<<endl;
    ret += BIT[pos];
    pos -= (pos & (-pos));
  }
  return ret;
}
void prep(int a,int b,int mxc) {
  if(a<b) {
    int up = mxc - b+2;
    int dn = mxc - a+2;
    add(1,1,mxc);
    add(up, -1, mxc);
    add(dn, 1, mxc);
  }
  else {
    int up = mxc - a +2 ;
    int dn = mxc - b +2;
    add(up, 1, mxc);
    add(dn, -1, mxc);
  }
}
int check(VVI &inp,int cur, int nxt,int mxc) {
  int ok = 0;
  for(int p = 0, q = 0 ; p<inp[cur].size() && q<inp[nxt].size() ; p++,q++) {
    if(inp[cur][p] < inp[nxt][q]) {
      prep(inp[cur][p], inp[nxt][q], mxc);
      ok = 1; break;
    }
    else if(inp[cur][p] > inp[nxt][q]) {
      prep(inp[cur][p], inp[nxt][q], mxc);
      ok = 1; break;
    }
  }
  if(ok == 0) {
    if(inp[cur].size() <= inp[nxt].size()) {
      add(1,1,mxc);
      return 1;
    }
    return 0;
  }
  return ok==1;
} 
int main() {
  int n,c;
  while(cin>>n>>c) {
    VVI inp(n);
    int len;
    int bp = -1;
    int bpcnt = 0;
    memset(BIT, 0, sizeof BIT);
    for(int i = 0  ; i<n ; i++) {
      cin>>len;
      inp[i] = VI(len);

      for(auto &x: inp[i]) {
        cin>>x;
      }
    }

    for(int i = 0  ;i<n-1 ; i++) {
      if(!check(inp, i, i+1, c)) {
        bp = i;
        bpcnt++;
      }
    }

    if(bpcnt>1) {
      cout<<-1<<endl;
    } else {
      int sol = -1;
      for(int i = 1 ; i<=c ; i++) {
        if(get(i)==(n-1)){
          sol = i-1;
          break;
        }
      }
      cout<<sol<<endl;
    }
  }
  return 0;
}
