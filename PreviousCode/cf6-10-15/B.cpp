#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bmod(ll b,ll p,ll mod)
{
    if(p==0) return 1LL;
    ll ret= bmod(b , p/2 , mod);
    ret = (ret*ret)%mod;
    if(p&1LL) ret = (ret*b)%mod;
    return ret;
}

int main()
{
    int n;
    ll mod = 1000000007LL;
    while(cin>>n)
    {
        ll sol = bmod(3 , 3*n , mod);
        sol = sol - bmod(7 , n , mod);
        sol %= mod;
        sol += mod;
        sol %= mod;
        cout<<sol<<endl;
    }
    return 0;
}
