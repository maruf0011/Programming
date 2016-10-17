#include <bits/stdc++.h>


using namespace std;

int main()
{
    int a,b,c,l;

    while(cin>>a>>b>>c>>l)
    {
        ll total = 0;
        for(int i = 0 ; i<=l ; i++)
        {
            int rem = l-i;
            int extra = ((b+c) - (a+i)) > 0 ? rem : rem - ((b+c) - (a+i))-1 ;

            ll sol =
        }
    }
    return 0;
}
