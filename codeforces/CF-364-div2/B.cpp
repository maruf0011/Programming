#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
	ll n,m;
	while(cin>>n>>m) {
		set<int>sr,sc;
		ll total = n*n;


		for(int i = 0 ; i<m  ; i++) {
			int x,y;
			cin>>x>>y;

			if(sr.count(x)==0) {
				total -= (n - (int)sc.size());
				sr.insert(x);
			}
			if(sc.count(y)==0) {
				total -= (n- (int)sr.size());
				sc.insert(y);
			}
			cout<<total<<' ';
		}
		cout<<endl;
	}
	return 0;
}