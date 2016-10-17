#include <bits/stdc++.h>


using namespace std;

int main()
{
    int tcase,cas=1;

    cin>>tcase;

    vector<string>v= {"FRIDAY", "SATURDAY", "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY"};

    int cnt = 0;
    map<string,int>mp;
    for(auto x: v)
    {
        mp[x] = cnt++;
    }

    int x,y;
    string str;
    while(tcase--)
    {
        cin>>x>>y>>str;
//        assert(y>=x);
        int day;
        day = abs(y-x)%7;
        if(x<=y)day = (day+mp[str])%7;
        else day = ((mp[str]-day)+7)%7;

        cout<<"Case "<<cas++<<": "<<v[day]<<endl;
    }
    return 0;
}
