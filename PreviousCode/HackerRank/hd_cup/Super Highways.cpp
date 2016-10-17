#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll bmod(ll b,ll p,ll mod)
{
    ll ret =1;
    if(p==0) return ret;
    ret = bmod(b , p/2  , mod);
    ret = (ret * ret)%mod;
    if(p&1LL) ret = (ret *b)%mod;
    return ret;
}

int main()
{
    int tcase,cas=1;
    cin>>tcase;;
    ll mod = 1000000009LL;
    while(tcase--)
    {
        ll n,k,c;

        cin>>n>>k>>c;

        ll n_s = n-1LL;

        ll s_sum = ((n_s%mod) *((n_s+1LL)%mod))%mod;
        s_sum = (s_sum  * bmod(2, mod-2LL , mod))%mod;

        ll sc = (s_sum*(c%mod))%mod;
        ll skn = (s_sum*(n%mod))%mod;

        ll s_sqsum = ((n_s%mod) *((n_s+1LL)%mod))%mod;
        s_sqsum = (s_sqsum*((2LL*n_s+1LL)%mod))%mod;
        s_sqsum = (s_sqsum*bmod(6 , mod-2LL , mod))%mod;

        ll ksum = (skn - s_sqsum)%mod;
        ksum %= mod;
        ksum += mod;
        ksum %= mod;

        ksum = ((k%mod)*ksum)%mod;
        ll sol = (sc+ksum)%mod;

        cout<<sol<<endl;
    }
    return 0;
}
