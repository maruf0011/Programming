#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using VI = vector<ll>;


int find_idx(VI &v, ll target){
    int low = 0 ,  high = v.size()-1;

    while(low<high){
        int mid = (low+high)>>1;
        if(v[mid]<target)
            low = mid+1;
        else high = mid;
    }
//    cout<<low<<" - "<<v[low]<<endl;
    return low;
}

int main()
{
    int k;

    while(cin>>k){
        int n;
        cin>>n;

        VI rad(k);
        for(auto &x: rad){
            cin>>x;
            x=x*x;
        }
        rad.push_back(50100*50100);
        sort(rad.begin() , rad.end());
//        for(auto xx: rad)
//            cout<<xx<<endl;

        ll sol = 0;
        for(int i = 0 ; i<n ; i++)
        {
            ll x,y;
            cin>>x>>y;
            ll dist = x*x+y*y;
            sol += (k-find_idx(rad, dist));
//            cout<<sol<<endl;
        }
        cout<<sol<<endl;
    }
    return 0;
}
