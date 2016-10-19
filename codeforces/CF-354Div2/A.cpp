#include <bits/stdc++.h>

using namespace std;

int main(){
	int p,q;

	int n;
	while(cin>>n){
		for(int i = 1 ;  i<=n ; i++){
			int v;
			cin>>v;

			if(v==1) p=i;
			if(v==n) q = i;
		}

		int sol = max(p-1,n-p);
		sol = max(sol , max(q-1,n-q));
		cout<<sol<<endl;
	}
	return 0;
}