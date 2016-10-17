#include <bits/stdc++.h>


using namespace std;

typedef tuple<int,int,int> ti;

#define maxx 100100

long long _bit[maxx];

void update(int x,long long value,int n)
{
//    cout<<"come "<<endl;
    while(x<=n)
    {
//        cout<<"upadte "<<x<<" "<<value<<endl;
        _bit[x] = max(_bit[x] , value);
        x += (x&(-x));
    }
    return;
}

long long get_value(int x)
{
    long long ret = 0 ;
    while(x>0)
    {
        ret = max(ret , _bit[x]);
        x -= (x&(-x));
    }
    return ret;
}

int main()
{
    int n;

    while(cin>>n)
    {
        vector<ti>vt;
        vector<int>vy;
        for(int i = 0 ; i<n ; i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            vt.push_back((ti){x,y,z});
            vy.push_back(y);
        }

        sort(vy.begin() , vy.end());
        sort(vt.begin() , vt.end());

//        for(int i = 0 ; i<vt.size(); i++)
//        {
//            cout<<get<0>(vt[i])<<" "<<get<1>(vt[i])<<" "<<get<2>(vt[i])<<endl;
//        }

        memset(_bit , 0 , sizeof _bit);

        map<int,int>idx;
        int cnt = 0;

        for(int i = 0 ; i<vy.size()  ; i++)
        {
            if(!i || vy[i]!=vy[i-1])
            {
                idx[vy[i]] = ++cnt;
            }
        }

        for(int i = 0 ; i<vt.size() ; i++)
        {
            int now = idx[get<1>(vt[i])];
            int now_dia = get<2>(vt[i]);
            //cout<<"for i "<<i<<" "<<get_value(now)<<endl;
            update(now , get_value(now)+now_dia , cnt);
        }

        cout<<get_value(cnt)<<endl;

    }
    return 0;
}
