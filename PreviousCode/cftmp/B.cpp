#include <bits/stdc++.h>

using namespace std;

map<int,int>b,s;

int main()
{
    int n,_s;
    while(cin>>n>>_s)
    {
        char ch;
        int p,o;
        b.clear();
        s.clear();
        int mx = 0;
        for(int i = 0  ; i<n ; i++)
        {
            cin>>ch>>p>>o;

            if(ch=='B') b[p] += o;
            else s[p] += o;

            mx = max(mx , p);
        }
        int tmp = _s;
        vector<pair<int,int> >v;
        for(int i = 0 ; i<=mx  && tmp ;  i++)
        {
            if(s.find(i)!=s.end())
            {
                v.push_back(make_pair(i , s[i]));
                tmp--;
            }
        }

        for(int i = v.size()-1 ; i>=0 ; i--)
            cout<<"S "<<v[i].first<<" "<<v[i].second<<endl;
        tmp = _s;
        for(int i = mx ; i>=0  && tmp; i--)
        {
            if(b.find(i)!=b.end())
            {
                cout<<"B "<<i<<" "<<b[i]<<endl;
                tmp--;
            }
        }


    }
    return 0;
}
