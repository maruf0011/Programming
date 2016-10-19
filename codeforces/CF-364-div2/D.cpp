#include "bits/stdc++.h"

using namespace std;

bool check(int tot,double l,double v1,double v2,double p) {
	double x = (p*v1*v2 - l*v1)/(v2-v1);
	double tper = x/v1;
	double tbus = (l-x)/v2;

	double tmid = (2*(l-x))/(v1+v2);

	double tottime = tmid*(tot-1.0)+tbus;

	return tottime<=p;
}

int main(int argc, char const *argv[])
{
	int n,k;
	double l,v1,v2;

	while(cin>>n>>l>>v1>>v2>>k) {
		
		double low = 0, high = l/v1;

		int person = (n+(k-1))/k;

		while(fabs(low-high)>=1E-7) {
			double mid = (low+high)/2.0;

			if(check(person,l,v1,v2,mid)) {
				high = mid;
			}
			else low = mid;
		}

		printf("%.9lf\n",(low+high)/2.0);
	}

	return 0;
}