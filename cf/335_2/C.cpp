#include <bits/stdc++.h>

using namespace std;

using VI =  vector<int>;

int main()
{
    int n;

    while(cin>>n)
    {
        VI pos(n+1);

        int x;
        for(int i= 0 ; i<n; i++)
        {
            cin>>x;
            pos[x] = i+1;
        }

        int mxlen = 1;
        int curcnt = 1;
        for(int i = 2 ; i<=n ; i++)
        {
            if(pos[i]>pos[i-1]) curcnt++;
            else curcnt = 1;
            mxlen = max(mxlen , curcnt);
        }

        cout<<n-mxlen<<endl;
    }
    return 0;
}
