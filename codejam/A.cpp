#include "bits/stdc++.h"

using namespace  std;

using  VI = vector<int>;

int main(){
	freopen("AL.in" , "r" , stdin);
	freopen("AL.out" , "w" , stdout);
	int tcase,cas=1;

	cin>>tcase;
	int maxi = 0;
	while(tcase--){
		int n;

		cin>>n;
		int mask = 0;
		int sol = -1;
		int i;
		for(i = 1 ; i<200 && mask!=1023 ; i++){
			int value = n*i;
			sol = value;
			while(value){
				mask |= (1<<(value%10));
				value/=10;
			}
		}
		
		if(mask==1023) cout<<"Case #"<<cas++<<": "<<sol<<endl;
		else cout<<"Case #"<<cas++<<": INSOMNIA"<<endl;
	}
	return 0;
}