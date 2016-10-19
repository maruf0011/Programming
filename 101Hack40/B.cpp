#include <bits/stdc++.h>

using namespace std;

using VI = vector<long long>;

int main(){
  int n,m;

  while(cin>>n) {
    VI h(n+1);
    h[0] = 0;
    for(int i = 1 ; i<=n ; i++){
      cin>>h[i];
    }
    cin>>m;
    VI pos(m+1);
    pos[0] = 0;
    int last = 0;
    for(int i= 1 ; i<=m ; i++){
      cin>>pos[i];
      last = pos[i];
    }

    sort(pos.begin(),pos.end());
    last = pos[m];
    long long sol = 0;
    for(int i = 1 ; i<=m ; i++){
      for(int j = pos[i]-1 ; j>=1 && j>=pos[i-1] ; j--){
        sol += min(h[j], pos[i]-j);
      }
    }
    for(int i = last ; i<=n ; i++)
      sol += h[i];
    cout<<sol<<endl;
  }

}
