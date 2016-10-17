#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,m;
    while(cin>>n>>m)
    {
        int sol;
        if(m==1)
            sol = min(n , m+1);
        else if(m==n)
            sol = max(1,m-1);
        else
        {
            if((n-m) > (m-1))
                sol = m+1;
            else sol = m-1;
        }
        cout<<sol<<endl;
    }
    return 0;
}
