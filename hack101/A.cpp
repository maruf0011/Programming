#include "bits/stdc++.h"

using namespace std;

int main(){
	string str;

	while(cin>>str) {
		string now;
		
		for(int i = 0 ; i<str.size() ; i++) {
			if(now.size() ==0 || now[now.size()-1]!=str[i])
				now+=str[i];
			else {
				while(now.size() && now[now.size()-1]==str[i]) {
					now.pop_back();
				}
				//now += str[i];
			}
		}

		if(now.size()) cout<<now<<endl;
		else cout<<"Empty String"<<endl;
	}
	return 0;
}