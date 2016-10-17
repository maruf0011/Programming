#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int,int> > VP;
typedef vector<VP> VVP;
typedef std::vector<int> VI;
typedef std::vector<VI > VVI;

typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<VVD> VVVD;
typedef vector<VVVD> VVVVD;


//dp(n , VVVD(n , VVD(mx, VD(2,-1.0))))  

double dp[13][13][1000][2];
int vis[13][13][1000][2];
int flagcnt = 0;

struct H
{
	int n;
	VVP adj,rev;
	VVVVD dp;
	VVI isPossible;
	int mx;


	H(int n,int mx):mx(mx), n(n) ,adj(n,VP(0)) , rev(n,VP(0)), isPossible(n,VI(n,0)) {}

	void addEdge(int u,int v,int w)
	{
		adj[u].push_back(make_pair(v,w));
		rev[v].push_back(make_pair(u,w));
		isPossible[u][v] = 1;
	} 

	void preProcess()
	{
		for(int k = 0 ; k<n ; k++)
		{
			for(int i = 0 ; i<n ; i++)
				for(int j = 0 ; j<n ; j++)
					if(isPossible[i][k] && isPossible[k][j])
						isPossible[i][j] = 1;
		}

		for(int i = 0 ; i<n ; i++)
		{
			isPossible[i][i] = 1;
			// for(int j = 0 ; j<n; j++)
			// 	cout<<isPossible[i][j]<<' ';
			// cout<<endl;
		}
		return;
	}

	double rec(int u,int v,int dep,int isUnit)
	{
		// cout<<u<<" -- "<<v<<"d "<<dep<<" "<<isUnit<<endl;
		
		if(isUnit)
		{
			// cout<<"retur for isUnit "<<(int)(u==v)<<endl;
			if(u==v) return 1;
			return 0.0;
		}


		if(u==v) 
		{
			// cout<<"ret for match "<<endl;
			return 1.0/double(adj[u].size());
		}

		if(!isPossible[u][v]) return 0.0; 
		if(dep>=mx) return 1;


		double &ret = dp[u][v][dep][isUnit];

		if(vis[u][v][dep][isUnit]==flagcnt) return ret;

		vis[u][v][dep][isUnit]=flagcnt;

		ret = 0.0;
		
		int cnt = 0;
		for(int i= 0 ; i<adj[u].size() ; i++)
		{
			int next = adj[u][i].first;
			if(next==v)
			{
				ret += rec(next , v , dep+1 , 1);
				cnt++;
			}
		}

		// for(int i = 0 ; i<rev[v].size() ; i++)
		// {
		// 	int next = rev[v][i].first;
		// 	ret += rec(u,next , dep+1 , 1);
		// }

		for(int i = 0 ; i<adj[u].size() ; i++)
		{
			for(int j = 0 ; j<rev[v].size() ; j++)
			{
				if(isPossible[adj[u][i].first][ rev[v][j].first]) cnt++;
				if(adj[u][i].second==rev[v][j].second)
				{
					ret += rec(adj[u][i].first , rev[v][j].first , dep+1 , isUnit);
				}
			}
		}

		// cout<<ret<<endl;
		int total = ((int)adj[u].size()*(int)rev[v].size()) + cnt;
		if(cnt!=0 ) ret /= (double)cnt;
		else ret = 0;
		return ret;
	}

};

int main(int argc, char const *argv[])
{
	/* code */

	int n,m;
	int tcase,cas=1;
	cin>>tcase;
	while(tcase--)
	{
		flagcnt++;
		cin>>n>>m;
		H solver(n,500);

		for(int i = 0 ; i<m ; i++)
		{
			int u,v;
			char ch;

			scanf(" %d %d %c",&u,&v,&ch);
			solver.addEdge(u,v,ch);
		}

		solver.preProcess();

		int q;
		scanf(" %d",&q);
		printf("Case %d:\n",cas++);
		for(int i = 0 ; i<q ; i++)
		{
			int u,v;
			scanf(" %d %d",&u,&v);

			double sol = solver.rec(u,v,0 , 0);
			printf("%.6lf\n", sol);
		}
	}
	return 0;
}