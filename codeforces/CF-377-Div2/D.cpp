#include "bits/stdc++.h"

using namespace std;


using ll = long long;
using VL = vector<ll>;

int main(int argc, char const *argv[])
{
  int n;
  int m;
  while(cin>>n>>m) {
    VL pass(n), days(m);
    for(auto &x: pass) {
      cin>>x;
    }
    ll total = 0;
    for(auto &d: days){
      cin>>d;
      total += d;
    }
    int isPossible = 0;
    int low = 0, high = n;
    while(low<high) {
      int mid = (low+high) >>1;
      vector<int>last(m, -1);
      for(int i = 0 ; i<mid ; i++) {
        if(pass[i]==0) continue;
        last[pass[i]-1] = i;
      }
      int chk = 1;
      for(int i = 0 ; i<m  ; i++) {
        if(last[i]==-1) {
          chk = 0;
          break;
        }
      }

      if(chk==0) {
        low = mid+1;
      } else {
        int free = 0;
        chk = 1;
        for(int i = 0 ; i<mid ; i++) {
          if(pass[i] == 0) {
            free++;
            continue;
          }
          if(last[pass[i]-1]==i) {
            free -= days[pass[i]-1];
          } else {
            free++;
          }
          if(free < 0) {
            chk = 0; break;
          }
        }
        if(chk) {
          isPossible = 1;
          high = mid;
        } else low = mid+1;
      }
    }
    if(!isPossible) low = -1;
    cout<<low<<endl;

  }
  return 0;
}