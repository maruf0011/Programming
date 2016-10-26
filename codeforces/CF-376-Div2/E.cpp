#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;

int main(int argc, char const *argv[])
{
  int n;
  while(cin>>n) {
    VI dp(n, 0);
    VI sum(n, 0);
    VI mx(n, 0);

    for(int i = 0 ; i<n ; i++) {
      cin>>sum[i];
      if(i) sum[i] += sum[i-1];
    }
    dp[n-1] = 0;
    mx[n-1] = sum[n-1] - dp[n-1]; 
    for(int i = n-2 ; i>=0 ; i--) {
      dp[i] = mx[i+1];
      mx[i] = max(mx[i+1], sum[i] -dp[i]); 
    }

    cout<<dp[0]<<endl;
  }
  return 0;
}