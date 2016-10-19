#include <bits/stdc++.h>

using namespace std;

using VI  = std::vector<int>;
using VVI = vector<VI> ;

int main(){
	int n,k;

	while(cin>>n>>k){
		VVI dp(n+1,VI(n+1,0));

		for(int i = 1 ; i<=k ; i++){
			dp[0][0]+=1024;
			for(int j = 0 ; j<n ; j++){
				for(int k =0 ; k<=j ; k++){
					if(dp[j][k]>=1024){
						dp[j+1][k] += (dp[j][k]-1024)/2;
						dp[j+1][k+1] += (dp[j][k]-1024)/2;
						dp[j][k] = 1024;
					}
				}
			}
		}
		int sol = 0;
		for(int i = 0 ; i<n ; i++){
			for(int j = 0 ; j<n ; j++){
				if(dp[i][j]==1024) sol++;
			}
		}
		cout<<sol<<endl;
	}
	return 0;
}