#include "bits/stdc++.h"

using namespace std;

#define maxx 200100

int flag[2*maxx];
int _count[2*maxx];

int main(int argc, char const *argv[])
{
  int n;

  while(cin>>n) {
    memset(_count, 0, sizeof _count);
    memset(flag, 0 , sizeof flag);
    int mx = 0;
    for(int i = 1 ; i<=n ; i++) {
      int val;
      cin>>val;
      mx = max(mx, val);
      flag[val]++;
      _count[val]++;
    }
    mx *= 2;
    for(int i=1 ; i<=mx ; i++) {
      _count[i] += _count[i-1];
    }
    long long sol = 0;
    for(int i=1 ; i<=mx ; i++) {
      if(flag[i]) {
        long long tmp = 0;
        for(int j = i+i ; j<=mx ; j+= i) {
          tmp += ((long long)(_count[j-1]-_count[j-i-1])*(long long)(j-i));
        }
        sol= max(sol, tmp);
      }
    }
    cout<<sol<<endl;
  }
  return 0;
}

// 100
// 17 23 71 25 50 71 85 46 78 72 89 26 23 70 40 59 23 43 86 81 70 89 92 98 85 88 16 10 26 91 61 58 23 13 75 39 48 15 73 79 59 29 48 32 45 44 25 37 58 54 45 67 27 77 20 64 95 41 80 53 69 24 38 97 59 94 50 88 92 47 95 31 66 48 48 56 37 76 42 74 55 34 43 79 65 82 70 52 48 56 36 17 14 65 77 81 88 18 33 40
