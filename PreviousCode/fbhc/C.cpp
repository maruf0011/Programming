#include <bits/stdc++.h>


using namespace std;

using VI = vector<long long>;
using ll  = long long;

int bs(ll target,VI &v)
{
    int low = 0 , high = ((int)v.size())-1;

    while(low<high)
    {
        int mid = (low+high+1)>>1;

        if(v[mid]>target)
            high = mid-1;
        else low = mid;
    }
    return low;
}

int main()
{
    freopen("cin.txt" , "r" ,stdin );
    freopen("cout.txt" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    int tcase,cas=1;
    cin>>tcase;

    while(tcase--)
    {
        int n;
        ll p;
        cin>>n>>p;
        VI inp(n , 0);
        VI csum(n , 0);

        for(int i = 0 ; i<n  ; i++)
        {
            cin>>inp[i];
            if(!i) csum[i] = inp[i];
            else csum[i] = csum[i-1]+inp[i];
        }

        ll sol = 0;

        for(int i = 0 ; i<n ; i++)
        {
            ll target = csum[i]-inp[i]+p;

            if(target>=csum[i])
            {
                int pos = bs(target , csum);
                sol += (pos- i+1);
            }
        }
        cout<<"Case #"<<cas++<<": "<<sol<<endl;
    }
    return 0;
}
