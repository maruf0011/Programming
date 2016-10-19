#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
	string s;
	ll mod = 1000000007LL;
	while(cin>>s){
		ll total = 1;

		for(auto &x: s){
			int val;
			if(x>='0' && x<='9') val = x-'0';
			else if(x>='A' && x<='Z') val = x-'A'+10;
			else if(x>='a' && x<='z') val = x-'a'+ 36;
			else if(x=='-') val = 62;
			else val = 63;
			// cout<<val<<endl;
			ll tot = 6-__builtin_popcount(val);

			ll mul = 1;
			while(tot>0){
				mul *=3;
				mul %= mod;
				tot--;
			}
			total = (total*mul)%mod;
		}
		cout<<total<<endl;
	}
	return 0;
}