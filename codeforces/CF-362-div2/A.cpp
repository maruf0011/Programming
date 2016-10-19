#include "bits/stdc++.h"

using namespace std;

int main() {
	int tcase,cas=1;

	long long t,s,x;

	while(cin>>t>>s>>x) {
		if(x>=t && (((x-t)%s)==0 || (((x-t-1)%s)==0 && (x-t-1)>0))) {
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}