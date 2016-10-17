#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long>v;

    for(int i = 2 ; i<64 ; i++)
        for(int j = 0; j<i-1 ; j++)
        {
//            cout<<(((1LL<<i)-1)^(1LL<<j))<<" "<<i<< " "<<j<<endl;
            v.push_back(((1LL<<i)-1)^(1LL<<j));
        }

    sort(v.begin() , v.end());

    v.resize(unique(v.begin() , v.end())-v.begin());

    long long a,b;

//    for(int i = 0 ; i<10 ; i++)
//        cout<<v[i]<<endl;

    while(cin>>a>>b)
    {
        int cnt1= 0,cnt2 = 0;

        for(auto &x: v)
        {
            cnt1+=(x<a);
            cnt2 += (x<=b);
        }

        cout<<cnt2-cnt1<<endl;
    }


    return 0;
}
