#include "bits/stdc++.h"

using namespace std;

using VI = vector<int>;

struct solver
{
	VI start,to,next;
	VI visted,count;
	VI university;
	int n,k;
	solver(int n,int k): n(n), k(k), start(n+1, -1), visted(n+1, -1), count(n+1, -1), university(n+1, 0) {}

	void addEdge(int u,int v) {
		to.push_back(v);
		next.push_back(start[u]);
		start[u] = (int)to.size()-1;
	}

	long long dfs(int u,int par) {
		count[u] = (university[u]==1);
		long long ret = 0;
		for(int i = start[u]; i!=-1; i = next[i]) {
			int v = to[i];
			if(v==par) continue;

			ret += dfs(v, u);
			count[u] += count[v];
			long long _pair = min(count[v], 2*k-count[v]);
			ret += _pair;
		}
		return ret;
	}
};

int main(int argc, char const *argv[])
{
	int n,k;
	while(cin>>n>>k) {
		solver S(n,k);

		for(int i = 0 ; i<2*k ; i++) {
			int pos;
			cin>>pos;
			S.university[pos] = 1;
		}
		int u,v;
		for(int i= 1; i<n; i++) {
			cin>>u>>v;
			S.addEdge(u,v);
			S.addEdge(v,u);
		}

		long long sol = S.dfs(1,-1);

		cout<<sol<<endl;
	}
	return 0;
}