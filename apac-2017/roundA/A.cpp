#include "bits/stdc++.h"

using namespace std;

int main() {
	// freopen("inpAS.in","r",stdin);
	// freopen("outAS.out","w",stdout);

	freopen("inpAL.in","r",stdin);
	freopen("outAL.out","w",stdout);

	int tcase,cas=1;
	cin>>tcase;

	while(tcase--) {
		int n;
		cin>>n;

		string sol;
		int mx_cnt = 0;
		string inp;
		getline(cin,inp);

		for(int i = 0 ; i<n ; i++) {
			getline(cin,inp);
			int mask = 0;
			for(auto &ch: inp) {
				if(ch==' ') continue;
				mask |= (1<<(ch-'A'));
			}
			int tot_char = __builtin_popcount(mask);
			if(tot_char==mx_cnt) {
				if(inp<sol) 
					sol = inp;
			}
			else if(tot_char>mx_cnt) {
				mx_cnt = tot_char;
				sol = inp;
			}
		}
		cout<<"Case #"<<cas++<<": "<<sol<<endl;
	}
	return 0;
}