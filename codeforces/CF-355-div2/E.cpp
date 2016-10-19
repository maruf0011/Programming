#include <bits/stdc++.h>

using namespace std;

using VC = vector<char>;
using VVC = std::vector<VC>;

using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using VVVVI = vector<VVVI>;
using VP = vector<pair<int,int> >;

using ll = long long;


ll multi[4][1024];
const ll mod = 1000000007LL;

struct E
{
	int n;
	VVC g;
	VVVVI sum;
	VVVI cnt;
	VP dir; 
	E(){}
	E(int n,VVC &g,VP &dir):n(n), g(g) , sum(2,VVVI(n,VVI(n,VI(4,0)))) , cnt(2, VVI(n , VI(n,0))) , dir(dir){}

	void preprocess(){
		
		for(int d = 0 ; d<2 ; d++){
			for(int i = 0 ; i<n ; i++){
				for(int j = 0 ; j<n ; j++){
					//zero cnt
					int ni= i+dir[d].first,nj = j+dir[d].second;
					cnt[d][i][j] = (ni<0 || ni>=n || nj<0 || nj>=n) ? 0 : cnt[d][ni][nj];
					cnt[d][i][j] += (g[i][j]=='0');

					//calc sum
					sum[d][i][j] = (ni<0 || ni>=n || nj<0 || nj>=n) ? VI(4,0): sum[d][ni][nj];
					sum[d][i][j][g[i][j]-'0']++;
				}
			}
		}
	}
	bool getZeroCnt(int d,int x,int y,int len){
		int lx = x+dir[d].first*(len+1);
		int ly = y+dir[d].second*(len+1);

		int rx = x-dir[d].first*len;
		int ry = y-dir[d].second*len;

		if(lx==-1 || ly==-1 || lx==n || ly==n)
			return cnt[d][rx][ry]>0;
		return (cnt[d][rx][ry]-cnt[d][lx][ly])>0;
	}

	ll calcValue(int x,int y,int len){
		VI tot(4,0);
		for(int d = 0 ; d<2 ; d++){
			int lx = x+dir[d].first*(len+1);
			int ly = y+dir[d].second*(len+1);

			int rx = x-dir[d].first*len;
			int ry = y-dir[d].second*len;

			for(int i = 1 ; i<4 ; i++)
				tot[i] += (sum[d][rx][ry][i] - ((lx==-1 || ly==-1 || lx==n || ly==n) ? 0 : sum[d][lx][ly][i]));
		}

		tot[g[x][y]-'0']--;

		ll sol = 1;

		for(int i = 1 ; i<4 ; i++){
			sol = (sol * multi[i][tot[i]])%mod; 
		}

		return sol;
	}
	ll find_sol(int x,int y){
		int low = 0, high = min(min(x,n-x-1),min(y,n-y-1));

		while(low<high){
			int mid = (low+high+1)>>1;

			if(getZeroCnt(0,x,y,mid) || getZeroCnt(1,x,y,mid))
				high = mid-1;
			else low = mid;
		}
		return calcValue(x,y,low);
	}

	ll solve(){
		ll sol = 0;
		preprocess();
		for(int i =0 ; i<n ; i++){
			for(int j = 0 ; j <n ; j++){
				if(g[i][j]!='0'){
					sol = max(sol , find_sol(i,j));
				}
			}
		}
		return sol;
	}
};

int main(){
	int n;

	for(int i = 0 ; i<1024 ; i++){
		for(int j = 1; j<4 ; j++){
			multi[j][i] = !i ? 1 : (multi[j][i-1]*j)%mod;
		}
	}
	while(cin>>n){
		VVC g(n,VC(n));

		for(auto &x: g){
			for(auto &y: x){
				cin>>y;
			}
		}

		VP dir;
		dir.push_back({0,-1});
		dir.push_back({-1,0});

		E solver1(n,g,dir);
		ll sol = solver1.solve();
		dir.clear();
		dir.push_back({-1,-1});
		dir.push_back({-1,1});
		E solver2(n,g,dir);

		sol = max(sol,solver2.solve());

		cout<<sol<<endl;
	}
	return 0;
}