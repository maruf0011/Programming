#include <bits/stdc++.h>

using namespace std;

int main()
{
    istream is;
    is.setf(ios_base::failbit);
    long long a;
    int tcase,cas=1;

    cin>>tcase;

    while(tcase--)
    {
        cin>>a;
        int f = 0;
        long long m = 1;
        while(m<=a)
        {
            m = m*2LL;
            if((a+1)==m)
            {
                cout<<a/2LL<<endl;
                m= -1;
                break;
            }
        }
        if(m!=-1) cout<<"-1"<<endl;
    }
    return 0;
}
