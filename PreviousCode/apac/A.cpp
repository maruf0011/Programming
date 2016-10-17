#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> VL;


int main()
{
    freopen("al.in" , "r+" , stdin);
    freopen("al.out" , "w+" , stdout);
    int tcase,cas=1;

    cin>>tcase;

    VL fib(100 , 0);

    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2 ; fib[i-1]<1000000000000000100LL ; i++)
    {
        fib[i] = 2*fib[i-1]+1LL;
        //cout<<i<<" "<<fib[i]<<endl;
    }

    while(tcase--)
    {
        ll k;
        cin>>k;

        int idx = 0;
        while(fib[idx]<k)
            idx++;

        int flag= 0;
        cout<<"Case #"<<cas++<<": ";
        while(idx>0)
        {
            ll a = fib[idx-1];
            if(k==(a+1))
            {
                if(flag) cout<<"1"<<endl;
                else cout<<"0"<<endl;
                break;
            }
            else if(k>(a+1))
            {
                flag = !flag;
                k = k-(a+1);
                k = a - k+1;
            }
            idx--;
        }
    }
}
