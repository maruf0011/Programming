#include "bits/stdc++.h"

using namespace std;

#define sz(a) ((int)a.size())

using ll = long long;
using VI = vector<int>;
using VVI = vector<VI>;



int main(int argc, char const *argv[])
{
	freopen("AL.in", "r+", stdin);
	freopen("AL.out", "w+", stdout);
	int tcase,cas=1;
	cin>>tcase;

	while(tcase--) {
		int l,r;
		cin>>l>>r;
		ll mn = min(l,r);

		ll sol = (mn*(mn+1))/2LL;
		cout<<"Case #"<<cas++<<": "<<sol<<endl;
	}
	return 0;
}