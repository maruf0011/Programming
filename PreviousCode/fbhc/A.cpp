#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

using ll = long long;
using vp = vector<pair<ll,ll> >;

ll dist(pair<ll,ll> &a,pair<ll,ll> &b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main()
{
    freopen("ain.txt" , "r" ,stdin );
    freopen("aout.txt" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    int tcase,cas=1;
    cin>>tcase;

    while(tcase--)
    {
        int n;
        cin>>n;
        vp inp(n);

        for(auto &p: inp)
            cin>>p.x>>p.y;

        map<long long,int>mp;
        ll sol = 0;
        for(int i = 0 ; i<inp.size() ; i++)
        {
            mp.clear();
            for(int j = 0 ; j<inp.size() ; j++)
            {
                if(j==i) continue;
                ll d = dist(inp[i] , inp[j]);
                sol += mp[d];
                mp[d]++;
            }
        }

        cout<<"Case #"<<cas++<<": "<<sol<<endl;
    }

    return 0;
}
