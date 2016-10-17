#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef std::vector<VI> VVI;

int main()
{
	int n;
	ll k;
	int tcase,cas=1;
	cin>>tcase;
	while(tcase--)
	{
		cin>>n>>k;
		ll cnt = 0;
		ll now = 0;
		for (int i = 0; i < n; ++i)
		{
			ll val;
			cin>>val;
			if(val>=now)
			{
				val -= max(0LL , now-1);
				cnt += ((val+k-1)/k);
				now = (((val+k-1)/k)*k) - val;
			}
			else
			{
				now--;
				now -= val;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}