#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
	ll n,k,h;

	while(cin>>n>>h>>k){
		vector<ll>v(n);

		for(auto &x: v){
			cin>>x;
		}

		sort(v.rbegin(), v.rend());

		int st = 0;

		ll total = 0;
		ll sec = 0;

		for(int i = 0,j=  n-1; i<=j ){
			ll ext;
			if(total+v[i]>h){
				ll need=  total+v[i]-h;
				ll tme = (need+(k-1))/k;
				total -= min(total , tme*k);

			}
			total+= v[i];
		}
		if(total>0){
			sec += ((total+k-1)/k);
		}
		cout<<sec<<endl;
	}
	return 0;
}