#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tcase,cas=1;
    cin>>tcase;
    while(tcase--)
    {
        int n , m;

        cin>>n>>m;
        for(int i= 0 ; i<m ; i++)
        {
            int u,v;
            cin>>u>>v;
        }
        long long x = (n/2) , y = (n+1)/2;

        cout<<(x*y)-m<<endl;
    }
    return 0;
}
