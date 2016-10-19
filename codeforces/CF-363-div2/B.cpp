#include "bits/stdc++.h"

using namespace std;

using VI = vector<int>;
char inp[1024][1024];
int main(int argc, char const *argv[])
{
	int n,m;

	while(cin>>n>>m) {
		VI row(n,0);
		VI col(m,0);
		int tot = 0;
		for(int i = 0 ; i<n ; i++) {
			for(int j = 0 ; j<m ; j++) {
				char ch;
				cin>>ch;
				inp[i][j] = ch;
				if(ch=='*') {
					row[i]++;
					col[j]++;
					tot++;
				}
			}
		}

		// cout<<tot<<endl;
		int r = -1,c=-1;
		for(int i = 0 ; i<n && r==-1 ; i++) {
			for(int j = 0  ; j<m && r==-1 ; j++) {
				int tmp = row[i]+col[j] - (inp[i][j]=='*');
				// cout<<i<<" "<<j<<" -> "<<tmp<<endl;
				if(tmp==tot) {
					r = i,c = j;
				}
			}
		}
		if(r==-1) {
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			cout<<r+1<<" "<<c+1<<endl;
		}

	}
	return 0;
}