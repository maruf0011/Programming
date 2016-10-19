#include "bits/stdc++.h"

using namespace std;

int main() {
	int n;
	while(cin>>n) {
		string s;
		cin>>s;
		vector<int>v(n);
		int iscolide = 0;
		int f= 1;
		for(int i =0 ; i<n ; i++){
			cin>>v[i];
			if(s[i]=='L' && f==0) {
				iscolide = 1;
			}
			else if(s[i]=='R' && f==1){
				f = 0;
			}
		}


		int sol = -1;

		for(int i =1 ; i<n && iscolide ; i++) {
			if(s[i]=='L' && s[i-1]=='R') {
				int tmp = (v[i]-v[i-1])/2;
				if(sol==-1 || sol>tmp) {
					sol = tmp;
				}
			}
		}
		cout<<sol<<endl;

	}
	return 0;
}