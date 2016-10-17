#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,t;
    while(cin>>n>>t)
    {
        if(n==1 && t==10) cout<<"-1"<<endl;
        else{
            cout<<t;
            for(int i = 2+(t==10) ; i<=n ; i++)
                cout<<'0';
            cout<<endl;
        }
    }
    return 0;
}
