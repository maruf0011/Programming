#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d;
    string p,q;

    while(cin>>d>>p>>q)
    {
        int sol = 0;
        if(q=="month")
        {
            if(d<=29)
                sol = 12;
            else if(d<=30) sol = 11;
            else sol = 7;
        }
        else
        {
            sol = 52;
            if(d==5 || d== 6) sol++;
        }
        cout<<sol<<endl;
    }
    return 0;
}
