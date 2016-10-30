#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
  int n,k;

  while(cin>>n>>k) {
    vector<int>v;
    for(int i = 0 ; i<n ; i++) {
      int val;
      cin>>val;
      v.push_back(val);
    }
    if(!(n&1)) {
       v.push_back(k+1);
    }
    int sol = 0;
    for(int i= 1 ; i<n ; i++) {
      int mn = max(0, k- (v[i]+v[i-1]));
      v[i] += mn;
      sol += mn;
    }  
    
    cout<<sol<<endl;

    for (int i = 0; i < n; ++i)
    {
      if(i) cout<<' ';
      cout<<v[i];
    }
    cout<<endl;
  }
  return 0;
}