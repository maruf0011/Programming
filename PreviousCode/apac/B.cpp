#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> VL;

int main()
{
    freopen("bl.in" , "r+" , stdin);
    freopen("bl.out" , "w+" , stdout);

    int tcase,cas=1;

    cin>>tcase;

    while(tcase--)
    {
        int n;
        int m;
        cin>>n>>m;
        VL dim(n);

        for(int i = 0 ; i<n ; i++  )
        {
            cin>>dim[i];
        }
        cout<<"Case #"<<cas++<<":\n";
        for(int i = 0 ; i<m ; i++)
        {
            int l,r;
            cin>>l>>r;
            double sol = 0;
            for(int j = l ; j<=r ; j++)
            {
                sol += log((double)dim[j]);
            }
            sol /= (double)(r-l+1);
            sol = exp(sol);
            printf("%.9lf\n",sol);
        }
    }
    return 0;
}
