#include "bits/stdc++.h"

using namespace std;

int dp[128][3];
int activity[128];

int rec(int day,int prev){
	if(day==0) return 0;

	int &ret= dp[day][prev];
	if(ret!=-1) return ret;

	ret = 100000000;

	ret = min(ret ,rec(day-1,2)+1);
	if(prev!=1 && (activity[day]&2)) ret = min(ret , rec(day-1 , 1));
	if(prev!=0 && (activity[day]&1)) ret = min(ret, rec(day-1, 0));

	return ret;
}

int main(int argc, char const *argv[])
{
	int n;

	while(cin>>n) {
		for(int i=1 ; i<=n ; i++) {
			cin>>activity[i];
		}

		memset(dp , -1 ,  sizeof dp);

		int sol = rec(n,2);

		cout<<sol<<endl;
	}
	return 0;
}