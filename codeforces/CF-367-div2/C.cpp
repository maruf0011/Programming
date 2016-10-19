#include "bits/stdc++.h"

using namespace std;

long long dp[100100][2];

int _function(string &x,string &y,int a,int b){
	// cout<<x<<" "<<y<<" "<<a<<" "<<b<<endl; 
	int stx,incx,sty,incy;

	if(a==0){
		stx = 0,incx = 1;
	} else {
		stx = x.size()-1;
		incx = -1;
	}
	if(b==0) {
		sty = 0;
		incy = 1;
	} else {
		sty = y.size()-1;
		incy = -1;
	}
	int match = 0;
	for(int i = stx,j = sty ; i!=(a?-1:x.size()) && j!= (b?-1 : y.size()) ; i+=incx,j+= incy) {
		if(x[i]==y[j]) match++;
		if(x[i]<y[j]) return true;
		if(x[i]>y[j]) return false;
	}

	if(match==x.size()) return true;
	return false;
}

int main(int argc, char const *argv[])
{
	
	int n;

	while(cin>>n){
		vector<string>v(n);
		vector<int>cost(n);

		for(auto &x: cost){
			cin>>x;
		}

		for(auto &x: v){
			cin>>x;
		}

		memset(dp , -1, sizeof dp);

		dp[0][0] = 0;
		dp[0][1] = cost[0];

		for(int i =1 ; i<n ; i++) {
			for(int j = 0 ; j<2 ; j++) {
				for(int k = 0 ; k<2 ; k++) {
					if(_function(v[i-1],v[i],j,k) && dp[i-1][j]!=-1) {
						// cout<<"returnded "<<i<<" "<<j<<" "<<k<<endl;
						if(dp[i][k]==-1) dp[i][k] = dp[i-1][j] + (k? cost[i] : 0);
						else dp[i][k] = min(dp[i][k],dp[i-1][j]+(k? cost[i] : 0));
					}
				}
			}
		}

		// for(int i=0 ; i<n ; i++){
		// 	for(int j = 0 ; j<2 ; j++)
		// 		cout<<dp[i][j]<<' ';
		// 	cout<<endl;
		// }

		if(dp[n-1][0]==-1 && dp[n-1][1]==-1) {
			cout<<"-1"<<endl;
		}		
		else {
			long long sol = -1;
			if(sol==-1 || (sol>dp[n-1][0] && dp[n-1][0]!=-1)) sol = dp[n-1][0];
			if(sol==-1 || (sol>dp[n-1][1] && dp[n-1][1]!=-1)) sol = dp[n-1][1];
			cout<<sol<<endl;
		}
	}
	return 0;
}