#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    int n,m;
    while(cin>>n>>m)
    {
        cin>>s;
        int f = 0;
        int tot = 0;
        int seg=  0;
        for(int i  =0 ; i<s.size(); i++)
        {
            if(f==0 & s[i]=='.')
            {
                f = 1;
                seg++;
            }
            if(f==1 && s[i]!='.')
            {
                f = 0;
            }
            tot += (s[i]=='.');
        }
        //cout<<tot<<" -- "<<seg<<endl;
        for(int i  =0 ; i<m ; i++)
        {
            int idx;
            char ch;
            cin>>idx>>ch;

            idx--;

            if(s[idx]=='.' && ch!='.')
            {
                tot-- , seg--;
                if(idx-1>=0 && s[idx-1]=='.') seg++;
                if(idx+1<n && s[idx+1]=='.') seg++;
            }
            else if(s[idx]!='.' && ch=='.')
            {
                tot++; seg++;
                if((idx-1>=0 && s[idx-1]=='.')) seg--;
                if( (idx+1<n && s[idx+1]=='.')) seg--;

            }
            s[idx] = ch;
            //cout<<tot<<" "<<seg<<endl;
            cout<<tot-seg<<endl;
        }
    }
    return 0;
}
