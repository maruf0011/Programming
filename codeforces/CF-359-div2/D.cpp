#include "bits/stdc++.h"

using namespace std;

using VI = std::vector<int>;

using VVI = std::vector<VI>;

#define maxx 300100

int _rank[maxx];
int deg[maxx];
int sol[maxx];

VI adj[maxx];

void init(int n){
	for(int i = 0 ; i<=n ; i++){
		_rank[i] = 0;
		adj[i].clear();
		deg[i] = 0;
		sol[i] = -1;
	}
}


int main(){
	int n,q;
	while(cin>>n>>q){
		init(n);
		VI par(n+1,-1);
		for(int i= 2 ; i<=n ; i++){
			int u;
			cin>>u;
			adj[u].push_back(i);
			adj[i].push_back(u);
			par[i] = u;
		}

		queue<int>Q;
		VI vis(n+2 , 0);

		VVI list(n+1);

		Q.push(1);
		vis[1] = 1;

		
		
		list[1].push_back(1);

		while(!Q.empty()){
			int u = Q.front(); Q.pop();
	
			for(auto &v: adj[u]) {
				if(vis[v]==0){
					vis[v] = vis[u]+1;
					Q.push(v);
					list[vis[v]].push_back(v);
				}
			}
		}
		VI cnt(n+1 , 1);

		for(int i = n ; i>=1 ; i--){
			for(auto &u : list[i]){
				for(auto &v: adj[u]){
					if(vis[v] == vis[u]+1){
						cnt[u]+= cnt[v];
					}
				}

				for(auto &v: adj[u]){
					if(vis[v] != vis[u]+1) continue;
					if(cnt[u] < cnt[v]*2) {
						int x = sol[v];
						while(cnt[x]*2<cnt[u]){
							x = par[x];
						}
						sol[u] = x;
						break;
					}
				}
				// cout<<" u "<<u<<endl;
				if(sol[u]==-1) sol[u] = u;
			}
		}

		for(int i = 0 ; i<q ; i++){
			int x;
			cin>>x;
			cout<<sol[x]<<endl;
		}
	}
}