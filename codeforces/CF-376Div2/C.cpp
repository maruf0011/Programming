#include "bits/stdc++.h"

using namespace std;

#define maxx 200100

int st[2*maxx], to[2*maxx], _next[2*maxx];
int col[maxx];
int vis[maxx];
int colIter[maxx];
int colCnt[maxx];

int sz = 0;

void addEdge(int u,int v) {
	to[sz] = v;
	_next[sz] = st[u];
	st[u] = sz;
	sz++;
	return;
}

int total = 0;
int mxcol = 0;
int mxcnt = 0;
void dfs(int u,int cnt) {
	if(vis[u]) return;
	vis[u] = 1;
	total++;

	if(colIter[col[u]] != cnt) {
		colIter[col[u]] = cnt;
		colCnt[col[u]] = 1;
	} else colCnt[col[u]]++;

	if(colCnt[col[u]] > mxcnt) {
		mxcnt = colCnt[col[u]];
		mxcol = col[u];
	}

	for(int i = st[u] ; i!=-1 ; i = _next[i]) {
		int v = to[i];
		dfs(v,cnt);
	}
	return;
}

int main(int argc, char const *argv[])
{
	int n,m,k;
	while(cin>>n>>m>>k) {
		memset(st, -1, sizeof st);
		sz = 0;
		for(int i = 1 ; i<=n ; i++) {
			cin>>col[i];
		}
		for(int i =0  ; i<m ; i++) {
			int u,v;
			cin>>u>>v;
			addEdge(u,v);
			addEdge(v,u);
		}

		memset(vis , 0 , sizeof vis);

		memset(colIter, -1, sizeof colIter);
		int tmpcnt = 0;

		int sol = 0;

		for(int i = 1 ; i<=n ; i++) {
			if(!vis[i]) {
				total = 0;
				mxcnt = 0;
				mxcol = 0;

				dfs(i,++tmpcnt);
				sol += (total - mxcnt);
			}
		}
		cout<<sol<<endl;
	}
	return 0;
}