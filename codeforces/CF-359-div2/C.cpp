#include "bits/stdc++.h"

using namespace std;

int main() {
	long long n,k;

	while(cin>>n>>k) {
	    char ch;
	    long long x;
	    long long sol = 0;
	    for(int i = 0 ; i<n ; i++){
	    	cin>>ch>>x;
	    	if(ch=='+') k+=x;
	    	else {
	    		if(k>=x) k-=x;
	    		else sol++;
	    	}
	    }
	    cout<<k<<" "<<sol<<endl;
	}
	return 0;
}