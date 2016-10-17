#include <bits/stdc++.h>

using namespace std;

int chk(int a)
{
    int m = 1;

    while(m<=a)
    {
        if(m==a) return true;
        m = m*2;
    }
    return false;
}

int main()
{
    int a,b;

    int tcase,cas=1;
    cin>>tcase;
    while(tcase--)
    {
        cin>>a>>b;
        int sol = 0;

        if(a!=b)
        {
            while(!chk(a) || a>b)
            {
                a = a/2;
                sol++;
            }

            while(a!=b)
            {
                a = a*2;
                sol++;
            }
        }

        cout<<sol<<endl;
    }
    return 0;
}
