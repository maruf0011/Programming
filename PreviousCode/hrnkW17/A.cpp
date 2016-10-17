#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll getSum(ll a,ll n,ll d)
{
    ll ret= 0;
    ret = n*a;
    ret += ((n*(n-1))*(d/2LL));

    return ret;
}

int main()
{
    int tcase,cas=1;

    cin>>tcase;

    while(tcase--)
    {
        ll n;
        cin>>n;

        ll oddn = (n+1)/2;
        ll even = (n/2);

        cout<<getSum(1,(oddn+1)/2 , 4) - getSum(3 , (oddn/2) , 4)<<" ";

        cout<<getSum(2 , (even+1)/2 , 4) - getSum(4 , even/2 , 4)<<endl;
    }
    return 0;
}
