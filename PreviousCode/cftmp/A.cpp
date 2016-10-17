#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;

int main()
{

    int n,m,p,q;

    while(cin>>n>>m)
    {
        cin>>p>>q;
        VI a(n),b(m);
        for(int i = 0 ; i<n ; i++)
            cin>>a[i];
        for(int i = 0 ; i<m ; i++)
            cin>>b[i];

        int x= p-1 , y = 0;
        int sol = 0;
        while(x<n && !sol)
        {
            while(y<m && b[y]<=a[x])
            {
                y++;
            }
            if((m-y)>=q)
            {
                sol = 1;
            }
            x++;
        }
        cout<<(sol==1 ? "YES" : "NO" )<<endl;
    }
    return 0;
}
