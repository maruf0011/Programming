#include "bits/stdc++.h"

using namespace std;

using VS = vector<string>;
using VI = vector<int>;
using VVI = vector<VI>;

int dp[4010];
VS vlist;
int n;
int sz;

const int mod = 1000000007;
int rec(int cur,VVI &vcnt,VVI &cnt) {
	if(cur==sz) {
		return 1;
	}
	int &ret = dp[cur];
	if(ret!=-1) return ret;

	ret = 0;
	for(int i = 0  ;i<n ; i++) {
		int len = vlist[i].size();
		if(sz-cur < len) continue;
		int isOk = 1;
		for(int j = 0 ; j<26 && isOk ; j++) {
			int need = cur ==0 ? cnt[len-1][j] : cnt[cur+len-1][j] - cnt[cur-1][j];
			isOk &= (need==vcnt[i][j]);
		}
		if(isOk) {
			ret = (ret + rec(cur+len,vcnt,cnt))%mod;
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int tcase,cas=1;

	cin>>tcase;

	while(tcase--) {
		int n,m;
		cin>>n>>m;
		vlist = VS(n);
		VVI vcnt(n,VI(26,0));
		for(int i = 0 ; i<n ; i++) {
			cin>>vlist[i];
			for(auto &ch: vlist[i]){
				vcnt[i][ch-'a']++;
			}
		}
		string s;
		for(int i = 0 ; i<m ; i++) {
			cin>>s;
			VVI cnt((int)s.size(), VI(26,0));
			for(int j  = 0 ; j<s.size() ; j++) {
				if(j) {
					for(int k = 0 ; k<26 ; k++) {
						cnt[j][k] = cnt[j-1][k];
					}
				}
				cnt[j][s[j]-'a']++;
			}
			memset(dp,-1,sizeof dp);
			int sol = rec(0, vcnt,cnt);
			cout<<sol<<endl;
		}
	}
	return 0;
}