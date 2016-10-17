#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    int tcase,cas=1;

    cin>>tcase;
    while(tcase--)
    {
        cin>>a;
        cin>>b;
        int sol = 1;
        for(int i = 0 ; i<a.size()  && sol ; i++)
        {
            if(a[i]!='?' && b[i]!='?' && a[i]!=b[i])
                sol = 0;
        }
        cout<<(sol ? "Yes" : "No")<<endl;
    }
    return 0;
}
