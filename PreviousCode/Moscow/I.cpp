#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        vector<bool>v(2000,false);
        int x,y;
        for(int i = 0 ; i<n ; i++){
            cin>>x>>y;
            for(int j = x ; j<=y ; j++)
                v[j] = 1;
        }

        int st = 1;
        int totsum = 0;

        for(int i = 1 ; i<=1826 ; i++)
        {
            if(i-st+1>180) totsum -= v[st],st++;
            totsum += v[i];
            if(totsum>90)
            {
                st = -1;
                break;
            }
        }
        if(st==-1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
