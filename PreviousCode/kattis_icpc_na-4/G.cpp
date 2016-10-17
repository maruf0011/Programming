#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    int tcase,cas=1;
    cin>>tcase;
    while(tcase--)
    {
        cin>>n;
        int mx = -1;
        int sol = -1;
        double _max= -1;
        for(int i = 1 ; i<=n ; i++)
        {
            double a,b,c;
            cin>>a>>b>>c;

            double tmp = (b*b + 4*a*c)/(4*a);
            if(i==1 || (tmp>_max))
            {
                _max = tmp;
                sol = i;
            }
        }
        cout<<sol<<endl;
    }
    return 0;
}
