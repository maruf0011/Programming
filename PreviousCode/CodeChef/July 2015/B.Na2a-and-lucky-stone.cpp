#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef std::vector<VI> VVI;


int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n)
	{
		for (int i = 0; i < n; ++i)
		{
			ll value;
			cin>>value;

			ll tmp = value;
			int cnt = 0;
			ll mul = 1;
			while(tmp%5LL ==0)
			{
				tmp/=5LL; cnt++;
			}

			while(tmp%2 ==0)
			{
				tmp/=2;
				cnt--;
			}

			ll sol = value;
			if(cnt>=1 ) sol = value*(1LL<<(2*(int)((cnt+1)/2)));

			cout<<sol<<endl;
		}
	}
	return 0;
}