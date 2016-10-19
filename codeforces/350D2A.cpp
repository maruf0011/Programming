#include "bits/stdc++.h"

using namespace std;

int main(){
	int n;
	while(cin>>n) {
		cout<<(int)(n/7)*2 + max(0,n%7-5)<<' '<<(int)((n/7)*2+min(2,n%7))<<endl;
	}
	return 0;
}