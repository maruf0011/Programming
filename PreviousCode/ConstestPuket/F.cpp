#include <bits/stdc++.h>

using namespace std;

int dp[101][1001][101][2];

vector<int> v;

int mod = 1007;

int rec(int now,int width,int cnt,int isFirst)
{
	cout<<now<<" -- "<<width<<" "<<cnt
	if(now==v.size() )
	{
		if(isFirst) return cnt;
		if(width>=v[0]) return 0;
		return cnt;
	}

	int &ret= dp[now][width][cnt][isFirst];
	if(ret!=-1) return ret;

	ret = rec(now+1 , width , cnt , isFirst);

	if(width>=v[now])
		ret += rec(now+1 , width-v[now] , cnt+1 , isFirst)*cnt;

	ret %= mod;

	return ret;
}

int main()
{
	int tcase,cas=1;

	scanf(" %d",&tcase);

	while(tcase--)
	{
		int n,w;

		scanf(" %d %d",&n,&w);

		memset(dp , -1, sizeof dp);
		v = std::vector<int> (n);
		for(int i = 0 ; i<n ; i++)
			scanf(" %d",&v[0]);

		int sol = 0;

		for(int i = 0 ; i<v.size() ; i++)
		{
			sol += rec(i+1 , w-v[i] , 0 , i==0);
			cout<<sol<<endl;
		}

		printf("Case %d: %d\n",cas++,sol%mod);
	}
}