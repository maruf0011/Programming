#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<ll> VL;
typedef vector<VL> VVL;

typedef vector<int> VI;
typedef vector<VI>VVI;

struct solver
{
	int n,m,k;
	VVL dp;
	vector<pair<int,int> > list[201];
	VI mincost;
	VL sum;
	VL A;
	solver(int n,int m,int k) : n(n) , m(m) , k(k) , dp(n+1 , VL(k+1 , -1)) , mincost(n+1 , -1),sum(n+1 , 0),A(n+1) {}


	ll rec(int cur,int rem)
	{
		if(cur==0)
			return 0;

		ll &ret = dp[cur][rem];

		if(ret!=-1) return ret;

		ret = -(1LL<<60);

		if(mincost[cur]<=rem)
			ret = max(ret, rec(cur-1 , rem-mincost[cur]));
		ret = max(ret , rec(cur-1 , rem)+A[cur]);

		return ret;
	}

	ll process()
	{
		for(int i = 1 ; i<=200 ; i++)
		{
			if(list[i].size()<=0) continue;
			sort(list[i].begin(), list[i].end());
			int now = 0;

			for(int j = 0 ; j<list[i].size(); j++)
			{
				now = max(now, list[i][j].first);
				while(now<=list[i][j].second)
				{
					if(mincost[now]==-1) mincost[now] = i;
					now++;
				}
			}
		}

		//cout<<"abal"<<endl;

		ll solution = 0;
		// solution = rec(n , k);

		return solution;
	}
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int tcase,n,m,k;

	cin>>tcase;

	while(tcase--)
	{
		cin>>n>>k>>m;

		solver s(n,m,k);

		for(int i = 1 ; i<=n ; i++)
		{
			cin>>s.A[i];
			s.sum[i] = s.sum[i-1]+s.A[i];
		}

		for(int i = 0 ; i<m ; i++)
		{
			int x,y,val;
			cin>>x>>y>>val;
			s.list[val].push_back(make_pair(x,y));
		}

		// cout<<"khashi"<<endl;
		ll sol = s.process();
		cout<<sol<<endl;
	}
	return 0;
}