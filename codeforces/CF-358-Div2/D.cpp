#include "bits/stdc++.h"

using namespace std;


int dp[1020][1020][11][2];
string s1,s2;
int rec(int n,int m,int k,int cur){
	if(k<0) return -1000000;
	if(n<0 || m<0) {
		if(k==0 && cur==0) return 0; 
		if(k==1 && cur==1) return 0;
		return -100000;
	}

	int &ret = dp[n][m][k][cur];
	if(ret!=-1) return ret;

	if(cur) {
		if(s1[n]==s2[m]) ret = max(ret, rec(n-1,m-1,k,cur)+1);
		if(k>=1) ret = max(ret, rec(n,m,k-1,!cur) );
	}
	else {
		if(s1[n]==s2[m] && k>=1) ret = max(ret, rec(n-1,m-1,k,!cur)+1);
		ret = max(ret, rec(n-1,m,k,cur));
		ret = max(ret, rec(n,m-1,k,cur));
	}
	return ret;
}

int main() {
	
	int n,m,k;
	while(cin>>n>>m>>k){
		cin>>s1>>s2;

		memset(dp,-1,sizeof dp);

		int sol = rec(n-1,m-1,k,0);
		cout<<sol<<endl;
	}
	return 0;
}