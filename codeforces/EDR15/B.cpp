#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using VI = vector<ll>;

int main(int argc, char const *argv[])
{
	int n;
	ll val;
	VI p(35);

	p[0] = 1;

	for(int i = 1 ; i<35 ; i++) {
		p[i] = p[i-1]*2LL;
	}
	while(cin>>n) {
		map<ll,ll>mp;
		ll sol = 0;
		for(int i = 0 ; i<n ; i++) {
			ll val;
			cin>>val;

			for(auto &x: p) {
				sol += mp[x-val];
			}
			mp[val]++;
		}
		cout<<sol<<endl;
	}
	return 0;
}