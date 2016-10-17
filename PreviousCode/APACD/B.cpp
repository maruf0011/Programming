#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef vector<int> VI;
typedef vector<pair<int,int> > VP;


int check(int tme , VI &hv, VP &b)
{
//    cout<<tme<<endl;
    int total = 0;
    for(auto bal: b)
    {
        int mn = 1000000;
        for(int i =0; i<hv.size() ; i++)
        {
            int v = hv[i];
//            if(v==0 )
//            {
//                if(bal.x==0) mn = 0;
//            }
////            cout<<bal.x*v<<endl;
            if(bal.x*v <= 0)
            {
                if((abs(bal.x)) <= (tme*abs(v)))
                {
                    mn = min(mn , abs(bal.y-i));
                }
            }
        }
        total += mn;
    }
//    cout<<" -> "<<total<<endl;
    return total;
}

//
//int dp[20][100];
//
//int rec(int cur,int rem,int n,VI &hv,VP &b)
//{
//    if(cur==n) return 0;
//
//    int &ret = dp[cur][rem];
//    if(ret!=-1) return ret;
//
//    ret = 1000000;
//    for(int i = 0 ; i<hv.size() ; i++)
//    {
//        int cost;
//        if(hv[i]==0)
//            cost =
//        ret = min(ret , max(rec()))
//    }
//}

int main()
{
    freopen("bl.in" , "r" , stdin);
    freopen("bl.out" , "w" , stdout);
    int tcase,cas=1;
    cin>>tcase;
    while(tcase--)
    {
        int m,n,q;
        cin>>n>>m>>q;

        VI hv(m);
        for(int i = 0 ; i<m ; i++)
            cin>>hv[i];

        VP b(n);
        for(int i = 0 ; i<n ; i++)
            cin>>b[i].x>>b[i].y;


        int low = 0 , high = 1000000;

        while(low<high)
        {
            int mid = (low+high)>>1;
            if(check(mid ,hv , b) > q)
                low = mid+1;
            else high = mid;
        }
        cout<<"Case #"<<cas++<<": ";
        if(low>=1000000)
            cout<<"IMPOSSIBLE"<<endl;
        else cout<<low<<endl;
    }
    return 0;
}
