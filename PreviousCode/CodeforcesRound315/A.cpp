#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,s,q;

    while(cin>>t>>s>>q)
    {
        int curtime = 0;
        int donwload = 0;
        int sol =0;
        while(curtime <t)
        {
            curtime++;
            donwload++;

            //cout<<curtime<<" "<<donwload<<" "<<s<<" "<<endl;

            if(donwload>1) s++;
            if(donwload==q) donwload = 0;
            if(curtime>s) {
                sol++;
                curtime = 1;
            }
        }
        cout<<sol+1<<endl;
    }
    return 0;
}
