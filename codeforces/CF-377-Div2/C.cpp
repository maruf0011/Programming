#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
  long long a;
  while(cin>>a) {
    vector<long long>v;

    v.push_back(a);
    cin>>a;
    v.push_back(a);
    cin>>a;
    v.push_back(a);
    sort(v.begin(), v.end());

    long long sol = 0;
    for(int i = 0 ; i<2 ; i++) {
      if(v[2]-v[i] > 1) {
        sol += (v[2]-v[i]-1);
      } 
    }
    cout<<sol<<endl;
  }
  return 0;
}