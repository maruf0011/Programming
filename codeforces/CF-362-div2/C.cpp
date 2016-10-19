#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int find_dep(ll x){
	if(x==1LL) return 0;
	return find_dep(x/2LL)+1;
}

int main() {
	int q;
	while(cin>>q){
		map<pair<ll,ll>,ll>mp;

		for(int i = 0 ; i<q ; i++) {
			int type;
			cin>>type;
			if(type==1){
				ll u,v,w;

				cin>>u>>v>>w;
				int du = find_dep(u);
				int dv = find_dep(v);

				while(du<dv) {
					ll par = v/2;
					dv--;
					mp[make_pair(par,v)] += w;
					mp[make_pair(v,par)] += w;
					v = par;
				}

				while(du>dv) {
					ll par = u/2;
					du--;
					mp[make_pair(u,par)] += w;
					mp[make_pair(par,u)] += w;
					u = par;
				}

				while(u!=v) {
				    ll pu = u/2,pv = v/2;
				    mp[make_pair(u,pu)] += w;
				    mp[make_pair(pu,u)] += w;
				    mp[make_pair(v,pv)] += w;
				    mp[make_pair(pv,v)] += w;
				    u = pu,v = pv;
				}
			}
			else {
				ll u,v,w;

				cin>>u>>v;
				int du = find_dep(u);
				int dv = find_dep(v);
				ll sol = 0;
				while(du<dv) {
					ll  par = v/2LL;
					dv--;
					sol += mp[make_pair(par,v)];
					v = par;
				}

				while(du>dv) {
					ll par = u/2LL;
					du--;
					sol += mp[make_pair(u,par)];
					u = par;
				}

				while(u!=v) {
				    ll pu = u/2,pv = v/2;
				    sol += mp[make_pair(u,pu)];
				    sol += mp[make_pair(v,pv)];
				    u = pu,v = pv;
				}

				cout<<sol<<endl;
			}
		}
	}
	return 0;
}