#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int>v(n);
        for(auto &x: v)
        {
            cin>>x;
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        for(int i = n-1; i>=0 ; i--)
        {
            if(m>0) m-= v[i] , cnt++;
            else break;
        }
        cout<<cnt<<endl;
    }
}
