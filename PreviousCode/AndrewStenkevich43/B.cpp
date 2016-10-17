#include <bits/stdc++.h>


using namespace std;

typedef vector<int> VI;
typedef long long ll;

int bs(VI a)
{
    for(int i = 0 ; i<a.size()-1 ; i++)
    {
        if(a[i] > a[i+1])
            swap(a[i] , a[i+1]);
    }

    for(int i = 0 ; i<a.size() ; i++)
        if(a[i]!=i) return false;

    return true;
}

unsigned long long dp[100];
int idx[100];
int ans[1000000];

int main()
{
//    int n = 6;
//    VI a(n);
//
//    for(int i = 0 ; i<n ; i++)
//        a[i] = i;
//    int sol = 0;
//    do
//    {
//        sol += bs(a);
//    }while(next_permutation(a.begin() , a.end()));
//
//    cout<<sol<<endl;

    freopen("bubble.in" , "r" ,stdin);
    freopen("bubble.out" , "w", stdout);

    dp[1] = 1;
    for(int i = 2; i<65 ; i++)
        dp[i] = dp[i-1]*2;

    int n;
    ll k;
//    cout<<dp[64]<<endl;
    while(cin>>n>>k )
    {
//        assert(n<=66);
        if(n==0 && k==0) break;
        int len = 0;

        for(int i = 1 ;  ; i++)
        {
            if(dp[i]>=k)
            {
                len = i;
                break;
            }
        }


        memset(idx , 0 ,sizeof idx);

        for(int i = 1 ; i<=n ; i++)
            ans[i] = i;
//            cout<<"for len "<<len<<endl;
        for(int i = len ; i>1 ; i--)
        {
            if(k>dp[i-1])
            {
                k -= dp[i-1];
                idx[i] = 1;
//                    cout<<"for i "<<i<<" "<<k<<endl;
            }
            else
            {
                idx[i] = 0;
            }
        }


        for(int i = 2 ; i<=len ; i++)
        {
            if(idx[i])
            {
                swap(ans[n-i+1] , ans[n-i+2]);
//                cout<<n-i+1<<" -- "<<n-i+2<<endl;
            }
        }

        for(int i =  1 ; i<=n ; i++)
            if(i!=1) cout<<' '<<ans[i];
            else cout<<ans[i];
        cout<<endl;
    }
    return 0;
}
