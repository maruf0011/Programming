#include "bits/stdc++.h"

using namespace std;

using VS = vector<string>;
using VI = std::vector<int>;


int main(int argc, char const *argv[])
{
  int n,k;

  while(cin>>n>>k) {
    VS vinp(n);
    for(auto &x: vinp) {
      cin>>x;
    }

    VI f(n,0);
    int isMultiple = 0, len = -1;
    for(int i = 0 ; i<k ; i++) {
      int idx;
      cin>>idx;
      idx--;
      f[idx] = 1;
      if(len==-1) {
        len = vinp[idx].size();
      } else if(len != vinp[idx].size()) {
        isMultiple = 1;
      }
    }

    if(isMultiple) {
      cout<<"No"<<endl;
    } else {
      int yes = 0;
      string sol = "";
      
      //cout<<" len "<<len<<endl;
      for(int i = 0 ; i<len ; i++) {
        VI mask(200, 0);
        int a = 0,b = 0,c = 0;
        for(int j = 0 ; j<n ; j++) {
          if(vinp[j].size() != len) continue;
          char ch = vinp[j][i];
          if(f[j]) {
            mask[ch] |= 1;
          } else mask[ch] |= 2;
        }
        char ch;
        for(int j = 0 ; j<200 ; j++) {
          int m = mask[j];
          if(m==1) {
            a++;
            ch = j;
          }
          else if(m==2) b++;
          else if(m==3) c++;
        }

        if(c==0 ) {
          if(a==1) {
            sol.push_back(ch);
            yes = 1;
          } else if(b == 0) {
            sol.push_back('?');
            yes= 1;
          } else sol.push_back('?');
        } else sol.push_back('?');
      }

      if(yes ){
        cout<<"Yes"<<endl;
        cout<<sol<<endl;
      } else {
        cout<<"No"<<endl;
      }
    }
  }
  return 0;
}