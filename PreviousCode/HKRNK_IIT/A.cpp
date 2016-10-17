#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    while(cin>>n)
    {
        ll sum = 0;
        ll tmp;
        for(int i =  0 ; i<n ; i++)
        {
            cin>>tmp;
            sum+=tmp;
        }

        int ans= 0;

        for(int i = 0 ; ; i++)
        {
            if((1LL<<i)>=sum)
            {
                ans = i; break;
            }
        }
        cout<<(1LL<<ans)<<endl;
    }
    return 0;
}
