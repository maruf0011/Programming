#include <bits/stdc++.h>

using namespace std;

using VP = vector<pair<int,int> >;

int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        VP v(n);

        for(auto &x: v)
        {
            cin>>x.first>>x.second;
        }

        sort(v.begin() , v.end());

        int sol = 0;
        int tme = 0;
        int now = m;
        for(int i = n-1 ; i>=0 ; i--)
        {
            if(now!=v[i].first)
            {
                sol += (now-v[i].first);
                tme += (now-v[i].first);
                now = v[i].first;
            }

            if(tme<v[i].second)
            {
                sol += (v[i].second-tme);
                tme = v[i].second;
            }
        }

        if(now!=0)
            sol += now;
        cout<<sol<<endl;
    }
    return 0;
}
