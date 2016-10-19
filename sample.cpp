
#include <bits/stdc++.h>
using namespace std;


using VI =  vector<int>;
using VVI = std::vector<VI>;
using VVVI = vector<VVI>;

int main(int argc, char const *argv[])
{

	VVI dp(10010,VI(10,0));
	VI leapYear(10010,0);
	string str = "0000";

	for(int i = 0 ; i<=10 ; i++){
		leapYear[i] = (i%100)==0 ? (i%400)==0 : (i%4)==0;
		leapYear[i] += (i? leapYear[i-1] : 0);
		////
		for(auto &ch: str){
			dp[i][ch-'0']++;
		}
		for(int j = 0 ; j<10 && i ; j++){
			dp[i][j] += dp[i-1][j];
		}
		int f = 1;
		for(int j=3 ; j>=0 && f ; j--){
			if(f){
				str[j] = (str[j]=='9' ? '0' : str[j]+1);
				f = str[j]=='0';
			}
		}
	}
	int y =0 ,m=1,d=2,h=3,s=4;
	
	VI inp1(5),inp2(5);
	string ch1,ch2;
	while(cin>>inp1[y]>>ch1) {
		for(int i = 1 ; i<5 ; i++) {
			cin>>inp1[i]>>ch1;
		}
		if(ch1=="PM") inp1[4]+=12;
		
		for(int i = 0 ; i<5 ; i++) {
			cin>>inp2[i]>>ch2;
		}
		if(ch2=="PM") inp2[4]+=12;

		int rev = 0;
		for(int i = 0 ; i<5 && !rev ; i++) {
			if(inp1[i]>inp2[i] {
				rev = 1; break;
			}
			if(inp1[i]<inp2[i]) {
				break;
			}
		}
		if(rev){
			swap(inp1,inp2);
			swap(ch1,ch2);
		}

		VI sol(10 , 0);

		if(ch1=='PM') inp1[4]-=12;
		if(ch2=='PM') inp2[4]-=12;
		int diff = 0;
		
		for(int i = 0 ; i<10 ; i++) {
			sol[i] += (dp[inp2[y]][i] - (inp1[y]==0 ? 0 : dp[inp1[y]-1][i]));
		}

		diff = inp2[y] - inp1[y];

		/// for month

		if(inp1[m] <= inp2[m]){
			for(int i = 0 ; i<10 ; i++) {
				sol[i] += (dp[inp2[m]][i] - (inp1[m]==0 ? 0 : dp[inp1[m]-1][i]));
			}
			sol[0] -= ((inp2[m]-inp1[m]+1)*2);
		}
		else{
			for(int i = 0 ; i<10 ; i++) {
				sol[i] += ((dp[12][i] - (inp1[m]==0 ? 0 : dp[inp1[m]-1][i]))+dp[inp2[m]][i]);
			}
			sol[0] -= ((12-abs(inp2[m]-inp1[m]+1))*2);
		}

		if(diff){
			for(int i = 0 ; i<10 ; i++) {
				sol[i] += ((dp[12][i]-dp[0][i])*diff);
			}
			sol[0] -= (diff*12*2);
		}

		///day ...... 
		

	}
	return 0;
}
