#include <bits/stdc++.h>

using namespace std;

#define EPS 10E-15

int main(int argc, char const *argv[])
{
	// freopen("inpCS.in","r",stdin);
	// freopen("outCS.out","w",stdout);

	freopen("inpCL.in","r",stdin);
	freopen("outCL.out","w",stdout);


	int tcase,cas=1;
	cin>>tcase;
	while(tcase--) {
		int n;
		cin>>n;

		vector<double> v(n+1);

		for(auto &x: v) {
			cin>>x;
		}

		double low = 0,high = 2.0;

		while(fabs(low-high)>EPS) {
			//cout<<low<<" "<<high<<endl;
			double mid = (low+high)/2.0;
			double mul = 1.0;
			double tot= 0;

			for(int i = n ; i>=0  ; i--) {
				tot += ((i==0? -1 : 1)*v[i]*mul);
				mul *= mid;
			}
			//cout<<"total "<<tot<<endl;
			if(tot<0.0) 
				high = mid;
			else low = mid;
		}

		printf("Case #%d: %.10lf\n",cas++,(low-1.0) );
	}
	return 0;
}