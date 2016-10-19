#include "bits/stdc++.h"

using namespace std;

using dd = double;
using VD = vector<dd>;


int main(int argc, char const *argv[])
{
	int n,m;

	while(cin>>n>>m) {
		VD pro(n);
		VD sol(n,0.0);
		VD dp((1<<n)+20,0.0);

		dp[0]=1.0;
		for(auto &x: pro) {
			cin>>x;
		}

		for(int mask = 0 ; mask<(1<<n) ; mask++) {
			dd total_pro = 0.0;

			int bit = __builtin_popcount(mask);
			
			for(int i=0 ; i<n ; i++){
				if(!(mask&(1<<i))) {
					total_pro += pro[i];
				}
				else if(bit==m && dp[mask]>1E-10){
					sol[i] += dp[mask];
				}
			}

			if(bit==m) continue;

			for(int i = 0 ; i<n ; i++) {
				if(pro[i]<=1E-7) continue;
				if(!(mask&(1<<i))) {
					dp[mask|(1<<i)] += (dp[mask]*pro[i])/total_pro;
				}
			}
		}
		for(int i = 0 ; i<n ; i++) {
			if(pro[i]>1E-7 && sol[i]<=1E-7)
				sol[i] = 1.0;
		}
		for(auto &x: sol) {
			cout<<x<<' ';
		}
		cout<<endl;

	}
	return 0;
}