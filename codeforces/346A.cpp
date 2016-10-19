#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int a,b,n;

	while(cin>>n>>a>>b) {
		a--;
	    int sol = (a+b)%n;
	    sol =(sol+n)%n;
	    cout<<sol+1<<endl;
	}
	return 0;
}
