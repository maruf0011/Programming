#include <bits/stdc++.h>

using namespace std;

int main()
{
    string p = "per";
    string str;
    while(cin>>str)
    {
        int cnt = 0;
        for(int  i= 0 ; i<str.size() ; i++)
        {
            if(tolower(str[i])!=p[i%3]) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
