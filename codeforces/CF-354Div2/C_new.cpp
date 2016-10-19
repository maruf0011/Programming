#include "bits/stdc++.h"

using namespace std;

int main(){
	int n,k;
	while(cin>>n>>k){
		string str;
		cin>>str;

		int sol = 0;
		int total = 0;
		char ch = 'b';
		int root = 0;
		for(int i = 0 ; i<n ; i++) {
			if(str[i]==ch) total++;

			while(total>k){
				if(str[root]==ch) total--;
				root++;
			}
			sol = max(sol , i-root+1);
		}


		total= 0;
		ch = 'a';
		root = 0;
		for(int i = 0 ; i<n ; i++) {
			if(str[i]==ch) total++;

			while(total>k){
				if(str[root]==ch) total--;
				root++;
			}

			sol = max(sol , i-root+1);
		}

		cout<<sol<<endl;
	}
}