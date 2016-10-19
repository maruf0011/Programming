#include "bits/stdc++.h" 

using namespace std;


using ll = long long;
using VI = vector<int>;
using VVI = vector<VI>;


int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n) {
		int a= 0 , b = 0;
		for(int i= 0 ; i<n  ; i++) {
			int x,y;
			cin>>x>>y;
			if(x>y) a++;
			else if(x<y) b++;
		}
		if(a>b) cout<<"Mishka"<<endl;
		else if(b>a) cout<<"Chris"<<endl;
		else cout<<"Friendship is magic!^^"<<endl; 
	}	
	return 0;
}