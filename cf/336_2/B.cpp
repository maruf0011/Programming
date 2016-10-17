#include <bits/stdc++.h>

using namespace std;

using VP  = vector<pair<int,int>>;

int main()
{
    string a,b;

    while(cin>>a)
    {
        cin>>b;
        int n = a.size();
        int m = b.size();
        int ext = m-n;

        VP cnt(n);
        if(a[0]=='0')
            cnt[0] = {1,0};
        else cnt[0] = {0,1};

        for(int i =1  ; i<n ; i++)
        {
            cnt[i] = cnt[i-1];
            if(a[i]=='0')
                cnt[i].first += 1;
            else cnt[i].second += 1;
        }
        long long sum = 0;
        pair<int,int>tmp;
        for(int i = 0 ; i<m ; i++)
        {
            if(i<n)
            {
                int ed = i;
                int st = max(0 , (i-ext));
                tmp = cnt[ed];
                if(st!=0) tmp.first -= cnt[st-1].first , tmp.second-= cnt[st-1].second;
                if(b[i]=='0')
                    sum += tmp.second;
                else sum += tmp.first;
            }
            else
            {
                int ed = n-1;
                int st = max(0 , ((n-1)-(m-1-i)));
                tmp = cnt[ed];
                if(st!=0) tmp.first -= cnt[st-1].first , tmp.second-= cnt[st-1].second;
                if(b[i]=='0')
                    sum += tmp.second;
                else sum += tmp.first;
            }
//            cout<<sum<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}
