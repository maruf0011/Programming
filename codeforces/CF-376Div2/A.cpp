#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	while(cin>>str) {
		char curPos = 'a';
		long long sol = 0;
		for(auto &ch: str) {
			sol += min(abs(ch-curPos), 26-abs(ch-curPos));
			curPos = ch;
		}
		cout<<sol<<endl;
	}
	return 0;
}