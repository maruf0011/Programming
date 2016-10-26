#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int n;

	while(cin>>n) {
		int sol = 1;
		int ok = 1;
		for(int i = 0 ; i<n  ; i++) {
			int val;
			cin>>val;
			if(!ok) continue;
			if(val==0) {
				if(!sol) ok = 0;
			}
			else if(val&1) sol = !sol;
		}
		if(sol && ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}