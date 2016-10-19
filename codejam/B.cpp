#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
	freopen("BL.in" , "r" , stdin);
	freopen("BL.out" , "w" , stdout);
	int tcase,cas=1;

	cin>>tcase;

	while(tcase--) {
	    string inp;
	    cin>>inp;
	    string str= "";
	    str += inp[0];

	    for(int i = 1 ; i<inp.size() ; i++){
	    	if(inp[i]!=inp[i-1])
	    		str += inp[i];
	    }

	    int move = 0;

	    for(int i = (int)str.size()-1 ; i>=0 ; i-- ){
	    	if((str[i]=='+' && move%2) || (str[i]=='-' && !(move%2))){
	    		move++;
	    	}
	    }
	    cout<<"Case #"<<cas++<<": "<<move<<endl;
	}
	return 0;
}