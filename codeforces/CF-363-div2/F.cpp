#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using pll= pair<long long ,long long>
using VP = vector<pll>;


typedef ll T;
const T EPS = 1e-7;
struct PT {
 T x, y;
 PT() {}
 PT(T x, T y) : x(x), y(y) {}
	bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
	bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};


T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }



int main(){
	int n,k;

	while(cin>>k>>n) {
		vector<PT> stone,mons;

		for(int i = 0 ; i<k ; i++) {
			ll x,y;
			cin>>x>>y;
			stone.push_back(PT(x,y));
		}
		for(int i = 0 ; i<n ; i++) {
			ll x,y;
			cin>>x>>y;
			mons.push_back(PT(x,y));
		}
		vector<int> vis(1024,0);
		for(int i = 0 ; i<k ; i++) {
			for(int j = 0 ; j<n ; j++) {
				for(int m = 0 ; m<n ; m++) {
					if(j==m) continue;
					PT ab = ()
					ll tmp = cross()
				}
			}
		}
	}
	return 0;
}