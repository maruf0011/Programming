#include "bits/stdc++.h"

using namespace std;

using VI  = vector<int>;

int main(int argc, char const *argv[])
{
	VI inp(5);
	VI cnt(101,0);
	int sum = 0;
	for(auto &x: inp)
	{
		cin>>x;
		cnt[x]++;
		sum += x;
	}
	int sol = sum;
	for(auto &x: inp){
		if(cnt[x]>1){
			sol = min(sol , sum-min(3, cnt[x])*x);
		}
	}
	cout<<sol<<endl;
	return 0;
}