#include <bits/stdc++.h>

using namespace std;

#define maxx 100100

map<int,int>idx;

vector<pair<int,int> >v[2*maxx];

int main()
{
    int tcase,cas=1;

    int n,k;

    while(cin>>n>>k)
    {
        vector<int> a(n);
        vector<int> tme(2*n);
        idx.clear();
        for(int i = 0 ; i<n ; i++)
        {
            cin>>a[i];
            tme[i] = a[i];
            tme[i+n] = a[i]+1000;
        }

        sort(tme.begin() , tme.end());
        int cnt = 1;
        for(int i = 0 ; i<tme.size() ; i++)
        {
            if(!i || tme[i]!=tme[i-1])
            {
                idx[tme[i]] = cnt++;
            }
        }

        for(int i = 0 ; i<cnt ; i++)
            v[i].clear();

        for(int i = 0 ; i<n ; i++)
        {
            v[idx[a[i]]].push_back(make_pair(i , 1));
            v[idx[a[i]+1000]].push_back(make_pair(i , 0));
        }
        set<int>s;
        int mxcnt = 0;
        for(int i = 1 ; i<cnt ; i++)
        {
            for(int j = 0 ; j<v[i].size() ; j++)
            {
                if(v[i][j].second==0) s.erase(v[i][j].first);
            }
            for(int j = 0 ; j<v[i].size() ; j++)
            {
                if(v[i][j].second==1) s.insert(v[i][j].first);
            }

            mxcnt = max(mxcnt , (int)s.size());
        }

        cout<<(mxcnt+(k-1))/k<<endl;
    }
    return 0;
}
