#include "bits/stdc++.h"

using namespace std;

using VI = vector<int>;
int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n) {
		VI par(n+1);
		VI vis(n+1,0);
		int root = -1;
		for(int i = 1 ; i<=n ; i++){
			cin>>par[i];
			if(i==par[i] && root==-1) {
				root = i;
				vis[i] = n+2;
			}
		}

		
		int change = 0;
		for(int i =1 ; i<=n ; i++){
			if(vis[i]==0) {
				int x = i;
				while(vis[x]==0){
					int px = par[x];
					vis[x] = i;
					if(px==x){
						if(root==-1) {
							root = x;
						}
						else {
							par[x] = root;
							change++;
						}
						break;
					}
					else{
						if(vis[px]==0){
							x = px;
						}
						else {
							if(vis[px]==vis[x]){
								if(root==-1) {
									root = x;
								}
								par[x] = root;
								change++;
								break;
							}
							else break;
						}
					}
				}
			}
		}
		cout<<change<<endl;
		for(int i = 1 ; i<=n ; i++)
			cout<<par[i]<<' ';
		cout<<endl; 
	}
	return 0;
}