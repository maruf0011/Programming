#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
  int r,k;
  while(cin>>k>>r) {
    int sol = -1;
    k %= 10;
    for(int i = 1 ; i<=10 ; i++) {
      int tmp = (k*i)%10;
      if(tmp == 0 || tmp == r) {
        if(sol==-1 || sol>i) sol = i;
        break;
      }
    }
    cout<<sol<<endl;
  }
  return 0;
}