#include "bits/stdc++.h" 

using namespace std;
using ll = long long;
using VI = vector<ll>;

int main(int argc, char const *argv[])
{
	int n,m;

	while(cin>>n>>m) {
		VI cell(n);

		for(auto &x: cell) {
			cin>>x;
		}

		VI pos(m);

		for(auto &x: pos) {
			cin>>x;
		}

		int idx = 0;

		ll sol = 0;
		for(int i = 0 ; i<n ; i++) {
			while(idx<m && pos[idx]<cell[i]) {
				idx++;
			}

			int left = idx-1;

			ll tmp1 = left>=0 ? cell[i]-pos[left] : 1000000000000LL;
			ll tmp2 = idx<m ? pos[idx]-cell[i] : 1000000000000LL;
			//cout<<i<<" - "<<tmp1<<" "<<tmp2<<endl;
			sol = max(sol , min(tmp2,tmp1));
		}
		cout<<sol<<endl;
	}	
	return 0;
}