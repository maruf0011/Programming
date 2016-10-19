#include <bits/stdc++.h>

using namespace std;

#define maxn 2048

using ll = long long;
using VI = vector<int>;
using VP = vector<pair<int, int> >;
using VPP = vector<pair<pair<int, int>, int> >;
using VVP = vector<VPP>;

long long bit[2018][2048];


long long query(int x,int y){
  long long ret = 0;
  while(x>0){
    int j = y;
    while(j>0) {
      ret += bit[x][j];
      j -= (j&(-j));
    }
    x -= (x&(-x));
  }
  return ret;
}

void update(int x,int y,int w){
  while(x<maxn){
    int j = y;
    while(j<maxn) {
      bit[x][j] += w;
      j += (j&(-j));
    }
    x += (x&(-x));
  }
}

int main(){
  int n,m,k;
  while(scanf("%d %d %d",&n,&m,&k)==3){
    memset(bit, 0, sizeof bit);
    VVP gland(k);
    for(int i = 0 ; i<k ; i++){
      int len;
      scanf("%d",&len);
      int x,y,w;
      for(int j = 0 ; j<len ; j++) {
        scanf("%d %d %d",&x,&y, &w);
        gland[i].push_back({{x, y}, w});
      }
    }
  
   VI ison(k,1);
   VI last(k,0);
   VI sol;
   int q;
   scanf("%d",&q);
   char str[10];
   int idx,x1,x2,y1,y2;
   for(int i = 0; i<q; i++){
     scanf( "%s",str);
     if(str[0] == 'S') {
       cin>>idx;
       scanf(" %d",&idx);
       ison[idx-1]^=1;
     } else {
       scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
       for(int j = 0; j<k ; j++){
         if(ison[j]==last[j]) continue;
         for(auto &p: gland[j]) {
           update(p.first.first, p.first.second, ison[j]? p.second: -p.second);
         }
         last[j] = ison[j];
        }
        long long s = query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
       // sol.push_back(s);
        printf("%lld\n",s);
      }
    }
  }
  return 0;
}
