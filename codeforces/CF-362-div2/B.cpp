#include "bits/stdc++.h"

using namespace std;

int main(){
	string inp;
	while(cin>>inp){
		string a="";
		a += inp[0];
		string d = "";
		int i;
		for(i = 2 ; i<inp.size() ; i++) {
			if(inp[i]=='e') break;
			d += inp[i];
		}
		int expo = 0;
		for(int j = i+1 ; j<inp.size() ; j++) {
			expo = (expo*10)+(inp[j]-'0');
		}
		string dsol = "";
		if(expo<d.size()) {
			dsol = d.substr(0,expo)+"."+d.substr(expo);
		}
		else dsol = d+string(expo-d.size(),'0');

		string sol = a+dsol;

		if(dsol.size()==2 && dsol[1]=='0') sol = a;

		cout<<sol<<endl;
	}
	return 0;
}