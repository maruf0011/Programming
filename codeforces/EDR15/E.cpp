#include "bits/stdc++.h"

using namespace std;

using VI = vector<long long>;
using VVI = vector<VI>;

int main(int argc, char const *argv[])
{
	int n;
	long long c;
	while(cin>>n>>c) {
		VI par(n);
		VI cost(n);

		for(int i=0 ; i<n ; i++) {
			cin>>par[i];
		}

		for(auto &x: cost) {
			cin>>x;
		}

		VVI ancestor(n, VI(36));
		VVI sum(n, VI(36));
		VVI minimal(n, VI(36));
		VI sol(n,0);
		for(int _pow = 0 ; _pow<36 ; _pow++) {
			for(int i = 0 ; i<n ; i++) {
				if(!_pow) {
					ancestor[i][_pow] = par[i];
					sum[i][_pow] = cost[i];
					minimal[i][_pow] = cost[i];
				}
				else {
					sum[i][_pow] = sum[i][_pow-1] + sum[ancestor[i][_pow-1]][_pow-1];
					ancestor[i][_pow] = ancestor[ancestor[i][_pow-1]][_pow-1];
					minimal[i][_pow] = min(minimal[i][_pow-1], minimal[ancestor[i][_pow-1]][_pow-1]);
				}
			}
		}

		//cout<<"bokkor"<<endl;

		for(int i = 0 ; i<n ; i++) {
			long long tmp = c,mn = -1;
			int u = i;
			for(int j = 35 ; j>=0 ; j--) {
				if(tmp>=(1LL<<j)) {
					tmp -= (1LL<<j);
					sol[i]+= sum[u][j];
					if(mn==-1 || mn>minimal[u][j]) mn = minimal[u][j];
					u = ancestor[u][j];
				}
			}
			cout<<sol[i]<<' '<<mn<<endl;
		}
	}
	return 0;
}