#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        vector<long long>v(m+1 ,0);
        int x;
        for(int i =1 ; i<=n ; i++)
        {
            cin>>x;v[x]++;
        }
        long long sol = 0;
        for(int i=1 ; i<=m ; i++)
            for(int j = i+1 ; j<=m ; j++)
        {
            sol += (v[i]*v[j]);
        }
        cout<<sol<<endl;
    }
    return 0;
}
