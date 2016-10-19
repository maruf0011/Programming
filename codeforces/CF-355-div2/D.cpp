#include "bits/stdc++.h"

#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

typedef int T;
typedef vector<T> VT;
typedef vector<VT> VVT;

typedef vector<int> VI;
typedef vector<VI> VVI;

using vp= std::vector<pair< int, int> >;
using vvp = vector<vp>;


struct pq
{
	int r,c,d;
	pq(int r,int c,int d):r(r),c(c),d(d){}
	bool operator<(const pq &b)const{
		return d>b.d;
	}
};


int main(int argc, char const *argv[])
{
	int n,m,p;
	while(cin>>n>>m>>p){
		VVI inp(n,VI(m));
		VI cnt(p+1,0);

		vvp vlist(p+1);
		int ii = 0,jj = 0;
		for(auto &x: inp){
			for(auto &y: x){
				cin>>y;
				cnt[y]++;
				vlist[y].push_back({ii,jj});
				jj++;
			}
			ii++;jj = 0;
		}
		VVI dist(n,VI(m, 1000000000));
		VVI vis(n,VI(m , 0));

		VI xx = {0,0,1,-1};
		VI yy = {1,-1,0,0};

		priority_queue<pq>Q;

		for(int i = 0; i<n ; i++)
			for(int j = 0 ; j<m ; j++){
				if(inp[i][j]==1){
					dist[i][j] = i+j;
					vis[i][j] = 2;
					Q.push(pq(i,j,dist[i][j]));
				}
			}
		int sol;
		for(int i = 2 ; i<=p ; i++){
			if(cnt[i-1]*cnt[i]>=n*m){
				//--
				while(!Q.empty()){
				int rx = Q.top().r;
				int ry = Q.top().c ; 
				int rc = Q.top().d;
				Q.pop();

				for(int j = 0 ; j<4 ; j++){
					int nx = rx+xx[j];
					int ny = ry+yy[j];
					if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
					if(vis[nx][ny]!=i){
						vis[nx][ny] = i;
						dist[nx][ny] = dist[rx][ry]+1;
						// cout<<"nx ny "<<nx<<" "<<ny<<" "<<dist[nx][ny]<<endl;
						Q.push(pq(nx,ny,dist[nx][ny]));
						}
					}
				}
				// cout<<" for "<<i<<endl;
				for(int j = 0 ; j<n ; j++)
					for(int k = 0 ; k<m ; k++)
						if(inp[j][k]==i){
							vis[j][k]=  i+1;
							// cout<<" -- "<<j<<" : "<<k<<" -> "<<dist[j][k]<<endl;
							Q.push(pq(j,k,dist[j][k]));
							if(inp[j][k]==p) sol = dist[j][k]; 
						}	
				//--

			}
			else{

				while(!Q.empty()) Q.pop();

				for(auto &v: vlist[i]){
					for(auto &u: vlist[i-1]){
						int cost = abs(u.first-v.first)+abs(u.second-v.second);
						// cout<<u.first<<" from "<<u.second<<endl;
						// cout<<v.first<<" to "<<v.second<<endl;
						// cout<<cost<<endl;
						// cout<<" -> "<<dist[u.first][u.second]+cost<<endl;
						if(vis[v.first][v.second]==i)
							dist[v.first][v.second] = min(dist[v.first][v.second] , dist[u.first][u.second]+cost);
						else dist[v.first][v.second] =  dist[u.first][u.second]+cost;

						vis[v.first][v.second] = i;
					}
				}
				// cout<<"for i "<<i<<endl;
				for(int j = 0 ; j<n ; j++)
					for(int k = 0 ; k<m ; k++)
						if(inp[j][k]==i){
							vis[j][k]=  i+1;
							Q.push(pq(j,k,dist[j][k]));
							// cout<<" --- "<<j<<" :: "<<k<<" --> "<<dist[k][j]<<endl;
							if(inp[j][k]==p) sol = dist[j][k]; 
						}
			}
		}

		cout<<sol<<endl;

	}
}