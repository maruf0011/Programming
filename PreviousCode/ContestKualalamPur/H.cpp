#include "bits/stdc++.h"

using namespace std;

#define ll long long

typedef vector<int> VI;
typedef vector<VI> VVI;


struct H
{
	int n,m;
	VI rank,par;
	ll total;
	ll mxLen;

	vector<pair<int, pair<int,int> > > e;

	H(int n,int m) : mxLen(-1), total(0), n(n) , m(m), rank(n+1, 0) , par(n+1 , -1){}

	void addEdge(int u,int v,int w)
	{
		e.push_back(make_pair(w , make_pair(u,v)));
		total += w;
	}

	int find_par(int x)
	{
		if(par[x]!=-1) return par[x] = find_par(par[x]);
		return x;
	}


	void link(int u,int v)
	{
		if(rank[u]>rank[v])
			par[v] = par[u] ==-1 ? u : par[u];
		else par[u] = par[v] ==-1 ? v : par[v];

		if(rank[u]==rank[v]) 
			rank[v]++;
	}

	void _union(int u,int v)
	{
		link(find_par(u) , find_par(v));
	}

	ll mst()
	{
		sort(e.rbegin() , e.rend());
		//cout<<"okay "<<endl;
		for (int i = 0; i < e.size(); ++i)
		{
			int u = e[i].second.first;
			int v = e[i].second.second;
			int w = e[i].first;
			// cout<<"u "<<u<<" v "<<v<<" "<<w<<endl;
			// cout<<"d "<<find_par(u)<<" "<<find_par(v)<<endl;
			if(find_par(u)!=find_par(v))
			{
				total -=w;
				_union(u,v);
			}
			else if(mxLen==-1)
			{
				mxLen = w;
			}
			// cout<<"bokkor "<<endl;
			/* code */
		}
		return total;
	}
};

bool flag[1000000];

int main(int argc, char const *argv[])
{
	for (int i = 3 ; i < 1000000 ; i+=2)
	{
		if(!flag[i])
		{
			cout<<" -> "<<i<<endl;
			for (int j = i+i ; j < 1000000 ; j+=i )
			{
				flag[j] = true;
			}
		}
		/* code */
	}
	int tcase,cas=1;

	cin>>tcase;

	while(tcase--)
	{
		int n,m;
		cin>>n>>m;
		H hsolver(n , m);

		//cout<<hsolver.find_par(2)<<endl;

		for (int i = 0; i < m; ++i)
		{
			int u,v,w;
			cin>>u>>v>>w;
			hsolver.addEdge(u,v,w);
		}

		ll sol = hsolver.mst();
		ll mxLen = hsolver.mxLen;

		cout<<"Case #"<<cas++<<": "<<sol<<" "<<mxLen<<endl;
	}
	return 0;
}