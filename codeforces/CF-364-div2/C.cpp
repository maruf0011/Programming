#include "bits/stdc++.h"

using namespace std;

using VI  = vector<int>;

int main(int argc, char const *argv[])
{
	int n,m;

	while(cin>>n) {
		string str;

		cin>>str;

		VI flag(300,0);

		int tot = 0;

		for(auto &x: str) {
			flag[x]++;
			if(flag[x]==1) tot++;
		}

		int st = 0;
		VI cnt(300 , 0);
		int _uni = 0;
		int sol = -1;
		for(int i = 0 ; i<n ; i++) {
			cnt[str[i]]++;
			if(cnt[str[i]]==1) _uni++;

			while(cnt[str[st]]>1) {
				cnt[str[st]]--;
				st++;
			}

			if(_uni==tot) {
				int tmp = i-st+1;
				if(sol==-1 || tmp<sol) sol = tmp;
			}
		}
		cout<<sol<<endl;
	}
	return 0;
}