#include "bits/stdc++.h"

using namespace std;

#define sz(a) ((int)a.size())

using ll = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;

const ll mod = 1000000007LL;



ll bmod(ll b,ll p,ll m) {
	// cout<<" -> "<<m<<endl;
	if(p==0) return 1LL;

	ll ret = bmod(b,p/2LL,m);
	ret = (ret*ret)%m;

	if(p&1LL) ret = (ret*b)%m;

	return ret;
}

int main(int argc, char const *argv[])
{
	ll f = 0;
	map<ll,ll>mp;
	for(int i = 1 ; i<1000000 && f<10; i++) {
		
		ll value = bmod(i,124722,2696);
		ll idx;
		if(mp.find(value)!=mp.end()) {
			idx = mp[value];
			f = 1;
		}
		else mp[value] = i;

		if(f){
			cout<<idx<<" "<<i<<endl;
			f++;
		}

	}
	// freopen("BS2.in", "r+", stdin);
	// freopen("BS2.out", "w+", stdout);
	// //cout<<bmod(2,2,2)<<endl;
	// int tcase,cas=1;
	// cin>>tcase;

	// while(tcase--) {
	// 	map<ll,ll>mp;

	// 	ll n,a,b,k;

	// 	cin>>a>>b>>n>>k;

	// 	VL jb(n+1);

	// 	for(int j = 1 ; j<=n ; j++) {
	// 		jb[j] = bmod(j, b, k)%k;
	// 		mp[jb[j]]++;
	// 	}
	// 	ll sol = 0LL;
	// 	for(int i=1 ; i<=n ; i++) {
	// 		ll rem = (k-bmod(i, a, k)%k)%k;
	// 		ll tmp = mp[rem];
	// 		if(tmp>0 && jb[i]==rem) tmp--;
	// 		sol = (sol+ tmp)%mod; 
	// 	}

	// 	cout<<"Case #"<<cas++<<": "<<sol<<endl;
	// }
	return 0;
}