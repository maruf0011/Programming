#include "bits/stdc++.h"

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII  = pair<int,int>;

int rr[] = {-1, 0, 0, 1};
int cc[] = {0, -1, 1, 0};

struct solver
{
	int n,m;
	VVI grid,visited;
	vector<pair<int, PII> >heightList;
	int iter = 0;
	vector<bool> valided;
	solver(int n,int m): n(n), m(m), grid(n, VI(m)), visited(n, VI(m, 0)), valided(n*m*100, false){}

	void _inp() {
		iter = 0;
		for(int i = 0; i<grid.size(); i++) {
			for(int j = 0 ; j<grid[i].size() ; j++) {
				cin>>grid[i][j];
				heightList.push_back({grid[i][j] , {i,j}});
			}
		}
		sort(heightList.begin(),heightList.end());
	}

	int isPossible(int r,int c,int height) {
		// cout<<"r "<<r<<" "<<c<<" H "<<height<<endl;
		iter++;
		queue<int>Q;

		Q.push(r);
		Q.push(c);
		visited[r][c] = iter;
		int total = height - grid[r][c];

		while(!Q.empty()) {
			int _cr = Q.front(); Q.pop();
			int _cc = Q.front(); Q.pop();

			for(int i = 0 ; i<4; i++) {
				int nxr= _cr+rr[i];
				int nxc= _cc+cc[i];
				if(nxr<0 || nxr==n || nxc<0 || nxc==m) return 0;

				if(valided[visited[nxr][nxc]]) return 0;
				if(grid[nxr][nxc] >= height || visited[nxr][nxc]==iter ) continue;

				total += (height-grid[nxr][nxc]);
				visited[nxr][nxc] = iter;
				Q.push(nxr); Q.push(nxc);
			}
		}
		// cout<<"total "<<total<<endl;
		return total;
	}

	int getMaxHeight(int r,int c) {
		int low = 0,high = 1010;

		while(low<high) {
			//cout<<" -> "<<low<<" "<<high<<endl;
			int mid = (low+high+1)>>1;
			int height = isPossible(r,c,grid[r][c]+mid);

			if(!height) {
				high = mid-1;
			}
			else low = mid;
		}
		//cout<<" he he "<<low<<endl;
		int ret = isPossible(r,c,grid[r][c]+low);
		valided[iter] = true;
		return ret;
	}

	int solution() {
		int sol = 0;

		for(auto &cur: heightList) {
			int x = cur.first;
			int r = cur.second.first;
			int c = cur.second.second;

			if(!valided[visited[r][c]]) {
				sol += getMaxHeight(r,c);
				// cout<<sol<<endl;
			}
		}
		return sol;
	}
};

int main() {

	// freopen("inpBS.in","r",stdin);
	// freopen("outBS.out","w",stdout);

	freopen("inpBL.in","r",stdin);
	freopen("outBL.out","w",stdout);

	int cas=1;
	int tcase;

	cin>>tcase;

	while(tcase--) {
		int n,m;
	    cin>>n>>m;

	    solver S(n,m);

	    S._inp();

	   int sol = S.solution();

	   cout<<"Case #"<<cas++<<": "<<sol<<endl;
	}
	return 0;
}