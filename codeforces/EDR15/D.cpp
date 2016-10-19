#include "bits/stdc++.h" 

using namespace std;
using ll = long long;
using dd = double;
using VI = vector<ll>;

int main(int argc, char const *argv[])
{
	ll d,k,a,b,t;

	while(cin>>d>>k>>a>>b>>t) {
		ll tme;
		if(a*k+t < b*k) {
			ll cnt = d/k;
			ll rem = d%k;
			tme = max(0LL,cnt-1)*(a*k+t)+a*k;
			//cout<<tme<<endl;
			if(rem*a+t < rem*b)
				tme += (rem*a+t);
			else tme += (rem*b);
		}
		else {
			tme = min(k,d)*a + max(0LL , d-k)*b;
		}
		cout<<tme<<endl;
	}
	return 0;
}