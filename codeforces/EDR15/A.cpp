#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int n;

	while(cin>>n) {
		int prev = -1;
		int sol = 1;
		int cnt = 0;
		for(int i = 0 ; i<n ; i++) {
			int val;
			cin>>val;
			if(prev==-1) {
				cnt = 1;
				prev = val;
			}
			else {
				if(prev<val) {
					cnt++;
					prev = val;
					sol = max(cnt,sol);
				}
				else {
					sol = max(sol , cnt);
					prev = val;
					cnt = 1;
				}
			}
		}
		cout<<sol<<endl;
	}
	return 0;
}