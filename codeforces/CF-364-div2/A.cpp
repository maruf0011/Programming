#include "bits/stdc++.h"

using namespace std;

using VP = vector<pair<int,int> >;

int main(int argc, char const *argv[])
{
	int n;
	while(cin>> n) {
		VP v(n);

		for(int i = 0 ; i<n ; i++) {
			int val;
			cin>>val;
			v[i] = {val, i+1};
		}

		sort(v.begin(), v.end());

		for(int i = 0; i<n/2 ; i++) {
			cout<<v[i].second<<' '<<v[n-i-1].second<<endl;
		}
	}
	return 0;
}